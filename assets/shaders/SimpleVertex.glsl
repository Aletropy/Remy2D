#version 460 core

layout(location = 0) in vec4 aVertexPosition;
layout(location = 1) in vec4 aVertexColor;

out vec4 vVertexColor;

uniform mat4 uViewProjMatrix;

void main()
{
    vVertexColor = aVertexColor;
    gl_Position = uViewProjMatrix * aVertexPosition;
}