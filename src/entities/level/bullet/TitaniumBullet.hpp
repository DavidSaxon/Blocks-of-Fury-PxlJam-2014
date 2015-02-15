#ifndef BOF_LEVEL_BULLET_TITANIUMBULLET_H_
#    define BOF_LEVEL_BULLET_TITANIUMBULLET_H_

#include "Bullet.hpp"

class TitaniumBullet : public Bullet {
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    TitaniumBullet(bullet::Owner owner, const util::vec::Vector3& pos);

    //--------------------------------------------------------------------------
    //                                 DESTRUCTOR
    //--------------------------------------------------------------------------

    ~TitaniumBullet();

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    util::vec::Vector3 computeBulletMove();

    void addExplosion();

    float getDamage() const;
};

#endif
