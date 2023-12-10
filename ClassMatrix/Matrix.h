#pragma once
#include <iostream>
#include <Windows.h>

using namespace std;

template <typename T>
class Matrix
{
private:
    T** data;
    int rows;
    int cols;

public:

    Matrix() : data(nullptr), rows(0), cols(0) {}

    Matrix(int rows, int cols) : rows(rows), cols(cols)
    {
        data = new T * [rows];

        for (int i = 0; i < rows; ++i)
        {
            data[i] = new T[cols];
        }
    }

    ~Matrix()
    {
        for (int i = 0; i < rows; ++i)
        {
            delete[] data[i];
        }
        delete[] data;
    }

    void fillFromKeyboard()
    {
        cout << "¬ведите элементы матрицы:" << endl;

        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                cout << "Ёлемент [" << i + 1 << "][" << j + 1 << "]: ";
                cin >> data[i][j];
            }
        }
    }

    void fillRandom()
    {
        srand(time(0));
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                data[i][j] = rand() % 100;
            }
        }
    }

    void display() const
    {
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                cout << setw(5) << data[i][j] << " ";
            }
            cout << endl;
        }
    }

    Matrix<T> operator+(const Matrix<T>& other) const
    {
        Matrix<T> result(rows, cols); 

        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    Matrix<T> operator-(const Matrix<T>& other) const
    {
        Matrix<T> result(rows, cols);

        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }
        return result;
    }

    Matrix<T> operator*(const Matrix<T>& other) const
    {
        Matrix<T> result(rows, other.cols);

        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < other.cols; ++j)
            {
                result.data[i][j] = 0;
                for (int k = 0; k < cols; ++k)
                {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    Matrix<T> operator/(const T& num) const
    {
        Matrix<T> result(rows, cols);

        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                result.data[i][j] = data[i][j] / num;
            }
        }
        return result;
    }

    T findMax() const
    {
        T maxElement = data[0][0];

        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                if (data[i][j] > maxElement)
                {
                    maxElement = data[i][j];
                }
            }
        }
        return maxElement;
    }
};
