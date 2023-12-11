#pragma once
#ifndef STUDENT_H
#define STUDENT_H
#include<string>
#include"Course.h"
#include"FileHandler.h"
#include<fstream>
#include<Windows.h>
#include <iostream>
using namespace std;

class Student
{
private:
	string name;
	string roll_num;
	int age;
	long long contact;
	Course* courses;
	int total_courses;
public:
	friend class FileHandler;
	Student(string n = " ", string r = " ", int a = 0, long c = 0, Course* co = 0, int total = 0)
	{
		name = n;
		roll_num = r;
		age = a;
		contact = c;
		courses = co;
		total_courses = total;
	}
	friend ostream& operator<<(ostream& out, Student& obj)
	{
		out << obj.name << endl;
		out << obj.age << endl;
		out << obj.roll_num << endl;
		out << obj.contact << endl;
		return out;
	}
	void enroll();
	void DisplayStudents();
	void Enter();
	string getname();
	string getrollnum();
	int getage();
	long long getcontact();
	void ReadDataFromFile(string Name, string roll_no, int Age, long long contact_no, Course* Courses, int Total_Courses)
	{
		name = Name;
		roll_num = roll_no;
		age = Age;
		contact = contact_no;
		total_courses = Total_Courses;
		if (Total_Courses > 0)
		{
			courses = new Course[Total_Courses];
			for (int i = 0; i < Total_Courses; i++)
			{
				courses[i] = Courses[i];
			}
			
		}
		else
		{
			courses = 0;
			total_courses = 0;
		}
	}
};

#endif // !STUDENT_H

