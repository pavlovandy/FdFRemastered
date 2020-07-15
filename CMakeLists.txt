cmake_minimum_required(VERSION 3.15)
project(FdFRemastered)

set(CMAKE_CXX_STANDARD 14)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -o3")
#-Wconversion
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/CMake_Targets)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS} ${SDL2_TTF_INCLUDE_DIRS})


add_executable(FdFRemastered main.cpp triangle.h MathTypes/vec4.h MathTypes/mat4.h MathTypes/vec3.h parser.cpp parser.h etc/terminal-colors.h sdl-library.cpp sdl-library.h viewport.cpp viewport.h screen.cpp screen.h Map.h MathTypes/PlaneMath.h)
target_link_libraries(FdFRemastered ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} ${SDL2_TTF_LIBRARIES})