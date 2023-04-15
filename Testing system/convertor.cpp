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
	getline(f, Ivan.login);
	getline(f, Ivan.password);
	
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
	fstream ivan("students.txt",ios::app);
	code_student(Ivan, ivan);
	f.close();
	fstream file("cycles.txt");
	fstream q1_res("cycles_hex.txt");
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
		if (i != 29) q1_res << '\n';
	}
	q1_res.close();
	file.close();
	return 0;
}*/