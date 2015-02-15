#ifndef OMICRON_TEST_HUMAN_H_
#    define OMICRON_TEST_HUMAN_H_

#include "src/omicron/entity/Entity.hpp"

class Human : public omi::Entity {
public:

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** #Override */
    void init();

    /** #Override */
    void update();
};

#endif
