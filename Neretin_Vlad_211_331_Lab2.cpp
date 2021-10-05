#include <iostream>
#include <climits>
#include <string>
using namespace std;

void task1();
void task2();
void task3();
double fact(double L);
int main(){
    short int choice;
    while (true) {
        cout << "Что вы хотите выполнить? \n";
        cout << "1. задание 1\n";
        cout << "2. задание 2\n";
        cout << "3. задание 3\n";
        cout << "4. выход\n";
        cin >> choice;

        switch (choice)
        {
            case 1:
                task1();
                break;
            case 2:
                task2();
                break;
            case 3:
                task3();
                break;
            case 4:
               return 0;
            default:
                cout <<"Повторите" << endl;
                break;
        }
    }
}

void task1(){
    int n;
    cout << "Введите n ";
    cin >> n;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n ; j++){
            if(i >= j)
                cout << j;
        }
        cout << endl;
    }
    cout << endl;
}
void task2(){
    double n, k = 0, C;
    cout << "Введите натуральное число n: ";
    cin >> n;
    C = fact(n);
    while (k <= n)
    {
        double K = C / (fact(n - k) * fact(k));
        cout << K << " ";
        k++;
    }
    cout << endl;
}
void task3(){
    int sum = 0, n = 0;
    string str;
    cout << "Введите стоп слово ";
    cin >>str;
    string V;
    while (true){
        cout << "Введите число ";
        cin >> V;
        if(str != V){
            sum = sum + stoi(V);
            n++;
        }else{
            cout << "Среднее арифметическое = " << double(sum) / n << endl;
            break;
        }
    }
}
double fact(double L){
    if(L < 0)
        return 0;
    if(L == 0)
        return 1;
    if(L > 1 )
        return L * fact(L - 1);
}
