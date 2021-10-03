#include <iostream>
#include <string>
#include <bitset>
int main()
{
    using namespace std;
    //task 1
    cout << "1." <<endl;
    cout <<"Neretin Vladislav Evgenivich 211-331" <<endl;

    //task 2
    cout << "2." <<endl;
    cout << "min int=" << int(0b10000000000000000000000000000000)<<", max int=" << 0b01111111111111111111111111111111<<", size of int="<< sizeof(int)<<endl;
    cout << "min unsigned int="<<0<<", max unsigned int="<<0b11111111111111111111111111111111<<", size of unsidned int="<<sizeof(int)<<endl;
    cout << "min short=" << 0b100000000000000<<", max short="<<0b111111111111111<<", size of short="<<sizeof(short)<<endl;
    cout << "min unsigned short="<< 0<<", max unsigned short="<<0b111111111111111<<", size of unsigned short="<<sizeof(short)<<endl;
    cout << "min long=" <<-long(0b10000000000000000000000000000000)<<", max long="<<0b1111111111111111111111111111111<<", size of long="<<sizeof(long)<<endl;
    cout << "min long long=" <<long (long(0b1000000000000000000000000000000000000000000000000000000000000000))<<", max long long="<< 0b111111111111111111111111111111111111111111111111111111111111111<<", size of long long="<<sizeof(long long)<<endl;
    cout << "min double=" <<-double(0b1000000000000000000000000000000000000000000000000000000000000000)<<", max double="<<0b111111111111111111111111111111111111111111111111111111111111111<<", size of double="<<sizeof(double)<<endl;
    cout << "min char=" <<0<<", max char="<<0b11111111<<", size of char="<<sizeof(char)<<endl;
    cout << "min bool=" <<0<<", max bool="<<0b11111111<<", size of bool="<<sizeof(bool)<<endl;

    //task 3
    cout << "3." <<endl;
    double c;
    cout <<"Введите число: ";
    cin >> c;
    cout <<endl<<"В бинарном виде ";
    bitset <8 * sizeof(c)> x(c);
    cout <<x<<endl;
    cout <<"В шестнадцатеричнм виде "<<hex<<c<<endl;
    cout <<"bool: "<<bool(c)<<endl;
    cout <<"double: "<<double(c)<<endl;
    cout <<"char: "<<char(c)<<endl;

    //task 4
    cout <<"4."<<endl;
    double a, b;
    cout <<"Введите коэффициенты a * x = b: "<<endl;
    cin >> a >> b;
    cout <<endl<<a<<" * x = "<<b<<endl;
    cout <<"x = "<<b<<"/"<<a<<endl;
    cout <<"x = "<<b/a<<endl;
    cout <<"Ответ: "<<b/a<<"."<<endl;

    //task 5
    cout <<"5."<<endl;
    double y,z;
    cout <<"Введите координаты отрезка на прямой: "<<endl;
    cin >>y>>z;
    cout <<"Середина отрезканаходится в точке с координатой "<<(y+z)/2<<".\n";

    return 0;
}
