#pragma once
#include <iostream>
using namespace std;
#include <fstream>
#include <string.h>
#include <string>
#include <malloc.h>
#include <math.h>
struct quest;
struct student;
void add_student(student*& person, int& kolvo_studentov);
void del_student(student*& person, int& kolvo_studentov);
void change_progress(student*& person, int& kolvo_studentov);
void delete_question(quest*& vopros, int& n);
void add_question(quest*& vopros, int& n);
void change_question(quest* vopros, int& n);
void question_menu();
void student_menu();
void prepod_login();
