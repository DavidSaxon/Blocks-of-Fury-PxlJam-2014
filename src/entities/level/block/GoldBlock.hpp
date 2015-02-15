#ifndef BOF_LEVEL_BLOCK_GOLDBLOCK_H_
#    define BOF_LEVEL_BLOCK_GOLDBLOCK_H_

#include "Block.hpp"

#include "src/entities/level/bullet/GoldBullet.hpp"

class GoldBlock : public Block {
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    GoldBlock(const util::vec::Vector3& pos, block::Owner owner);

    //--------------------------------------------------------------------------
    //                                 DESTRUCTOR
    //--------------------------------------------------------------------------

    ~GoldBlock();

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    void createBullet();
};

#endif
