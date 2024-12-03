cmake_minimum_required(VERSION 3.0)
project(eigen_test)

find_package(Eigen3 3.3.7 REQUIRED)

add_executable(eigen_test main.cpp)
target_link_libraries(eigen_test Eigen3::Eigen)
