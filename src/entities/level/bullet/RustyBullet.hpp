#ifndef BOF_LEVEL_BULLET_RUSTYBULLET_H_
#    define BOF_LEVEL_BULLET_RUSTYBULLET_H_

#include "Bullet.hpp"

class RustyBullet : public Bullet {
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    RustyBullet(bullet::Owner owner, const util::vec::Vector3& pos);

    //--------------------------------------------------------------------------
    //                                 DESTRUCTOR
    //--------------------------------------------------------------------------

    ~RustyBullet();

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    
    util::vec::Vector3 computeBulletMove();

    void addExplosion();

    float getDamage() const;
};

#endif
