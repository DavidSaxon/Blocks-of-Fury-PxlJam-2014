#include "PlayerShip.hpp"

//------------------------------------------------------------------------------
//                                   CONSTANTS
//------------------------------------------------------------------------------

namespace {

static const float MOVE_SPEED = 0.25f;

}

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

PlayerShip::PlayerShip() :
    m_first(true),
    m_start(false),
    m_coinTimer(0.0f) {
}

//------------------------------------------------------------------------------
//                                   DESTRUCTOR
//------------------------------------------------------------------------------

PlayerShip::~PlayerShip() {
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void PlayerShip::init() {

    buildShip();
    initComponents();
}

void PlayerShip::update() {

    if (!m_start) {

        m_coinTimer += 0.045f * omi::fpsManager.getTimeScale();
        if (m_coinTimer >= 1.0f) {

            m_coinTimer -= 1.0f;
            m_coinSprite->visible = !m_coinSprite->visible;
        }

        if (omi::input::isKeyPressed(sf::Keyboard::Space)) {

            m_guiSprite->visible = false;
            m_coinSprite->visible = false;
            m_introMusic->setLoop(false);
            m_start = true;
        }
    }

    if (m_introMusic->isStopped() && m_music->isStopped()) {

        m_music->play();
    }

    if (!m_first) {

        rebuild();
    }
    else {

        m_first = false;
    }

    processBlockGrab();

    // process input
    processInput();

    collisions();
}

//------------------------------------------------------------------------------
//                            PRIVATE MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void PlayerShip::processBlockGrab() {

    std::vector<Block*> newBlocks;
    // check over the collisions of the blocks contained withing this
    for (std::vector<Block*>::iterator it = m_blocks.begin();
         it != m_blocks.end(); ++it) {

        // get collision data from each block
        for (std::vector<omi::CollisionData>::iterator data =
            (*it)->m_collisionDetect->getCollisionData().begin();
            data != (*it)->m_collisionDetect->getCollisionData().end();
            ++data) {

            if (data->group.compare("none_block")) {

                continue;
            }

            // cast the entity to a block
            Block* block = static_cast<Block*>(data->entity);

            // add to the list of new blocks
            if (block->getOwner() == block::NONE &&
                find(newBlocks.begin(), newBlocks.end(), block) == 
                newBlocks.end()) {

                // add to the list of new entities;
                newBlocks.push_back(block);
            }
        }
    }

    // process the new blocks
    for (std::vector<Block*>::iterator it = newBlocks.begin();
         it != newBlocks.end(); ++it) {

        // find the closet block
        Block* closet = 0;
        float distance = 10000000.0f;
        for (std::vector<Block*>::iterator block = m_blocks.begin();
             block != m_blocks.end(); ++block) {

            if ((*block)->top != NULL && (*block)->bottom != NULL &&
                (*block)->left != NULL && (*block)->right != NULL) {

                continue;
            }

            if (util::vec::distance(
                (*it)->m_transform->translation,
                (*block)->m_transform->translation) <
                distance) {

                distance = util::vec::distance(
                    (*it)->m_transform->translation,
                    (*block)->m_transform->translation);
                closet = *block;
            }
        }
        // calculate the angle between the blocks
        float angle = util::vec::angleBetween(
            (*it)->m_transform->translation.xy(),
            closet->m_transform->translation.xy());
        if (angle < 0.0) {

            angle += 360.0f;
        }
        else if (angle >= 360.0f) {

            angle -= 360.0f;
        }
        // attach to the closet block
        if (angle > 45.0f &&  angle < 135.0f) {

            closet->bottom = *it;
            (*it)->top = closet;
        }
        else if (angle > 135.0f &&  angle < 225.0f) {

            closet->left = *it;
            (*it)->right = closet;
        }
        else if (angle > 225.0f &&  angle < 315.0f) {

            closet->top = *it;
            (*it)->bottom = closet;
        }
        else {

            closet->right = *it;
            (*it)->left = closet;
        }
    }
    for (std::vector<Block*>::iterator it = newBlocks.begin();
         it != newBlocks.end(); ++it) {

        (*it)->setOwner(block::PLAYER);
        (*it)->attach(true);
        m_blocks.push_back(*it);
    }
}

void PlayerShip::rebuild() {
    
    for (unsigned i = 0; i < m_blocks.size(); ++i) {

        m_blocks[i]->traversed = false;
        m_blocks[i]->top = NULL;
        m_blocks[i]->bottom = NULL;
        m_blocks[i]->left = NULL;
        m_blocks[i]->right = NULL;
    }
    rebuildRec(m_hub);
    // destroy any blocks that have not been connected
    for (std::vector<Block*>::iterator it = m_blocks.begin();
         it != m_blocks.end();) {

        if (!(*it)->traversed) {

            (*it)->destroy();
            it = m_blocks.erase(it);
        }
        else {

            ++it;
        }
    }
}

