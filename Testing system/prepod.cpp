﻿#include "Prepod.h"
#include "files.h"
#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
using namespace std;

void otsenki_itog(student* person, int& kolvo_studentov) {
    int v = -1, co = 0, n;
    cout << "\n1)фильтрованный  вывод\n2)не фильтрованный вывод\n0)Выход\n";
    do {
        cout << "\nВведите нужный вариант: ";
        cin >> v;
        if (v < 0 || v > 4) cout << "введено неверное значение. попробуйте снова." << endl;
    } while (v < 0 || v >4);

    switch (v)
    {
    case 0: cout << "\nВыход"; break;
    case 1:
        do {
            cout << "введите оценку: "; cin >> n;
            cout << endl;
        } while (n < 0);
        for (int i = 0; i < kolvo_studentov; i++)
        {
            if (person[i].exam_mark == n) {
                cout << person[i].name << " ";
                cout << person[i].surname << endl;
                cout << "Итоговый тест: ";
                if (person[i].exam_mark <= 0) cout << "тест ещё не был пройден" << endl;
                else { cout << person[i].exam_mark << endl; }
                cout << endl;
                co++;
            }
        }
        if (co == 0) cout << "данная оценка не найдена";
        //student_menu();
        break;
    case 2:
        cout << endl;
        for (int i = 0; i < kolvo_studentov; i++)
        {
            cout << person[i].name << " ";
            cout << person[i].surname << endl;
            cout << "Итоговый тест: ";
            if (person[i].exam_mark <= 0) { cout << "тест ещё не был пройден" << endl; }
            else { cout << person[i].exam_mark << endl; }
            cout << endl;
        }
        //student_menu();
        break;
    }
}

void otsenki_sredn(student* person, int& kolvo_studentov) {
    int v = -1, co = 0;
    double n;
    cout << "\n1)фильтрованный вывод\n2)не фильтрованный  вывод\n0)Выход\n";
    do {
        cout << "\nВведите нужный вариант: ";
        cin >> v;
        if (v < 0 || v > 4) cout << "введено неверное значение. попробуйте снова." << endl;
    } while (v < 0 || v > 4);

    switch (v)
    {
    case 0: cout << "\nВыход"; break;
    case 1:
        do {
            cout << "введите оценку: "; cin >> n;
            cout << endl;
        } while (n < 0);
        n = round(n * 10) / 10;
        for (int i = 0; i < kolvo_studentov; i++)
        {
            if (person[i].sr_mark == n) {
                cout << person[i].name << " ";
                cout << person[i].surname << endl;
                cout << "Средняя оценка: ";
                if (person[i].sr_mark <= 0) { cout << "тест ещё не был пройден" << endl; }
                else { cout << person[i].sr_mark << endl; }
                cout << endl;
                co++;
            }
        }

        if (co == 0) cout << "данная оценка не найдена";
        //student_menu();
        break;
    case 2:
        cout << endl;
        cout << endl;
        for (int i = 0; i < kolvo_studentov; i++)
        {
            cout << person[i].name << " ";
            cout << person[i].surname << endl;
            cout << "Средняя оценка: ";
            if (person[i].sr_mark <= 0) { cout << "тест ещё не был пройден" << endl; }
            else { cout << person[i].sr_mark << endl; }
            cout << endl;
        }

        //student_menu();
        break;
    }
}

