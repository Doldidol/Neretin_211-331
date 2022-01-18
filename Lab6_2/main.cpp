#include <iostream> // подключение библиотеки ввода-вывода
#include <deque>    // подключение библиотеки deque
#include <string>   // подключение библиотеки с++ строк
#include <clocale>  // язык

using namespace std;




// Вывод целочисленного массива на печать
void print_int_array(int* c_print_int_array, int len_print_int_array) {
    if (c_print_int_array != nullptr) {
        for (int i_print_int_array = 0; i_print_int_array < len_print_int_array; i_print_int_array++) {
            cout << *(c_print_int_array + i_print_int_array) << " ";
        }
    }
}

// Очистка экрана
void clear_screen() {
    system("pause");
    system("cls");
}

// Вывод на экран deque с переводом из кодировки символов
void print_deque(deque<int>& main_deque, deque<int>::const_iterator iter, int& temp_number) {
    cout << endl;
    for (iter = main_deque.begin(); iter != main_deque.end(); iter++) {
        std::cout << char(*iter);  // так как символы храняться в виде чисел, то необходмио их конвертировать обратно
    }
    cout << std::endl;
    temp_number = 0;
    for (iter = main_deque.begin(); iter != main_deque.end(); iter++) {
        if (*iter == 32) {                                                          // 32 - код пробела
            cout << temp_number << " элемент: <пробел>" << endl;
            temp_number++;
        }
        else {
            cout << temp_number << " элемент: ";
            std::cout << char(*iter) << endl;  // так как символы храняться в виде чисел, то необходмио их конвертировать обратно
            temp_number++;
        }
    }
    cout << std::endl;
}

// Вывод на экран deque в исходном виде
void print_deque_original(deque<int>& main_deque, deque<int>::const_iterator iter, int& temp_number) {
    cout << endl;
    cout << "В main_deque содержаться следующие сведения:\n";
    for (iter = main_deque.begin(); iter != main_deque.end(); iter++) {
        std::cout << *iter;  // так как символы храняться в виде чисел, то необходмио их конвертировать обратно
    }
    cout << std::endl;
    temp_number = 0;
    for (iter = main_deque.begin(); iter != main_deque.end(); iter++) {
        if (*iter == 32) {                                                          // 32 - код пробела
            cout << temp_number << " элемент: <пробел>" << endl;
            temp_number++;
        }
        else {
            cout << temp_number << " элемент: ";
            std::cout << *iter << endl;  // так как символы храняться в виде чисел, то необходмио их конвертировать обратно
            temp_number++;
        }
    }
    cout << std::endl;
}

// Очистка deque
void clear_deque(deque<int>& main_deque) {
    main_deque.clear();
}

// Проверка на палиндром
void check_palindrome(deque<int>& main_deque, string& main_line, deque<int>::const_iterator iter, bool answer, int& size_of_, int& temp_number) {
    cout << "Введите строку > ";
    getline(cin, main_line);
    cout << endl;

    // очистка deque, если не пустой
    if (main_deque.size() != 0) {
        clear_deque(main_deque);
    }

    size_of_ = main_line.size();                    // получение размера введенной строки
    for (int i = 0; i < size_of_; i++) {            // посимвольное считывание строки
        if (main_line.at(i) != 32) {
            main_deque.push_back(main_line.at(i));      // занесение считанного символа в deque
        }
    }

    // печать deque
    print_deque(main_deque, iter, temp_number);

    answer = true;                                  // задание значения "ответ верный"
    while (main_deque.size() >= 2) {
        if (main_deque.front() == main_deque.back()) {
            main_deque.pop_front();
            main_deque.pop_back();
        }
        else {
            answer = false;
            break;
        }
    }

    if (answer == true) cout << "\nЭто палиндромом\n";
    if (answer == false) cout << "\nНе палиндромом\n";
}

// проверка угла поворота
// Для определения  с какой стороны от вектора AB находится точка C
// (положительное значение соответствует левой стороне, отрицательное — правой)
int check_degree(int main_x, int main_y, int x1, int y1, int x2, int y2) {
    if ((x1 - main_x) * (y2 - y1) - (y1 - main_y) * (x2 - x1) >= 0) { return 1; }
    else { return 2; }
}

