#include "student.h"
#include <iostream>
using namespace std;
void menu(){
    string login, password;
    int k;
    cout << "Введите сначала логин, потом пароль " << endl;
    do{
        cin >> login;
        cin >> password;
        if (login != "правильный логин")
            cout << "Доступ запрещен. Введите корректный логин " << endl;
        if (password != "правильный пароль")
            cout << "Доступ запрещен. Введите корректный пароль " << endl;
    }while(login != "правильный логин" || password != "правильный пароль");
    do {
        cout << "Выберите режим 1 - тренинг по теме, 2 - тестирование по теме, 3 - итоговый тест" << endl;
        cin >> k;
        switch (k) {
        case 1: training_test();
            break;
        case 2: theme_test();
            break;
        case 3: exam_test();
            break;
        }
    } while (k < 0 || k>3);
}

void training_test() {
    cout << "Выберите тему: 1 - циклы, массивы"<<endl;
    
}
