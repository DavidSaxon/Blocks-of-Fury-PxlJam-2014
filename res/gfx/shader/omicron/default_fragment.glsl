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

//------------------------------------------------------------------------------
//                                 MAIN FUNCTION
//------------------------------------------------------------------------------

void main() {

    //---------------------------------MATERIAL---------------------------------

    // the colour of the material
    vec4 material = u_colour;

    //apply texturing
    vec4 textureColour = texture2D(u_texture, v_texCoord);
    if (u_hasTexture != 0) {

        material *= textureColour;
    }

    //---------------------------------LIGHTING---------------------------------

    // apply ambient light
    vec3 light = u_ambientLight;

    // // apply point lights
    // // TODO: vec3(0.0) = light pos
    // vec3 L = normalize(vec3(0.0, -1.0, 0.0) - v_vertex);
    // vec3 E = normalize(-v_vertex);
    // vec3 R = normalize(-reflect(L, v_normal));

    // // TODO: vec3(1.0) = diffuse
    // vec3 diffuse = vec3(1.5) * max(dot(v_normal, L), 0.0);

    // // TODO:
    // light += diffuse;

    //----------------------------------OUTPUT----------------------------------

    gl_FragColor = material * vec4(light, 1.0);
}
