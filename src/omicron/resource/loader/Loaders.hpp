#ifndef OMICRON_RESOURCE_LOADER_LOADERS_H_
#   define OMICRON_RESOURCE_LOADER_LOADERS_H_

#include <fstream>
#include <GL/glew.h>
#include <iostream>
#include <IL/il.h>
#include <SFML/OpenGL.hpp>
#include <sstream>

#include "lib/Utilitron/FileUtil.hpp"
#include "lib/Utilitron/StringUtil.hpp"
#include "lib/Utilitron/Vector.hpp"

#include "src/omicron/rendering/object_data/Geometry.hpp"
#include "src/omicron/rendering/shading/Animation.hpp"
#include "src/omicron/rendering/shading/Material.hpp"
#include "src/omicron/rendering/shading/Shader.hpp"
#include "src/omicron/rendering/shading/Texture.hpp"

namespace omi {

/***********************************************\
| Functions used for loading data into Omicron. |
\***********************************************/
namespace loader {

//------------------------------------------------------------------------------
//                                   FUNCTIONS
//------------------------------------------------------------------------------

//--------------------------------SHADER LOADERS--------------------------------

/** Loads a shader from seperate file paths for each shader
@param vertexPath the path to the vertex shader
@param fragmentPath the path to the fragment shader */
Shader loadShaderFromFiles(
        const std::string& vertexPath,
        const std::string& fragmentPath);

//-------------------------------TEXTURE LOADERS--------------------------------

/** Loads a texture from an image file
@param filePath the path to the image
@return the loaded texture */
Texture* textureFromImage(const std::string& filePath);

/** Loads an animation from an image sequence
@param filePath the path of the sequence (omitting the frame number)
@param frameRate the playback speed of the animation
@param repeat if the animation should repeat 
@param begin the beginning frame of the animation
@param end the ending frame of the animation */
Texture* animationFromImage(
    const std::string& filePath, unsigned frameRate,
    bool repeat, unsigned begin, unsigned end);

//-------------------------------MATERIAL LOADER--------------------------------

/** Loads a material using the given values
@param colour the colour of the material
@param texture the texture of the material
@param shader the shader of the material
@return the loaded material */
Material materialFromValues(
        const util::vec::Vector4& colour,
              Texture             texture,
              Shader              shader);

//-------------------------------GEOMETRY LOADERS-------------------------------

/** Loads geometry data from a wavefront file
@param filePath the path to the file to load the data from
@return the loaded geometry data */
Geometry* geoFromWavefront(const std::string& filePath);

} // namespace loader

} // namespace omi

#endif
