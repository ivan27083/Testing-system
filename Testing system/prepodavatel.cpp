#include "Prepod.h"
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
    int  n = -1;
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
    person2[kolvo_studentov - 1].exam_mark = -1;
    person2[kolvo_studentov - 1].sr_mark = -1;

    person = new student[kolvo_studentov];
    person = person2;
    cout << "Студент " << person2[kolvo_studentov - 1].surname << "  " << person2[kolvo_studentov - 1].name << " зарегистрирован" << endl;
    //student_menu();
}

void sort_sredn(student* person, int& kolvo_studentov) {

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

void change_progress(student*& person, int& kolvo_studentov)
{
    int menu = -1, n = -1, mark = -2;
    //student* person2 = new student[kolvo_studentov];
    while (n < 1 || n > kolvo_studentov) {
        cout << "Введите номер студента: ";
        cin >> n;
        if (n<1 || n>kolvo_studentov + 1) cout << "Введено некорректное значение" << endl;
    }
    while (menu < 0 || menu>10)
    {
        cout << "\nЧто требуется изменить в прогрессе?" << endl;
        cout << "1)Оценка по теме циклы\n2)Оценка по теме массивы\n3)Оценка по теме строки\n4)Оценка по теме рекурсия\n5)Оценка по теме структуры\n6)Оценка по теме файлы\n7)Оценка по теме адреса и указатели\n8)Оценка по теме динамическая память\n9)Оценка за итоговый тест\n10)Прогресс студента\n0)Выход\n";
        cout << "Введите номер нужного варианта: ";
        cin >> menu;
        if (menu < 0 || menu>10) cout << "\nВведено некорректное значение\n" << endl;
    }
    if (menu == 0) { cout << "Выход и меню\n";}
    if (menu < 8 && menu>0)
    {
        cout << "Текущая оценка " << person[n - 1].name << " " << person[n - 1].surname << ": " << person[n - 1].marks[menu] << endl;
        while (mark < -1 || mark>5)
        {
            cout << "Введите новое значение (от -1, если тест нужно считать не пройденным, до 5): ";
            cin >> mark;
            if (mark < -1 || mark>5) cout << "\nВведено некорректное значение\n" << endl;
        }
        person[n - 1].marks[menu] = mark;
        cout << "Новая оценка " << person[n - 1].name << " " << person[n - 1].surname << ": " << person[n - 1].marks[menu] << endl;
    }
    if (menu == 9)
    {
        cout << "Текущая оценка " << person[n - 1].name << " " << person[n - 1].surname << ": " << person[n - 1].exam_mark << endl;
        while (mark < -1 || mark>5)
        {
            cout << "Введите новое значение (от -1, если тест нужно считать не пройденным, до 5): ";
            cin >> mark;
            if (mark < -1 || mark>5) cout << "\nВведено некорректное значение\n" << endl;
        }
        person[n - 1].exam_mark = mark;
        cout << "Новая оценка " << person[n - 1].name << " " << person[n - 1].surname << ": " << person[n - 1].exam_mark << endl;
    }
    /*if (menu == 10)
    {
        cout << "Текущая оценка " << person[n - 1].name << " " << person[n - 1].surname << ": " << person[n - 1].progress << endl;
        while (mark < -1 || mark>40)
        {
            cout << "Введите новое значение (от -1, если тест нужно считать не пройденным, до 40): ";
            cin >> mark;
            if (mark < -1 || mark>40) cout << "\nВведено некорректное значение\n" << endl;
        }
        person[n - 1].progress = mark;
        cout << "Новый показатель " << person[n - 1].name << " " << person[n - 1].surname << ": " << person[n - 1].progress << endl;
    }*/
}

void student_menu() {
    system("chcp 1251");
    int kolvo_studentov = 0;//нужно передать из файла
    int menu = -1, menu1 = -1, menu2 = -1;
    student* person = new student[1];//массив со структурой
    fstream students("students.txt");
    while (!students.eof()) {
        append_s(person, kolvo_studentov);
        decode_student(person[kolvo_studentov], students);
        kolvo_studentov++;
    }
    while (menu != 0)
    {
        cout << "\n\tРабота со списком студентов";
        cout << "\n1)Удаление студентов\n2)Регистрация студентов\n3)Вывод с сортировкой \n4)Вывод списка студентов с оценками по категориям\n5)Изменение прогресса студента\n0)Выход\n";

        menu = -1;
        do {
            cout << "\nВведите нужный вариант: ";
            cin >> menu;
            if (menu < 0 || menu > 5) cout << "Введено неверное значение. Попробуйте снова." << endl;
        } while (menu < 0 || menu > 5);

        switch (menu)
        {
        case 0: cout << "\nВыход\n"; break;
        case 1: { del_student(person, kolvo_studentov);
            break;}
        case 2: {add_student(person, kolvo_studentov);
            break;}
        case 3: {cout << "\n\tВывод рейтинга студентов";
            cout << "\n1)по всем темам\n2)по конктретной теме \n3)только итоговый тест\n4)только средний балл\n0)Выход\n";
            do {
                cout << "\nВведите нужный вариант: ";
                cin >> menu2;
                if (menu < 0 || menu > 4) cout << "Введено неверное значение. Попробуйте снова." << endl;
            } while (menu2 < 0 || menu2>4);

            switch (menu2)
            {
            case 0: cout << "\nВыход"; break;
            case 1: sort_vse(person, kolvo_studentov); break;
            case 2: sort_tema(person, kolvo_studentov); break;
            case 3: sort_itog(person, kolvo_studentov); break;
            case 4: sort_sredn(person, kolvo_studentov); break;
            }}
        case 4: {
            cout << "\n\tВывод оценок студентов";
            cout << "\n1)по всем темам\n2)по конктретной теме \n3)только итоговый тест \n4) только средний балл\n0)Выход\n";
            do {
                cout << "\nВведите нужный вариант";
                cin >> menu1;
                if (menu < 0 || menu > 4) cout << "Введено неверное значение. Попробуйте снова." << endl;
            } while (menu1 < 0 || menu1>4);

            switch (menu1)
            {
            case 0: cout << "\nВыход"; break;
            case 1: otsenki_vse(person, kolvo_studentov); break;
            case 2: otsenki_tema(person, kolvo_studentov); break;
            case 3: otsenki_itog(person, kolvo_studentov); break;
            case 4: otsenki_sredn(person, kolvo_studentov);  break;
            }
            break;}
        case 5: change_progress(person, kolvo_studentov); break;

        }

        students.close();
        if (menu != 0) {

            fstream studentt("students.txt", ios::out);
            for (int i = 0;i < kolvo_studentov;i++)
            {
                code_student(person[i], studentt);
                if (i != kolvo_studentov - 1) studentt << '\n';
            }
            studentt.close();
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
    system("chcp 1251");
    fstream vopros1("cycles_hex.txt");
    fstream vopros2("arrays_hex.txt");
    fstream vopros3("lines_hex.txt");
    fstream vopros4("recursion_hex.txt");
    fstream vopros5("structure_hex.txt");
    fstream vopros6("files_hex.txt");
    fstream vopros7("addresses_and_pointers_hex.txt");
    fstream vopros8("dynamic_memory_hex.txt");
    int kolvo_voprosov;//нужно передать из файла
    int menu = -1, menu1 = -1;
    quest* vopros = new quest[1];//массив со структурой
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
    case 1:
        kolvo_voprosov = 0;
        while (!vopros1.eof()) {
            append_q(vopros, kolvo_voprosov);
            decode_question(vopros[kolvo_voprosov], vopros1);
            kolvo_voprosov++;
        }
        break;//Циклы
    case 2:
        kolvo_voprosov = 0;
        while (!vopros2.eof()) {
            append_q(vopros, kolvo_voprosov);
            decode_question(vopros[kolvo_voprosov], vopros2);
            kolvo_voprosov++;
        }break;//Массивы
    case 3:
        kolvo_voprosov = 0;
        while (!vopros3.eof()) {
            append_q(vopros, kolvo_voprosov);
            decode_question(vopros[kolvo_voprosov], vopros3);
            kolvo_voprosov++;
        }break;//Строки
    case 4:
        kolvo_voprosov = 0;
        while (!vopros4.eof()) {
            append_q(vopros, kolvo_voprosov);
            decode_question(vopros[kolvo_voprosov], vopros4);
            kolvo_voprosov++;
        }break;//Рекурсия
    case 5:
        kolvo_voprosov = 0;
        while (!vopros5.eof()) {
            append_q(vopros, kolvo_voprosov);
            decode_question(vopros[kolvo_voprosov], vopros5);
            kolvo_voprosov++;
        }break;//Структуры
    case 6:
        kolvo_voprosov = 0;
        while (!vopros6.eof()) {
            append_q(vopros, kolvo_voprosov);
            decode_question(vopros[kolvo_voprosov], vopros6);
            kolvo_voprosov++;
        }break;//Файлы
    case 7:
        kolvo_voprosov = 0;
        while (!vopros7.eof()) {
            append_q(vopros, kolvo_voprosov);
            decode_question(vopros[kolvo_voprosov], vopros7);
            kolvo_voprosov++;
        }break;//Адреса и указатели
    case 8:
        kolvo_voprosov = 0;
        while (!vopros8.eof()) {
            append_q(vopros, kolvo_voprosov);
            decode_question(vopros[kolvo_voprosov], vopros8);
            kolvo_voprosov++;
        }break;//Динамическая память
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
                break;
            case 2: add_question(vopros, kolvo_voprosov);
               break;
            case 3: change_question(vopros, kolvo_voprosov);
                break;
            }
        }
        vopros1.close();
        vopros2.close();
        vopros3.close();
        vopros4.close();
        vopros5.close();
        vopros6.close();
        vopros7.close();
        vopros8.close();

        fstream v;

        switch (menu1)
        {
        case 1:
            v.open("cycles_hex.txt", ios::out);
            for (int i = 0;i < kolvo_voprosov;i++)
            {
                code_question(vopros[i], v);
                if (i!=kolvo_voprosov-1)v << '\n';
            }
            break;//Циклы
        case 2:
            v.open("arrays_hex.txt", ios::out);
            for (int i = 0;i < kolvo_voprosov;i++)
            {
                code_question(vopros[i], v);
                if (i != kolvo_voprosov - 1)v << '\n';
            }
            break;//Массивы
        case 3:
            v.open("lines_hex.txt", ios::out);
            for (int i = 0;i < kolvo_voprosov;i++)
            {
                code_question(vopros[i], v);
                if (i != kolvo_voprosov - 1)v << '\n';
            }
            break;//Строки
        case 4:
            v.open("recursion_hex.txt", ios::out);
            for (int i = 0;i < kolvo_voprosov;i++)
            {
                code_question(vopros[i], v);
                if (i != kolvo_voprosov - 1)v << '\n';
            }
            break;//Рекурсия
        case 5:
            v.open("structure_hex.txt", ios::out);
            for (int i = 0;i < kolvo_voprosov;i++)
            {
                code_question(vopros[i], v);
                if (i != kolvo_voprosov - 1)v << '\n';
            }
            break;//Структуры
        case 6:
            v.open("files_hex.txt", ios::out);
            for (int i = 0;i < kolvo_voprosov;i++)
            {
                code_question(vopros[i], v);
                if (i != kolvo_voprosov - 1)v << '\n';
            }
            break;//Файлы
        case 7:
            v.open("addresses_and_pointers_hex.txt", ios::out);
            for (int i = 0;i < kolvo_voprosov;i++)
            {
                code_question(vopros[i], v);
                if (i != kolvo_voprosov - 1)v << '\n';
            }
            break;//Адреса и указатели
        case 8:
            v.open("dynamic_memory_hex.txt", ios::out);
            for (int i = 0;i < kolvo_voprosov;i++)
            {
                code_question(vopros[i], v);
                if (i != kolvo_voprosov - 1)v << '\n';
            }
            break;//Динамическая память
        }
        v.close();
    }
}

//студенты или вопросы
void choice() {
    int k = -1;
    
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

    logpar[0].login = "admin";
    logpar[0].parol = "admin";
    logpar[1].login = "erdhhdy";
    logpar[1].parol = "e567438";
    logpar[2].login = "liadha";
    logpar[2].parol = "l334675";


    cout << "\nДобро пожаловать\nВведите логин: "; cin >> login;
    for (int i = 0; i < n; i++) if (logpar[i].login != login) y++;
    if (y == n) cout << "\nЛогин не найден!" << endl;
    else {
        cout << "Введите пароль: "; cin >> parol;
        for (int i = 0; i < n; i++) {
            if (logpar[i].login == login && logpar[i].parol == parol)
            {
                choice();
            }
            else if (logpar[i].login == login && logpar[i].parol != parol) { cout << "\nПароль не верный!" << endl; }
        }

    }
}
