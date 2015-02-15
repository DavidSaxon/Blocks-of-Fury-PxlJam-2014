#ifndef BOF_LEVEL_BULLET_GOLDBULLET_H_
#    define BOF_LEVEL_BULLET_GOLDBULLET_H_

#include "Bullet.hpp"

class GoldBullet : public Bullet {
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    GoldBullet(bullet::Owner owner, const util::vec::Vector3& pos, float dir);

    //--------------------------------------------------------------------------
    //                                 DESTRUCTOR
    //--------------------------------------------------------------------------

    ~GoldBullet();

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