void  otsenki_tema(student* person, int& kolvo_studentov) {
    int v = -1, co = 0, n;
    int menu1 = -1;
    cout << "\n1)фильтрованный вывод\n2)не фильтрованный вывод\n0)Выход\n";
    do {
        cout << "\nВведите нужный вариант: ";
        cin >> v;
        if (v < 0 || v > 2) cout << "введено неверное значение. попробуйте снова." << endl;
    } while (v < 0 || v > 2);

    switch (v)
    {
    case 0: cout << "\nВыход"; break;
    case 1:
        cout << "\n\tВыберите тему";
        cout << "\n1)Циклы\n2)Массивы\n3)Строки\n4)Рекурсия\n5)Структуры\n6)Файлы\n7)Адреса и указатели\n8)Динамическая память\n0)Выход\n";
        do {
            cout << "\nВведите нужный вариант: ";
            cin >> menu1;
            if (menu1 < 0 || menu1 > 8) cout << "введено неверное значение. попробуйте снова." << endl;
        } while (menu1 < 0 || menu1>8);

        switch (menu1)
        {
        case 0: cout << "\nВыход"; break;
        case 1:
            do {
                cout << "введите оценку: "; cin >> n;
                cout << endl;
            } while (n < 0);
            for (int i = 0; i < kolvo_studentov; i++)
            {
                if (person[i].marks[0] == n) {
                    cout << person[i].name << " ";
                    cout << person[i].surname << endl;
                    cout << "Циклы: ";
                    if (person[i].marks[0] <= 0) { cout << "тест ещё не был пройден" << endl; }
                    else { cout << person[i].marks[0] << endl; }
                    cout << endl;
                }
            }
            if (co == 0) cout << "данная оценка не найдена";
            //student_menu();
            break;
        case 2:
            do {
                cout << "введите оценку: "; cin >> n;
                cout << endl;
            } while (n < 0);
            for (int i = 0; i < kolvo_studentov; i++)
            {
                if (person[i].marks[1] == n) {
                    cout << person[i].name << " ";
                    cout << person[i].surname << endl;
                    cout << "Массивы: ";
                    if (person[i].marks[1] <= 0) { cout << "тест ещё не был пройден" << endl; }
                    else { cout << person[i].marks[1] << endl; }
                    cout << endl;
                }
            }
            if (co == 0) cout << "данная оценка не найдена";
            //student_menu();
            break;
        case 3: {
            do {
                cout << "введите оценку: "; cin >> n;
                cout << endl;
            } while (n < 0);
            for (int i = 0; i < kolvo_studentov; i++)
            {
                if (person[i].marks[2] == n) {
                    cout << person[i].name << " ";
                    cout << person[i].surname << endl;
                    cout << "Строки: ";
                    if (person[i].marks[2] <= 0) { cout << "тест ещё не был пройден" << endl; }
                    else { cout << person[i].marks[2] << endl; }
                    cout << endl;
                }
            }
            if (co == 0) cout << "данная оценка не найдена";
            //student_menu();
        }
              break;

        case 4:
            do {
                cout << "введите оценку: "; cin >> n;
                cout << endl;
            } while (n < 0);
            for (int i = 0; i < kolvo_studentov; i++)
            {
                if (person[i].marks[3] == n) {
                    cout << person[i].name << " ";
                    cout << person[i].surname << endl;
                    cout << "Рекурсия: ";
                    if (person[i].marks[3] <= 0) { cout << "тест ещё не был пройден" << endl; }
                    else { cout << person[i].marks[3] << endl; }
                    cout << endl;
                }
            }
            if (co == 0) cout << "данная оценка не найдена";
            //student_menu();
            break;
        case 5:
            do {
                cout << "введите оценку: "; cin >> n;
                cout << endl;
            } while (n < 0);
            for (int i = 0; i < kolvo_studentov; i++)
            {
                if (person[i].marks[4] == n) {
                    cout << person[i].name << " ";
                    cout << person[i].surname << endl;
                    cout << "Структуры: ";
                    if (person[i].marks[4] <= 0) { cout << "тест ещё не был пройден" << endl; }
                    else { cout << person[i].marks[4] << endl; }
                    cout << endl;
                }
            }
            if (co == 0) cout << "данная оценка не найдена";
            //student_menu();
            break;
        case 6:
            do {
                cout << "введите оценку: "; cin >> n;
                cout << endl;
            } while (n < 0);
            for (int i = 0; i < kolvo_studentov; i++)
            {
                if (person[i].marks[5] == n) {
                    cout << person[i].name << " ";
                    cout << person[i].surname << endl;
                    cout << "Файлы: ";
                    if (person[i].marks[5] <= 0) { cout << "тест ещё не был пройден" << endl; }
                    else { cout << person[i].marks[5] << endl; }
                    cout << endl;
                }
            }
            if (co == 0) cout << "данная оценка не найдена";
            //student_menu();
            break;
        case 7:
            do {
                cout << "введите оценку: "; cin >> n;
                cout << endl;
            } while (n < 0);
            for (int i = 0; i < kolvo_studentov; i++)
            {
                if (person[i].marks[6] == n) {
                    cout << person[i].name << " ";
                    cout << person[i].surname << endl;
                    cout << "Адреса и указатели: ";
                    if (person[i].marks[6] <= 0) { cout << "тест ещё не был пройден" << endl; }
                    else { cout << person[i].marks[6] << endl; }
                    cout << endl;
                }
            }
            if (co == 0) cout << "данная оценка не найдена";
            //student_menu();
            break;
        case 8:
            do {
                cout << "введите оценку: "; cin >> n;
                cout << endl;
            } while (n < 0);
            for (int i = 0; i < kolvo_studentov; i++)
            {
                if (person[i].marks[7] == n) {
                    cout << person[i].name << " ";
                    cout << person[i].surname << endl;
                    cout << "Динамическая память: ";
                    if (person[i].marks[7] <= 0) { cout << "тест ещё не был пройден" << endl; }
                    else { cout << person[i].marks[7] << endl; }
                    cout << endl;
                }
            }
            if (co == 0) cout << "данная оценка не найдена";
            //student_menu();
            break;
        }
    case 2:
        cout << "\n\tВыберите тему";
        cout << "\n1)Циклы\n2)Массивы\n3)Строки\n4)Рекурсия\n5)Структуры\n6)Файлы\n7)Адреса и указатели\n8)Динамическая память\n0)Выход\n";
        do {
            cout << "\nВведите нужный вариант: ";
            cin >> menu1;
        } while (menu1 < 0 || menu1>3);

        switch (menu1)
        {
        case 0: cout << "\nВыход"; break;
        case 1:
            cout << endl;
            for (int i = 0; i < kolvo_studentov; i++)
            {
                cout << person[i].name << " ";
                cout << person[i].surname << endl;
                cout << "Циклы: ";
                if (person[i].marks[0] <= 0) { cout << "тест ещё не был пройден" << endl; }
                else { cout << person[i].marks[0] << endl; }
                cout << endl;
            }
            break;
        case 2:
            cout << endl;
            for (int i = 0; i < kolvo_studentov; i++)
            {
                cout << person[i].name << " ";
                cout << person[i].surname << endl;
                cout << "Массивы: ";
                if (person[i].marks[1] <= 0) { cout << "тест ещё не был пройден" << endl; }
                else { cout << person[i].marks[1] << endl; }
                cout << endl;
            }
            break;
        case 3:
            cout << endl;
            for (int i = 0; i < kolvo_studentov; i++)
            {
                cout << person[i].name << " ";
                cout << person[i].surname << endl;
                cout << "Строки: ";
                if (person[i].marks[2] <= 0) { cout << "тест ещё не был пройден" << endl; }
                else { cout << person[i].marks[2] << endl; }
                cout << endl;
            }
            break;

        case 4:
            cout << endl;
            for (int i = 0; i < kolvo_studentov; i++)
            {
                cout << person[i].name << " ";
                cout << person[i].surname << endl;
                cout << "Рекурсия: ";
                if (person[i].marks[3] <= 0) { cout << "тест ещё не был пройден" << endl; }
                else { cout << person[i].marks[3] << endl; }
                cout << endl;
            }break;
        case 5:
            cout << endl;
            for (int i = 0; i < kolvo_studentov; i++)
            {
                cout << person[i].name << " ";
                cout << person[i].surname << endl;
                cout << "Структуры: ";
                if (person[i].marks[4] <= 0) { cout << "тест ещё не был пройден" << endl; }
                else { cout << person[i].marks[4] << endl; }
                cout << endl;
            }
            break;
        case 6:
            cout << endl;
            for (int i = 0; i < kolvo_studentov; i++)
            {
                cout << person[i].name << " ";
                cout << person[i].surname << endl;
                cout << "Файлы: ";
                if (person[i].marks[5] <= 0) { cout << "тест ещё не был пройден" << endl; }
                else { cout << person[i].marks[5] << endl; }
                cout << endl;
            }break;
        case 7:
            cout << endl;
            for (int i = 0; i < kolvo_studentov; i++)
            {
                cout << person[i].name << " ";
                cout << person[i].surname << endl;
                cout << "Адреса и указатели: ";
                if (person[i].marks[6] <= 0) { cout << "тест ещё не был пройден" << endl; }
                else { cout << person[i].marks[6] << endl; }
                cout << endl;
            }break;
        case 8:
            cout << endl;
            for (int i = 0; i < kolvo_studentov; i++)
            {
                cout << person[i].name << " ";
                cout << person[i].surname << endl;
                cout << "Динамическая память: ";
                if (person[i].marks[7] <= 0) { cout << "тест ещё не был пройден" << endl; }
                else { cout << person[i].marks[7] << endl; }
                cout << endl;
            } break;

        }
        //student_menu();
        break;
    }
}

