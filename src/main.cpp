#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

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
    window = glfwCreateWindow(1080, 720, "OpenGL_Colorful_Rectangle", NULL, NULL);
    if (!window)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // Встановлюємо сірий колір фону для контрасту
    glClearColor(0.2f, 0.2f, 0.2f, 1.0f);

    // --- ШЕЙДЕРИ ---
    
    // Vertex Shader: тепер приймає позицію (location 0) та колір (location 1)
    auto vertexShaderCode = R"(
        #version 330 core
        layout(location = 0) in vec2 aPos;
        layout(location = 1) in vec3 aColor;

        out vec3 vertexColor; // передаємо колір у фрагментний шейдер

        void main() {
            gl_Position = vec4(aPos, 0.0, 1.0);
            vertexColor = aColor;
        }
    )";

    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderCode, nullptr);
    glCompileShader(vertexShader);

    // Fragment Shader: отримує інтерпольований колір
    auto fragmentShaderCode = R"(
        #version 330 core
        in vec3 vertexColor;
        out vec4 FragColor;

        void main() {
            FragColor = vec4(vertexColor, 1.0);
        }
    )";

    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderCode, nullptr);
    glCompileShader(fragmentShader);

    GLuint shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    // --- ГЕОМЕТРІЯ (Прямокутник з двох трикутників) ---

    // Формат даних: X, Y, R, G, B
    float vertices[] = {
        // Перший трикутник
        -0.5f,  0.5f,  1.0f, 0.0f, 0.0f,  // Вершина 1: Верхня-ліва (Червона)
         0.5f,  0.5f,  1.0f, 1.0f, 0.0f,  // Вершина 2: Верхня-права (Жовта)
         0.5f, -0.5f,  0.0f, 1.0f, 0.0f,  // Вершина 3: Нижня-права (Зелена)

        // Другий трикутник
         0.5f, -0.5f,  0.0f, 1.0f, 0.0f,  // Вершина 3: Нижня-права (Зелена)
        -0.5f, -0.5f,  0.0f, 0.0f, 1.0f,  // Вершина 4: Нижня-ліва (Синя)
        -0.5f,  0.5f,  1.0f, 0.0f, 0.0f   // Вершина 1: Верхня-ліва (Червона)
    };

    GLuint VBO, VAO;
    glGenBuffers(1, &VBO);
    glGenVertexArrays(1, &VAO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Атрибут 0: Позиція (X, Y)
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // Атрибут 1: Колір (R, G, B)
    // Зміщення (offset) складає 2 float (пропускаємо X та Y)
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(2 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindVertexArray(0);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window) && !glfwGetKey(window, GLFW_KEY_ESCAPE))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shaderProgram);
        glBindVertexArray(VAO);
        
        // Малюємо 6 вершин (2 трикутники)
        glDrawArrays(GL_TRIANGLES, 0, 6);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    // Очищення
    glDeleteBuffers(1, &VBO);
    glDeleteVertexArrays(1, &VAO);
    glDeleteProgram(shaderProgram);

    glfwTerminate();
    return 0;
}