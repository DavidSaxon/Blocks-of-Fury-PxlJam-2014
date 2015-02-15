#ifndef BOF_LEVEL_BULLET_STEELBULLET_H_
#    define BOF_LEVEL_BULLET_STEELBULLET_H_

#include "Bullet.hpp"

class SteelBullet : public Bullet {
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    SteelBullet(bullet::Owner owner, const util::vec::Vector3& pos);

    //--------------------------------------------------------------------------
    //                                 DESTRUCTOR
    //--------------------------------------------------------------------------

    ~SteelBullet();

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    util::vec::Vector3 computeBulletMove();

    void addExplosion();

    float getDamage() const;
};

#endif
