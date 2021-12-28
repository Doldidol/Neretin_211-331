#pragma once
class Matrix
{
private:
    int col;
    int row;
    int* element;

public:

    Matrix();
    Matrix(int i, int j);
    Matrix(int i, int j, const int* arr);

    ~Matrix();

    Matrix(const Matrix& orig);

    void sum(int row, int col, const int* arr);
    bool sum(Matrix second);

    bool mult(int row, int col, const int* arr);
    bool mult(Matrix second);

    void input(int i, int j, bool flag);
    void input(int i, int j, const int* arr);

    void print();
};
