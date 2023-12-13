#pragma once
#ifndef STUDENT_h
#define STUDENT_h
#include<iostream>
#include"FileHandler.h"
#include"Course.h";
using namespace std;

class Help
{
public:
	static int strlength(string ch)
	{
		int i = 0;
		for (; ch[i] != '\0'; i++);
		return i;
	}
	static void strcopy(char* des, string src)
	{
		int i;
		for (i = 0; src[i] != '\0'; i++)
		{
			des[i] = src[i];
		}
		des[i] = '\0';
	}
	static char* GetStrFromBuffer(string arr)
	{
		int n = strlength(arr);
		char* temp = new char[n];
		strcopy(temp, arr);
		return temp;
	}
	static bool searchstr(char* str, const char*& substr)
	{

		for (int i = 0; str[i] != '\0'; i++)
		{
			if (substr[0] == str[i])
			{
				bool f1 = true;
				int k = i;
				for (int j = 0; substr[j] != '\0'; j++, k++)
				{
					if (str[k] != substr[j])
					{
						f1 = false;
					}
				}
				if (f1 == true)
				{
					return true;
				}
			}
		}
		return false;
	}
};
class Student
{
private:
	string name;
	string roll_num;
	int age;
	long long contact;
	//course* courses;
	char* attendance;
	int Attendance_Count;
	int* marks;
	int Marks_Count;
public:
	friend class FileHandler;
	Student();
	Student(string n, string r, int a, long long c, char* att, int* m, int t, int t1, string code);
	void MarkAttendance(string code);
	void AssignMarks(string code);
	Student(const Student& obj)
	{
		name = obj.name;
		roll_num = obj.roll_num;
		age = obj.age;
		contact = obj.contact;
		attendance = obj.attendance;
		marks = obj.marks;
	}
	void operator=(const Student& obj)
	{
		name = obj.name;
		roll_num = obj.roll_num;
		age = obj.age;
		contact = obj.contact;
		attendance = obj.attendance;
		marks = obj.marks;
		Attendance_Count = obj.Attendance_Count;
		if (Attendance_Count > 0)
		{
			attendance = new char[Attendance_Count];
			for (int i = 0; i < Attendance_Count; i++)
			{
				attendance[i] = obj.attendance[i];
			}
		}
		Marks_Count = obj.Marks_Count;
		if (Marks_Count > 0)
		{
			marks = new int[Marks_Count];
			for (int i = 0; i < Marks_Count; i++)
			{
				marks[i] = obj.marks[i];
			}
		}
	}
	friend void operator<<(ostream& out, Student& obj)
	{
		out << obj.name << "\t\t";
		out << obj.age << "\t\t";
		out << obj.roll_num << "\t\t";
		out << obj.contact << "\n\n";
	}
	string GetName()
	{
		return name;
	}
	string GetRollNum()
	{
		return roll_num;
	}
	int GetAge()
	{
		return age;
	}
	long long GetContact()
	{
		return contact;
	}
	int GetTotalAttendance()
	{
		return Attendance_Count;
	}
	int GetTotalMarks()
	{
		return Marks_Count;
	}
	void MarkAttendance(int t)
	{
		Attendance_Count = t;
		attendance = new char[Attendance_Count];
		for (int i = 0; i < Attendance_Count; i++)
		{
			attendance[i] = '_';
		}
	}
	void setmarks(int t)
	{
		Marks_Count = t;
		attendance = new char[Marks_Count];
		for (int i = 0; i < Marks_Count; i++)
		{
			attendance[i] = 404;
		}
	}
	void updateStudent()
	{
		string firstname, surname;
		cout << "\n\"Enter the updated detail of student\"\n\n";
		cout << "Enter first name = ";
		cin >> firstname;
		cout << "Enter last name = ";
		cin >> surname;
		name = firstname + " " + surname;
		cout << "Enter roll num = ";
		cin >> roll_num;
		cout << "Enter age = ";
		cin >> age;
		cout << "Enter the contact number = ";
		cin >> contact;
	}
	void DisplayAttendance()
	{
		if (Attendance_Count == 0)
		{
			cout << "there hasn't been any session held for the class to date!!!\n";
		}
		else
		{
			for (int i = 0; i < Attendance_Count; i++)
			{
				cout << attendance[i];
				if (i != Attendance_Count - 1)
				{
					cout << " , ";
				}
			}
			cout << endl;
		}
	}
	void DisplayMarks()
	{
		if (Marks_Count == 0)
		{
			cout << "there hasn't been any session held for the class to date!!!\n";
		}
		else
		{
			for (int i = 0; i < Marks_Count; i++)
			{
				cout << marks[i];
				if (i != Marks_Count - 1)
				{
					cout << " , ";
				}
			}
			cout << endl;
		}
	}
	~Student()
	{
		name = "";
		roll_num = "";
		age = 0;
		contact = 0;
		if (attendance)
		{
			delete[] attendance;
		}
		else
		{
			attendance = 0;
		}
		if (marks)
		{
			delete[] marks;
		}
		else
		{
			marks = 0;
		}
	}
};
#endif 