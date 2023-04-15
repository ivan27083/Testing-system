#include <iostream>
#include <fstream>
#include <sstream>
#include "files.h"
using namespace std;

string inttohex(int a) {
	string tmp("");
	do
	{
		int r(a % 16);
		if (r > 9) { r += (int)'A' - 10; }
		else { r += (int)'0'; };
		tmp = (char)r + tmp;
		a /= 16;
	} while (a);
	return tmp;
}

int hexToDec(string hex) {
	int dec = 0;
	for (int i = hex.length() - 1; i >= 0; i--) {
		int digit = 0;
		if (hex[i] >= '0' && hex[i] <= '9') {
			digit = hex[i] - '0';
		}
		else if (hex[i] >= 'A' && hex[i] <= 'F') {
			digit = hex[i] - 'A' + 10;
		}
		else if (hex[i] >= 'a' && hex[i] <= 'f') {
			digit = hex[i] - 'a' + 10;
		}
		dec += digit * pow(16, hex.length() - i - 1);
	}
	return dec;
}

void append_s(student *&mas, int n){
	student* mass = new student[n+1];
	for (int i = 0; i < n; i++) {
		mass[i] = mas[i];
	}
	mas = new student[n+1];
	for (int i = 0; i < n; i++) {
		mas[i] = mass[i];
	}
}

void append_q(quest*& mas, int n) {
	quest* mass = new quest[n + 1];
	for (int i = 0; i < n; i++) {
		mass[i] = mas[i];
	}
	mas = new quest[n + 1];
	for (int i = 0; i < n; i++) {
		mas[i] = mass[i];
	}
}

void code_student(student surname, fstream& f) {
	string login="", password="", marks="",name="",surnamee="";
	for (int i = 0; i < surname.name.length(); i++) {
		name += inttohex(int(unsigned char(surname.name[i]))) + ".";
	}
	f << name;
	f << "\n";
	for (int i = 0; i < surname.surname.length(); i++) {
		surnamee += inttohex(int(unsigned char(surname.surname[i]))) + ".";
	}
	f << surnamee;
	f << "\n";
	for (int i = 0; i < surname.login.length(); i++) {
		login += inttohex(int(unsigned char(surname.login[i]))) + ".";
	}
	f << login;
	f << "\n";
	for (int i = 0; i < surname.password.length(); i++) {
		password += inttohex(int(unsigned char(surname.password[i]))) + ".";
	}
	f << password;
	f << "\n";
	char a;
	for (int i = 0; i < 8; i++) {
		marks += inttohex(surname.marks[i]+48) + ".";
	}
	f << marks;
	f << "\n";
	string ex_mark = inttohex(surname.exam_mark + 48) + ".";
	f << ex_mark;
}

void code_question(quest quest, fstream& f) {
	string ans="";
	for (int i = 0; i < quest.question.length(); i++) {
		ans += inttohex(int(unsigned char(quest.question[i]))) + ".";
	}
	f << ans;
	f << "\n";
	for (int i = 0; i < 4; i++) {
		ans = "";
		for (int j = 0; j < quest.answers[i].length(); j++) {
			ans += inttohex(int(unsigned char(quest.answers[i][j]))) + ".";
		}
		f << ans;
		if (i != 3) f << "\n";
	}
}

void decode_student(student &surname, fstream& f) {
	string a="", b = "";
	getline(f, a);
	int i = 0;
	while (i != a.length()) {
		if (a[i] == '.') {
			surname.login += char(hexToDec(b));
			b = "";
			i++;
		}
		else {
			b += a[i];
			i++;
		}
	}
	a = "", b = "";
	getline(f, a);
	i = 0;
	while (i != a.length()) {
		if (a[i] == '.') {
			surname.password += char(hexToDec(b));
			b = "";
			i++;
		}
		else {
			b += a[i];
			i++;
		}
	}
	a = "", b = "";
	getline(f, a);
	i = 0;
	int j = 0;
	while (i != a.length()) {
		if (a[i] == '.') {
			surname.marks[j++] = hexToDec(b)-48;
			b = "";
			i++;
		}
		else {
			b += a[i];
			i++;
		}
	}
	a = "";
	getline(f, a);
	surname.exam_mark = int(char(hexToDec(a)));
}
void decode_question(quest& quest, fstream& f) {
	string a = "", b = "";
	int i = 0;
	getline(f, a);
	quest.question = "";
	while (i != a.length()) {
		if (a[i] == '.') {
			quest.question += char(hexToDec(b));
			b = "";
			i++;
		}
		else {
			b += a[i];
			i++;
		}
	}
	for (int j = 0; j < 4; j++) {
		quest.answers[j] = "";
		a = "";
		i = 0;
		getline(f, a);
		while (i != a.length()) {
			if (a[i] == '.') {
				quest.answers[j] += char(hexToDec(b));
				b = "";
				i++;
			}
			else {
				b += a[i];
				i++;
			}
		}
	}
}