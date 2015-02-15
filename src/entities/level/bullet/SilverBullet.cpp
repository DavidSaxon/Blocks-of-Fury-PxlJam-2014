#include "SilverBullet.hpp"

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

SilverBullet::SilverBullet(bullet::Owner owner, const util::vec::Vector3& pos) :
    Bullet(owner, "bullet_silver", pos) {

    m_dir = 45.0f;
    m_left = true;
    if (rand() % 2) {

        m_dir = -45.0f;
        m_left = false;
    }
}

//------------------------------------------------------------------------------
//                                   DESTRUCTOR
//------------------------------------------------------------------------------

SilverBullet::~SilverBullet() {
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

util::vec::Vector3 SilverBullet::computeBulletMove() {

    // update angel
    if (m_left) {

        m_dir -= 3.0f * omi::fpsManager.getTimeScale();
        if (m_dir <= -45.0f) {

            m_dir = -45.0f;
            m_left = false;
        }
    }
    else {

        m_dir += 3.0f * omi::fpsManager.getTimeScale();
        if (m_dir >= 45.0f) {

            m_dir = 45.0f;
            m_left = true;
        }
    }

    m_transform->rotation.z = -m_dir;

    return util::vec::Vector3(
        sin(m_dir * util::math::DEGREES_TO_RADIANS) * 0.35f,
        cos(m_dir * util::math::DEGREES_TO_RADIANS) * 0.35f, 0.0f);
}

void SilverBullet::addExplosion() {

    addEntity(new Explosion(
        m_transform->translation, "bullet_explosion_4"));
}

float SilverBullet::getDamage() const {

    return 0.5f;
}

