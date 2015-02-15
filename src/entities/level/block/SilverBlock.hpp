#ifndef BOF_LEVEL_BLOCK_SILVERBLOCK_H_
#    define BOF_LEVEL_BLOCK_SILVERBLOCK_H_

#include "Block.hpp"

#include "src/entities/level/bullet/SilverBullet.hpp"

class SilverBlock : public Block {
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    SilverBlock(const util::vec::Vector3& pos, block::Owner owner);

    //--------------------------------------------------------------------------
    //                                 DESTRUCTOR
    //--------------------------------------------------------------------------

    ~SilverBlock();

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    void createBullet();
};

#endif
