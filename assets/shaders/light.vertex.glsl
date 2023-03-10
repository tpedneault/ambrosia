#version 410 core

layout (location = 0) in vec4 vPosition;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main() {
    gl_Position = projection * view * model * vec4(vPosition.x, vPosition.y, vPosition.z, 1.0f);
}