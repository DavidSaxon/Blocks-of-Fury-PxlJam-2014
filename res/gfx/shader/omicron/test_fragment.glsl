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

//the vertex coords
varying vec3 v_vertex;
//the texture coords
varying vec2 v_texCoord;
//the normals
varying vec3 v_normal;

//------------------------------------------------------------------------------
//                                 MAIN FUNCTION
//------------------------------------------------------------------------------

void main() {

    // the final colour
    vec4 finalColour = u_colour;
    vec4 textureColour = texture2D(u_texture, v_texCoord);

    if (u_hasTexture > 0) {

        finalColour *= textureColour;
    }

    gl_FragColor = finalColour;
}
