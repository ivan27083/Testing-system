#pragma once
#include <fstream>
#include <iostream>
using namespace std;
struct student {
	string name;
	string surname;
	string login = "";
	string password = "";
	int marks[8];
	int exam_mark;
	double sr_mark;
};
struct quest {
	string question;
	string answers[4];
	int right_answer;
};
void append_s(student*& mas, int n);
void append_q(quest*& mas, int n);
void code_student(student surname, fstream& f);
void code_question(quest quest, fstream &f);
void decode_student(student &surname, fstream &f);
void decode_question(quest& quest, fstream& f);