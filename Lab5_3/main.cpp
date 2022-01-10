#include "matrix.h"
#include <iostream>
#include <clocale>

using namespace std;

int main() {
    setlocale(LC_CTYPE, "rus");

    matrix matr;

    int choice = 0;
    while (true) {
        cout << "1. Ввод." << endl;
        cout << "2. Ввод с размером(автоматический)" << endl;
        cout << "3. Вывод" <<endl;
        cout << "4. Получить элемент и размер" <<endl;
        cout << "5. Бинарный минус" <<endl;
        cout << "6. Унарный минус" <<endl;
        cout << "7. Сложение" <<endl;
        cout << "8. Умножение на число" <<endl;
        cout << "9. След матрицы" <<endl;
        cout << "10. Перемножение" <<endl;
        cout << "11. Определитель" <<endl;
        cout << "12. >> (ввод, перегрузка)." <<endl;
        cout << "13. << (вывод)." <<endl;
        cout << "14. += поэлементно" <<endl;
        cout << "15. -= поэлементно" <<endl;
        cout << "16. Выход." <<endl;

        cin >> choice;

        switch (choice) {
        case 1:
        {
            matr.input();
            break;
        }
        case 2:
        {
            int n;
            cout << "Введите размер:";
            cin >> n;
            matr.input(n);
            break;
        }
        case 3:
        {
            matr.print();
            break;
        }
        case 4:
        {
            int i, j;
            cout << "Введите i и j: ";
            cin >> i >> j;
            cout << matr.get_elem(i, j) << endl;
            cout << matr.get_size() << endl;
            break;
        }
        case 5:
        {
            matrix matr2;
            matr2.input();
            matr - matr2;
            break;
        }
        case 6:
        {
            -matr;
            break;
        }
        case 7:
        {
            matrix matr2;
            matr2.input();
            matr + matr2;
            break;
        }
        case 8:
        {
            int number;
            cout << "Введите число ";
            cin >> number;
            matr* number;
            break;
        }
        case 9:
        {
            cout << matr.trace() <<endl;
            break;
        }
        case 10:
        {
            matrix matr2;
            matr2.input();
            matr* matr2;
            break;
        }
        case 11:
        {
            cout << matr.det() <<endl;
            break;
        }
        case 12:
        {
            cin >> matr;
            break;
        }
        case 13:
        {
            cout << matr;
            break;
        }
        case 14:
        {
            matrix matr2;
            matr2.input();
            matr += matr2;
            break;
        }
        case 15:
        {
            matrix matr2;
            matr2.input();
            matr -= matr;
            break;
        }
        default:
        {
            return 1;
        }

        }
    }
}
