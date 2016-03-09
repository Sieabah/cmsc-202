cmake_minimum_required(VERSION 3.3)
project(RayTracer)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Vector3D.cpp Vector3D.h Renderer.cpp Renderer.h Polygon.cpp Polygon.h)
add_executable(RayTracer ${SOURCE_FILES})