#version 460

void main()
{
    vec2 positions[3] = vec2[](
        vec2(0.0, -0.5),
        vec2(0.5, 0.5),
        vec2(-0.5, 0.5)
    );

    gl_Position = vec4(
        positions[gl_VertexIndex], // gl_VertexIndex is a built-in variable when computing each point
        0.0, // z_depth value from 0.0 to 1.0
        1.0 // 4th component for homogenous coordinate sys.
    );
}