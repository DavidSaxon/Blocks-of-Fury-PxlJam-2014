#include "RustyBullet.hpp"

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

RustyBullet::RustyBullet(bullet::Owner owner, const util::vec::Vector3& pos) :
    Bullet(owner, "bullet_rusty", pos) {
}

//------------------------------------------------------------------------------
//                                   DESTRUCTOR
//------------------------------------------------------------------------------

RustyBullet::~RustyBullet() {
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

util::vec::Vector3 RustyBullet::computeBulletMove() {

    return util::vec::Vector3(0.0f, 0.2f, 0.0f);
}

void RustyBullet::addExplosion() {

    addEntity(new Explosion(
        m_transform->translation, "bullet_explosion_1"));
}

float RustyBullet::getDamage() const {

    return 0.25f;
}