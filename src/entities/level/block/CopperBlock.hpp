#ifndef BOF_LEVEL_BLOCK_COPPERBLOCK_H_
#    define BOF_LEVEL_BLOCK_COPPERBLOCK_H_

#include "Block.hpp"

#include "src/entities/level/bullet/CopperBullet.hpp"

class CopperBlock : public Block {
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    CopperBlock(const util::vec::Vector3& pos, block::Owner owner);

    //--------------------------------------------------------------------------
    //                                 DESTRUCTOR
    //--------------------------------------------------------------------------

    ~CopperBlock();

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    void createBullet();
};

#endif