void PlayerShip::rebuildRec(Block* block) {

    if (block->traversed) {

        return;
    }
    block->traversed = true;

    // get collision data from each block
    for (std::vector<omi::CollisionData>::iterator data =
        block->m_collisionDetect->getCollisionData().begin();
        data != block->m_collisionDetect->getCollisionData().end();
        ++data) {

        if (data->group.compare("player_block")) {

            continue;
        }

        // cast the entity to a block
        Block* collide = static_cast<Block*>(data->entity);

        // find the side it's nearest too
        float angle = util::vec::angleBetween(
            block->m_transform->translation.xy(),
            collide->m_transform->translation.xy());
        if (angle < 0.0) {

            angle += 360.0f;
        }
        else if (angle >= 360.0f) {

            angle -= 360.0f;
        }
        // attach to the closet block
        if (angle > 45.0f &&  angle < 135.0f) {

            if (block->top != NULL) {

                continue;
            }

            collide->bottom = block;
            block->top = collide;
        }
        else if (angle > 135.0f &&  angle < 225.0f) {

            if (block->right != NULL) {

                continue;
            }

            collide->left = block;
            block->right = collide;
        }
        else if (angle > 225.0f &&  angle < 315.0f) {

            if (block->bottom != NULL) {

                continue;
            }

            collide->top = block;
            block->bottom = collide;
        }
        else {

            if (block->left != NULL) {

                continue;
            }

            collide->right = block;
            block->left = collide;
        }
    }

    // rebuild neighbors
    if (block->top != NULL) {

        rebuildRec(block->top);
    }
    if (block->bottom != NULL) {

        rebuildRec(block->bottom);
    }
    if (block->left != NULL) {

        rebuildRec(block->left);
    }
    if (block->right != NULL) {

        rebuildRec(block->right);
    }
}

void PlayerShip::processInput() {

    movement();
}

void PlayerShip::movement() {

    // calculate movement speed
    if (m_start) {

        float moveSpeed = MOVE_SPEED * omi::fpsManager.getTimeScale();
        if (omi::input::isKeyPressed(sf::Keyboard::Up)) {

            m_shipT->translation.y += moveSpeed;
        }
        if (omi::input::isKeyPressed(sf::Keyboard::Down)) {

            m_shipT->translation.y -= moveSpeed;
        }
        if (omi::input::isKeyPressed(sf::Keyboard::Left)) {

            m_shipT->translation.x -= moveSpeed;
        }
        if (omi::input::isKeyPressed(sf::Keyboard::Right)) {

            m_shipT->translation.x += moveSpeed;
        }
    }

    // stop the player going out of bounds
    if (m_shipT->translation.x >= 31.0f) {

        m_shipT->translation.x = 31.0f;
    }
    else if (m_shipT->translation.x <= -31.0f) {

        m_shipT->translation.x = -31.0f;
    }
    if (m_shipT->translation.y >= 17.0f) {

        m_shipT->translation.y = 17.0f;
    }
    else if (m_shipT->translation.y <= -17.0f) {

        m_shipT->translation.y = -17.0f;
    }

    // pass the position to the hub
    for(std::vector<Block*>::iterator it = m_blocks.begin();
        it != m_blocks.end(); ++it) {
        (*it)->traversed = false;
    }
    m_hub->setPosition(m_shipT->translation);
}

void PlayerShip::collisions() {

    for (std::vector<Block*>::iterator it = m_blocks.begin();
         it != m_blocks.end();) {

        // get collision data from each block
        for (std::vector<omi::CollisionData>::iterator data =
            (*it)->m_collisionDetect->getCollisionData().begin();
            data != (*it)->m_collisionDetect->getCollisionData().end();
            ++data) {

            if (!data->group.compare("enemy_bullet")) {

                // cast the entity to a bullet
                Bullet* bullet = static_cast<Bullet*>(data->entity);
                bullet->destroy();
                (*it)->m_health -= bullet->getDamage() * 1.0f;
            }
            if (!data->group.compare("enemy_block")) {

                (*it)->m_health = -1000.0f;
            }
        }

        // TODO: hub destruction
        // destroy blocks if we need to
        if ((*it)->m_health <= 0.0f && *it != m_hub) {

            (*it)->destroy();
            it = m_blocks.erase(it);
        }
        else {

            ++it;
        }
    }
}

