#include "student.h"
#include "files.h"
#include <time.h>
#include <string>
using namespace std;

void choice(student& st) {
    int k;
    bool p = true;
    do {
        cout << "Выберите режим\n1 - тренинг по теме\n2 - тестирование по теме\n3 - итоговый тест\n0 - Выход" << endl;
        cin >> k;
        switch (k) {
        case 0: p = false; break;
        case 1: tema_trening(st); break;
        case 2: tema_test(st); break;
        case 3: finish_test(st); break;
        }
    } while (p);
}
void student_login() {
    setlocale(LC_ALL, "Rus");
    system("chcp 1251");
    int l;
    student* arr = new student[1];
    fstream students("students.txt");
    int n = 0;
    while (!students.eof()) {
        append_s(arr, n);
        decode_student(arr[n], students);
        n++;
    }
    string login, password;
    bool flag = true;
    cout << "Авторизация студента: " << endl;
    do {
        cout << "Логин: ";
        cin >> login;
        cout << "Пароль: ";
        cin >> password;
        for (int i = 0; i < n; i++) {
            if (arr[i].login == login && arr[i].password == password) {
                flag = false;
                l = i;
                choice(arr[l]);
            }
        }
        if (flag == true) cout << "Доступ запрещен. Введите корректный логин и пароль" << endl;
    } while (flag);
    students.close();
    fstream studentss("students.txt", ios::out);
    code_student(arr[l], studentss);
    delete[] arr;
    studentss.close();
}

void train(fstream& f, student& st) {
    char zv;
    zv = '*';
    srand(time(NULL));
    quest* q = new quest[1];
    int n = 0;
    while (!f.eof()) {
        append_q(q, n);
        decode_question(q[n], f);
        n++;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            if (q[i].answers[j][q[i].answers[j].size() - 1] == zv) {
                q[i].right_answer = j + 1;
                q[i].answers[j][q[i].answers[j].size() - 1] = NULL;
            }
        }
    }
    int questions_num[10];
    int count = 0;
    bool p = true;
    int answer;
    for (int u = 0; u < 10; u++) questions_num[u] = -1;
    questions_num[0] = rand() % n;
    int k = 1;
    while (k < 10) {
        p = true;
        int r = rand() % 30;
        for (int j = 0; j < 10; j++) if (r == questions_num[j]) p = false;
        if (p) {
            questions_num[k] = r;
            k++;
        }
    }
    for (int i = 0; i < 10; i++) {
        p = true;
        cout << q[questions_num[i]].question << endl;
        for (int j = 0; j < 4; j++) {
            cout << q[questions_num[i]].answers[j] << endl;
        }
        do {
            cout << "Введите ответ на вопрос:";
            cin >> answer;
            if (answer == q[questions_num[i]].right_answer) p = false;
            else cout << "Ответ неверный, попробуйте еще раз " << endl;
        } while (p);
    }
}
void test(fstream& f, student& st, int t) {
    char zv;
    zv = '*';
    int wa = 0;
    srand(time(NULL));
    int wrong[10];
    int mark;
    quest wrong_answers[10];
    quest* q = new quest[1];
    int n = 0;
    while (!f.eof()) {
        append_q(q, n);
        decode_question(q[n], f);
        n++;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            if (q[i].answers[j][q[i].answers[j].size() - 1] == zv) {
                q[i].right_answer = j + 1;
                q[i].answers[j][q[i].answers[j].size() - 1] = NULL;
            }
        }
    }
    int questions_num[10];
    int count = 0;
    bool p = true;
    int answer;
    for (int u = 0; u < 10; u++) questions_num[u] = -1;
    questions_num[0] = rand() % n;
    int k = 1;
    while (k < 10) {
        p = true;
        int r = rand() % 30;
        for (int j = 0; j < 10; j++) if (r == questions_num[j]) p = false;
        if (p) {
            questions_num[k] = r;
            k++;
        }
    }
    for (int i = 0; i < 10; i++) {
        p = true;
        cout << q[questions_num[i]].question << endl;
        for (int j = 0; j < 4; j++) {
            cout << q[questions_num[i]].answers[j] << endl;
        }
        cout << "Введите ответ на вопрос:";
        cin >> answer;
        if (answer == q[questions_num[i]].right_answer) p = false;
        else {
            wa++;
            wrong_answers[i].question = q[questions_num[i]].question;
            for (int j = 0; j < 4; j++) {
                wrong_answers[i].answers[j] = q[questions_num[i]].answers[j];
            }
            wrong_answers[i].right_answer = answer;
            wrong[i] = 1;
        }
    }
    if ((10 - wa) / 10.0 >= 0.85) mark = 5;
    else if ((10 - wa) / 10.0 >= 0.7) mark = 4;
    else if ((10 - wa) / 10.0 >= 0.5) mark = 3;
    else mark = 2;
    cout << endl;
    cout << "Ваша оценка: " << mark << endl;
    cout << "Ошибки: " << endl;
    for (int i = 0; i < 10; i++) {
        if (wrong[i] == 1) {
            cout << wrong_answers[i].question << endl;
            for (int j = 0; j < 4; j++) {
                cout << wrong_answers[i].answers[j] << endl;
            }
            cout << "Ваш ответ: " << wrong_answers[i].right_answer << endl;
            cout << "Правильный ответ: " << q[questions_num[i]].right_answer << endl;
            cout << endl;
        }
    }
    st.marks[t] = mark;
}

