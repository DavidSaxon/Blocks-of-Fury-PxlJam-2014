#ifndef OMICRON_ENTITIES_TEST_SKYBOX_H_
#   define OMICRON_ENTITIES_TEST_SKYBOX_H_

#include "src/omicron/entity/Entity.hpp"

class Skybox : public omi::Entity {
public:

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** #Override */
    void init();

    /** Override */
    void update();
};

#endif