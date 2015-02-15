#ifndef BOF_SCENES_LEVELSCENE_H_
#   define BOF_SCENES_LEVELSCENE_H_

#include "src/omicron/input/Input.hpp"
#include "src/omicron/physics/collision_detect/CollisionDetect.hpp"
#include "src/omicron/scene/Scene.hpp"

#include "src/override/Values.hpp"

#include "src/entities/level/EnemyShip.hpp"
#include "src/entities/level/PlayerShip.hpp"
#include "src/entities/level/Terrain.hpp"

class LevelScene: public omi::Scene {
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    LevelScene();

    //--------------------------------------------------------------------------
    //                                 DESTRUCTOR
    //--------------------------------------------------------------------------

    ~LevelScene();

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** #Override */
    virtual void init();

    /** #Override */
    virtual bool update();

    /** #Override */
    virtual omi::Scene* nextScene() const;

private:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    float m_enemyTimer;

    float m_diff;

    bool m_start;
};

#endif