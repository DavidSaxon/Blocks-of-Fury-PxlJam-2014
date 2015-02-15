#ifndef BOF_LEVEL_ENEMYSHIP_H_
#    define BOF_LEVEL_ENEMYSHIP_H_

#include "src/omicron/entity/Entity.hpp"

#include "src/entities/level/block/EnemyHub.hpp"
#include "src/entities/level/block/SteelBlock.hpp"
#include "src/entities/level/block/RustyBlock.hpp"
#include "src/entities/level/block/CopperBlock.hpp"
#include "src/entities/level/block/TitaniumBlock.hpp"
#include "src/entities/level/block/SilverBlock.hpp"
#include "src/entities/level/block/GoldBlock.hpp"

class EnemyShip : public omi::Entity {
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    EnemyShip(const util::vec::Vector3 pos, float diff);

    //--------------------------------------------------------------------------
    //                                 DESTRUCTOR
    //--------------------------------------------------------------------------

    ~EnemyShip();

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** #Override */
    void init();

    /** #Override */
    void update();

private:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    // the transform of the ship
    omi::Transform* m_shipT;

    // the hub of the ship
    EnemyHub* m_hub;
    // the list of all blocks in the ship
    std::vector<Block*> m_blocks;

    float m_health;

    bool m_right;
    float m_sideSpeed;

    float m_diff;

    //--------------------------------------------------------------------------
    //                          PRIVATE MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    void movement();

    void collisions();

    void destroy();

    void buildShip();

    Block* getBlock(const util::vec::Vector3& pos);

    void buildShip1();

    void buildShip2();

    void buildShip3();

    void buildShip4();

    void buildShip5();
};

#endif
