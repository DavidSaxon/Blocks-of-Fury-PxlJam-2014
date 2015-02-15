#ifndef OMICRON_TEST_PLAYER_H_
#    define OMICRON_TEST_PLAYER_H_

#include "lib/Utilitron/MathUtil.hpp"

#include "src/omicron/entity/Entity.hpp"
#include "src/omicron/input/Input.hpp"

class Player : public omi::Entity {
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    Player();

    //--------------------------------------------------------------------------
    //                                 DESTRUCTOR
    //--------------------------------------------------------------------------

    ~Player();

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

    // the transform of the camera
    omi::Transform* m_camT;

    // the collision detector
    omi::CollisionDetector* m_collisionDetect;

    // music
    omi::Music* m_musicStart;
    omi::Music* m_musicMain;

    // sounds
    unsigned m_sound_1;
    unsigned m_sound_2;

    // is true if the shoot button is down
    bool m_shootButton;
};

#endif
