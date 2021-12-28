#include <iostream>
#include "matr.h"
#include <clocale>
using namespace std;

int main()
{
    setlocale(LC_CTYPE, "rus");

    bool a = true;
    int x;
    //cout << "1. Введите матрицу\n" << "2. Печать матрицы в консоль\n" << "3. Умножение двух матриц\n" << "4. Cложение двух матриц\n" << "5. След матрицы\n" << "6. Умножение матрицы на число\n" << "7. Определитель матриц\n" << "8. вернуть (i,j) элемент\n";


    while (a) {
        cout << "1. Введите матрицу\n" << "2. Умножение двух матриц\n" << "3. Cложение двух матриц\n" << "4. След матрицы\n" << "5. Умножение матрицы на число\n" << "6. Определитель матриц\n" << "7. вернуть (i,j) элемент\n" << "8. Выход\n";

        cin >> x;

        switch (x) {
        case 1:
        {
            matr* m1 = new matr();
            m1->input();
            cout << "Матрица 1" << endl;
            m1->print();
            cout << "Матрица введена" << endl;

            break;
        }
        case 2:
        {
            matr* m2 = new matr();
            matr* m3 = new matr();
            matr* m4 = new matr();
            cout << "Введите матрицу 1\n";
            m2->input();
            cout << "Введите матрицу 2\n";
            m3->input();

            m4 = m2->mult(m3);
            cout << "Матрица 1 * матрица 2: \n";
            m4->print();
            cout << endl;

            break;


        }
        case 3:
        {
            matr* m2 = new matr();
            matr* m3 = new matr();
            matr* m4 = new matr();
            cout << "Введите матрицу 1\n";
            m2->input();
            cout << "Введите матрицу 2\n";
            m3->input();

            m4 = m2->sum(m3);
            cout << "Матрица 1 + матрица 2: \n";
            m4->print();
            cout << endl;

            break;


        }
        case 4:
        {
            matr* m4 = new matr();
            m4->input();
            cout << "След матрицы: " << m4->trace() << endl;


            break;


        }

        case 5:
        {
            matr* m4 = new matr();
            cout << "Введите матрицу 1\n";
            m4->input();
            cout << "Введите число\n";
            double s;
            cin >> s;
            m4->mult_by_num(s);
            m4->print();


            break;


        }

        case 6:
        {
            matr* m4 = new matr();
            cout << "Введите матрицу 1\n";
            m4->input();
            cout << "Определитель = " << m4->det() << endl;



            break;


        }

        case 7:
        {
            int i, j;
            matr* m4 = new matr();
            cout << "Введите матрицу 1\n";
            m4->input();

            cout << "Матрица =\n";
            m4->print();
            cout << "Введите i\n ";
            cin >> i;
            cout << "Введите j\n ";
            cin >> j;
            cout << m4->get_elem(i, j) << endl;
            break;


        }




        case 8:
        {
            a = false;
            break;
        }
        }
    }




























    /*int N = 3, M = 2;
    double arr1[6] = { 1,2,3,4,5,6 };
    matr* m1 = new matr(N, M, arr1);
    cout << "Колоннок столько: " << m1->get_columns() << endl;
    cout << "Рядов столько: " << m1->get_rows() << endl;

    cout << "Элемент [1;1] равен " << m1->get_elem(1, 1) << endl;
    cout << "Элемент [1;2] равен " << m1->get_elem(1, 2) << endl;
    cout << "Элемент [2;1] равен " << m1->get_elem(2, 1) << endl;
    cout << "Элемент [2;2] равен " << m1->get_elem(2, 2) << endl;
    cout << "Элемент [3;1] равен " << m1->get_elem(3, 1) << endl;
    cout << "Элемент [3;2] равен " << m1->get_elem(3, 2) << endl;

    double arr2[9] = { 1,2,3,4,5,6,7,8,9 };
    matr* m2 = new matr(3, 3, arr2);
    cout << "Элемент [1;1] равен " << m2->get_elem(1, 1) << endl;
    cout << "Элемент [1;2] равен " << m2->get_elem(1, 2) << endl;
    cout << "Элемент [1;3] равен " << m2->get_elem(1, 3) << endl;
    cout << "Элемент [2;1] равен " << m2->get_elem(2, 1) << endl;
    cout << "Элемент [2;2] равен " << m2->get_elem(2, 2) << endl;
    cout << "Элемент [2;3] равен " << m2->get_elem(2, 3) << endl;
    cout << "Элемент [3;1] равен " << m2->get_elem(3, 1) << endl;
    cout << "Элемент [3;2] равен " << m2->get_elem(3, 2) << endl;
    cout << "Элемент [3;3] равен " << m2->get_elem(3, 3) << endl;

    matr* m3 = new matr(M, N, arr1);
    cout << "Элемент [1;1] равен " << m3->get_elem(1, 1) << endl;
    cout << "Элемент [1;2] равен " << m3->get_elem(1, 2) << endl;
    cout << "Элемент [1;3] равен " << m3->get_elem(1, 3) << endl;
    cout << "Элемент [2;1] равен " << m3->get_elem(2, 1) << endl;
    cout << "Элемент [2;2] равен " << m3->get_elem(2, 2) << endl;
    cout << "Элемент [2;3] равен " << m3->get_elem(2, 3) << endl;

    cout << "След матрицы: " << m2->trace() << endl;

    cout << "Матрица 3\n";
    m3->print();

    m3->mult_by_num(-0.5);
    cout << "Матрица 3, умноженная на -0.5\n";
    m3->print();

    matr* m4 = new matr(M, N, arr1);
    m4->sum(m3);
    cout << "Матрица 4 + матрица 3: \n";
    m4->print();




    matr* m5 = new matr();
    m5->input();
    cout << "Матрица 5" << endl;
    m5->print();







    m1 = m1->mult(m4);
    cout << "Матрица 1 * матрица 4: \n";
    m1->print();
    cout << endl;

    double arr3[16] = { 1,2,4,8,3,9,27,81,4,16,64,256,5,25,125,625 };
    matr* m6 = new matr(4, 4, arr3);
    cout << m6->det() << endl;*/





    return 0;
}
