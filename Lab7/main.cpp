#include <string>
#include <iostream>
using namespace std;

struct Person {
    std::string surname, name;
    int age;
};

auto param(Person P, int par) {
    if (par == 1) {
        return P.surname;
    }
    if (par == 2) {
        return P.name;
    }
    if (par == 3) {
        std::string res = "";
        res += char(P.age);
        return res;
    }
}



template <class T>
void quicksort(T* mas, int first, int last)
{
    T mid;
    T count;
    int f = first, l = last;
    int size = f + l;
    mid = mas[(size) / 2]; //вычисление опорного элемента
    do
    {
        while (mas[f] < mid) f++;
        while (mas[l] > mid) l--;
        if (f <= l) //перестановка элементов
        {
            count = mas[f];
            mas[f] = mas[l];
            mas[l] = count;
            f++;
            l--;
        }
    } while (f < l);
    if (first < l) quicksort(mas, first, l);
    if (f < last) quicksort(mas, f, last);

}

template <class T>
void quicksort(T* mas, int first, int last, int par/* = 0*/) {
    if (par == 1) {
        std::string mid, countf, countn;
        int count;
        int f = first, l = last;
        int size = f + l;
        mid = param(mas[(size) / 2], par);
        //mid = mas[(size) / 2]; //вычисление опорного элемента

        do
        {
            while (param(mas[f], par) < mid) f++;
            while (param(mas[l], par) > mid) l--;
            if (f <= l) //перестановка элементов
            {
                countf = mas[f].surname;
                mas[f].surname = mas[l].surname;
                mas[l].surname = countf;

                count = mas[f].age;
                mas[f].age = mas[l].age;
                mas[l].age = count;

                countn = mas[f].name;
                mas[f].name = mas[l].name;
                mas[l].name = countn;
                f++;
                l--;
            }
        } while (f < l);
        if (first < l) quicksort(mas, first, l, par);
        if (f < last) quicksort(mas, f, last, par);
    }
    else if (par == 2) {
        std::string mid, countf, countn;
        int count;
        int f = first, l = last;
        int size = f + l;
        mid = mas[(size) / 2].name; //вычисление опорного элемента
        do
        {
            while (mas[f].name < mid) f++;
            while (mas[l].name > mid) l--;
            if (f <= l) //перестановка элементов
            {
                countf = mas[f].surname;
                mas[f].surname = mas[l].surname;
                mas[l].surname = countf;

                count = mas[f].age;
                mas[f].age = mas[l].age;
                mas[l].age = count;

                countn = mas[f].name;
                mas[f].name = mas[l].name;
                mas[l].name = countn;
                f++;
                l--;
            }
        } while (f < l);
        if (first < l) quicksort(mas, first, l, par);
        if (f < last) quicksort(mas, f, last, par);
    }
    else if (par == 3) {
        int mid;
        int count;
        std::string countf, countn;
        int f = first, l = last;
        int size = f + l;
        mid = mas[(size) / 2].age; //вычисление опорного элемента

        do
        {
            while (mas[f].age < mid) f++;
            while (mas[l].age > mid) l--;
            if (f <= l) //перестановка элементов
            {
                countf = mas[f].surname;
                mas[f].surname = mas[l].surname;
                mas[l].surname = countf;

                count = mas[f].age;
                mas[f].age = mas[l].age;
                mas[l].age = count;

                countn = mas[f].name;
                mas[f].name = mas[l].name;
                mas[l].name = countn;
                f++;
                l--;
            }
        } while (f < l);
        if (first < l) quicksort(mas, first, l, par);
        if (f < last) quicksort(mas, f, last, par);
    }

}


int main()
{
    int n = 4;
    int first = 0;
    int last = n - 1;

    int I[] = { 4, 2, 9, 6 };
    quicksort(I, first, last);
    std::cout << std::endl << "Result (int): ";
    for (int i = 0; i < n; i++) std::cout << I[i] << " ";

    char C[] = { 'i', 'u', 'a', 'k' };
    quicksort(C, first, last);
    std::cout << std::endl << "Result (char): ";
    for (int i = 0; i < n; i++) std::cout << C[i] << " ";

    double D[] = { 3.05, 2.76, 0.70, 1.00 };
    quicksort(D, first, last);
    std::cout << std::endl << "Result (double): ";
    for (int i = 0; i < n; i++) std::cout << D[i] << " ";

    Person un[] = { {"Ner", "Vlad", 27 }, { "Grish", "Dima", 16 }, { "Nicit", "Julia", 44 }, { "Belog", "Den", 3 } };
    std::cout << std::endl << "Choose a parameter (1 - Surname, 2 - Name, 3 - Age): ";
    int par;
    std::cin >> par;
    quicksort(un, first, last, par);
    for (auto a : un)     std::cout << a.surname << " " << a.name << " " << a.age << std::endl;

}

