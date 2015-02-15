#ifndef BOF_LEVEL_BLOCK_RUSTYBLOCK_H_
#    define BOF_LEVEL_BLOCK_RUSTYBLOCK_H_

#include "Block.hpp"

#include "src/entities/level/bullet/RustyBullet.hpp"

class RustyBlock : public Block {
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    RustyBlock(const util::vec::Vector3& pos, block::Owner owner);

    //--------------------------------------------------------------------------
    //                                 DESTRUCTOR
    //--------------------------------------------------------------------------

    ~RustyBlock();

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    void createBullet();
};

#endif
