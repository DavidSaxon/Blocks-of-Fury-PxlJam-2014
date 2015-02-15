#ifndef BOF_LEVEL_EXPLOSION_H_
#    define BOF_LEVEL_EXPLOSION_H_

#include "src/omicron/entity/Entity.hpp"

class Explosion : public omi::Entity {
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    Explosion(const util::vec::Vector3& pos, const std::string& name);

    //--------------------------------------------------------------------------
    //                                 DESTRUCTOR
    //--------------------------------------------------------------------------

    ~Explosion();

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** #Override */
    void init();

    /** #Override */
    void update();

private:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    omi::Transform* m_transform;
    omi::Sprite* m_sprite;

    float m_timer;
};

#endif
