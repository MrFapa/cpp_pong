#version 430 core
layout(location = 0) in vec4 position;

out vec4 vertexColor; // specify a color output to the fragment shader

uniform mat4 u_MVP;
void main()
{
    gl_Position = u_MVP * position;
}