void  otsenki_vse(student* person, int& kolvo_studentov) {
    int v = -1, co = 0;
    double n;

    cout << "\n1)фильтрованный  вывод\n2)не фильтрованный  вывод\n0)Выход\n";
    do {
        cout << "\nВведите нужный вариант: ";
        cin >> v;
        if (v < 0 || v > 2) cout << "введено неверное значение. попробуйте снова." << endl;
    } while (v < 0 || v >2);

    switch (v)
    {
    case 0: cout << "\nВыход"; break;
    case 1:
        do {
            cout << "введите оценку: "; cin >> n;
            cout << endl;
        } while (n < 0);
        for (int i = 0; i < kolvo_studentov; i++)
        {
            if (person[i].marks[0] == n) co++;
            if (person[i].marks[1] == n) co++;
            if (person[i].marks[2] == n) co++;
            if (person[i].marks[3] == n) co++;
            if (person[i].marks[4] == n) co++;
            if (person[i].marks[5] == n) co++;
            if (person[i].marks[6] == n) co++;
            if (person[i].marks[7] == n) co++;
            if (person[i].exam_mark == n) co++;
            if (person[i].exam_mark == n) co++;

            if (co == 0) cout << "данная оценка не найдена у студента " << person[i].name << " " << person[i].surname << endl;
            if (co != 0) {
                cout << person[i].name << " ";
                cout << person[i].surname << endl;
                if (person[i].marks[0] == n) {
                    cout << "Циклы: ";
                    if (person[i].marks[0] <= 0) { cout << "тест ещё не был пройден" << endl; }
                    else { cout << person[i].marks[0] << endl; }
                    cout << endl;
                }
                if (person[i].marks[1] == n) {
                    cout << "Массивы: ";
                    if (person[i].marks[1] <= 0) { cout << "тест ещё не был пройден" << endl; }
                    else { cout << person[i].marks[1] << endl; }
                    cout << endl;
                }
                if (person[i].marks[2] == n) {
                    cout << "Строки: ";
                    if (person[i].marks[2] <= 0) { cout << "тест ещё не был пройден" << endl; }
                    else { cout << person[i].marks[2] << endl; }
                    cout << endl;
                }
                if (person[i].marks[3] == n) {
                    cout << "Рекурсия: ";
                    if (person[i].marks[3] <= 0) { cout << "тест ещё не был пройден" << endl; }
                    else { cout << person[i].marks[3] << endl; }
                    cout << endl;
                }
                if (person[i].marks[4] == n) {
                    cout << "Структуры: ";
                    if (person[i].marks[4] <= 0) { cout << "тест ещё не был пройден" << endl; }
                    else { cout << person[i].marks[4] << endl; }
                    cout << endl;
                }
                if (person[i].marks[5] == n) {
                    cout << "Файлы: ";
                    if (person[i].marks[5] <= 0) { cout << "тест ещё не был пройден" << endl; }
                    else { cout << person[i].marks[5] << endl; }
                    cout << endl;
                }
                if (person[i].marks[6] == n) {
                    cout << "Адреса и указатели: ";
                    if (person[i].marks[6] <= 0) { cout << "тест ещё не был пройден" << endl; }
                    else { cout << person[i].marks[6] << endl; }
                    cout << endl;
                }
                if (person[i].marks[7] == n) {
                    cout << "Динамическая память: ";
                    if (person[i].marks[7] <= 0) { cout << "тест ещё не был пройден" << endl; }
                    else { cout << person[i].marks[7] << endl; }
                    cout << endl;
                }
                if (person[i].exam_mark == n) {
                    cout << "Итоговый тест: ";
                    if (person[i].exam_mark <= 0) { cout << "тест ещё не был пройден" << endl; }
                    else { cout << person[i].exam_mark << endl; }
                    cout << endl;
                }
                if (person[i].exam_mark == n) {
                    cout << "средняя оценка: ";
                    if (person[i].sr_mark <= 0) { cout << "тест ещё не был пройден" << endl; }
                    else { cout << person[i].sr_mark << endl; }
                    cout << endl;
                }
            }
        }
        cout << endl;
        if (co == 0) cout << "данная оценка не найдена";
        //student_menu();
        break;

    case 2:
        cout << endl;
        cout << endl;
        cout << endl;
        for (int i = 0; i < kolvo_studentov; i++)
        {
            cout << person[i].name << " ";
            cout << person[i].surname << endl;
            cout << "Циклы: ";
            if (person[i].marks[0] <= 0) { cout << "тест ещё не был пройден" << endl; }
            else { cout << person[i].marks[0] << endl; }
            cout << "Массивы: ";
            if (person[i].marks[1] <= 0) { cout << "тест ещё не был пройден" << endl; }
            else { cout << person[i].marks[1] << endl; }
            cout << "Строки: ";
            if (person[i].marks[2] <= 0) { cout << "тест ещё не был пройден" << endl; }
            else { cout << person[i].marks[2] << endl; }
            cout << "Рекурсия: ";
            if (person[i].marks[3] <= 0) { cout << "тест ещё не был пройден" << endl; }
            else { cout << person[i].marks[3] << endl; }
            cout << "Структуры: ";
            if (person[i].marks[4] <= 0) { cout << "тест ещё не был пройден" << endl; }
            else { cout << person[i].marks[4] << endl; }
            cout << "Файлы: ";
            if (person[i].marks[5] <= 0) { cout << "тест ещё не был пройден" << endl; }
            else { cout << person[i].marks[5] << endl; }
            cout << "Адреса и указатели: ";
            if (person[i].marks[6] <= 0) { cout << "тест ещё не был пройден" << endl; }
            else { cout << person[i].marks[6] << endl; }
            cout << "Динамическая память: ";
            if (person[i].marks[0] <= 0) { cout << "тест ещё не был пройден" << endl; }
            else { cout << person[i].marks[0] << endl; }
            cout << "Итоговый тест: ";
            if (person[i].exam_mark <= 0) { cout << "тест ещё не был пройден" << endl; }
            else { cout << person[i].exam_mark << endl; }
            cout << "прогресс: ";
            if (person[i].sr_mark <= 0) { cout << "тест ещё не был пройден" << endl; }
            else { cout << person[i].sr_mark << endl; }
            cout << endl;
        }
        //student_menu();
        break;
    }
}

