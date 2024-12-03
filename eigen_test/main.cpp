#include <iostream>
#include <Eigen/Dense>

int main()
{
    // Création de matrices et vecteurs
    Eigen::Matrix4d A = Eigen::Matrix4d::Random();
    Eigen::Matrix4d B = Eigen::Matrix4d::Identity();
    Eigen::Vector4d v(1.0, 2.0, 3.0, 4.0);

    // Opérations
    std::cout << "=== Test de vérification Eigen ===" << std::endl;
    
    // Test 1: A * I = A
    Eigen::Matrix4d test1 = A * B;
    std::cout << "\nTest 1: A * I = A" << std::endl;
    std::cout << "Différence: " << (test1 - A).norm() << " (doit être proche de 0)" << std::endl;

    // Test 2: A * v
    Eigen::Vector4d test2 = A * v;
    std::cout << "\nTest 2: A * v" << std::endl;
    std::cout << "Résultat: \n" << test2 << std::endl;

    // Test 3: Transposée
    Eigen::Matrix4d AT = A.transpose();
    std::cout << "\nTest 3: (A^T)^T = A" << std::endl;
    std::cout << "Différence: " << (AT.transpose() - A).norm() << " (doit être proche de 0)" << std::endl;

    return 0;
}
