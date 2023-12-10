#include <iostream>
#include <Windows.h>
#include <iomanip>
#include "Matrix.h"

using namespace std;


int main()
{
    setlocale(LC_ALL, "RU");

    Matrix<double> mat1(2, 3);
    mat1.fillFromKeyboard();

    Matrix<double> mat2(2, 3);
    mat2.fillRandom();

    cout << "Матрица 1:" << endl;
    mat1.display();

    cout << "Матрица 2:\n" << endl;
    mat2.display();

    Matrix<double> matSum = mat1 + mat2;
    cout << "Сумма матриц:" << endl;
    matSum.display();

    double scalar = 2.5;
    Matrix<double> matDiv = mat1 / scalar;
    cout << "Деление матрицы 1 на " << scalar << ":" << endl;
    matDiv.display();

    cout << "Максимальный элемент в матрице 1: " << mat1.findMax() << endl;

    return 0;
}