void  sort_tema(student* person, int& kolvo_studentov) {
    int menu1 = -1;

    cout << "\n\tВыберите тему";
    cout << "\n1)Циклы\n2)Массивы\n3)Строки\n4)Рекурсия\n5)Структуры\n6)Файлы\n7)Адреса и указатели\n8)Динамическая память\n0)Выход\n";
    do {
        cout << "\nВведите нужный вариант: ";
        cin >> menu1;
        if (menu1 < 0 || menu1 > 8) cout << "введено неверное значение. попробуйте снова." << endl;
    } while (menu1 < 0 || menu1>8);

    switch (menu1)
    {
    case 0: cout << "\nВыход"; break;
    case 1:
        for (int n = 100; n > 0; n--) {
            for (int i = 0; i < kolvo_studentov; i++)
            {
                if (person[i].marks[0] == n) {
                    cout << person[i].name << " ";
                    cout << person[i].surname << endl;
                    cout << "Циклы: ";
                    if (person[i].marks[0] <= 0) { cout << "тест ещё не был пройден" << endl; }
                    else { cout << person[i].marks[0] << endl; }
                }
            }
        }
        //student_menu();
        break;
    case 2:
        for (int n = 100; n > 0; n--) {
            for (int i = 0; i < kolvo_studentov; i++)
            {
                if (person[i].marks[1] == n) {
                    cout << person[i].name << " ";
                    cout << person[i].surname << endl;
                    cout << "Массивы: ";
                    if (person[i].marks[1] <= 0) { cout << "тест ещё не был пройден" << endl; }
                    else { cout << person[i].marks[1] << endl; }
                }
            }
        }
        //student_menu();
        break;
    case 3:
        for (int n = 100; n > 0; n--) {
            for (int i = 0; i < kolvo_studentov; i++)
            {
                if (person[i].marks[2] == n) {
                    cout << person[i].name << " ";
                    cout << person[i].surname << endl;
                    cout << "Строки: ";
                    if (person[i].marks[2] <= 0) { cout << "тест ещё не был пройден" << endl; }
                    else { cout << person[i].marks[2] << endl; }
                }
            }
        }
        //student_menu();
        break;
    case 4:
        for (int n = 100; n > 0; n--) {
            for (int i = 0; i < kolvo_studentov; i++)
            {
                if (person[i].marks[3] == n) {
                    cout << person[i].name << " ";
                    cout << person[i].surname << endl;
                    cout << "Рекурсия: ";
                    if (person[i].marks[3] <= 0) { cout << "тест ещё не был пройден" << endl; }
                    else { cout << person[i].marks[3] << endl; }
                }
            }
        }
        //student_menu();
        break;
    case 5:
        for (int n = 100; n > 0; n--) {
            for (int i = 0; i < kolvo_studentov; i++)
            {
                if (person[i].marks[4] == n) {
                    cout << person[i].name << " ";
                    cout << person[i].surname << endl;
                    cout << "Структуры: ";
                    if (person[i].marks[4] <= 0) { cout << "тест ещё не был пройден" << endl; }
                    else { cout << person[i].marks[4] << endl; }
                }
            }
        }
        //student_menu();
        break;
    case 6:
        for (int n = 100; n > 0; n--) {
            for (int i = 0; i < kolvo_studentov; i++)
            {
                if (person[i].marks[5] == n) {
                    cout << person[i].name << " ";
                    cout << person[i].surname << endl;
                    cout << "Файлы: ";
                    if (person[i].marks[5] <= 0) { cout << "тест ещё не был пройден" << endl; }
                    else { cout << person[i].marks[5] << endl; }
                }
            }
        }
        //student_menu();
        break;
    case 7:
        for (int n = 100; n > 0; n--) {
            for (int i = 0; i < kolvo_studentov; i++)
            {
                if (person[i].marks[6] == n) {
                    cout << person[i].name << " ";
                    cout << person[i].surname << endl;
                    cout << "Адреса и указатели: ";
                    if (person[i].marks[6] <= 0) { cout << "тест ещё не был пройден" << endl; }
                    else { cout << person[i].marks[6] << endl; }
                }
            }
        }
        //student_menu();
        break;
    case 8:
        for (int n = 100; n > 0; n--) {
            for (int i = 0; i < kolvo_studentov; i++)
            {
                if (person[i].marks[7] == n) {
                    cout << person[i].name << " ";
                    cout << person[i].surname << endl;
                    cout << "Динамическая память: ";
                    if (person[i].marks[7] <= 0) { cout << "тест ещё не был пройден" << endl; }
                    else { cout << person[i].marks[7] << endl; }
                }
            }
        }
        //student_menu();
        break;
    }
    //student_menu();
}

