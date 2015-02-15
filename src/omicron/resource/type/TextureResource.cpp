#include "TextureResource.hpp"

namespace omi {

//------------------------------------------------------------------------------
//                                  CONSTRUCTORS
//------------------------------------------------------------------------------

TextureResource::TextureResource(
              resource_group::ResourceGroup resourceGroup,
        const std::string&                  filePath)
    :
    Resource  (resourceGroup),
    m_type    (tex::TEXTURE),
    m_filePath(filePath)       {        
}

TextureResource::TextureResource(
              resource_group::ResourceGroup resourceGroup,
        const std::string&                  filePath,
              unsigned                      frameRate,
              bool                          repeat,
              unsigned                      begin,
              unsigned                      end)
    :
    Resource   (resourceGroup),
    m_type     (tex::ANIMATION),
    m_filePath (filePath),
    m_frameRate(frameRate),
    m_repeat   (repeat),
    m_begin    (begin),
    m_end      (end) {
}

//------------------------------------------------------------------------------
//                                   DESTRUCTOR
//------------------------------------------------------------------------------

TextureResource::~TextureResource() {
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void TextureResource::load() {

    if (!m_loaded) {

        switch (m_type) {

            case tex::TEXTURE: {

                m_texture = std::unique_ptr<Texture>(
                    loader::textureFromImage(m_filePath));
                break;
            }
            case tex::ANIMATION: {

                m_texture = std::unique_ptr<Texture>(loader::animationFromImage(
                    m_filePath, m_frameRate, m_repeat, m_begin, m_end));
                break;
            }
        }
        m_loaded = true;
    }
}

void TextureResource::release() {

    if (m_loaded) {

        GLuint id = m_texture->getId();
        glDeleteTextures(1, &id);
        m_texture = std::unique_ptr<Texture>();
        m_loaded = false;
    }
}

Texture* TextureResource::get() const {

    if (!m_loaded) {

        std::cout << "attempted to get unloaded texture" << std::endl;

        //TODO: throw an exception
    }

    //copy the texture based on type
    Texture* tex;
    if (m_texture->getType() == tex::ANIMATION) {

        tex = new Animation(*dynamic_cast<Animation*>(m_texture.get()));
    }
    else {

        tex = new Texture(*m_texture.get());
    }

    return tex;
}

} // namespace omi