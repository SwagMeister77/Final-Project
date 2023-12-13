#pragma once
#ifndef SYSTEM_H
#define SYSTEM_H
#include<iostream>
#include<fstream>
#include<string>
#include"Student.h"
#include"Course.h"
#include"FileHandler.h"
using namespace std;

class System
{
private:
	Course* courses;
	int totalcourses;
	int main_choice;
	FileHandler file;
public:
	System()
	{
		courses = 0;
		totalcourses = 0;
		main_choice = 0;
		file;
		file.open("Courses.txt", ios::in);
		file.read(courses, totalcourses);
		file.close();
	}
	void DisplayMain()
	{
	start:
		cout << "\t1 - Enroll Student\n";
		cout << "\t2 - Course Registration\n";
		cout << "\t3 - Attendance\n";
		cout << "\t4 - Marks\n";
		cout << "\t5 - Exit\n";
		cin >> main_choice;
		if (main_choice > 5 || main_choice < 0)
		{
			system("cls");
			cout << "\n\n\t\tInvalid Entry\n";
			Sleep(3000);
			goto start;
		}
		else if (main_choice <= 4)
		{
			this->DisplaySub(main_choice);
		}
		else if (main_choice == 5)
		{
			system("cls");
			cout << "THANK YOU FOR USING FLEXX\n";
		}
		Sleep(3000);
	}
	void DisplaySub(int mmc)
	{
		int sub_choice;
	start:
		system("cls");
		if (mmc == 1)
		{
			cout << "\t1 - Display Already Enrolled Students\n";
			cout << "\t2 - Add a Student\n";
			cout << "\t3 - Remove a Student\n";
			cout << "\t4 - Edit Student Detail\n";
			cout << "\t5 - Back\n";
			cin >> sub_choice;
			if (sub_choice > 5 || sub_choice < 0)
			{
				system("cls");
				cout << "\n\n\t\tInvalid Entry\n";
				Sleep(3000);
				goto start;
			}
			else if (sub_choice == 1)
			{
				for (int i = 0; i < totalcourses; i++)
				{
					courses[i].DisplayStudents();
				}
				goto start;
			}
			else if (sub_choice == 2)
			{
			a:
				int i = 0;
				system("cls");
				cout << "\t\"Available course\"\n\n";
				for (int j = 0; j < totalcourses; j++)
				{
					cout << "\t" << j << " - ";
					courses[j].AvailableCourses();
				}
				do
				{
					if (i < 0 || i > totalcourses - 1)
					{
						system("cls");
						cout << "\n\n\t\tInvalid Entry\n";
						Sleep(3000);
						goto a;
					}
					cout << "\nSelect Course in which you want to enroll students in = ";
					cin >> i;
				} while (i < 0 || i > totalcourses - 1);
				courses[i].EnrollStudent();
				Sleep(3000);
				goto start;
			}
			else if (sub_choice == 3)
			{
			b:
				int i = 0;
				system("cls");
				cout << "\t\Available Courses\"\n\n";
				for (int j = 0; j < totalcourses; j++)
				{
					cout << "\t" << j << " - ";
					courses[j].AvailableCourses();
				}
				do
				{
					if (i < 0 || i > totalcourses - 1)
					{
						system("cls");
						cout << "\n\n\t\tInvalid Entry\n";
						Sleep(3000);
						goto b;
					}
					cout << "\nEnter Course from which you want to remove student = ";
					cin >> i;
				} while (i < 0 || i > totalcourses - 1);
				courses[i].DeleteStudent();
				Sleep(3000);
				goto start;

			}
			else if (sub_choice == 4)
			{
				courses = courses->EditStudentDetails(totalcourses);
				Sleep(3000);
				goto start;
			}
			else if (sub_choice == 5)
			{
				this->DisplayMain();
			}
		}
		else if (mmc == 2)
		{
			cout << "\t1 - Available Courses\n";
			cout << "\t2 - Add a New Course\n";
			cout << "\t3 - Back\n";
			cin >> sub_choice;
			if (sub_choice > 3 || sub_choice < 0)
			{
				system("cls");
				cout << "\n\n\t\tInvalid Entry\n";
				Sleep(3000);
				goto start;
			}
			else if (sub_choice == 1)
			{
				system("cls");
				cout << "\t\"Available course\"\n\n";
				for (int j = 0; j < totalcourses; j++)
				{
					courses[j].AvailableCourses();
				}
				Sleep(3000);
				goto start;
			}
			else if (sub_choice == 2)
			{
				int len = totalcourses + 1, i = 0;
				Course* temp = new Course[len];
				for (i; i < totalcourses; i++)
				{
					temp[i] = courses[i];
				}
				temp[i].Enter();
				delete[] courses;
				courses = temp;
				totalcourses = len;
				remove("Courses.txt");
				file.open("Courses.txt", ios::app);
				file << totalcourses;
				file << '\n';
				for (int j = 0; j < totalcourses; j++)
				{
					file << courses[j].getcode();
					file << "\t\t";
					file << courses[j].GetName();
					file << "\t\t";
					file << courses[j].getinstructor();
					file << "\t\t";
					file << courses[j].getcredits();
					file << "\t\t";
					file << courses[j].getcapacity();
					file << '\n';
				}
				cout << "New Course Successfully Added\n";
				file.close();
				Sleep(3000);
				goto start;
			}
			else if (sub_choice == 3)
			{
				this->DisplayMain();
			}
		}
		else if (mmc == 3)
		{
			cout << "\t1 - Display Attendance(Course wise)\n";
			cout << "\t2 - Mark Attendance.\n";
			cout << "\t3 - Back\n";
			cin >> sub_choice;
			if (sub_choice > 3 || sub_choice < 0)
			{
				system("cls");
				cout << "\n\n\t\tInvalid Entry\n";
				Sleep(3000);
				goto start;
			}
			else if (sub_choice == 1)
			{
			c:
				int i = 0;
				system("cls");
				cout << "\t\"Available course\"\n\n";
				for (int j = 0; j < totalcourses; j++)
				{
					cout << "\t" << j << " - ";
					courses[j].AvailableCourses();
				}
				do
				{
					if (i < 0 || i > totalcourses - 1)
					{
						system("cls");
						cout << "\n\n\t\tInvalid Entry\n";
						Sleep(3000);
						goto c;
					}
					cout << "\nFor which course you want to Display Attendance = ";
					cin >> i;
				} while (i < 0 || i > totalcourses - 1);
				courses[i].DisplayAttendance();
				Sleep(3000);
				goto start;
			}
			else if (sub_choice == 2)
			{
			d:
				int i = 0;
				system("cls");
				cout << "\t\"Available course\"\n\n";
				for (int j = 0; j < totalcourses; j++)
				{
					cout << "\t" << j << " - ";
					courses[j].AvailableCourses();
				}
				do
				{
					if (i < 0 || i > totalcourses - 1)
					{
						system("cls");
						cout << "INVALID ENTRY\n";
						Sleep(3000);
						goto d;
					}
					cout << "\nFor which course you want to Mark Attendance = ";
					cin >> i;
				} while (i < 0 || i > totalcourses - 1);
				courses[i].MarkAttendance();
				Sleep(3000);
				goto start;
			}
			else if (sub_choice == 3)
			{
				this->DisplayMain();
			}
		}
		else if (mmc == 4)
		{
			cout << "\t1 - Display Marks(subject wise)\n";
			cout << "\t2 - Assign Marks.\n";
			cout << "\t3 - Back\n";
			cin >> sub_choice;
			if (sub_choice > 3 || sub_choice < 0)
			{
				system("cls");
				cout << "\n\n\t\tInvalid Entry\n";
				Sleep(3000);
				goto start;
			}
			else if (sub_choice == 1)
			{
				int i = 0;
			e:
				system("cls");
				cout << "\t\"Available course\"\n\n";
				for (int j = 0; j < totalcourses; j++)
				{
					cout << "\t" << j << " - ";
					courses[j].AvailableCourses();
				}
				do
				{
					if (i < 0 || i > totalcourses - 1)
					{
						system("cls");
						cout << "\n\n\t\tInvalid Entry\n";
						Sleep(3000);
						goto e;
					}
					cout << "\nSelect the course For which you want to Display Marks = ";
					cin >> i;
				} while (i < 0 || i > totalcourses - 1);
				courses[i].DisplayMarks();
				Sleep(3000);
				goto start;
			}
			else if (sub_choice == 2)
			{
				int i = 0;
			f:
				system("cls");
				cout << "\t\"Available course\"\n\n";
				for (int j = 0; j < totalcourses; j++)
				{
					cout << "\t" << j << " - ";
					courses[j].AvailableCourses();
				}
				do
				{
					if (i < 0 || i > totalcourses - 1)
					{
						system("cls");
						cout << "\n\n\t\tInvalid Entry\n";
						Sleep(3000);
						goto f;
					}
					cout << "\nSelect the Course For which you want to Assign Marks = ";
					cin >> i;
				} while (i < 0 || i > totalcourses - 1);
				courses[i].AssignMarks();
				Sleep(3000);
				goto start;
			}
			else if (sub_choice == 3)
			{
				this->DisplayMain();
			}
		}
		Sleep(3000);
	}
};
#endif // !SYSTEM_H
