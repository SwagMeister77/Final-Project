#pragma once
#ifndef COURSE_H
#define COURSE_H
#include<string>
#include"Student.h"
#include"FileHandler.h"
#include<iostream>
using namespace std;

class Course
{
private:
	string code;
	string name;
	string instructor;
	int creds;
	int capacity;
	char* attendance;
	int* marks;
	int attendance_count;
	int marks_count;
	/*Student* students;*/
public:
	friend class FileHandler;
	Course(string c = " ", string n = " ", string ins = " ", int cre = 0, int cap = 0 , char* att = 0 , int* mar = 0  , int a_count = 0 , int m_count = 0)
	{
		code = c;
		name = n;
		instructor = ins;
		creds = cre;
		capacity = cap;
		attendance = att;
		marks = mar;
		attendance_count = a_count;
		marks_count = m_count;
	}
	//void DisplayStudents()
	//{
	//	FileHandler out;
	//	out.open("read.txt", ios::in);
	///*	out >> students[0];*/
	///*	cout << students[0];*/
	//	out.close();
	//}
	void operator=(const Course& obj)
	{
		code = obj.code;
		name = obj.name;
		creds = obj.creds;
		instructor = obj.instructor;
		capacity = obj.capacity;
		attendance_count = obj.attendance_count;
		if (attendance_count > 0)
		{
			attendance = new char[attendance_count];
			for (int i = 0; i < attendance_count; i++)
			{
				attendance[i] = obj.attendance[i];
			}
		}
		marks_count = obj.marks_count;
		if (marks_count > 0)
		{
			marks = new int[marks_count];
			for (int j = 0; j < marks_count; j++)
			{
				marks[j] = obj.marks[j];
			}
		}

	}
};

#endif // !COURSE_H
