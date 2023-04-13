#include <iostream>
#include <fstream>
#include "files.h"
using namespace std;
/*
int main() {
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
	fstream file_a("res.txt", ios::app);
	code_student(Ivan, file_a);
	file_a.close();
	fstream file_r("res.txt");
	decode_student(Ivan,file_r);
	file_r.close();
	fstream file_a2("res2.txt", ios::app);
	code_student(Ivan, file_a2);
	file_a2.close();
	return 0;
}*/