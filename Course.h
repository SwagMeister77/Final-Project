#pragma once
#ifndef COURSE_H
#define COURSE_H
#include<iostream>
#include<Windows.h>
#include"Filehandler.h"
#include"Student.h";
using namespace std;
class Course
{
private:
	string code;
	string name;
	string instructor;
	int credits;
	int capacity;
	Student* students;
	int totalStudents;
public:
	friend class FileHandler;
	Course();
	Course(string c, string n, string ins, int cre, int cap, int ts, Student* st);
	void DisplayStudents();
	void EnrollStudent();
	void DeleteStudent();
	void operator=(const Course& obj);
	void Enter();
	Course* EditStudentDetails(int);
	void File_Reader(string c, string n, string ins, int cre, int cap, Student* obj, int t);
	void AvailableCourses();
	string getcode();
	string GetName();
	string getinstructor();
	int getcredits();
	int getcapacity();
	void DisplayAttendance();
	void MarkAttendance();
	void AssignMarks();
	void DisplayMarks();
	~Course();
};
#endif