void  sort_vse(student* person, int& kolvo_studentov) {

    for (int i = 0; i < kolvo_studentov; i++)
    {
        cout << person[i].name << " ";;
        cout << person[i].surname << endl;
        for (int n = 100; n > 0; n--) {
            if (person[i].marks[0] == n) {
                cout << "Циклы: ";
                cout << person[i].marks[0] << endl;
            }
            if (person[i].marks[1] == n) {
                cout << "Массивы: ";
                cout << person[i].marks[1] << endl;
            }
            if (person[i].marks[2] == n) {
                cout << "Строки: ";
                cout << person[i].marks[2] << endl;
            }
            if (person[i].marks[3] == n) {
                cout << "Рекурсия: ";
                cout << person[i].marks[3] << endl;
            }
            if (person[i].marks[4] == n) {
                cout << "Структуры: ";
                cout << person[i].marks[4] << endl;
            }
            if (person[i].marks[5] == n) {
                cout << "Файлы: ";
                cout << person[i].marks[5] << endl;
            }
            if (person[i].marks[6] == n) {
                cout << "Адреса и указатели: ";
                cout << person[i].marks[6] << endl;
            }
            if (person[i].marks[7] == n) {
                cout << "Динамическая память: ";
                cout << person[i].marks[7] << endl;
            }
            if (person[i].exam_mark == n) {
                cout << "Итоговый тест: ";
                cout << person[i].exam_mark << endl;
            }
            if (person[i].exam_mark == n) {
                cout << "средняя оценка: ";
                cout << person[i].sr_mark << endl;
            }
        }
        cout << endl;
    }
    //student_menu();
}

void  sort_itog(student* person, int& kolvo_studentov) {

    for (int n = 100; n > 0; n--) {
        for (int i = 0; i < kolvo_studentov; i++)
        {
            if (person[i].exam_mark == n) {
                cout << person[i].name << " ";;
                cout << person[i].surname << endl;
                cout << "Итоговый тест: ";
                if (person[i].exam_mark <= 0) { cout << "тест ещё не был пройден" << endl; }
                else { cout << person[i].exam_mark << endl; }
            }
        }
    }
    //student_menu();
}

void del_student(student*& person, int& kolvo_studentov)
{
    int menu = -1, n = -1;
    kolvo_studentov -= 1;
    student* person2 = new student[kolvo_studentov];
    while (n < 1 || n > kolvo_studentov) {
        cout << "Введите номер студента: ";
        cin >> n;
        if (n<1 || n>kolvo_studentov + 1) cout << "Введено некорректное значение" << endl;
    }
    n -= 1;
    for (int i = 0; i < n; i++)
    {
        person2[i] = person[i];
    }
    for (int i = n; i < kolvo_studentov; i++)
    {
        person2[i] = person[i + 1];
    }

    person = new student[kolvo_studentov];
    person = person2;
    cout << "Студент номер " << n + 1 << " удален" << endl;
    //student_menu();
}

