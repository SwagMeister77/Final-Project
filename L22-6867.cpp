#include<iostream>
#include<fstream>
#include<string>
#include<Windows.h>
#include"Filehandler.h"
#include"Course.h"
#include"Student.h"
#include"System.h"
#include<stdio.h>
using namespace std;

class Course;
class Student;
class Filehandler;
class System;

bool CheckRollNum(string r)
{
	if (r.length() != 8)
	{
		return true;
	}
	if (r[2] != 'L')
	{
		return true;
	}
	if (r[3] != '-')
	{
		return true;
	}
	return false;
}
Student::Student()
{
	name = "";
	roll_num = "";
	age = 0;
	contact = 0;
	//courses = co;
	attendance = 0;
	Attendance_Count = 0;
	marks = 0;
	Marks_Count = 0;
}
Student::Student(string n, string r, int a, long long c, char* att, int* m, int t, int t1, string code)
{
	name = n;
	roll_num = r;
	age = a;
	contact = c;
	attendance = att;
	Attendance_Count = t;
	marks = m;
	Marks_Count = t1;
	string f = code + roll_num + ".txt";
	FileHandler fin;
	fin.open(f, ios::out);
	fin.close();
	f = code + roll_num + "M.txt";
	fin.open(f, ios::out);
	fin.close();
}
void Student::AssignMarks(string code)
{
	if (Marks_Count > 0)
	{
		for (int i = 0; i < Marks_Count; i++)
		{
			cout << marks[i] << " - ";
		}
		int today;
		cin >> today;
		int* temp;

		int len = Marks_Count + 1;
		temp = new int[len];
		int k = 0;
		for (k; k < Marks_Count; k++)
		{
			temp[k] = marks[k];
		}
		temp[k] = today;
		delete[] marks;
		marks = temp;
		Marks_Count = len;
		string f = roll_num + "Marks" + ".txt";
		const char* filename = Help::GetStrFromBuffer(code + f);
		remove(filename);
		FileHandler fin;
		fin.open(filename, ios::app);
		fin << Marks_Count;
		fin << '\n';
		for (int i = 0; i < Marks_Count; i++)
		{
			fin << marks[i];
			fin << '\t';
		}
		fin.close();
	}
	else
	{
		Marks_Count = Marks_Count + 1;
		marks = new int[Marks_Count];
		cin >> marks[Marks_Count - 1];
		string f = roll_num + "Marks" + ".txt";
		const char* filename = Help::GetStrFromBuffer(code + f);
		FileHandler fin;
		fin.open(filename, ios::app);
		fin << Marks_Count;
		fin << '\n';
		fin << marks[Marks_Count - 1];
		fin << '\t';
		fin.close();
	}
}
void Student::MarkAttendance(string code)
{
	if (Attendance_Count > 0)
	{
		for (int i = 0; i < Attendance_Count; i++)
		{
			cout << attendance[i] << " , ";
		}
		char today;
		cin >> today;
		char* temp;

		int len = Attendance_Count + 1;
		temp = new char[len];
		int k = 0;
		for (k; k < Attendance_Count; k++)
		{
			temp[k] = attendance[k];
		}
		temp[k] = today;
		delete[] attendance;
		attendance = temp;
		Attendance_Count = len;
		string f = roll_num + ".txt";
		const char* filename = Help::GetStrFromBuffer(code + f);
		remove(filename);
		FileHandler fin;
		fin.open(filename, ios::app);
		fin << Attendance_Count;
		fin << '\n';
		for (int i = 0; i < Attendance_Count; i++)
		{
			fin << attendance[i];
			fin << '\t';
		}
		fin.close();
	}
	else
	{
		Attendance_Count = Attendance_Count + 1;
		attendance = new char[Attendance_Count];
		cin >> attendance[Attendance_Count - 1];
		string f = roll_num + ".txt";
		const char* filename = Help::GetStrFromBuffer(code + f);
		FileHandler fin;
		fin.open(filename, ios::app);
		fin << Attendance_Count;
		fin << '\n';
		fin << attendance[Attendance_Count - 1];
		fin << '\t';
		fin.close();
	}
}
Course::Course()
{
	code = " ";
	name = " ";
	instructor = " ";
	credits = 0;
	students = 0;
	totalStudents = 0;
}
Course::Course(string c, string n, string ins, int cre, int cap, int ts, Student* st)
{
	code = c;
	name = n;
	instructor = ins;
	credits = cre;
	capacity = cap;
	students = st;
	totalStudents = ts;
}
Course::~Course()
{
	code = " ";
	name = " ";
	instructor = " ";
	credits = 0;
	totalStudents = 0;
	if (students)
	{
		delete[] students;
	}
	else
	{
		students = 0;
	}
}
void Course::AssignMarks()
{
	for (int i = 0; i < totalStudents; i++)
	{
		cout << students[i].GetName() << " : ";
		students[i].AssignMarks(code);
	}
}
void Course::DisplayMarks()
{
	for (int i = 0; i < totalStudents; i++)
	{
		cout << students[i].GetName() << " : ";
		students[i].DisplayMarks();
	}
}
void Course::MarkAttendance()
{
	for (int i = 0; i < totalStudents; i++)
	{
		cout << students[i].GetName() << " : ";
		students[i].MarkAttendance(code);
	}
}
void Course::DisplayAttendance()
{
	for (int i = 0; i < totalStudents; i++)
	{
		cout << students[i].GetName() << " : ";
		students[i].DisplayAttendance();
	}
}
string Course::getcode()
{
	return code;
}
string Course::GetName()
{
	return name;
}
string Course::getinstructor()
{
	return instructor;
}
int Course::getcredits()
{
	return credits;
}
int Course::getcapacity()
{
	return capacity;
}
void Course::Enter()
{
	system("cls");
	string fname, lname;
	cout << "Enter the Course Code = ";
	cin >> code;
	cout << "Enter the name of the course in the format (First name-Second name) = ";
	cin >> name;
	cout << "Enter the First Name of The Instructor = ";
	cin >> fname;
	cout << "Enter the Second Nmae of The Instructor = ";
	cin >> lname;
	instructor = fname + " " + lname;
	cout << "Enter the Credits Hours of the Course = ";
	cin >> credits;
	cout << "Enter the Course Capacity = ";
	cin >> capacity;
	totalStudents = 0;
	students = 0;
}
void Course::operator=(const Course& obj)
{
	code = obj.code;
	name = obj.name;
	instructor = obj.instructor;
	credits = obj.credits;
	capacity = obj.capacity;
	totalStudents = obj.totalStudents;
	students = new Student[totalStudents];
	for (int i = 0; i < totalStudents; i++)
	{
		students[i] = obj.students[i];
	}
}
void Course::DisplayStudents()
{
	system("cls");
	cout << code << "\t\t"
		<< name << "\t\t"
		<< instructor << "\t\t"
		<< credits << "\t\t"
		<< capacity << "\t\t\t\n\n"
		"Total Number of Enrolled Students : " << totalStudents << "\n\n";
	for (int i = 0; i < totalStudents; i++)
	{
		cout << students[i];
	}
	Sleep(3000);
}
Course* Course::EditStudentDetails(int t)
{
	Course* temp = this;
	string roll;
	int len, a, b;
	bool flag = false;
	system("cls");
	do
	{
		cout << "Enter the Roll number of Student in format(XXL-XXXX) : ";
		cin >> roll;
	} while (CheckRollNum(roll));
	for (int i = 0; i < t; i++)
	{
		len = temp[i].totalStudents;
		for (int j = 0; j < len; j++)
		{
			if (roll == temp[i].students[j].GetRollNum())
			{
				temp[i].students[j].updateStudent();
				a = i;
				b = j;
				flag = true;
				FileHandler fin;
				const char* filename;
				filename = Help::GetStrFromBuffer(temp[i].code + ".txt");
				remove(filename);
				fin.open(filename, ios::app);
				fin << temp[i].totalStudents;
				fin << '\n';
				for (int k = 0; k < temp[i].totalStudents; k++)
				{
					fin << temp[i].students[k].GetName();
					fin << "\t\t";
					fin << temp[i].students[k].GetAge();
					fin << "\t\t";
					fin << temp[i].students[k].GetRollNum();
					fin << "\t\t";
					fin << temp[i].students[k].GetContact();
					fin << '\n';
				}
				fin.close();
				break;
			}
		}
		if (flag == true) break;
	}
	if (flag == true && a != t - 1)
	{
		for (int i = a + 1; i < t; i++)
		{
			len = temp[i].totalStudents;
			for (int j = 0; j < len; j++)
			{
				if (roll == temp[i].students[j].GetRollNum())
				{
					temp[i].students[j] = temp[a].students[b];
					FileHandler fin;
					const char* filename;
					filename = Help::GetStrFromBuffer(temp[i].code + ".txt");
					remove(filename);
					fin.open(filename, ios::app);
					fin << temp[i].totalStudents;
					fin << '\n';
					for (int k = 0; k < temp[i].totalStudents; k++)
					{
						fin << temp[i].students[k].GetName();
						fin << "\t\t";
						fin << temp[i].students[k].GetAge();
						fin << "\t\t";
						fin << temp[i].students[k].GetRollNum();
						fin << "\t\t";
						fin << temp[i].students[k].GetContact();
						fin << '\n';
					}
					fin.close();
				}
			}
		}
		cout << "Student Details updated Successfully\n";

	}
	else
	{
		cout << "Student Does not exist in the Database\n";
		return this;
	}
	return temp;
}
void Course::DeleteStudent()
{
	FileHandler fin;
	string roll;
	Student* temp;
	int len;
	system("cls");
	do
	{
		cout << "Enter the Roll number of Student in format(XXL-XXXX) : ";
		cin >> roll;
	} while (CheckRollNum(roll));
	bool flag = false;
	for (int i = 0; i < totalStudents; i++)
	{
		if (roll == students[i].GetRollNum())
		{
			flag = true;
			len = totalStudents - 1;
			temp = new Student[len];
			int k = 0;
			for (int j = 0; j < totalStudents; j++)
			{
				if (roll == students[j].GetRollNum())
				{
					const char* filename;
					string removefile = code + students[j].GetRollNum();
					filename = Help::GetStrFromBuffer(removefile + ".txt");
					remove(filename);
					continue;
				}
				else
				{
					temp[k] = students[j];
					k++;
				}
			}
			delete[] students;
			students = temp;
			totalStudents = len;
		}

	}
	if (!flag)
	{
		cout << "Student Does not exist in the Database\n";
	}
	const char* filename;
	filename = Help::GetStrFromBuffer(code + ".txt");
	remove(filename);
	fin.open(filename, ios::app);
	fin << totalStudents;
	fin << '\n';
	for (int i = 0; i < totalStudents; i++)
	{
		fin << students[i].GetName();
		fin << "\t\t";
		fin << students[i].GetAge();
		fin << "\t\t";
		fin << students[i].GetRollNum();
		fin << "\t\t";
		fin << students[i].GetContact();
		fin << '\n';
	}
	cout << "Student Removed Successfully\n";
	fin.close();
	Sleep(3000);
}
void Course::EnrollStudent()
{
	FileHandler Fin;
	int tmp = totalStudents;
	totalStudents++;
	string name, roll_num, fname, lname;
	int age, * y = 0, t = 0, t1 = 0;
	long long contact;
	char* a = 0;
	system("cls");
	cout << "First name : ";
	cin >> fname;
	cout << "Last name : ";
	cin >> lname;
	name = fname + " " + lname;
	cout << "Age : ";
	cin >> age;
	do
	{
		cout << "Roll num in format(XXL-XXXX) : ";
		cin >> roll_num;
	} while (CheckRollNum(roll_num));
	cout << "Contact : ";
	cin >> contact;
	if (tmp > 0)
	{
		Student* temp = new Student[totalStudents];
		for (int i = 0; i < tmp; i++)
		{
			temp[i] = students[i];
		}
		temp[totalStudents - 1] = Student(name, roll_num, age, contact, a, y, t, t1, code);
		int kia = temp[0].GetTotalAttendance();
		int kia1 = temp[0].GetTotalMarks();
		temp[totalStudents - 1] = Student(name, roll_num, age, contact, a, y, t, t1, code);
		kia = temp[0].GetTotalAttendance();
		temp[totalStudents - 1].MarkAttendance(kia);
		delete[] students;
		students = temp;
	}
	else
	{
		Student* temp = new Student(name, roll_num, age, contact, a, y, t, t1, code);
		students = temp;
	}
	const char* filename;
	filename = Help::GetStrFromBuffer(code + ".txt");
	remove(filename);
	Fin.open(filename, ios::app);
	Fin << totalStudents;
	Fin << '\n';
	for (int i = 0; i < totalStudents; i++)
	{
		Fin << students[i].GetName();
		Fin << "\t\t";
		Fin << students[i].GetAge();
		Fin << "\t\t";
		Fin << students[i].GetRollNum();
		Fin << "\t\t";
		Fin << students[i].GetContact();
		Fin << '\n';
	}
	cout << "Student Added Sucessfully\n";
	Fin.close();
	Sleep(3000);
}
void Course::File_Reader(string c, string n, string ins, int cre, int cap, Student* obj, int t)
{
	code = c;
	name = n;
	instructor = ins;
	credits = cre;
	capacity = cap;
	totalStudents = t;
	if (t > 0)
	{
		students = new Student[t];
		for (int i = 0; i < t; i++)
		{
			students[i] = obj[i];
		}
	}
	else
	{
		totalStudents = 0;
		students = 0;
	}
}
void Course::AvailableCourses()
{
	cout << "(" << code << ") - " << name << endl;
}

int main()
{
	system("cls");
	cout << "\t\t\t=========WELCOME TO FLEXX =========\n";
	Sleep(4000);
	System sys;
	sys.DisplayMain();
	return 0;
}