#version 330 core

//in vec3 color;
uniform vec4 uColor;

out vec4 FragColor;

void main() {
    FragColor = uColor;  // колір отриманий з юніформи
}