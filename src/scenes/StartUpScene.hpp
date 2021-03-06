#ifndef OMICRON_SCENES_STARTUPSCENE_H_
#   define OMICRON_SCENES_STARTUPSCENE_H_

#include "src/omicron/scene/Scene.hpp"

#include "src/scenes/LevelScene.hpp"

#include "src/entities/start_up/OmicronLogo.hpp"

/*************************************************************\
| Loads the initial resources and displays start up graphics. |
\*************************************************************/
class StartUpScene : public omi::Scene {
public:

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

    // the omicron cinematic
    OmicronLogo* m_omicronLogo;
};

#endif
