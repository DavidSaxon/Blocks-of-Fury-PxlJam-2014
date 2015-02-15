#ifndef BOF_LEVEL_BLOCK_TITANIUMBLOCK_H_
#    define BOF_LEVEL_BLOCK_TITANIUMBLOCK_H_

#include "Block.hpp"

#include "src/entities/level/bullet/TitaniumBullet.hpp"

class TitaniumBlock : public Block {
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    TitaniumBlock(const util::vec::Vector3& pos, block::Owner owner);

    //--------------------------------------------------------------------------
    //                                 DESTRUCTOR
    //--------------------------------------------------------------------------

    ~TitaniumBlock();

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    void createBullet();
};

#endif
