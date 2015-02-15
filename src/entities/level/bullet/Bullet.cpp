#include "Bullet.hpp"

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

Bullet::Bullet(bullet::Owner owner,
        const std::string& spriteName, const util::vec::Vector3& pos) :
    m_owner(owner),
    m_spriteName(spriteName),
    m_dead(false) {

    if (m_owner == bullet::PLAYER) {
        m_transform = new omi::Transform(
            "", pos,
            util::vec::Vector3(),
            util::vec::Vector3(1.0f, 1.0f, 1.0f)
        );
    }
    else {

        m_transform = new omi::Transform(
            "", pos,
            util::vec::Vector3(0.0f, 0.0f, 180.0f),
            util::vec::Vector3(1.0f, 1.0f, 1.0f)
        );
    }
}

//------------------------------------------------------------------------------
//                                   DESTRUCTOR
//------------------------------------------------------------------------------

Bullet::~Bullet() {
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void Bullet::init() {

    m_components.add(m_transform);
    m_components.add(omi::ResourceManager::getSprite(
        m_spriteName, "", m_transform));

    std::string group = "enemy_bullet";
    if (m_owner == bullet::PLAYER) {

        group = "player_bullet";
    }

    m_collisionDetect =
        new omi::CollisionDetector("", group, this);
    m_collisionDetect->addBounding(
        new omi::BoundingCircle(0.125f, m_transform));
    m_components.add(m_collisionDetect);
}

void Bullet::update() {

    if (m_owner == bullet::PLAYER) {

        m_transform->translation += computeBulletMove();
    }
    else {

        m_transform->translation -= computeBulletMove();
    }

    // blow up the bullet
    if (m_dead) {

        addExplosion();
        remove();
    }

    //check if the bullet has gone out of bounds
    if (m_transform->translation.x >= 62.0f) {

        remove();
    }
    else if (m_transform->translation.x <= -62.0f) {

        remove();
    }
    if (m_transform->translation.y >= 40.0f) {

        remove();
    }
    else if (m_transform->translation.y <= -40.0f) {

        remove();
    }
}

void Bullet::destroy() {

    m_dead = true;
}