#pragma once
#ifndef FILEHANDLER_H
#define FILEHANDLER_H
#include<string>
#include<fstream>
#include"Student.h"
using namespace std;

class FileHandler
{
private:
	string filename;
	ios::openmode mode;
	fstream fin;
public:
	FileHandler()
	{
		filename = "";
		mode = 0;
		fin;
	}
	void open(const char* f, ios::openmode m)
	{
		fin.open(f, m);
	}
	void close()
	{
		fin.close();
	}
	void READ(Student*& student, int& cap)
	{
		fin >> cap;
		student = new Student[cap];
		string c_name, f_name, l_name, roll_ID;
		int age;
		long long contact_num;
		for (int i = 0; i < cap; i++)
		{
			fin >> f_name;
			fin >> l_name;
			c_name = f_name + " " + l_name;
			fin >> roll_ID;
			fin >> age;
			fin >> contact_num;
			fstream temp;
			int total_attendance;
			int Marks_count;
			Course* course;
			int course_count;
			filename = roll_ID + "_C.txt";
			temp.open(filename, ios::in);
			if (temp)
			{
				string IF_name, IL_name;

				temp >> course_count;
				course = new Course[course_count];
				for (int n = 0; n < course_count; n++)
				{
					temp >> course[n].code;
					temp >> course[n].name;
					temp >> course[n].creds;
					temp >> IF_name;
					temp >> IL_name;
					course[n].instructor = IF_name + " " + IL_name;
					temp >> course[n].capacity;
					fstream tmp;
					string filename = (course[n].code) + roll_ID + "_A.txt";
					tmp.open(filename, ios::in);
					if (tmp)
					{
						tmp >> total_attendance;
						course[n].attendance_count = total_attendance;
						course[n].attendance = new char[total_attendance];
						for (int j = 0; j < total_attendance; j++)
						{
							tmp >> course[n].attendance[j];
						}
					}
					tmp.close();
					string filename1 = (course[n].code) + roll_ID + "_M.txt";
					tmp.open(filename1, ios::in);
					if (tmp)
					{
						tmp >> Marks_count;
						course[n].marks_count = Marks_count;
						course[n].marks = new int[Marks_count];
						for (int j = 0; j < Marks_count; j++)
						{
							tmp >> course[n].marks[j];
						}
					}
					tmp.close();
				}

			}
			else
			{
				course = 0;
				course_count = 0;
			}
			temp.close();

			student[i].ReadDataFromFile(c_name, roll_ID, age, contact_num, course, course_count);
		}

	}

	void operator>>(Student& obj)
	{
		fin >> obj.name;
		fin >> obj.age;
		fin >> obj.roll_num;
		fin >> obj.contact;
	}
	void operator<<(string n)
	{
		fin << n;
		fin << " ";
	}
	void operator<<(int a)
	{
		fin << a;
		fin << " ";
	}
	void operator<<(long long c)
	{
		fin << c;
		fin << " ";
	}
	void operator<<(char a)
	{
		fin << a;
		fin << " ";
	}
};
#endif // !FILEHANDLER_H