void add_student(student*& person, int& kolvo_studentov)
{
    kolvo_studentov += 1;
    student* person2 = new student[kolvo_studentov];
    for (int i = 0; i < kolvo_studentov - 1; i++)
    {
        person2[i] = person[i];
    }
    cout << "\nВведите имя студента: ";
    cin >> person2[kolvo_studentov - 1].name;
    cout << "\nВведите фамилию студента: ";
    cin >> person2[kolvo_studentov - 1].surname;
    cout << "\nВведите логин студента: ";
    cin >> person2[kolvo_studentov - 1].login;
    cout << "\nВведите пароль студента: ";
    cin >> person2[kolvo_studentov - 1].password;
    for (int j = 0; j < 8; j++)
    {
        person2[kolvo_studentov - 1].marks[j] = -1;
    }
    person2[kolvo_studentov - 1].exam_mark = -1;/////////////////////не забыть убрать 20
    person2[kolvo_studentov - 1].sr_mark = 2.5;

    person = new student[kolvo_studentov];
    person = person2;
    cout << "Студент " << person2[kolvo_studentov - 1].surname << "  " << person2[kolvo_studentov - 1].name << " зарегистрирован" << endl;
    //student_menu();
}

void  sort_sredn(student* person, int& kolvo_studentov) {

    for (double n = 5; n > 0; n -= 0.1) {
        n = round(n * 10) / 10;
        for (int i = 0; i < kolvo_studentov; i++)
        {
            if (person[i].sr_mark == n) {
                cout << person[i].name << " ";
                cout << person[i].surname << endl;
                cout << "Средний результат: ";
                if (person[i].sr_mark <= 0) { cout << "тест ещё не был пройден" << endl; }
                else { cout << person[i].sr_mark << endl; }
            }
        }
    }
    //student_menu();
}

void student_menu() {
    int kolvo_studentov = 3;//нужно передать из файла
    int menu = -1, menu1 = -1, menu2 = -1;
    student* person = new student[kolvo_studentov];//массив со структурой
    {
        person[0].name = "Олег";
        person[0].surname = "Волков";
        person[0].login = "kugtduf";
        person[0].password = "764487";
        person[0].marks[0] = 21;
        person[0].marks[1] = 11;
        person[0].marks[2] = 31;
        person[0].marks[3] = 0;
        person[0].marks[4] = 5;
        person[0].marks[5] = 61;
        person[0].marks[6] = 71;
        person[0].marks[7] = 81;
        person[0].exam_mark = 47;
        person[0].sr_mark = 4.1;

        person[1].name = "Сергей";
        person[1].surname = "Разумовский";
        person[1].login = "srjnrjry";
        person[1].password = "36573457";
        person[1].marks[0] = 12;
        person[1].marks[1] = 32;
        person[1].marks[2] = 22;
        person[1].marks[3] = 0;
        person[1].marks[4] = 5;
        person[1].marks[5] = 62;
        person[1].marks[6] = 72;
        person[1].marks[7] = 82;
        person[1].exam_mark = 48;
        person[1].sr_mark = 4.8;


        person[2].name = "Игорь";
        person[2].surname = "Гром";
        person[2].login = "rshgfhf";
        person[2].password = "245767";
        person[2].marks[0] = 13;
        person[2].marks[1] = 23;
        person[2].marks[2] = 33;
        person[2].marks[3] = 43;
        person[2].marks[4] = 5;
        person[2].marks[5] = 73;
        person[2].marks[6] = 63;
        person[2].marks[7] = 83;
        person[2].exam_mark = 49;
        person[2].sr_mark = 3.2;


        cout << "СПИСОК СТУДЕНТОВ" << endl;
        for (int i = 0; i < kolvo_studentov; i++)
        {
            cout << endl << i + 1 << endl;
            cout << person[i].name << endl;
            cout << person[i].surname << endl;
            cout << person[i].marks[0] << endl;
            cout << person[i].marks[1] << endl;
            cout << person[i].marks[2] << endl;
            cout << person[i].marks[3] << endl;
            cout << person[i].marks[4] << endl;
            cout << person[i].marks[5] << endl;
            cout << person[i].marks[6] << endl;
            cout << person[i].marks[7] << endl;
            cout << person[i].exam_mark << endl;
            cout << person[i].exam_mark << endl;
            cout << "sr znach=" << person[i].sr_mark << endl;
            cout << endl << endl;
        }
    }
    while (menu != 0) {
        cout << "\n\tРабота со списком студентов";
        cout << "\n1)Удаление студентов\n2)Регистрация студентов\n3)Вывод с сортировкой \n4)Вывод списка студентов с оценками по категориям\n0)Выход\n";

        menu = -1;
        do {
            cout << "\nВведите нужный вариант: ";
            cin >> menu;
            if (menu < 0 || menu > 4) cout << "введено неверное значение. попробуйте снова." << endl;
        } while (menu < 0 || menu > 4);

        switch (menu)
        {
        case 0: cout << "\nВыход"; break;
        case 1: del_student(person, kolvo_studentov);
            /////////////////////////////////
            for (int i = 0; i < kolvo_studentov; i++)
            {
                cout << endl << i + 1 << endl;
                cout << person[i].name << endl;
                cout << person[i].surname << endl;
                cout << person[i].marks[0] << endl;
                cout << person[i].marks[1] << endl;
                cout << person[i].marks[2] << endl;
                cout << person[i].marks[3] << endl;
                cout << person[i].marks[4] << endl;
                cout << person[i].marks[5] << endl;
                cout << person[i].marks[6] << endl;
                cout << person[i].marks[7] << endl;
                cout << person[i].exam_mark << endl;
                cout << person[i].exam_mark << endl;
                cout << "sr znach=" << person[i].sr_mark << endl;
                cout << endl << endl;
            }

            break;
        case 2: add_student(person, kolvo_studentov);
            ///////////////////////////////////////////
            for (int i = 0; i < kolvo_studentov; i++)
            {
                cout << endl << i + 1 << endl;
                cout << person[i].name << endl;
                cout << person[i].surname << endl;
                cout << person[i].marks[0] << endl;
                cout << person[i].marks[1] << endl;
                cout << person[i].marks[2] << endl;
                cout << person[i].marks[3] << endl;
                cout << person[i].marks[4] << endl;
                cout << person[i].marks[5] << endl;
                cout << person[i].marks[6] << endl;
                cout << person[i].marks[7] << endl;
                cout << person[i].exam_mark << endl;
                cout << person[i].exam_mark << endl;
                cout << "sr znach=" << person[i].sr_mark << endl;
                cout << endl << endl;
            }


            break;
        case 3:
            cout << "\n\tВывод рейтинга студентов";
            cout << "\n1)по всем темам\n2)по конктретной теме \n3)только итоговый тест\n4) только средний балл\n0)Выход\n";
            do {
                cout << "\nВведите нужный вариант: ";
                cin >> menu2;
                if (menu < 0 || menu > 4) cout << "введено неверное значение. попробуйте снова." << endl;
            } while (menu2 < 0 || menu2>4);

            switch (menu2)
            {
            case 0: cout << "\nВыход"; break;
            case 1: sort_vse(person, kolvo_studentov); break;
            case 2: sort_tema(person, kolvo_studentov); break;
            case 3: sort_itog(person, kolvo_studentov); break;
            case 4: sort_sredn(person, kolvo_studentov); break;
            }
        case 4:
            cout << "\n\tВывод оценок студентов";
            cout << "\n1)по всем темам\n2)по конктретной теме \n3)только итоговый тест \n4) только средний балл\n0)Выход\n";
            do {
                cout << "\nВведите нужный вариант";
                cin >> menu1;
                if (menu < 0 || menu > 4) cout << "введено неверное значение. попробуйте снова." << endl;
            } while (menu1 < 0 || menu1>4);

            switch (menu1)
            {
            case 0: cout << "\nВыход"; break;
            case 1: otsenki_vse(person, kolvo_studentov); break;
            case 2: otsenki_tema(person, kolvo_studentov); break;
            case 3: otsenki_itog(person, kolvo_studentov); break;
            case 4: otsenki_sredn(person, kolvo_studentov);  break;
            }
        }
    }
}

