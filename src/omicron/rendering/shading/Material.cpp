#include "Material.hpp"

namespace omi {

//------------------------------------------------------------------------------
//                                  CONSTRUCTORS
//------------------------------------------------------------------------------

Material::Material()
    :
    shader (),
    colour (1.0f, 1.0f, 1.0f, 1.0f),
    texture() {
}

Material::Material(const Shader&             a_shader,
                   const util::vec::Vector4& a_colour,
                         Texture*            a_texture)
    :
    shader (a_shader),
    colour (a_colour),
    texture(a_texture) {
}

Material::Material(const Material& other) :
    colour (other.colour),
    texture(other.texture),
    shader (other.shader) {
}

//------------------------------------------------------------------------------
//                                   DESTRUCTOR
//------------------------------------------------------------------------------

Material::~Material() {
}

//------------------------------------------------------------------------------
//                                   OPERATORS
//------------------------------------------------------------------------------

const Material& Material::operator=(const Material& other) {

    shader  = other.shader;
    colour  = other.colour;
    texture = other.texture;

    return *this;
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void Material::update() {

    // update the texture
    if (texture != NULL) {

        texture->update();
    }
}

bool Material::isVisible() const {

    if (texture != NULL) {

        return texture->isVisible();
    }

    return true;
}

} // namespace omi
