#include "student.h"
using namespace std;
struct quest {
    string question;
    string answers[4];
};
struct student {
    string login;
    string password;
    int marks[8];
    int exam_mark;
    double sr_mark;
};
void choice(student st){
    int k;
    cout << "Выберите режим 1-тренинг по теме, 2 - тестирование по теме, 3 - итоговый тест" << endl;
    cin >> k;
    switch(k){
        case 1: {tema_trening(st); break;}
        case 2: {tema_test(st); break;}
        case 3: {finish_test(); break;}
    }
}
void menu(){
    int l;
    student arr[100];
    student st1;
    st1.login = "АннаКлековкина";
    st1.password = "12345";
    arr[0] = st1;
    student st2;
    st2.login = "ВаняСемин";
    st2.password = "12345";
    arr[1] = st2;
    string login, password;
    bool flag = true;
    cout << "Введите сначала логин, потом пароль " << endl;
    do{
        cin >> login;
        cin >> password;
        for (int i = 0; i < 100;i++){
            if (arr[i].login == login && arr[i].password == password ){
                flag = false;
                l = i;
                choice(arr[l]);
            }
        }
        cout << "Доступ запрещен. Введите корректный логин и пароль" << endl;
    }while(flag);
}

void train(string name, student st){
    string que, ans1 ,ans2, ans3 ,ans4, t;
    quest wrong_answers[10];
    char zv;
    int n, k, answer;
    k = 0;
    zv = '*';
    quest St1;
    St1.question = "Вопрос";
    St1.answers[0] = "Ответ 1";
    St1.answers[1] = "Ответ 2";
    St1.answers[2] = "Ответ 3";
    St1.answers[3] = "Ответ 4";
    quest St2;
    St2.question = "Вопрос 2";
    St2.answers[0] = "Ответ 21";
    St2.answers[1]= "Ответ 22 *";
    St2.answers[2] = "Ответ 23";
    St2.answers[3] = "Ответ 24";
    quest St3;
    St3.question = "Вопрос 3";
    St3.answers[0] = "Ответ 13";
    St3.answers[1] = "Ответ 23*";
    St3.answers[2] = "Ответ 33";
    St3.answers[3] = "Ответ 43";
    quest St4;
    St4.question = "Вопрос 4";
    St4.answers[0] = "Ответ 41";
    St4.answers[1]= "Ответ 42 *";
    St4.answers[2] = "Ответ 43";
    St4.answers[3] = "Ответ 44";
    quest arr[30];
    arr[0] = St1;
    arr[1] = St2;
    arr[2] = St3;
    arr[3] = St4;
    int questions_num[10];
    int count = 0;
    for (int u =0; u < 10; u++)
        questions_num[u] = -1;
    for (int i = 0; i < 3; i++){
        do{
            count = 0;
            n = rand() % 4;
            for (int h = 0; h < 10 ; h++){
                //cout << questions_num[h] << endl;
//                cout << n;
                if (n == questions_num[h]) count++;}
            }while(count > 0);
        //n = rand() % 4;
        questions_num[i] = n;
        que = arr[n].question;
        for (int j = 0; j < 4; j++){
            t = arr[n].answers[j];
            for(int l = 0; l < size(t);l++){
                char  h = t[l];
                if (h == zv){
                    k = j + 1;
                    arr[n].answers[j].resize(arr[n].answers[j].size() - 1);
                }
            }
        }
        ans1 = arr[n].answers[0];
        ans2 = arr[n].answers[1];
        ans3 = arr[n].answers[2];
        ans4 = arr[n].answers[3];
        cout << que << endl;
        cout << ans1 << endl;
        cout << ans2 << endl;
        cout << ans3 << endl;
        cout << ans4 << endl;
        cout << "Введите ответ на вопрос" << endl;
        do{
            cin >> answer;
            if (answer != k) cout << "Попробуйте еще раз "<<endl;
        }while(answer != k);
//        if (answer != k){
//            cout << ""
//            answers[wa] = answer;
//            right_answers[wa] = k;
//            wa++;
//        }
    }
    choice(st);
}
void test(string name, student st){
    string que, ans1 ,ans2, ans3 ,ans4, t;
    quest wrong_answers[10];
    int answers[10];
    int right_answers[10];
    char zv;
    int n, k, answer;
    k = 0;
    int len = 0;
    int mark = 0;
    zv = '*';
    quest St1;
    St1.question = "Вопрос";
    St1.answers[0] = "Ответ 1";
    St1.answers[1] = "Ответ 2";
    St1.answers[2] = "Ответ 3";
    St1.answers[3] = "Ответ 4";
    quest St2;
    St2.question = "Вопрос 2";
    St2.answers[0] = "Ответ 21";
    St2.answers[1]= "Ответ 22 *";
    St2.answers[2] = "Ответ 23";
    St2.answers[3] = "Ответ 24";
    quest St3;
    St3.question = "Вопрос 3";
    St3.answers[0] = "Ответ 13";
    St3.answers[1] = "Ответ 23*";
    St3.answers[2] = "Ответ 33";
    St3.answers[3] = "Ответ 43";
    quest St4;
    St4.question = "Вопрос 4";
    St4.answers[0] = "Ответ 41";
    St4.answers[1]= "Ответ 42 *";
    St4.answers[2] = "Ответ 43";
    St4.answers[3] = "Ответ 44";
    quest arr[30];
    arr[0] = St1;
    arr[1] = St2;
    arr[2] = St3;
    arr[3] = St4;
    int questions_num[10];
    int count = 0;
    int wa = 0;
    for (int u =0; u < 10; u++)
        questions_num[u] = -1;
    for (int i = 0; i < 3; i++){
        do{
            count = 0;
            n = rand() % 4;
            for (int h = 0; h < 10 ; h++){
                if (n == questions_num[h]) count++;}
            }while(count > 0);
        questions_num[i] = n;
        que = arr[n].question;
        for (int j = 0; j < 4; j++){
            t = arr[n].answers[j];
            for(int l = 0; l < size(t);l++){
                char  h = t[l];
                if (h == zv){
                    k = j + 1;
                    arr[n].answers[j].resize(arr[n].answers[j].size() - 1);
                }
            }
        }
        ans1 = arr[n].answers[0];
        ans2 = arr[n].answers[1];
        ans3 = arr[n].answers[2];
        ans4 = arr[n].answers[3];
        cout << que << endl;
        cout << ans1 << endl;
        cout << ans2 << endl;
        cout << ans3 << endl;
        cout << ans4 << endl;
        cout << "Введите ответ на вопрос" << endl;
        cin >> answer;
        if (answer != k){
            wrong_answers[wa] = arr[n];
            answers[wa] = answer;
            right_answers[wa] = k;
            wa++;
        }
    }
    
    cout << "количество ошибок:"<<wa<<endl;
    if (wa <= 1) {mark = 5; cout << "Оценка 5" << endl;}
    if (wa >= 2 && wa <=3) {mark = 4;cout << "Оценка 4" << endl;}
    if (wa >= 4 && wa <=6) {mark = 3; cout << "Оценка 3" << endl;}
    if (wa > 6) {mark = 2;cout << "Оценка 2" << endl;
        for (int j = 0; j < 8; j++){
            if (st.marks[j] <= 5 && st.marks[j] > 1){
                len++;
            }
        }
        st.marks[len - 1] = mark;
        cout << "Неверно решенные задания" << endl;}
    for (int i = 0; i < wa; i++){
        cout << wrong_answers[i].question << endl;
        cout << wrong_answers[i].answers[0] << endl;
        cout << wrong_answers[i].answers[1]<< endl;
        cout << wrong_answers[i].answers[2] << endl;
        cout << wrong_answers[i].answers[3] << endl;
        cout << "Ваш ответ:"<< answers[i]<<endl;
        cout << "Правильный ответ:"<<right_answers[i] <<endl;
    }
    choice(st);
}

