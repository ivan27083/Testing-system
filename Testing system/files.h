#pragma once
struct student {
	string login;
	string password;
	int marks[8];
	int exam_mark;
	double sr_mark;
};
struct quest {
	string question;
	string answers[4];
};
void code();
void open_code();