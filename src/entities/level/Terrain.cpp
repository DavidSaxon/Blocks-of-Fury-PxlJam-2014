#include "Terrain.hpp"

//------------------------------------------------------------------------------
//                                   CONSTANTS
//------------------------------------------------------------------------------

namespace {

    static const unsigned PLANE_COUNT = 3;
    static const float    PLANE_SIZE = 65.0f;
    static const float    MOVE_SPEED = 0.1f;

}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void Terrain::init() {

    m_state = terrain::GRASS;

    // add the ground planes
    for (unsigned i = 0; i < PLANE_COUNT; ++i) {

        // transform
        omi::Transform* transform = new omi::Transform(
            "",
            util::vec::Vector3(0.0f, i * PLANE_SIZE, 0.0f),
            util::vec::Vector3(),
            util::vec::Vector3(1.0f, 1.0f, 1.0f)
        );
        m_transforms.push_back(transform);
        m_components.add(transform);

        // sprite
        omi::Sprite* sprite = omi::ResourceManager::getSprite(
            "terrain", "", transform);
        m_sprites.push_back(sprite);
        m_components.add(sprite);
    }

}

void Terrain::update() {



    // scroll the terrain down
    float moveSpeed = value::DOWN_SPEED * 2.0f * omi::fpsManager.getTimeScale();
    for (unsigned i = 0; i < m_transforms.size(); ++i) {

        m_transforms[i]->translation.y -= moveSpeed;
        // shift up if it has gone past the user's view
        if (m_transforms[i]->translation.y < -PLANE_SIZE) {

            m_transforms[i]->translation.y += PLANE_SIZE * PLANE_COUNT;

            if (rand() % 2) {

                if (m_state == terrain::GRASS) {

                    if (rand() % 2) {

                        m_state = terrain::DIRT;
                        m_sprites[i]->getMaterial().texture =
                            omi::ResourceManager::getTexture(
                                "terrain_grass_to_dirt");
                    }
                    else {

                        m_state = terrain::CAVE;
                        m_sprites[i]->getMaterial().texture =
                            omi::ResourceManager::getTexture(
                                "terrain_grass_to_cave");
                        addEntity(new Cave(false));
                    }
                }
                else if (m_state == terrain::DIRT) {

                    if (rand() % 2) {

                        m_state = terrain::GRASS;
                        m_sprites[i]->getMaterial().texture =
                            omi::ResourceManager::getTexture(
                                "terrain_dirt_to_grass");
                    }
                    else {

                        m_state = terrain::DESERT;
                        m_sprites[i]->getMaterial().texture =
                            omi::ResourceManager::getTexture(
                                "terrain_dirt_to_desert");
                    }
                }
                else if (m_state == terrain::DESERT) {

                    m_state = terrain::DIRT;
                    m_sprites[i]->getMaterial().texture =
                        omi::ResourceManager::getTexture(
                            "terrain_desert_to_dirt");
                }
                else if (m_state == terrain::CAVE) {

                    m_state = terrain::GRASS;
                    m_sprites[i]->getMaterial().texture =
                        omi::ResourceManager::getTexture(
                            "terrain_cave_to_grass");
                    addEntity(new Cave(true));
                }
            }
            else {

                if (m_state == terrain::GRASS) {

                    m_sprites[i]->getMaterial().texture =
                        omi::ResourceManager::getTexture(
                            "terrain_grass");
                }
                else if (m_state == terrain::DIRT) {

                    m_sprites[i]->getMaterial().texture =
                        omi::ResourceManager::getTexture(
                            "terrain_dirt");
                }
                else if (m_state == terrain::DESERT) {

                    m_sprites[i]->getMaterial().texture =
                        omi::ResourceManager::getTexture(
                            "terrain_desert");
                }
                else if (m_state == terrain::CAVE) {

                    m_sprites[i]->getMaterial().texture =
                        omi::ResourceManager::getTexture(
                            "terrain_cave");
                }
            }
        }
    }
}

