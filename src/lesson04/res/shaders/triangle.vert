#version 330 core

in vec4 aPos;
in vec3 aColor;

out vec3 color;  // вихідний параметр, який передаємо на фрагментний шейдер

void main() {
    gl_Position = aPos;
    color = aColor;
}