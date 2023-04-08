#include <iostream>
#include <fstream>
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
void code_student(student surname) {
	for (int i = 0; i < surname.login.length(); i++) {
		inttohex(int(surname.login[i]));
	}
}