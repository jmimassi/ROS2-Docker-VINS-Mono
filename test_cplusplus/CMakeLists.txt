cmake_minimum_required(VERSION 3.0)
project(test_libs)

find_package(Eigen3 3.3.7 REQUIRED)
find_package(Ceres REQUIRED)
find_package(OpenCV 4.2.0 REQUIRED)

add_executable(test_libs main.cpp)
target_link_libraries(test_libs 
    Eigen3::Eigen 
    ceres 
    ${OpenCV_LIBS}
)
