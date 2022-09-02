cmake_minimum_required(VERSION 2.8)
project( graph )
find_package( OpenCV REQUIRED )

include_directories( ${OpenCV_INCLUDE_DIRS}, include )

set(SOURCES
	graph.cpp
	src/window.cpp
	src/barChart.cpp
	include/window.h
	include/barChart.h)

add_executable( graph  ${SOURCES} )
target_link_libraries( graph ${OpenCV_LIBS} )