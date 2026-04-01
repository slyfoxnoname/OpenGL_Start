cmake_minimum_required(VERSION 3.10.0)
project(OpenGL_Start VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)

# set(var "hello world") # var = "hello world"
# set(var1 hello world) # var1 = ["hello", "world"]
# message("var : ${var}")
# message(PROJECT_NAME=${PROJECT_NAME}) # message для дебагу зручно використовувати

add_subdirectory(external)

add_executable(${PROJECT_NAME} src/main.cpp)

find_package(OpenGL REQUIRED)
set(libs
    ${OPENGL_LIBRARY}
    glad
    glfw
    glm

)

target_link_libraries(${PROJECT_NAME} ${libs})