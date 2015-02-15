#include "CopperBullet.hpp"

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

CopperBullet::CopperBullet(bullet::Owner owner, const util::vec::Vector3& pos,
    float dir) :
    Bullet(owner, "bullet_copper", pos),
    m_dir(dir) {
}

//------------------------------------------------------------------------------
//                                   DESTRUCTOR
//------------------------------------------------------------------------------

CopperBullet::~CopperBullet() {
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void CopperBullet::init() {

    Bullet::init();

    m_transform->rotation.z = -m_dir;
}

util::vec::Vector3 CopperBullet::computeBulletMove() {

    return util::vec::Vector3(
        sin(m_dir * util::math::DEGREES_TO_RADIANS) * 0.35f,
        cos(m_dir * util::math::DEGREES_TO_RADIANS) * 0.35f,
        0.0f);
}

void CopperBullet::addExplosion() {

    addEntity(new Explosion(
        m_transform->translation, "bullet_explosion_2"));
}

float CopperBullet::getDamage() const {

    return 0.4f;
}