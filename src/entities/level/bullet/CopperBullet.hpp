#ifndef BOF_LEVEL_BULLET_COPPERBULLET_H_
#    define BOF_LEVEL_BULLET_COPPERBULLET_H_

#include "Bullet.hpp"

class CopperBullet : public Bullet {
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    CopperBullet(bullet::Owner owner, const util::vec::Vector3& pos, float dir);

    //--------------------------------------------------------------------------
    //                                 DESTRUCTOR
    //--------------------------------------------------------------------------

    ~CopperBullet();

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    void init();

    util::vec::Vector3 computeBulletMove();

    void addExplosion();

    float getDamage() const;

private:

    float m_dir;
};

#endif
