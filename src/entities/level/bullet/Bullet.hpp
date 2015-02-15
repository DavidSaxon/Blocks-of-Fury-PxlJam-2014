#ifndef BOF_LEVEL_BULLET_BULLET_H_
#    define BOF_LEVEL_BULLET_BULLET_H_

#include "src/omicron/entity/Entity.hpp"

#include "src/entities/level/Explosion.hpp"

namespace bullet {

    enum Owner {
        PLAYER,
        ENEMY
    };

} // namespace bullet

class Bullet : public omi::Entity {
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    Bullet(bullet::Owner owner,
        const std::string& spriteName, const util::vec::Vector3& pos);

    //--------------------------------------------------------------------------
    //                                 DESTRUCTOR
    //--------------------------------------------------------------------------

    ~Bullet();

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** #Override */
    void init();

    /** #Override */
    void update();

    void destroy();

    virtual util::vec::Vector3 computeBulletMove() = 0;

    virtual void addExplosion() = 0;

    virtual float getDamage() const = 0;

protected:

    //--------------------------------------------------------------------------
    //                                 VARIABALES
    //--------------------------------------------------------------------------

    bullet::Owner m_owner;
    omi::Transform* m_transform;
    std::string m_spriteName;

    omi::CollisionDetector* m_collisionDetect;

    bool m_dead;
};

#endif
