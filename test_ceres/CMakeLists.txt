cmake_minimum_required(VERSION 3.0)
project(test_install)

find_package(Eigen3 3.3.7 REQUIRED)
find_package(Ceres REQUIRED)

add_executable(test_eigen_ceres main.cpp)
target_link_libraries(test_eigen_ceres Eigen3::Eigen ceres)