void delete_question(quest*& vopros, int& kolvo_voprosov)
{
    kolvo_voprosov -= 1;
    quest* vopros2 = new quest[kolvo_voprosov];
    int v = 0, i = 0;
    while (v<1 || v>kolvo_voprosov + 1)
    {
        cout << "Введите номер вопроса, который нужно удалить: ";
        cin >> v;
        if (v<1 || v>kolvo_voprosov + 1)
            cout << "Введено некорректное значение" << endl;
    }
    v -= 1;
    for (i = 0; i < v; i++)
    {
        vopros2[i] = vopros[i];
    }
    for (i = v; i < kolvo_voprosov; i++)
    {
        vopros2[i] = vopros[i + 1];
    }

    vopros = new quest[kolvo_voprosov];
    vopros = vopros2;
    cout << "Вопрос " << v + 1 << " удален." << endl;

}

void add_question(quest*& vopros, int& kolvo_voprosov)
{
    int k = -1;
    string sque, s, s2;
    kolvo_voprosov += 1;
    quest* vopros2 = new quest[kolvo_voprosov];
    for (int i = 0; i < kolvo_voprosov - 1; i++)
    {
        vopros2[i] = vopros[i];
    }
    cin.seekg(cin.eof());
    cout << "\nВведите вопрос, который нужно добавить: ";
    getline(cin, sque);
    vopros2[kolvo_voprosov - 1].question = '№' + to_string(kolvo_voprosov) + sque;

    for (int i = 0; i < 4; i++)
    {
        cout << "\nВведите ответ номер " << i + 1 << ": ";
        getline(cin, s);
        s2 = to_string(i + 1) + ')';
        vopros2[kolvo_voprosov - 1].answers[i] = s2 + s;

    }

    while (k<1 || k>kolvo_voprosov)
    {
        cout << "Введите номер правильного ответа: ";
        cin >> k;
        if (k<1 || k>kolvo_voprosov) cout << "Введено некорректное значение" << endl;
    }
    k -= 1;
    vopros2[kolvo_voprosov - 1].answers[k] += '*';
    //vopros = NULL;
    vopros = new quest[kolvo_voprosov];
    for (int i = 0; i < kolvo_voprosov; i++)
    {
        vopros[i] = vopros2[i];
    }
    cout << "Вопрос добавлен." << endl;

}

void change_question(quest* vopros, int& kolvo_voprosov)
{
    string s, s2, sque;
    int v = 0, k = -1;
    while (v<1 || v>kolvo_voprosov)
    {
        cout << "Введите номер вопроса, который нужно заменить: ";
        cin >> v;
        if (v<1 || v>kolvo_voprosov)
            cout << "Введено некорректное значение" << endl;
    }
    cin.seekg(cin.eof());
    cout << "\nВведите измененный вопрос: ";
    getline(cin, sque);
    vopros[v - 1].question = '№' + to_string(v) + sque;
    for (int i = 0; i < 4; i++)
    {
        cout << "\nВведите ответ номер " << i + 1 << ": ";
        getline(cin, s);
        s2 = to_string(i + 1) + ')';
        vopros[v - 1].answers[i] = s2 + s;
    }
    while (k<1 || k>kolvo_voprosov)
    {
        cout << "Введите номер правильного ответа: ";
        cin >> k;
        if (k<1 || k>kolvo_voprosov) cout << "Введено некорректное значение" << endl;
    }
    k -= 1;
    vopros[v - 1].answers[k] += '*';
    cout << "Вопрос изменен." << endl;

}

