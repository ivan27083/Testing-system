#include <iostream>
#include <fstream>
#include <vector>
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


void code_student(student surname) {
	string login="", password="", marks="";
	ofstream f("data.txt");
	for (int i = 0; i < surname.login.length(); i++) {
		login += inttohex(int(surname.login[i])) + ".";
	}
	f << login;
	for (int i = 0; i < surname.password.length(); i++) {
		login += inttohex(int(surname.password[i])) + ".";
	}
	f << password;
	for (int i = 0; i < 8; i++) {
		marks += inttohex(surname.marks[i]) + ".";
	}
	f << marks;
	string ex_mark = inttohex(surname.exam_mark);
	f << ex_mark;
	string sr_mark = inttohex(surname.sr_mark);
	f << sr_mark;
	f.close();
}

void code_question(quest quest, fstream f) {
	string ans="";
	f << quest.question;
	for (int i = 0; i < 4; i++) {
		ans += quest.answers[i];
	}
	f << ans;
	f.close();
}

void decode_student(student surname) {
	ifstream f("data.txt");
	string a="", b = "";
	f >> a;
	int i = 0;
	while (a != ""){
		if (a[i] == '.') {
			surname.login += string(hexToDec(b),sizeof(string));
			b = "";
		}
		b += a[i];
		i++;
	}

	f.close();
}