// Алгоритм Грэхема
void algorithm(int*& coor_arr, int*& ord_arr, int& size_coor_arr, int& size_ord_arr, deque<int>& main_deque, int& temp_number, deque<int>::const_iterator iter) {
    cout << "Введите количество точек > ";
    cin >> temp_number;
    cout << endl;

    if (coor_arr != nullptr) { delete[]coor_arr; }
    if (ord_arr != nullptr) { delete[]ord_arr; }

    size_coor_arr = temp_number * 2;
    size_ord_arr = temp_number;

    coor_arr = new int[size_coor_arr];
    ord_arr = new int[size_ord_arr];

    // Заполнение массивов с координатами и порядковыми номерами
    for (int i = 0; i < size_ord_arr; i++) {
        cout << "Введите координату x " << i + 1 << " точки > ";
        cin >> coor_arr[i * 2];
        cout << "Введите координату y " << i + 1 << " точки > ";
        cin >> coor_arr[i * 2 + 1];
        cout << endl;
        ord_arr[i] = i;
    }

    print_int_array(coor_arr, size_coor_arr); cout << endl; print_int_array(ord_arr, size_ord_arr); cout << endl;



    // выявление начальной точки
    int left_vertex = 0;
    int value_left_vertex = 2147483647;
    for (int i = 0; i < size_ord_arr; i++) {
        if (coor_arr[i * 2] < value_left_vertex) {
            value_left_vertex = coor_arr[i * 2];
            left_vertex = i;
        }
    }

    // начальная точка помещается в начало массива
    int temp_x = coor_arr[0];
    int temp_y = coor_arr[1];
    int temp_num = ord_arr[0];
    coor_arr[0] = coor_arr[left_vertex * 2];
    coor_arr[1] = coor_arr[left_vertex * 2 + 1];
    ord_arr[0] = left_vertex;
    coor_arr[left_vertex * 2] = temp_x;
    coor_arr[left_vertex * 2 + 1] = temp_y;
    ord_arr[left_vertex] = temp_num;

    print_int_array(coor_arr, size_coor_arr); cout << endl; print_int_array(ord_arr, size_ord_arr); cout << endl;

    // сравнения поворота относительно начальной точки
    int res_check = 0;
    for (int i = 1; i < size_ord_arr; i++) {
        for (int j = i; j < size_ord_arr; j++) {
            res_check = check_degree(coor_arr[0], coor_arr[1],                      // координаты начальной точки
                coor_arr[(j - 1) * 2], coor_arr[(j - 1) * 2 + 1],  // координаты первой точки для сравнения
                coor_arr[j * 2], coor_arr[(j * 2) + 1]);       // координаты второй точки для сравнения
// обмен местами, если вторая точка находится правее
            if (res_check == 2) {
                temp_x = coor_arr[(j - 1) * 2];
                temp_y = coor_arr[(j - 1) * 2 + 1];
                temp_num = ord_arr[j - 1];
                coor_arr[(j - 1) * 2] = coor_arr[j * 2];
                coor_arr[(j - 1) * 2 + 1] = coor_arr[j * 2 + 1];
                ord_arr[j - 1] = ord_arr[j];
                coor_arr[j * 2] = temp_x;
                coor_arr[j * 2 + 1] = temp_y;
                ord_arr[j] = temp_num;
            }
        }
    }

    print_int_array(coor_arr, size_coor_arr); cout << endl; print_int_array(ord_arr, size_ord_arr); cout << endl;

    // занесение в дек
    clear_deque(main_deque);                                                    // очистка дека
    main_deque.push_back(ord_arr[0]);
    main_deque.push_back(ord_arr[1]);

    for (int i = 2; i < size_ord_arr - 1; i++) {
        res_check = check_degree(coor_arr[(i - 2) * 2], coor_arr[(i - 2) * 2 + 1],
            coor_arr[(i - 1) * 2], coor_arr[(i - 1) * 2 + 1],
            coor_arr[i * 2], coor_arr[i * 2 + 1]);
        if (res_check == 1) { main_deque.push_back(ord_arr[i]); }
        if (i + 1 == size_ord_arr) {
            res_check = check_degree(coor_arr[i * 2], coor_arr[i * 2 + 1],
                coor_arr[0], coor_arr[1],
                coor_arr[2], coor_arr[3]);
            if (res_check == 1) { main_deque.push_back(ord_arr[i]); }
        }
    }

    // вывод ответа (дек)
    cout << endl;
    print_deque_original(main_deque, iter, temp_number);
}

// Меню.
int start_menu(deque<int>& main_deque, string& main_line, deque<int>::const_iterator iter, bool answer, int& size_of_, int& temp_number, int*& coor_arr, int*& ord_arr, int& size_coor_arr, int& size_ord_arr) {
    setlocale(LC_ALL, "rus");

    while (true) {
        cout << "Проверка на полиндро" << endl << endl;
        check_palindrome(main_deque, main_line, iter, answer, size_of_, temp_number);

        clear_screen();

        cout << "Алгоритм Грэхема" << endl << endl;
        algorithm(coor_arr, ord_arr, size_coor_arr, size_ord_arr, main_deque, temp_number, iter);

        clear_screen();
    }

    return 0;
}

// тело объявления переменных и запуска меню
int main()
{
    //    7 + 1 + 2 - + 3 * 4 - -

    int result_start_menu;  // переменная для контроля закрытия меню

    deque<int> main_deque;              // создание главного deque
    deque<int>::const_iterator iter;    // создание указателя для deque
    string main_line;                   // создание главной строки
    int* coor_arr = nullptr;            // массив с координатами формула x <i * 2>, y <i * 2 + 1>
    int* ord_arr = nullptr;             // массив с порядковыми номерами точек
    int size_coor_arr = 0;              // размер массива с координатами
    int size_ord_arr = 0;               // размер массива с порядковыми номерами точек
    int size_of_ = 0;                   // создание переменной для хранения размера чего-либо
    bool answer = false;                // результат проверки
    int temp_number = 0;                // временная целочисленная переменная

    result_start_menu = start_menu(main_deque, main_line, iter, answer, size_of_, temp_number, coor_arr, ord_arr, size_coor_arr, size_ord_arr);
    if (result_start_menu == 0) { return 0; }
}
