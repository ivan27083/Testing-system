#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
#ifndef student_h
#define student_h
struct quest;
struct student;
void choice(student st);
void tema_trening(student st);
void tema_test(student st);
void finish_test(student st);
void student_login();
void test(fstream& f, student& st, int t);
void train(fstream& f, student& st);
#endif /* student_h */