void tema_trening(student st){
    int k;
    cout << "Выберите тему: 1 - циклы, 2 - массивы одномерные и двумерные, 3 - строки, 4 - рекурсия, 5 - структуры, 6 - файлы, 7 - адреса и указатели, 8 - динамическая память"<<endl;
    do{
        cin >> k;
        if( k != 1 && k != 2 && k != 3 && k != 4 && k != 5 && k != 6 && k != 7 && k != 8)
            cout << "Выберите тему: 1 - циклы, 2 - массивы одномерные и двумерные, 3 - строки, 4 - рекурсия, 5 - структуры, 6 - файлы, 7 - адреса и указатели, 8 - динамическая память"<< endl;
    }while(k != 1 && k != 2 && k != 3 && k != 4 && k != 5 && k != 6 && k != 7 && k != 8);
    switch(k){
        case 1: {train("cycles.txt", st); break;}
        case 2: {train("arrays.txt", st); break;}
        case 3: {train("lines.txt", st); break;}
        case 4: {train("recursion.txt", st); break;}
        case 5: {train("sructure.txt", st); break;}
        case 6: {train("files.txt", st); break;}
        case 7: {train("addresses and pointers.txt", st); break;}
        case 8: {train("dynamic memory.txt", st); break;}
    }
}
void tema_test(student st){
    int k;
    cout << "Выберите тему: 1 - циклы, 2 - массивы одномерные и двумерные, 3 - строки, 4 - рекурсия, 5 - структуры, 6 - файлы, 7 - адреса и указатели, 8 - динамическая память"<<endl;
    do{
        cin >> k;
        if( k != 1 && k != 2 && k != 3 && k != 4 && k != 5 && k != 6 && k != 7 && k != 8)
            cout << "Выберите тему: 1 - циклы, 2 - массивы одномерные и двумерные, 3 - строки, 4 - рекурсия, 5 - структуры, 6 - файлы, 7 - адреса и указатели, 8 - динамическая память"<< endl;
    }while(k != 1 && k != 2 && k != 3 && k != 4 && k != 5 && k != 6 && k != 7 && k != 8);
    switch(k){
        case 1: {test("cycles.txt", st); break;}
        case 2: {test("arrays.txt", st); break;}
        case 3: {test("lines.txt", st); break;}
        case 4: {test("recursion.txt", st); break;}
        case 5: {test("sructure.txt", st); break;}
        case 6: {test("files.txt", st); break;}
        case 7: {test("addresses and pointers.txt", st); break;}
        case 8: {test("dynamic memory.txt", st); break;}
    }
}



