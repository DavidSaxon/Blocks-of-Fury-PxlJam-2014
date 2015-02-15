#ifndef OMICRON_SCENES_TESTSCENE_H_
#   define OMICRON_SCENES_TESTSCENE_H_

#include <memory>

#include "src/omicron/scene/Scene.hpp"

#include "src/entities/test/Human.hpp"
#include "src/entities/test/Player.hpp"
#include "src/entities/test/Skybox.hpp"

/**************************************\
| Testing scene for the Omicron engine |
\**************************************/
class TestScene : public omi::Scene {
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    /** Creates a new test scene */
    TestScene();

    //--------------------------------------------------------------------------
    //                                 DESTRUCTOR
    //--------------------------------------------------------------------------

    virtual ~TestScene();

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** #Override */
    virtual void init();

    /** #Override */
    virtual bool update();

    /** #Override */
    virtual omi::Scene* nextScene() const;
};

#endif
