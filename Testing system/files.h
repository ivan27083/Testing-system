#pragma once
struct student {
	string login;
	string password;
	double marks[8];
	int exam_mark;
	double sr_mark;
};
struct test {
	string question;
	string answers[4];
};
void code();
void open_code();