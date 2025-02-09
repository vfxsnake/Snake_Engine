#version 460

// declaring variables
// layout (qualifier)  is a set of location, it can be several each one it's own integer id
// the out qualifier   sets the varialb outColor as an output of the shader
layout (location = 0) out vec4 outColor;

void main()
{
    outColor = vec4(1.0, 0.0, 0.0, 1.0);  // RGBAs values for the fragments.
}