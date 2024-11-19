// Lab_11-12.cpp : Створити лінійний односпрямований список з дійсних чисел. Видалити зі списку
// перший елемент менший за модулем 5//

#include <iostream>
#include <iomanip> 
#include <forward_list>
#include <windows.h> 
#include <cmath>

using namespace std;

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    forward_list<double> List = {7.2, 3.0, -4.3, 12.1, -9.8, 10.2};

    cout << "Список чисел: ";
    for (double number : List) {
        cout << setprecision(2) << fixed << number << " ";
    }
    cout << endl;

    // Пошук і видалення першого елемента, модуль якого менший за 5
    auto it = List.begin();
    auto prev = List.before_begin();

    while (it != List.end()) {
        if (abs(*it) < 5) {
            List.erase_after(prev);
            break;
        }
        ++it;
        ++prev;
    }

    cout << "Оновлений список: ";
    for (double number : List) {
        cout << setprecision(2) << fixed << number << " ";
    }
    cout << endl;

    List.clear();
}