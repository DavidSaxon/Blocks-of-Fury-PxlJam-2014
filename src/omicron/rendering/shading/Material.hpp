#ifndef OMICRON_RENDERING_SHADING_MATERIAL_H_
#   define OMICRON_RENDERING_SHADING_MATERIAL_H_

#include "lib/Utilitron/Vector.hpp"

#include "src/omicron/rendering/shading/Shader.hpp"
#include "src/omicron/rendering/shading/Texture.hpp"

namespace omi {

/*********************************************************\
| A material contains all the shading data for an object. |
\*********************************************************/
class Material {
public:

    //--------------------------------------------------------------------------
    //                                 VARIABLES
    //--------------------------------------------------------------------------

    //! the shader used for the material
    Shader shader;
    //! the colour of the material
    util::vec::Vector4 colour;
    //! a pointer to the texture of the material
    Texture* texture;

    //--------------------------------------------------------------------------
    //                                CONSTRUCTORS
    //--------------------------------------------------------------------------

    /** Creates a material with the default set up */
    Material();

    // TODO:
    /** Creates a material using the given values
    @param a_shader the shader of the material
    @param a_colour the colour of the material
    @param a_texture the texture of the material */
    Material(const Shader&             a_shader,
             const util::vec::Vector4& a_colour,
                   Texture*            a_texture);

    /** Creates a copy of the given material
    @param other the material to copy from */
    Material(const Material& other);

    //--------------------------------------------------------------------------
    //                                 DESTUCTOR
    //--------------------------------------------------------------------------

    ~Material();

    //--------------------------------------------------------------------------
    //                                 OPERATORS
    //--------------------------------------------------------------------------

    /** Copies the values of the given material to this material
    @param other the material to copy from */
    const Material& operator=(const Material& other);

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /** Updates the material */
    void update();

    /** @return if the material is visible */
    bool isVisible() const;
};

} // namespace omi

#endif 