void finish_test(student st){
    string que, ans1 ,ans2, ans3 ,ans4, t;
    quest wrong_answers[40];
    int answers[40];
    int right_answers[40];
    char zv;
    int n, k, answer;
    k = 0;
    int mark = 0;
    zv = '*';
    quest St1;
    St1.question = "Вопрос Тема 0";
    St1.answers[0] = "Ответ 1";
    St1.answers[1] = "Ответ 2";
    St1.answers[2] = "Ответ 3 *";
    St1.answers[3] = "Ответ 4";
    quest St2;
    St2.question = "Вопрос 2 Тема 1";
    St2.answers[0] = "Ответ 21";
    St2.answers[1]= "Ответ 22 *";
    St2.answers[2] = "Ответ 23";
    St2.answers[3] = "Ответ 24";
    quest St3;
    St3.question = "Вопрос 3 Тема2";
    St3.answers[0] = "Ответ 13";
    St3.answers[1] = "Ответ 23*";
    St3.answers[2] = "Ответ 33";
    St3.answers[3] = "Ответ 43";
    quest St4;
    St4.question = "Вопрос 4 Тема 3";
    St4.answers[0] = "Ответ 41";
    St4.answers[1]= "Ответ 42 *";
    St4.answers[2] = "Ответ 43";
    St4.answers[3] = "Ответ 44";
    quest St5;
    St5.question = "Вопрос Тема 1";
    St5.answers[0] = "Ответ 1";
    St5.answers[1] = "Ответ 2*";
    St5.answers[2] = "Ответ 3";
    St5.answers[3] = "Ответ 4";
    quest St6;
    St6.question = "Вопрос 2 Тема 2";
    St6.answers[0] = "Ответ 21";
    St6.answers[1]= "Ответ 22 *";
    St6.answers[2] = "Ответ 23";
    St6.answers[3] = "Ответ 24";
    quest St7;
    St7.question = "Вопрос 3 Тема 3";
    St7.answers[0] = "Ответ 13";
    St7.answers[1] = "Ответ 23*";
    St7.answers[2] = "Ответ 33";
    St7.answers[3] = "Ответ 43";
    quest St8;
    St8.question = "Вопрос 4 Тема 4";
    St8.answers[0] = "Ответ 41";
    St8.answers[1]= "Ответ 42 *";
    St8.answers[2] = "Ответ 43";
    St8.answers[3] = "Ответ 44";
    int m[8];
    for (int i = 0; i < 8; i++){
        m[i] = 30;
    }
    quest** arr = (quest**)malloc(sizeof(quest*) * 8);
    for (int i = 0; i < 8; i++){
        arr[i] = (quest*)malloc(sizeof(quest)* m[i]);
        }
    arr[0][0] = St1;
    arr[1][0] = St2;
    arr[2][0] = St3;
    arr[3][0] = St4;
    arr[0][1] = St5;
    arr[1][1] = St6;
    arr[2][1] = St7;
    arr[3][1] = St8;
    int questions_num[8][40];
    int count = 0;
    int temp = -1;
    int g =0;
    int wa = 0;
    for (int u =0; u < 8; u++)
        for (int f = 0; f < 40;f++){
            questions_num[u][f] = -1;
        }
    for (int i = 0; i < 3; i++){
        do{
        n = rand() % 4;
        }while(n == temp);
        temp = n;
        //cout << n;
        do{
            count = 0;
            g = rand() % 2;
            for (int h = 0; h < 10 ; h++){
                //cout << g << questions_num[n][h];
                if (g == questions_num[temp][h]) count++;}
        }while(count > 0);
        //cout << n<< g<< endl;
//        g = rand() % 2;
        questions_num[n][i] = g;
        //cout << g << questions_num[n][i];
        que = arr[n][g].question;
        for (int j = 0; j < 4; j++){
            t = arr[n][g].answers[j];
            for(int l = 0; l < size(t);l++){
                char  h = t[l];
                if (h == zv){
                    k = j + 1;
                    arr[n][g].answers[j].resize(arr[n][g].answers[j].size() - 1);
                }
            }
        }
        ans1 = arr[n][g].answers[0];
        ans2 = arr[n][g].answers[1];
        ans3 = arr[n][g].answers[2];
        ans4 = arr[n][g].answers[3];
        cout << que << endl;
        cout << ans1 << endl;
        cout << ans2 << endl;
        cout << ans3 << endl;
        cout << ans4 << endl;
        cout << "Введите ответ на вопрос" << endl;
        cin >> answer;
        if (answer != k){
            wrong_answers[wa] = arr[n][g];
            answers[wa] = answer;
            right_answers[wa] = k;
            wa++;
        }
    }
    
    cout << "количество ошибок:"<<wa<<endl;
    if (wa <= 1) {mark = 5; cout << "Оценка 5" << endl;}
    if (wa >= 2 && wa <=3) {mark = 4;cout << "Оценка 4" << endl;}
    if (wa >= 4 && wa <=6) {mark = 3; cout << "Оценка 3" << endl;}
    if (wa > 6) {mark = 2;cout << "Оценка 2" << endl;
    st.exam_mark = mark;
    cout << "Неверно решенные задания" << endl;}
    for (int i = 0; i < wa; i++){
        cout << wrong_answers[i].question << endl;
        cout << wrong_answers[i].answers[0] << endl;
        cout << wrong_answers[i].answers[1]<< endl;
        cout << wrong_answers[i].answers[2] << endl;
        cout << wrong_answers[i].answers[3] << endl;
        cout << "Ваш ответ:"<< answers[i]<<endl;
        cout << "Правильный ответ:"<<right_answers[i] <<endl;
    }
    choice(st);
}


