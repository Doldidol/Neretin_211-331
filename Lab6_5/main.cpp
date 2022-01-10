#include <iostream>
#include <string>
#include <list>
using namespace std;

bool mysort(string& a1, string& a2) {
    string num1 = a1.substr(0, a1.find(" "));
    string num2 = a2.substr(0, a2.find(" "));
    return (num1<num2);

}

int main()
{
    string a;
    list<string> list;
    while (getline(cin, a)) {
        list.push_back(a);
        if (a == ",") break;
    }
    list.sort(mysort);
    for (auto i = list.begin(); i != list.end(); i++) {
        if (*i!=".") cout << *i << "\n";
    }
}
