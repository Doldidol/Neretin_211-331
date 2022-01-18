#include <iostream>
#include <string>
#include <map>
#include <stack> // для работы со стеками
using namespace std;

int main () {
    bool answ = true;
    map<char, char> data;
    data.insert(pair<char, int>('{', '}'));
    data.insert(pair<char, int>('{', '}')); // пары компилярности
    data.insert(pair<char, int>('{', '}'));

    stack <char> main_steck;
    string line_start;
    cin >> line_start;
    //cliar line
    for (auto i : line_start) {
        if (i == '{' or i == '(' or i == '[') {
            main_steck.push(i); //в вверх стека
        }
        else if (i == '}' or i == ')' or i == ']') {
            if (i == data[main_steck.top()]) {
                main_steck.pop();
            }
            else {
                answ = false;
                break;
            }
        }
    }

    // вывод ответа
    if (answ)
        cout << "-> Yes" << "\n";
    else
        cout << "-> No" << "\n";
}
