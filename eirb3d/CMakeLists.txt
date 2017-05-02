cmake_minimum_required(VERSION 3.7)
project(eirb3d)

set(CMAKE_C_STANDARD 99)

include_directories(/include)

link_directories(/lib)

set(SOURCE_FILES
        src/geometry.c
        src/events.c
        src/model.c
        src/vector.c
        src/window.c
        src/main.c)

add_executable(eirb3d ${SOURCE_FILES})

target_link_libraries(eirb3d SDL2main SDL2)