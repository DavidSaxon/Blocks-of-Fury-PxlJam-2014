#include "Block.hpp"

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

Block::Block(
        const std::string& sprite, const std::string& weapon,
        const std::string& engine, const std::string& trail,
        float bulletSpeed, const std::string& bulletSound,
        const util::vec::Vector3& pos,
              block::Owner         owner) :
    traversed(false),
    m_spriteName(sprite),
    m_weaponName(weapon),
    m_engineName(engine),
    m_trailName(trail),
    m_owner(owner),
    m_state(block::NOT_ATTACHED),
    top(NULL),
    bottom(NULL),
    left(NULL),
    right(NULL),
    m_trailIndex(0),
    m_trailTimer(0.0f),
    m_bulletSpeed(bulletSpeed),
    m_bulletTimer(1.0f),
    flyDir(0.0f),
    m_dead(false),
    m_health(1.0f) {

    // create the transforms
    m_transform = new omi::Transform(
        "", pos,
        util::vec::Vector3(),
        util::vec::Vector3(1.0f, 1.0f, 1.0f)
    );
    if (m_owner == block::ENEMY) {

        m_transform->rotation.z = 180.0f;
    }
    m_weaponT = new omi::Transform(
        "",
        m_transform->translation,
        util::vec::Vector3(),
        util::vec::Vector3(1.0f, 1.0f, 1.0f)
    );
    m_engineT = new omi::Transform(
        "",
        m_transform->translation,
        util::vec::Vector3(),
        util::vec::Vector3(1.0f, 1.0f, 1.0f)
    );
    m_trailT = new omi::Transform(
        "",
        util::vec::Vector3(),
        util::vec::Vector3(),
        util::vec::Vector3(1.0f, 1.0f, 1.0f)
    );

    // create trail positions
    for (unsigned i = 0; i < 9; ++i) {

        m_trailPositions[i] = pos;
    }

    // sound
    m_bulletSound = omi::ResourceManager::getSound(bulletSound);
    m_blockSound = omi::ResourceManager::getSound("block_explosion");
}

//------------------------------------------------------------------------------
//                                   DESTRUCTOR
//------------------------------------------------------------------------------