void question_menu()
{
    int kolvo_voprosov = 3;//нужно передать из файла
    int menu = -1, menu1 = -1;
    quest* vopros = new quest[kolvo_voprosov];//массив со структурой

    vopros[0].question = "№1lalal?";
    vopros[0].answers[0] = "1)da";
    vopros[0].answers[1] = "2)net";
    vopros[0].answers[2] = "3)maybe";
    vopros[0].answers[3] = "4)sure*";

    vopros[1].question = "№2geeergerreg ergegrg?";
    vopros[1].answers[0] = "1)rrr rr";
    vopros[1].answers[1] = "2)neeeeet*";
    vopros[1].answers[2] = "3)maybrrrrre";
    vopros[1].answers[3] = "4)surwwwwwwwe";

    vopros[2].question = "№3l l l l l?";
    vopros[2].answers[0] = "1)e233*";
    vopros[2].answers[1] = "2)да";
    vopros[2].answers[2] = "3)нет";
    vopros[2].answers[3] = "4)может быть";

    while (menu1 < 0 || menu1>8)
    {
        cout << "\nМЕНЮ ТЕМ\n";
        cout << "\n1)Циклы\n2)Массивы\n3)Строки\n4)Рекурсия\n5)Структуры\n6)Файлы\n7)Адреса и указатели\n8)Динамическая память\n0)Выход\n";
        cout << "Введите номер темы вопроса: ";
        cin >> menu1;
        if (menu1 < 0 || menu1>8) cout << "\nВведено некорректное значение\n" << endl;
    }
    switch (menu1)
    {
    case 0: cout << "Выход из меню" << endl; break;
    case 1: break;//Циклы
    case 2: break;//Массивы
    case 3: break;//Строки
    case 4: break;//Рекурсия
    case 5: break;//Структуры
    case 6: break;//Файлы
    case 7: break;//Адреса и указатели
    case 8: break;//Динамическая память
    }
    if (menu1 != 0) {
        while (menu != 0) {
            menu = -1;
            while (menu < 0 || menu>3)
            {
                cout << "\nМЕНЮ\n" << endl;
                cout << "1)Удаление вопросов" << endl;
                cout << "2)Добавление вопросов" << endl;
                cout << "3)Изменение вопросов" << endl;
                cout << "0)Выход в меню тем" << endl;
                cout << "Введите номер нужного варианта: ";
                cin >> menu;
            }
            switch (menu)
            {
            case 0: cout << "Выход в меню тем" << endl; question_menu(); break;
            case 1: delete_question(vopros, kolvo_voprosov);
                for (int i = 0; i < kolvo_voprosov; i++)
                {
                    cout << vopros[i].question << endl;
                    cout << vopros[i].answers[0] << endl;
                    cout << vopros[i].answers[1] << endl;
                    cout << vopros[i].answers[2] << endl;
                    cout << vopros[i].answers[3] << endl;
                    cout << endl;
                }break;
            case 2: add_question(vopros, kolvo_voprosov);
                for (int i = 0; i < kolvo_voprosov; i++)
                {
                    cout << vopros[i].question << endl;
                    cout << vopros[i].answers[0] << endl;
                    cout << vopros[i].answers[1] << endl;
                    cout << vopros[i].answers[2] << endl;
                    cout << vopros[i].answers[3] << endl;
                    cout << endl;
                }break;
            case 3: change_question(vopros, kolvo_voprosov);
                for (int i = 0; i < kolvo_voprosov; i++)
                {
                    cout << vopros[i].question << endl;
                    cout << vopros[i].answers[0] << endl;
                    cout << vopros[i].answers[1] << endl;
                    cout << vopros[i].answers[2] << endl;
                    cout << vopros[i].answers[3] << endl;
                    cout << endl;
                }break;
            }
        }

    }
}

//студенты или вопросы
void choice() {
    int k = -1;
    while (k != 0) {
        while (k < 0 || k>2)
        {
            cout << "\nМЕНЮ\n" << endl;
            cout << "1)Вопросы\n2)Студенты\n0)Выход" << endl;
            cout << "Введите номер нужного варианта: ";
            cin >> k;
            if (k < 0 || k>2) cout << "Введено некорректное значение." << endl;
        }
        switch (k) {
        case 0: {cout << "Выход из меню" << endl; break; }
        case 1: {question_menu(); break; }
        case 2: {student_menu(); break; }
        }
    }
}

//вход в учётную запись
struct person
{
    string login;
    string parol;
};

void prepod_login()
{
    setlocale(LC_ALL, "rus");
    struct person logpar[10];
    int co = 0, menu, n = 3, y = 0;
    string login, parol;

    logpar[0].login = "s";
    logpar[0].parol = "a";
    logpar[1].login = "erdhhdy";
    logpar[1].parol = "e567438";
    logpar[2].login = "liadha";
    logpar[2].parol = "l334675";

    cout << "\nДобро пожаловать\nВведите логин: "; cin >> login;
    for (int i = 0; i < n; i++) if (logpar[i].login != login) y++;
    if (y == n) cout << "\n логин не найден " << endl;
    else {
        cout << "\nВведите пароль: "; cin >> parol;
        for (int i = 0; i < n; i++) {
            if (logpar[i].login == login && logpar[i].parol == parol)
            {
                choice();
            }
            else if (logpar[i].login == login && logpar[i].parol != parol) { cout << "\n пароль не верный" << endl; }
        }

    }
}