void PlayerShip::initComponents() {

    //----------------------------------CAMERA----------------------------------
    m_camT = new omi::Transform("",
        util::vec::Vector3(0.0f, 0.0f, -1.0f),
        util::vec::Vector3(),
        util::vec::Vector3(0.055f, 0.055f, 0.055f)
    );
    m_components.add(m_camT);
    m_components.add(
        new omi::Camera("", omi::cam::ORTHOGRAPHIC, m_camT));
    //------------------------------SHIP POSITION-------------------------------
    m_shipT = new omi::Transform(
        "",
        util::vec::Vector3(0.0f, -10.0f, 0.0f),
        util::vec::Vector3(),
        util::vec::Vector3(1.0f, 1.0f, 1.0f)
    );
    m_components.add(m_shipT);
    //----------------------------------MUSIC-----------------------------------
    
    m_introMusic = new omi::Music(
        "", "res/sound/music/level/intro.ogg", 1.0f, true
    );
    m_components.add(m_introMusic);
    m_introMusic->play();

    m_music = new omi::Music(
        "", "res/sound/music/level/music.ogg", 1.0f, true
    );
    m_components.add(m_music);

    //-----------------------------------GUI------------------------------------
    m_guiT = new omi::Transform(
        "",
        util::vec::Vector3(),
        util::vec::Vector3(),
        util::vec::Vector3(1.0f, 1.0f, 1.0f)
    );
    m_components.add(m_guiT);
    m_guiSprite = omi::ResourceManager::getSprite(
        "title_screen", "", m_guiT);
    m_components.add(m_guiSprite);
    m_coinSprite = omi::ResourceManager::getSprite(
        "insert_coin", "", m_guiT);
    m_components.add(m_coinSprite);
}

void PlayerShip::buildShip() {

    // create the hub
    m_hub = new PlayerHub(util::vec::Vector3());
    m_hub->attach(true);
    m_blocks.push_back(m_hub);
    addEntity(m_hub);

    //------------------------------INITIAL BLOCKS------------------------------

    Block* block1 = new SteelBlock(
        util::vec::Vector3(-1.0f, 0.0f, 0.0f), block::PLAYER);
    m_hub->left = block1;
    block1->right = m_hub;
    block1->attach(true);
    m_blocks.push_back(block1);
    addEntity(block1);

    Block* block2 = new SteelBlock(
        util::vec::Vector3(1.0f, 0.0f, 0.0f), block::PLAYER);
    m_hub->right = block2;
    block2->left = m_hub;
    block2->attach(true);
    m_blocks.push_back(block2);
    addEntity(block2);

    Block* block3 = new SteelBlock(
        util::vec::Vector3(0.0f, 1.0f, 0.0f), block::PLAYER);
    m_hub->top = block3;
    block3->bottom = m_hub;
    block3->attach(true);
    m_blocks.push_back(block3);
    addEntity(block3);

    Block* block4 = new SteelBlock(
        util::vec::Vector3(-2.0f, 0.0f, 0.0f), block::PLAYER);
    block1->left = block4;
    block4->right = block1;
    block4->attach(true);
    m_blocks.push_back(block4);
    addEntity(block4);

    Block* block5 = new SteelBlock(
        util::vec::Vector3(2.0f, 0.0f, 0.0f), block::PLAYER);
    block2->right = block5;
    block5->left = block2;
    block5->attach(true);
    m_blocks.push_back(block5);
    addEntity(block5);

    Block* block6 = new SteelBlock(
        util::vec::Vector3(-1.0f, -1.0f, 0.0f), block::PLAYER);
    block1->bottom = block6;
    block6->top = block1;
    block6->attach(true);
    m_blocks.push_back(block6);
    addEntity(block6);

    Block* block7 = new SteelBlock(
        util::vec::Vector3(1.0f, -1.0f, 0.0f), block::PLAYER);
    block2->bottom = block7;
    block7->top = block2;
    block7->attach(true);
    m_blocks.push_back(block7);
    addEntity(block7);

    Block* block8 = new SteelBlock(
        util::vec::Vector3(0.0f, -1.0f, 0.0f), block::PLAYER);
    m_hub->bottom = block8;
    block8->top = m_hub;
    block8->attach(true);
    m_blocks.push_back(block8);
    addEntity(block8);

    Block* block9 = new SteelBlock(
        util::vec::Vector3(0.0f, -2.0f, 0.0f), block::PLAYER);
    block8->bottom = block9;
    block9->top = block8;
    block9->attach(true);
    m_blocks.push_back(block9);
    addEntity(block9);

    Block* block10 = new SteelBlock(
        util::vec::Vector3(-2.0f, 1.0f, 0.0f), block::PLAYER);
    block4->top = block10;
    block10->bottom = block4;
    block10->attach(true);
    m_blocks.push_back(block10);
    addEntity(block10);

    Block* block11 = new SteelBlock(
        util::vec::Vector3(2.0f, 1.0f, 0.0f), block::PLAYER);
    block5->top = block11;
    block11->bottom = block5;
    block11->attach(true);
    m_blocks.push_back(block11);
    addEntity(block11);
}