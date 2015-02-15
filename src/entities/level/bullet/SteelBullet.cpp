#include "SteelBullet.hpp"

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

SteelBullet::SteelBullet(bullet::Owner owner, const util::vec::Vector3& pos) :
    Bullet(owner, "bullet_steel", pos) {
}

//------------------------------------------------------------------------------
//                                   DESTRUCTOR
//------------------------------------------------------------------------------

SteelBullet::~SteelBullet() {
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

util::vec::Vector3 SteelBullet::computeBulletMove() {

    return util::vec::Vector3(0.0f, 0.3f, 0.0f);
}

void SteelBullet::addExplosion() {

    addEntity(new Explosion(
        m_transform->translation, "bullet_explosion_1"));
}

float SteelBullet::getDamage() const {

    return 0.5f;
}