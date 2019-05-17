cmake_minimum_required (VERSION 3.8)

project ("opengl-tutorial")

link_directories( ${CMAKE_SOURCE_DIR}/lib )

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

find_package(OpenGL REQUIRED)

find_package(OpenMP)

if (OPENMP_FOUND)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
endif()

add_library(
	opengl-tutorial-libs
	lib/gl3w.c
	lib/LoadShaders.cpp
)

include_directories( include )

add_executable (1-triangles "exercises/1-triangles.cpp" "include/glimports.h")
target_link_libraries(1-triangles ${OPENGL_LIBRARIES} glfw3 opengl-tutorial-libs)
