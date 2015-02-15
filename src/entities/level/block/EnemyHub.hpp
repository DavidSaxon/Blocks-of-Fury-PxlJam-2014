#ifndef BOF_LEVEL_BLOCK_ENEMYHUB_H_
#    define BOF_LEVEL_BLOCK_ENEMYHUB_H_

#include "Block.hpp"

#include "src/entities/level/bullet/SteelBullet.hpp"

class EnemyHub : public Block {
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    EnemyHub(const util::vec::Vector3& pos);

    //--------------------------------------------------------------------------
    //                                 DESTRUCTOR
    //--------------------------------------------------------------------------

    ~EnemyHub();

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    void createBullet();
};

#endif