Block::~Block() {
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void Block::init() {

    // add components
    m_components.add(m_transform);
    m_components.add(omi::ResourceManager::getSprite(
        m_spriteName, "", m_transform));
    std::string group = "none_block";
    if (m_owner == block::PLAYER) {

        group = "player_block";
    }
    else if (m_owner == block::ENEMY) {

        group = "enemy_block";
    }
    m_collisionDetect = new omi::CollisionDetector("", group, this);
    m_collisionDetect->addBounding(new omi::BoundingCircle(0.55f, m_transform));
    m_components.add(m_collisionDetect);

    m_components.add(m_weaponT);
    m_weaponSprite = omi::ResourceManager::getSprite(
        m_weaponName, "", m_weaponT);
    m_components.add(m_weaponSprite);
    m_engineSprite = omi::ResourceManager::getSprite(
        m_engineName, "", m_engineT);
    m_components.add(m_engineSprite);
    m_trailSprite = omi::ResourceManager::getMesh(
        m_trailName, "", m_trailT);
    m_components.add(m_trailSprite);

    m_trailSprite->shaderFunction = [&] (GLuint program) {

        GLfloat trailPos[27];

        unsigned index = 0;
        for (int i = m_trailIndex; i >= 0; --i) {

            if (i == m_trailIndex) {

                trailPos[(index * 3) + 0] = m_trailPositions[i].x;
            }
            else if (i == 8) {

                trailPos[(index * 3) + 0] =
                    (m_trailPositions[i].x * (1.0f - m_trailTimer)) +
                    (m_trailPositions[0].x * m_trailTimer);
            }
            else {

                trailPos[(index * 3) + 0] =
                    (m_trailPositions[i].x * (1.0f - m_trailTimer)) +
                    (m_trailPositions[i + 1].x * m_trailTimer);

            }
            if (m_state == block::ATTACHING) {

                trailPos[(index * 3) + 1] = m_transform->translation.y -
                    (1.25f - m_trailTimer);
            }
            else {

                trailPos[(index * 3) + 1] = m_transform->translation.y - 1.25f;
            }
            trailPos[(index * 3) + 2] = m_transform->translation.z;
            ++index;
        }
        for (int i = 8; i > m_trailIndex; --i) {

            if (i == 8) {

                trailPos[(index * 3) + 0] =
                    (m_trailPositions[i].x * (1.0f - m_trailTimer)) +
                    (m_trailPositions[0].x * m_trailTimer);
            }
            else {

                trailPos[(index * 3) + 0] =
                    (m_trailPositions[i].x * (1.0f - m_trailTimer)) +
                    (m_trailPositions[i + 1].x * m_trailTimer);

            }
            if (m_state == block::ATTACHING) {

                trailPos[(index * 3) + 1] = m_transform->translation.y -
                    (1.25f - m_trailTimer);
            }
            else {

                trailPos[(index * 3) + 1] = m_transform->translation.y - 1.25f;
            }
            trailPos[(index * 3) + 2] = m_trailPositions[i].z;
            ++index;
        }

        // pass in trail positions
        glUniform3fv(glGetUniformLocation(program, "u_trailPositions"),
            27, trailPos);
        glUniform1f(glGetUniformLocation(program, "u_trailFade"),
            -m_engineOffset.y);
        glUniform1i(glGetUniformLocation(program, "u_enemy"),
            int(m_owner == block::ENEMY));
    };
}

void Block::update() {

    // update the trail timer
    m_trailTimer += 0.2f * omi::fpsManager.getTimeScale();
    if (m_trailTimer >= 1.0f) {

        m_trailTimer -= 1.0f;
        ++m_trailIndex;
        if (m_trailIndex == 9) {

            m_trailIndex = 0;
        }
    }
    // update the current trail
    m_trailPositions[m_trailIndex] = m_engineT->translation;

    // update based on state
    switch (m_state) {

        case block::NOT_ATTACHED: {

            m_weaponOffset = 0.0f;
            m_weaponSprite->visible = false;
            m_engineOffset = 0.0f;
            m_engineSprite->visible = false;
            m_trailSprite->visible = false;
            // clear trail positions
            for (unsigned i = 0; i < 9; ++i) {

                m_trailPositions[i] = m_engineT->translation;
            }
            break;
        }
        case block::ATTACHING: {

            float slideSpeed = 0.02f * omi::fpsManager.getTimeScale();;

            // slide out weapon
            m_weaponOffset.y += slideSpeed;
            if (m_weaponOffset.y >= 1.0f) {

                m_weaponOffset.y = 1.0f;
                m_state = block::ATTACHED;
            }
            m_weaponSprite->visible = true;

            // slide out engine
            m_engineOffset.y -= slideSpeed;
            if (m_engineOffset.y >= 1.0f) {

                m_engineOffset.y = 1.0f;
                m_state = block::ATTACHED;
            }
            m_engineSprite->visible = true;
            m_trailSprite->visible = true;
            break;
        }
        default: {

            m_weaponSprite->visible = true;
            m_engineSprite->visible = true;
            m_trailSprite->visible = true;
            break;
        }
    }

    // update based on owner
    switch (m_owner) {

        case block::NONE: {

            noOwnerUpdate();
            break;
        }
        case block::PLAYER: {

            playerUpdate();
            // visibility based on neighbours
            if (top != NULL) {

                m_weaponSprite->visible = false;
            }
            if (bottom != NULL) {

                m_engineSprite->visible = false;
                m_trailSprite->visible = false;
            }
            break;
        }
        case block::ENEMY: {

            enemyUpdate();
            // visibility based on neighbours
            if (bottom != NULL) {

                m_weaponSprite->visible = false;
            }
            if (top != NULL) {

                m_engineSprite->visible = false;
                m_trailSprite->visible = false;
            }
            break;
        }
    }

    if (m_dead) {

        if (m_transform->translation.y > -24.0f) {
        
            omi::SoundPool::play(m_blockSound, false, 1.0f);
        }
        addEntity(new Explosion(m_transform->translation, "block_explosion_1"));
        remove();
    }
}

void Block::setPosition(const util::vec::Vector3& pos) {

    traversed = true;
    m_transform->translation = pos;

    // set the position of neighbors
    if (top != NULL && !top->traversed) {

        top->setPosition(pos + util::vec::Vector3(0.0f, 1.0f, 0.0f));
    }
    if (bottom != NULL && !bottom->traversed) {

        bottom->setPosition(pos + util::vec::Vector3(0.0f, -1.0f, 0.0f));
    }
    if (left != NULL && !left->traversed) {

        left->setPosition(pos + util::vec::Vector3(-1.0f, 0.0f, 0.0f));
    }
    if (right != NULL && !right->traversed) {

        right->setPosition(pos + util::vec::Vector3(1.0f, 0.0f, 0.0f));
    }

    // update the weapons position
    if (m_owner == block::ENEMY) {

        m_weaponT->translation = m_transform->translation - m_weaponOffset;
        m_engineT->translation = m_transform->translation - m_engineOffset;
    }
    else {

        m_weaponT->translation = m_transform->translation + m_weaponOffset;
        m_engineT->translation = m_transform->translation + m_engineOffset;
    }
    
    m_weaponT->rotation    = m_transform->rotation;
    m_engineT->rotation    = m_transform->rotation;
}

void Block::renew() {

    traversed = true;
}

void Block::attach(bool a) {

    if (a) {

        m_state = block::ATTACHING;
    }
    else {

        m_state = block::NOT_ATTACHED;
    }
}

void Block::destroy() {

    m_dead = true;
}

//-----------------------------------GETTERS------------------------------------

block::Owner Block::getOwner() const {

    return m_owner;
}

//------------------------------------STTERS------------------------------------

void Block::setOwner(block::Owner owner) {

    m_owner = owner;
    std::string group = "none_block";
    m_transform->rotation.z = 0.0f;
    if (m_owner == block::PLAYER) {

        group = "player_block";
        m_transform->rotation.z = 0.0f;
    }
    else if (m_owner == block::ENEMY) {

        group = "enemy_block";
        m_transform->rotation.z = 180.0f;
    }
    m_collisionDetect->setGroup(group);
}

//------------------------------------------------------------------------------
//                            PRIVATE MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void Block::noOwnerUpdate() {

    // move the block down
    m_transform->translation.y -=
        value::DOWN_SPEED * omi::fpsManager.getTimeScale();

    //fly
    float flySpeed = m_flySpeed * omi::fpsManager.getTimeScale();
    m_transform->translation.x -= flySpeed *
        cos(flyDir * util::math::DEGREES_TO_RADIANS);
    m_transform->translation.y += flySpeed *
        sin(flyDir * util::math::DEGREES_TO_RADIANS);

    setPosition(m_transform->translation);

    if (m_flySpeed > 0.0f) {

        m_flySpeed -= 0.0002f * omi::fpsManager.getTimeScale();
    }
    else {

        m_flySpeed = 0.0f;
    }

    // rotate
    m_transform->rotation.z += m_rotSpeed * omi::fpsManager.getTimeScale();

    // check bounds
    if (m_transform->translation.x >= 62.0f) {

        destroy();
    }
    else if (m_transform->translation.x <= -62.0f) {

        destroy();
    }
    if (m_transform->translation.y >= 40.0f) {

        destroy();
    }
    else if (m_transform->translation.y <= -26.0f) {

        destroy();
    }
}

void Block::playerUpdate() {

    if (omi::input::isKeyPressed(sf::Keyboard::Space) && top == NULL) {

        m_bulletTimer += m_bulletSpeed * omi::fpsManager.getTimeScale();

        if (m_bulletTimer >= 1.0f) {
        
            createBullet();
            omi::SoundPool::play(m_bulletSound, false, 1.0f);
            m_bulletTimer -= 1.0f;
        }
    }
    else if (m_bulletTimer < 1.0f) {

        m_bulletTimer += m_bulletSpeed * omi::fpsManager.getTimeScale();

        if (m_bulletTimer >= 1.0f) {

            m_bulletTimer = 1.0f;
        }
    }
}

void Block::enemyUpdate() {

    if (bottom == NULL) {

        m_bulletTimer += m_bulletSpeed * omi::fpsManager.getTimeScale() * 0.25f;

        if (m_bulletTimer >= 1.0f) {
        
            createBullet();
            omi::SoundPool::play(m_bulletSound, false, 0.5f);
            m_bulletTimer -= 1.0f;
        }
    }
}
