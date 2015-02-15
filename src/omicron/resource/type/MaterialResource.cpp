#include "MaterialResource.hpp"

namespace omi {

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

MaterialResource::MaterialResource(
               resource_group::ResourceGroup resourceGroup,
         const std::string&                  shader,
         const util::vec::Vector4&           colour,
         const std::string&                  texture)
    :
    Resource (resourceGroup),
    m_shader (shader),
    m_colour (colour),
    m_texture(texture) {
}

//------------------------------------------------------------------------------
//                                   DESTRUCTOR
//------------------------------------------------------------------------------

MaterialResource::~MaterialResource() {
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void MaterialResource::load() {

    if (!m_loaded) {

        //check if we are using a texture or not
        // if (m_texture.compare("")) {

        //     // create material with texture
        //     m_material = Material(
        //         ResourceManager::getShader(m_shader),
        //         m_colour,
        //         ResourceManager::getTexture(m_texture)
        //     );
        // }
        // else {

        //     // create material without texture
        //     m_material = Material(
        //         ResourceManager::getShader(m_shader),
        //         m_colour,
        //         NULL
        //     );
        // }
        m_loaded = true;
    }
}

void MaterialResource::release() {

    if (m_loaded) {

        m_material = Material();
        m_loaded = false;
    }
}

Material MaterialResource::get() {

    if (!m_loaded) {

        std::cout << "attempted to get unloaded material" << std::endl;

        //TODO: throw an exception
    }

    if (m_texture.compare("")) {

        // create material with texture
        m_material = Material(
            ResourceManager::getShader(m_shader),
            m_colour,
            ResourceManager::getTexture(m_texture)
        );
    }
    else {

        // create material without texture
        m_material = Material(
            ResourceManager::getShader(m_shader),
            m_colour,
            NULL
        );
    }

    return m_material;
}

} // namespace omi
