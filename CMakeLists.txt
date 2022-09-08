cmake_minimum_required(VERSION 3.1)

project(graph)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS}, include)

add_compile_options(-Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic -Wcast-align -Wunused)

set(SOURCES
	graph.cpp
	src/window.cpp
	src/barChart.cpp
	src/initDataList.cpp
	include/window.h
	include/barChart.h
	include/initDataList.h
)

add_executable(graph ${SOURCES})
target_link_libraries(graph ${OpenCV_LIBS})
