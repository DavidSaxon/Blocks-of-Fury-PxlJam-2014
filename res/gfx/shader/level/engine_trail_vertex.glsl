#version 120

//------------------------------------------------------------------------------
//                                   VARIABLES
//------------------------------------------------------------------------------

// the position of the engine trails
uniform vec3 u_trailPositions[9];
uniform float u_trailFade;
uniform int u_enemy;

// the vertex coords 
varying vec3 v_vertex;
// the texture coords
varying vec2 v_texCoord;
// the normals
varying vec3 v_normal;

varying float v_colourAdd;
// the alpha level
varying float v_alpha;

//------------------------------------------------------------------------------
//                                 MAIN FUNCTION
//------------------------------------------------------------------------------

void main() {
    
    v_colourAdd = clamp(1.0 - abs(gl_Vertex.x * 6.0), 0.0, 1.0);
    v_alpha = ((gl_Vertex.y + 7.5) / 8.0) * clamp(v_colourAdd + 0.9, 0.0, 1.0) *
        u_trailFade;

    int trailIndex = 8 - int(gl_Vertex.y + 7.7);
    vec4 trailPos = gl_Vertex;
    trailPos.x += u_trailPositions[trailIndex].x;
    if (u_enemy != 0) {

        trailPos.y = -trailPos.y + 2.0;
    }
    trailPos.y += u_trailPositions[trailIndex].y;

    //set the vertex coord
    v_vertex = vec3(gl_ModelViewMatrix * trailPos);
    //set the normal
    v_normal = normalize(gl_NormalMatrix * gl_Normal);
    //set the texture coords
    v_texCoord = vec2(gl_MultiTexCoord0);

    //set the position
    gl_Position = gl_ModelViewProjectionMatrix * trailPos;
}
