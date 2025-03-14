cmake_minimum_required(VERSION 3.10) 
project(cv)
set (OpenCV_DIR C:/opencv/build) 
find_package (OpenCV REQUIRED) 
include_directories(1_introduction) # Thay tên thư mục
file(GLOB SRC_FILES 1_introduction/display_a_trackbar_video.cpp) # Thay tên file
add_executable(${PROJECT_NAME} ${SRC_FILES}) 
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})