void tema_trening(student& st) {
    int k;
    fstream cycles("cycles_hex.txt");
    fstream arrays("arrays_hex.txt");
    fstream lines("lines_hex.txt");
    fstream recursion("recursion_hex.txt");
    fstream sructure("sructure_hex.txt");
    fstream files("files_hex.txt");
    fstream addresses_and_pointers("addresses_and_pointers_hex.txt");
    fstream dynamic_memory("dynamic_memory_hex.txt");
    cout << "Выберите тему: 1 - циклы, 2 - массивы одномерные и двумерные, 3 - строки, 4 - рекурсия, 5 - структуры, 6 - файлы, 7 - адреса и указатели, 8 - динамическая память" << endl;
    do {
        cin >> k;
        if (k != 1 && k != 2 && k != 3 && k != 4 && k != 5 && k != 6 && k != 7 && k != 8)
            cout << "Выберите тему: 1 - циклы, 2 - массивы одномерные и двумерные, 3 - строки, 4 - рекурсия, 5 - структуры, 6 - файлы, 7 - адреса и указатели, 8 - динамическая память" << endl;
    } while (k != 1 && k != 2 && k != 3 && k != 4 && k != 5 && k != 6 && k != 7 && k != 8);
    switch (k) {
    case 1: {train(cycles, st); break; }
    case 2: {train(arrays, st); break; }
    case 3: {train(lines, st); break; }
    case 4: {train(recursion, st); break; }
    case 5: {train(sructure, st); break; }
    case 6: {train(files, st); break; }
    case 7: {train(addresses_and_pointers, st); break; }
    case 8: {train(dynamic_memory, st); break; }
    }
    cycles.close();
    arrays.close();
    lines.close();
    recursion.close();
    sructure.close();
    files.close();
    addresses_and_pointers.close();
    dynamic_memory.close();
}
void tema_test(student& st) {
    int k;
    fstream cycles("cycles_hex.txt");
    fstream arrays("arrays_hex.txt");
    fstream lines("lines_hex.txt");
    fstream recursion("recursion_hex.txt");
    fstream sructure("sructure_hex.txt");
    fstream files("files_hex.txt");
    fstream addresses_and_pointers("addresses_and_pointers_hex.txt");
    fstream dynamic_memory("dynamic_memory_hex.txt");
    cout << "Выберите тему: 1 - циклы, 2 - массивы одномерные и двумерные, 3 - строки, 4 - рекурсия, 5 - структуры, 6 - файлы, 7 - адреса и указатели, 8 - динамическая память" << endl;
    do {
        cin >> k;
        if (k != 1 && k != 2 && k != 3 && k != 4 && k != 5 && k != 6 && k != 7 && k != 8)
            cout << "Выберите тему: 1 - циклы, 2 - массивы одномерные и двумерные, 3 - строки, 4 - рекурсия, 5 - структуры, 6 - файлы, 7 - адреса и указатели, 8 - динамическая память" << endl;
    } while (k != 1 && k != 2 && k != 3 && k != 4 && k != 5 && k != 6 && k != 7 && k != 8);
    switch (k) {
    case 1: {test(cycles, st, k-1); break; }
    case 2: {test(arrays, st, k-1); break; }
    case 3: {test(lines, st, k-1); break; }
    case 4: {test(recursion, st, k-1); break; }
    case 5: {test(sructure, st, k-1); break; }
    case 6: {test(files, st, k-1); break; }
    case 7: {test(addresses_and_pointers, st, k-1); break; }
    case 8: {test(dynamic_memory, st, k-1); break; }
    }
    cycles.close();
    arrays.close();
    lines.close();
    recursion.close();
    sructure.close();
    files.close();
    addresses_and_pointers.close();
    dynamic_memory.close();
}

