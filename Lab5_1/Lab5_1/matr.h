#pragma once
#include <iostream>
using namespace std;
class matr
{
private:
    int rows;
    int cols;
    double* mas;
public:
    matr(); /*{
        rows = 0;
        cols = 0;
        mas = new double[0];
    }*/

    matr(int matr_rows, int matr_cols, double* matr_mas);
    //{
    //	rows = matr_rows;
    //	cols = matr_cols;
    //	this->mas = new double[this->rows * cols];
    //	//возможно лишний код
    //	for (int j = 0; j < rows * cols; j++)
    //		mas[j] = matr_mas[j];
    //}




    int get_columns(); //{ return cols; }//Количество столбцов

    int get_rows(); //{ return rows; } // Количество столбцов


    double get_elem(int i, int j); /*{///вернуть (i,j) элемент
        return mas[(i - 1) * cols + (j - 1)];*/
        //}

    double trace(); //{//след матрицы (сумма диагональных элементов квадратной матрицы)
    //		double sum = 0;
    //		for (int j = 1; j <= rows; j++)
    //			sum += get_elem(j, j);
    //		return sum;
    //	}

    void print(); //{// печать матрицы в консоль
        //	for (int i = 1; i <= rows; i++) {
        //		for (int j = 1; j <= cols; j++) {
        //			cout << get_elem(i, j) << " ";
        //		}
        //		cout << endl;
        //	}
        //}

    matr* mult_by_num(double num); //{//умножение матрицы на число
    //	for (int i = 0; i < rows * cols; i++)
    //		mas[i] *= num;
    //	return this;
    //}

    matr* sum(const matr* mat2); //{// сложения матриц
    //		for (int i = 0; i < rows * cols; i++)
    //			mas[i] += mat2->mas[i];
    //		return this;
    //	}

    void input(); //{//ввести матрицу с клавиатуры
        //	cout << "Введите кол-во строк: " << endl;
        //	cin >> this->rows;
        //	cout << "Введите кол-во столбцов: " << endl;
        //	cin >> this->cols;
        //	this->mas = new double[rows * cols];
        //	for (int i = 1; i <= rows; i++)
        //		for (int j = 1; j <= cols; j++)
        //			cin >> mas[(i - 1) * cols + (j - 1)];
        //}

    matr* mult(const matr* mat2); //{//умножения двух матриц
    //		double* result = new double[rows * rows];
    //		int z = 0;
    //		for (int i = 1; i <= rows; i++) {
    //			for (int j = 1; j <= rows; j++) {
    //				result[z] = 0;
    //				for (int k = 1; k <= cols; k++) {
    //					double a = get_elem(i, k);
    //					double b = mat2->mas[(k - 1) * rows + (j - 1)];
    //					result[z] += a * b;
    //				}
    //				z++;
    //			}
    //		}
    //		matr* res = new matr(rows, rows, result);
    //		return res;
    //	}

    double det(); //{//определитель матрицы (для квадратных)
    //
    //
    //		//дописать
    //		//return mas[0] * mas[3] - mas[1] * mas[2];
    //		for (int j = 1; j <= cols; j++)
    //			for (int i = 1; i <= cols; i++)
    //				if (i > j) {
    //					double k = -get_elem(i, j) / get_elem(j, j);
    //					for (int z = (j - 1) * cols; z < cols * j; z++) mas[z] *= k;
    //					for (int z = (j - 1) * cols; z < cols * j; z++) mas[(i - j) * cols + z] += mas[z];
    //					for (int z = (j - 1) * cols; z < cols * j; z++) mas[z] /= k;
    //					/*this->print();
    //					cout << endl;*/
    //				}
    //		double d = 1;
    //		for (int j = 1; j <= rows; j++) d *= get_elem(j, j);
    //		return d;
    //	}

};
