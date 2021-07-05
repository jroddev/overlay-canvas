cmake_minimum_required(VERSION 3.17)
include(FetchContent)

project(overlay_canvas)

set(CMAKE_CXX_STANDARD 20)
# required to override options of subprojects
set(CMAKE_POLICY_DEFAULT_CMP0077 NEW)


FetchContent_Declare(
        express-draw-opengl-glfw
        GIT_REPOSITORY https://github.com/jroddev/express-draw-opengl-glfw
)
FetchContent_MakeAvailable(express-draw-opengl-glfw)

add_executable(overlay_canvas
        src/main.cpp)
target_link_libraries(overlay_canvas express-draw-opengl-glfw)


configure_file(assets/fonts/Arial.ttf assets/fonts/Arial.ttf COPYONLY)
