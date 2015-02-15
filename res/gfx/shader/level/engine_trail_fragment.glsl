#version 120

//------------------------------------------------------------------------------
//                                   VARIABLES
//------------------------------------------------------------------------------

// the colour
uniform vec4 u_colour;
// if the material has a texture
uniform int u_hasTexture;
// the texture
uniform sampler2D u_texture;

//the ambient light
uniform vec3 u_ambientLight;

//the vertex coords
varying vec3 v_vertex;
//the texture coords
varying vec2 v_texCoord;
//the normals
varying vec3 v_normal;

varying float v_colourAdd;
// the alpha level
varying float v_alpha;

//------------------------------------------------------------------------------
//                                 MAIN FUNCTION
//------------------------------------------------------------------------------

void main() {

    //---------------------------------MATERIAL---------------------------------

    // the colour of the material
    vec4 material = u_colour;
    material.r += v_colourAdd;
    material.g += v_colourAdd;
    material.b += v_colourAdd;
    material.a = v_alpha;

    gl_FragColor = material;
}
