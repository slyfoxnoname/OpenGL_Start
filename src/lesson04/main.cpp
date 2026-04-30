#include <fstream>
#include <iostream>
#include <sstream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "shader_utils.h"


int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }


    glClearColor(1.0, 1.0, 1.0, 1.0);

    std::string vertexShaderName = "res/shaders/triangle.vert";
    std::string fragmentShaderName = "res/shaders/triangle.frag";
    GLuint shaderProgram = createProgram(
        vertexShaderName,
        fragmentShaderName);

    // float vertices[] = {  // float* vertices
    //    /* position */ -0.5f, -0.5f, /*color: */ 1.0f, 0.0f, 0.0f, // червоний колір для першої вершини
    //    /* position */  0.5f, -0.5f, /*color: */ 0.0f, 1.0f, 0.0f, // зелений колір для другої вершини
    //    /* position */   0.f,  0.5f, /*color: */ 0.0f, 0.0f, 1.0f, // синій колір для третьої вершини
    // };

    float vertices[] = {
        -0.5f, -0.5f, /*color: */ 1.0f, 0.0f, 0.0f, // червоний колір для першої вершини    //  0
         0.5f, -0.5f,  /*color: */ 0.0f, 1.0f, 0.0f, // зелений колір для другої вершини     // 1
         0.5f, 0.5f,   /*color: */ 0.0f, 0.0f, 1.0f, // синій колір для третьої вершини      // 2
        -0.5f, 0.5f,  /*color: */ 0.0f, 1.0f, 0.0f, // зелений колір для другої вершини   // 3
    };

    unsigned int indices[] = {
        0, 1, 2, // перший трикутник
        0, 2, 3, // другий трикутник
    };


    GLuint VBO, indexBuffer; // data - ідентифікатор для даних - місток CPU та GPU
    GLuint VAO; // vertex array object


    glGenBuffers(1, &VBO);
    glGenBuffers(1, &indexBuffer);
    glGenVertexArrays(1, &VAO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, VBO); // bind = activate
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    GLuint posAttribLocation = glGetAttribLocation(shaderProgram, "aPos");
    glVertexAttribPointer(
        posAttribLocation,                  // знайдена командою glGetAttribLocation позиція атрибуту у шейдері
        2,                  // 2 компоненти: x, y
        GL_FLOAT,           // тип даних
        GL_FALSE,           // не нормалізувати
        5 * sizeof(float),  // stride: 5 float-а на вершину
        (void*)0            // offset: починаємо з 0
    );
    glEnableVertexAttribArray(posAttribLocation);

    GLuint colorAttribLocation = glGetAttribLocation(shaderProgram, "aColor");
    glVertexAttribPointer(
        colorAttribLocation,                  // знайдена командою glGetAttribLocation позиція атрибуту у шейдері
        3,                  // 3 компоненти: r, g, b
        GL_FLOAT,           // тип даних
        GL_FALSE,           // не нормалізувати
        5 * sizeof(float),  // stride: 5 float-а на вершину
        (void*)(2 * sizeof(float))        // offset: починаємо з 2
    );
    glEnableVertexAttribArray(colorAttribLocation);
    glBindVertexArray(0); // деактивувати VAO


    /* Loop until the user closes the window */
    do
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shaderProgram);
        glBindVertexArray(VAO);
        // glDrawArrays(GL_TRIANGLES, 0, 3);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    } while (!glfwWindowShouldClose(window) && !glfwGetKey(window, GLFW_KEY_ESCAPE));

    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &indexBuffer);
    glDeleteVertexArrays(1, &VAO);
    glDeleteProgram(shaderProgram);


    glfwTerminate();
    return 0;
}
