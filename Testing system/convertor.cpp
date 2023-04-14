/*#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
#include <locale>
#include "files.h"
using namespace std;

int main() {
	system("chcp 1251");
	setlocale(LC_ALL,"Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	fstream f("test.txt");
	student Ivan;
	string s;
	f >> Ivan.login;
	f >> Ivan.password;
	
	int j = 0;
	for (int i = 0; i < 8; i++) {
		f >> s;
		if (isdigit(s[0])) Ivan.marks[j++] = int(s[0]) - 48;
	}
	f >> Ivan.exam_mark;
	double sum = 0;
	for (int i = 0; i < 8; i++) {
		sum += Ivan.marks[i];
	}
	Ivan.sr_mark = sum / 8.0;
	f.close();
	fstream file("structure.txt");
	fstream q1_res("res.txt", ios::app);
	string mess;
	quest adr_and_point[30];
	for (int i = 0; i < 30; i++) {
		getline(file, adr_and_point[i].question);
		for (int j = 0; j < 4; j++) {
			getline(file, adr_and_point[i].answers[j]);
		}
		file >> mess;
	}
	for (int i = 0; i < 30; i++) {
		code_question(adr_and_point[i], q1_res);
	}
	q1_res.close();
	fstream q1_res_r("res.txt");
	for (int i = 0; i < 30; i++) {
		decode_question(adr_and_point[i], q1_res_r);
	}
	file.close();
	q1_res_r.close();
	//fstream file_a("res.txt", ios::app);
	//code_student(Ivan, file_a);
	//file_a.close();
	//fstream file_r("res.txt");
	//decode_student(Ivan,file_r);
	//file_r.close();
	return 0;
}*/