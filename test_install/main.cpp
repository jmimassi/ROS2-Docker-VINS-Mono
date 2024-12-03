#include <iostream>
#include <Eigen/Dense>
#include <ceres/ceres.h>

int main()
{
    // Test Eigen
    Eigen::Matrix3d m = Eigen::Matrix3d::Random();
    std::cout << "Test Eigen - Matrice aléatoire :\n"
              << m << "\n\n";

    // Test Ceres
    std::cout << "Test Ceres - Version : "
              << CERES_VERSION_MAJOR << "."
              << CERES_VERSION_MINOR << "."
              << CERES_VERSION_REVISION << std::endl;

    return 0;
}