void finish_test(student &st) {
    char zv;
    int n, k, answer;
    k = 0;
    int mark = 0;
    zv = '*';
    int len[8];
    fstream f;
    int wrong[10];
    int wa = 0;
    quest question[40];
    int prev = -1, cur;
    srand(time(NULL));
    bool p;
    bool questions_num[8][40]{false};
    for (int i = 0; i < 40; i++) {
        p = true;
        do {
            cur = rand() % 8;
        } while (cur == prev);
        switch (cur) {
        case 0: f.open("cycles_hex.txt"); break;
        case 1: f.open("arrays_hex.txt"); break;
        case 2: f.open("lines_hex.txt"); break;
        case 3: f.open("recursion_hex.txt"); break;
        case 4: f.open("structure_hex.txt"); break;
        case 5: f.open("files_hex.txt"); break;
        case 6: f.open("addresses_and_pointers_hex.txt"); break;
        case 7: f.open("dynamic_memory_hex.txt"); break;
        }
        n = 0;
        quest* q = new quest[1];
        while (!f.eof()) {
            append_q(q, n);
            decode_question(q[n], f);
            n++;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 4; j++) {
                if (q[i].answers[j][q[i].answers[j].size() - 1] == zv) {
                    q[i].right_answer = j + 1;
                    q[i].answers[j][q[i].answers[j].size() - 1] = NULL;
                }
            }
        }
        do {
            p = true;
            int r = rand() % n;
            if (questions_num[cur][r] == true) p = false;
            else {
                questions_num[cur][r] = true;
                question[i] = q[r];
            }
        } while (!p);
        prev = cur;
        delete[] q;
        f.close();
    }
    for (int i = 0; i < 40; i++) {
        p = true;
        cout << question[i].question << endl;
        for (int j = 0; j < 4; j++) {
            cout << question[i].answers[j] << endl;
        }
        cout << "Введите ответ на вопрос:";
        cin >> answer;
        if (answer == question[i].right_answer) p = false;
        else wa++;
    }
    if ((40 - wa) / 40.0 >= 0.85) mark = 5;
    else if ((40 - wa) / 40.0 >= 0.7) mark = 4;
    else if ((40 - wa) / 40.0 >= 0.5) mark = 3;
    else mark = 2;
    cout << endl;
    cout << "Количество ошибок: " << wa << endl;
    cout << "Ваша оценка: " << mark << endl;
    st.exam_mark = mark;
}