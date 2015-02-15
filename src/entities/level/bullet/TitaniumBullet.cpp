#include "TitaniumBullet.hpp"

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

TitaniumBullet::TitaniumBullet(bullet::Owner owner, const util::vec::Vector3& pos) :
    Bullet(owner, "bullet_titanium", pos) {
}

//------------------------------------------------------------------------------
//                                   DESTRUCTOR
//------------------------------------------------------------------------------

TitaniumBullet::~TitaniumBullet() {
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

util::vec::Vector3 TitaniumBullet::computeBulletMove() {

    return util::vec::Vector3(0.0f, 0.2f, 0.0f);
}

void TitaniumBullet::addExplosion() {

    addEntity(new Explosion(
        m_transform->translation, "bullet_explosion_3"));
}

float TitaniumBullet::getDamage() const {

    return 1.5f;
}

