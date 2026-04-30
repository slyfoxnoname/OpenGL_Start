cmake_minimum_required(VERSION 3.10)
project(OpenGL_Start)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(external)



find_package(OpenGL REQUIRED)

set(libs
        ${OPENGL_LIBRARY}
        glfw
        glad
        glm
)

########### LESSON 1 ##############
set(LESSON_TARGET lesson01)
set(LESSON_DIR src/${LESSON_TARGET})
add_executable(${LESSON_TARGET} ${LESSON_DIR}/main.cpp)
target_link_libraries(${LESSON_TARGET} ${libs})

########### LESSON 2 ##############
set(LESSON_TARGET lesson02)
set(LESSON_DIR src/${LESSON_TARGET})

FILE(GLOB_RECURSE LESSON_SRC
        ${LESSON_DIR}/*.cpp
        ${LESSON_DIR}/*.h
)
#MESSAGE("====" ${LESSON_SRC})

add_executable(${LESSON_TARGET}
        ${LESSON_SRC}
)
target_link_libraries(${LESSON_TARGET} ${libs})
target_include_directories(${LESSON_TARGET} PRIVATE ${LESSON_DIR})

add_custom_command(  # Копіює ресурси з папки src/res у build директорію
        TARGET ${LESSON_TARGET} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/${LESSON_DIR}/res
        $<TARGET_FILE_DIR:${LESSON_TARGET}>/res
)

set(UTILS_DIR src/utils)
file(GLOB_RECURSE UTILS_SRC
    ${UTILS_DIR}/*.cpp
    ${UTILS_DIR}/*.h
)
#MESSAGE("==== UTILS_DIR: " ${UTILS_SRC})

########### LESSON 3 ##############
set(LESSON_TARGET lesson03)
set(LESSON_DIR src/${LESSON_TARGET})

FILE(GLOB_RECURSE LESSON_SRC
        ${LESSON_DIR}/*.cpp
        ${LESSON_DIR}/*.h
)
#MESSAGE("====" ${LESSON_SRC})

add_executable(${LESSON_TARGET}
        ${LESSON_SRC}
        ${UTILS_SRC}
)
target_link_libraries(${LESSON_TARGET} ${libs})
#target_include_directories(${LESSON_TARGET} PRIVATE ${LESSON_DIR})
target_include_directories(${LESSON_TARGET} PRIVATE ${UTILS_DIR})

add_custom_command(  # Копіює ресурси з папки src/res у build директорію
        TARGET ${LESSON_TARGET} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/${LESSON_DIR}/res
        $<TARGET_FILE_DIR:${LESSON_TARGET}>/res
)


########### LESSON 4 ##############
set(LESSON_TARGET lesson04)
set(LESSON_DIR src/${LESSON_TARGET})

FILE(GLOB_RECURSE LESSON_SRC
        ${LESSON_DIR}/*.cpp
        ${LESSON_DIR}/*.h
)
#MESSAGE("====" ${LESSON_SRC})

add_executable(${LESSON_TARGET}
        ${LESSON_SRC}
        ${UTILS_SRC}
)
target_link_libraries(${LESSON_TARGET} ${libs})
target_include_directories(${LESSON_TARGET} PRIVATE ${UTILS_DIR})

add_custom_command(  # Копіює ресурси з папки src/res у build директорію
        TARGET ${LESSON_TARGET} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/${LESSON_DIR}/res
        $<TARGET_FILE_DIR:${LESSON_TARGET}>/res
)

########### LESSON 5 ##############
set(LESSON_TARGET lesson05)
set(LESSON_DIR src/${LESSON_TARGET})

FILE(GLOB_RECURSE LESSON_SRC
        ${LESSON_DIR}/*.cpp
        ${LESSON_DIR}/*.h
)
#MESSAGE("====" ${LESSON_SRC})

add_executable(${LESSON_TARGET}
        ${LESSON_SRC}
        ${UTILS_SRC}
)
target_link_libraries(${LESSON_TARGET} ${libs})
#target_include_directories(${LESSON_TARGET} PRIVATE ${LESSON_DIR})
target_include_directories(${LESSON_TARGET} PRIVATE ${UTILS_DIR})

add_custom_command(  # Копіює ресурси з папки src/res у build директорію
        TARGET ${LESSON_TARGET} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/${LESSON_DIR}/res
        $<TARGET_FILE_DIR:${LESSON_TARGET}>/res
)


########### LESSON 6 ##############
set(LESSON_TARGET lesson06)
set(LESSON_DIR src/${LESSON_TARGET})

FILE(GLOB_RECURSE LESSON_SRC
        ${LESSON_DIR}/*.cpp
        ${LESSON_DIR}/*.h
)
#MESSAGE("====" ${LESSON_SRC})

add_executable(${LESSON_TARGET}
        ${LESSON_SRC}
        ${UTILS_SRC}
)
target_link_libraries(${LESSON_TARGET} ${libs})
#target_include_directories(${LESSON_TARGET} PRIVATE ${LESSON_DIR})
target_include_directories(${LESSON_TARGET} PRIVATE ${UTILS_DIR})

add_custom_command(  # Копіює ресурси з папки src/res у build директорію
        TARGET ${LESSON_TARGET} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/${LESSON_DIR}/res
        $<TARGET_FILE_DIR:${LESSON_TARGET}>/res
)

########### LESSON 7 ##############
set(LESSON_TARGET lesson07)
set(LESSON_DIR src/${LESSON_TARGET})

FILE(GLOB_RECURSE LESSON_SRC
        ${LESSON_DIR}/*.cpp
        ${LESSON_DIR}/*.h
)
#MESSAGE("====" ${LESSON_SRC})

add_executable(${LESSON_TARGET}
        ${LESSON_SRC}
        ${UTILS_SRC}
)
target_link_libraries(${LESSON_TARGET} ${libs})
#target_include_directories(${LESSON_TARGET} PRIVATE ${LESSON_DIR})
target_include_directories(${LESSON_TARGET} PRIVATE ${UTILS_DIR})

add_custom_command(  # Копіює ресурси з папки src/res у build директорію
        TARGET ${LESSON_TARGET} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/${LESSON_DIR}/res
        $<TARGET_FILE_DIR:${LESSON_TARGET}>/res
)

########### LESSON 8 ##############
set(LESSON_TARGET lesson08)
set(LESSON_DIR src/${LESSON_TARGET})

FILE(GLOB_RECURSE LESSON_SRC
        ${LESSON_DIR}/*.cpp
        ${LESSON_DIR}/*.h
)
#MESSAGE("====" ${LESSON_SRC})

add_executable(${LESSON_TARGET}
        ${LESSON_SRC}
        ${UTILS_SRC}
)
target_link_libraries(${LESSON_TARGET} ${libs})
#target_include_directories(${LESSON_TARGET} PRIVATE ${LESSON_DIR})
target_include_directories(${LESSON_TARGET} PRIVATE ${UTILS_DIR})

add_custom_command(  # Копіює ресурси з папки src/res у build директорію
        TARGET ${LESSON_TARGET} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/${LESSON_DIR}/res
        $<TARGET_FILE_DIR:${LESSON_TARGET}>/res
)



