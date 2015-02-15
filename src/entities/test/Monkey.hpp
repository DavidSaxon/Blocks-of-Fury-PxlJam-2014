#ifndef OMICRON_TEST_MONKEY_H_
#    define OMICRON_TEST_MONKEY_H_

#include "src/omicron/entity/Entity.hpp"

class Monkey : public omi::Entity {
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
