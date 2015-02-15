#ifndef BOF_LEVEL_BLOCK_STEELBLOCK_H_
#    define BOF_LEVEL_BLOCK_STEELBLOCK_H_

#include "Block.hpp"

#include "src/entities/level/bullet/SteelBullet.hpp"

class SteelBlock : public Block {
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    SteelBlock(const util::vec::Vector3& pos, block::Owner owner);

    //--------------------------------------------------------------------------
    //                                 DESTRUCTOR
    //--------------------------------------------------------------------------

    ~SteelBlock();

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    void createBullet();
};

#endif
