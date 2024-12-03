#include <iostream>
#include <Eigen/Dense>
#include <ceres/ceres.h>
#include <opencv2/opencv.hpp>

int main()
{
    // Test Eigen
    std::cout << "=== Test Eigen ===" << std::endl;
    Eigen::Matrix3d m = Eigen::Matrix3d::Identity();
    std::cout << "Matrice identité :\n"
              << m << "\n\n";

    // Test Ceres
    std::cout << "=== Test Ceres ===" << std::endl;
    std::cout << "Version Ceres : "
              << CERES_VERSION_MAJOR << "."
              << CERES_VERSION_MINOR << "."
              << CERES_VERSION_REVISION << "\n\n";

    // Test OpenCV
    std::cout << "=== Test OpenCV ===" << std::endl;
    std::cout << "Version OpenCV : " << CV_VERSION << std::endl;

    // Création d'une image test
    cv::Mat image(200, 200, CV_8UC3, cv::Scalar(255, 255, 255));
    cv::circle(image, cv::Point(100, 100), 50, cv::Scalar(0, 0, 255), -1);
    cv::putText(image, "Test OK", cv::Point(60, 100),
                cv::FONT_HERSHEY_SIMPLEX, 1, cv::Scalar(0, 0, 0), 2);

    cv::imshow("Test des bibliothèques", image);
    cv::waitKey(0);

    return 0;
}
