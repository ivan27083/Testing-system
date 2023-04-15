#include <iostream>
#include "student.h"
#include "prepod.h"
using namespace std;

/*int main(int argc, char** argv)
{
    setlocale(LC_ALL, "Rus");
    int q;
    bool check = true;
    do {
        cout << "Выберите режим:" << endl << "1 - Режим студента" << endl << "2 - Режим преподавателя" << endl;
        cin >> q;
        switch (q) {
        case 0: check = false; break;
        case 1: student_login();
            continue;
        case 2: prepod_login();
            continue;
        default: cout << "Введено некорректное значение" << endl;
        }
    } while (check);
    return 0;
}*/