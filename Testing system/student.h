#include <iostream>
#include <fstream>
#include <string.h>
#ifndef student_h
#define student_h
struct quest;
struct student;
void choice(student st);
void tema_trening(student st);
void tema_test(student st);
void finish_test();
void menu();
void test(std::string name, student st);
void train(std::string name, student st);
#endif /* student_h */
