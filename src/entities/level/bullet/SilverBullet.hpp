#ifndef BOF_LEVEL_BULLET_SILVERBULLET_H_
#    define BOF_LEVEL_BULLET_SILVERBULLET_H_

#include "Bullet.hpp"

class SilverBullet : public Bullet {
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    SilverBullet(bullet::Owner owner, const util::vec::Vector3& pos);

    //--------------------------------------------------------------------------
    //                                 DESTRUCTOR
    //--------------------------------------------------------------------------

    ~SilverBullet();

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    util::vec::Vector3 computeBulletMove();

    void addExplosion();

    float getDamage() const;

private:

    float m_dir;
    bool m_left;
};

#endif
