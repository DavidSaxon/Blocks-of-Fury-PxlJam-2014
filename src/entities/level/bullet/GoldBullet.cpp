#include "GoldBullet.hpp"

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

GoldBullet::GoldBullet(bullet::Owner owner, const util::vec::Vector3& pos,
    float dir) :
    Bullet(owner, "bullet_gold", pos),
    m_dir(dir) {
}

//------------------------------------------------------------------------------
//                                   DESTRUCTOR
//------------------------------------------------------------------------------

GoldBullet::~GoldBullet() {
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void GoldBullet::init() {

    Bullet::init();

    m_transform->rotation.z = -m_dir;
}

util::vec::Vector3 GoldBullet::computeBulletMove() {

    return util::vec::Vector3(
        sin(m_dir * util::math::DEGREES_TO_RADIANS) * 0.37f,
        cos(m_dir * util::math::DEGREES_TO_RADIANS) * 0.37f,
        0.0f);
}

void GoldBullet::addExplosion() {

    addEntity(new Explosion(
        m_transform->translation, "bullet_explosion_5"));
}

float GoldBullet::getDamage() const {

    return 0.7f;
}