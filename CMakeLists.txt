cmake_minimum_required(VERSION 2.8)
project( fastCorners )
find_package( OpenCV REQUIRED )
add_executable( fastCorners fastCorners.cpp )
target_link_libraries( fastCorners ${OpenCV_LIBS} )
