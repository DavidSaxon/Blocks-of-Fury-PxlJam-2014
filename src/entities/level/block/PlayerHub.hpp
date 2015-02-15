#ifndef BOF_LEVEL_BLOCK_PLAYERHUB_H_
#    define BOF_LEVEL_BLOCK_PLAYERHUB_H_

#include "Block.hpp"

#include "src/entities/level/bullet/SteelBullet.hpp"

class PlayerHub : public Block {
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    PlayerHub(const util::vec::Vector3& pos);

    //--------------------------------------------------------------------------
    //                                 DESTRUCTOR
    //--------------------------------------------------------------------------

    ~PlayerHub();

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    void createBullet();
};

#endif
