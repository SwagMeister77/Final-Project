#pragma once
#ifndef SYSTEM_H
#define SYSTEM_H
#include<string>
#include"Student.h"
#include"Course.h"
#include"FileHandler.h"
using namespace std;
string Student::getname()
{
	return name;
}
string Student::getrollnum()
{
	return roll_num;
}
int Student::getage()
{
	return age;
}
long long Student::getcontact()
{
	return contact;
}
void Student::Enter()
{
	string fname , lname;
	cout << "Enter first name : ";
	cin >> fname;
	cout << "Enter last name : ";
	cin >> lname;
	name = fname + " " + lname;
	cout << "Enter roll no : ";
	cin >> roll_num;
	cout << "Enter age = ";
	cin >> age;
	cout << "Enter contact = ";
	cin >> contact;
}
void Student::DisplayStudents()
{
	cout << name << endl;
	cout << roll_num << endl;
	cout << age << endl;
	cout << contact << endl;
	cout << total_courses << endl;
}
class System
{
private:
	Student* students;
	//Course* courses;
	int menus;
	int total_students;
public:
	System()
	{
		students = 0;
		menus = 0;
		total_students = 0;
		FileHandler f1;
		f1.open("Students.txt", ios::in);
		f1.READ(students, total_students);

	}
	void Mainmenu()
	{
	start:
		system("cls");
		cout << "\t1 - enroll a student\n";
		cout << "\t2 - course registration\n";
		cout << "\t3 - attendance\n";
		cout << "\t4 - marks\n";
		cout << "\t5 - course withdraw\n";
		cout << "\t6 - exit\n";
		cin >> menus;
		if (menus > 6 || menus == 0)
		{
			system("cls");
			cout << "invalid input!!\n";
			Sleep(3000);
			goto start;
		}
		else if (menus <= 5)
		{
			this->submenu(menus);
		}
		else
		{   
				
		}
		Sleep(100);
	}
	void submenu(int i)
	{
		int in;
	start:
		system("cls");
		if (i == 1)
		{
			cout << "\t1 - display already enrolled students\n";
			cout << "\t2 - add a student\n";
			cout << "\t3 - remove a student\n";
			cout << "\t4 - edit student detail\n";
			cout << "\t5 - back\n";
			cin >> in;
			if (in > 5 || in == 0)
			{
				system("cls");
				cout << "invalid input!!\n";
				Sleep(3000);
				goto start;
			}
			else if (in == 1)
			{
				system("cls");
				for (int i = 0; i < total_students; i++)
				{
					students[i].DisplayStudents();
				}
				Sleep(3000);
				goto start;
			}
			else if (in == 2)
			{
				int len = total_students + 1, i = 0;
				Student* temp = new Student[len];
				for (i; i < total_students; i++)
				{
					temp[i] = students[i];
				}
				system("cls");
				temp[i].Enter();
				Sleep(3000);
				delete[] students;
				students = temp;
				total_students = len;
				FileHandler fin;
				remove("Students.txt");
				fin.open("Students.txt", ios::app);
				fin << total_students;
				fin << '\n';
				for (int j = 0; j < total_students; j++)
				{
					fin << students[j].getname();
					fin << "\t\t";
					fin << students[j].getrollnum();
					fin << "\t\t";
					fin << students[j].getage();
					fin << "\t\t";
					fin << students[j].getcontact();
					fin << '\n';
				}
				fin.close();
				Sleep(3000);
				goto start;
			}
			else if (in == 3)
			{
				system("cls");
				FileHandler fin;
				string roll;
				Student* temp;
				int len;
				cout << "Enter the Roll number of Student = ";
				cin >> roll;
				bool flag = false;
				for (int i = 0; i < total_students; i++)
				{
					if (roll == students[i].getrollnum())
					{
						flag = true;
						len = total_students - 1;
						temp = new Student[len];
						int k = 0;
						for (int j = 0; j < total_students; j++)
						{
							if (roll == students[j].getrollnum())
							{
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
						total_students = len;
					}

				}
				if (!flag)
				{
					cout << "Roll num not found!!!\n";
				}
				remove("Students.txt");
				fin.open("Students.txt", ios::app);
				fin << total_students;
				fin << '\n';
				for (int i = 0; i < total_students; i++)
				{
					fin << students[i].getname();
					fin << "\t\t";
					fin << students[i].getage();
					fin << "\t\t";
					fin << students[i].getrollnum();
					fin << "\t\t";
					fin << students[i].getcontact();
					fin << '\n';
				}
				fin.close();
				Sleep(100);
				goto start;
			}
			else if (in == 4)
			{
				system("cls");
				FileHandler fin;
				string roll;
				Student* temp;
				int len;
				cout << "Enter the Roll number of Student = ";
				cin >> roll;
				bool flag = false;
				for (int i = 0; i < total_students; i++)
				{
					if (roll == students[i].getrollnum())
					{
						cout << "Enter the updated detail of student under roll num " << roll << "!!!!!\n";
						students[i].Enter();
					}

				}
				if (!flag)
				{
					cout << "Roll num not found!!!\n";
				}
				remove("Students.txt");
				fin.open("Students.txt", ios::app);
				fin << total_students;
				fin << '\n';
				for (int i = 0; i < total_students; i++)
				{
					fin << students[i].getname();
					fin << "\t\t";
					fin << students[i].getage();
					fin << "\t\t";
					fin << students[i].getrollnum();
					fin << "\t\t";
					fin << students[i].getcontact();
					fin << '\n';
				}
				fin.close();
				Sleep(100);
				goto start;
			}
			else if (in == 5)
			{
				this->Mainmenu();
			}
		/*}
		else if (i == 2)
		{
			cout << "\t1 - available courses\n";
			cout << "\t2 - register course\n";
			cout << "\t3 - back\n";
			cin >> in;
			if (in > 3 || in == 0)
			{
				system("cls");
				cout << "invalid input!!\n";
				Sleep(3000);
				goto start;
			}
			else if (in == 1)
			{
				system("cls");
				cout << "\t\"Available course\"\n\n";
				for (int j = 0; j < totalcourses; j++)
				{
					courses[j].Availablecourse();
				}
				Sleep(3000);
				goto start;
			}
			else if (in == 2)
			{
				int len = totalcourses + 1, i = 0;
				Course* temp = new Course[len];
				for (i; i < totalcourses; i++)
				{
					temp[i] = courses[i];
				}
				temp[i].Input();
				delete[] courses;
				courses = temp;
				totalcourses = len;
				FileHandler fin;
				remove("courses.txt");
				fin.open("courses.txt", ios::app);
				fin << totalcourses;
				fin << '\n';
				for (int j = 0; j < totalcourses; j++)
				{
					fin << courses[j].getcode();
					fin << "\t\t";
					fin << courses[j].getname();
					fin << "\t\t";
					fin << courses[j].getinstructor();
					fin << "\t\t";
					fin << courses[j].getcredits();
					fin << "\t\t";
					fin << courses[j].getcapacity();
					fin << '\n';
				}
				fin.close();
				Sleep(3000);
				goto start;
			}
			else if (in == 3)
			{
				this->mainmenu();
			}
		}
		else if (i == 3)
		{
			cout << "\t1 - display attendance(subject wise)\n";
			cout << "\t2 - mark attendance.\n";
			cout << "\t3 - back\n";
			cin >> in;
			if (in > 3 || in == 0)
			{
				system("cls");
				cout << "invalid input!!\n";
				Sleep(3000);
				goto start;
			}
			else if (in == 1)
			{
				int i = 0;
			c:
				system("cls");
				cout << "\t\"Available course\"\n\n";
				for (int j = 0; j < totalcourses; j++)
				{
					cout << "\t" << j << " - ";
					courses[j].Availablecourse();
				}
				do
				{
					if (i < 0 || i > totalcourses)
					{
						system("cls");
						cout << "invalid input!!\n";
						Sleep(3000);
						goto c;
					}
					cout << "\nFor which course you want to display attendance = ";
					cin >> i;
				} while (i < 0 || i > totalcourses);
				courses[i].DisplayAttendance();
				Sleep(3000);
				goto start;
			}
			else if (in == 2)
			{
				int i = 0;
			d:
				system("cls");
				cout << "\t\"Available course\"\n\n";
				for (int j = 0; j < totalcourses; j++)
				{
					cout << "\t" << j << " - ";
					courses[j].Availablecourse();
				}
				do
				{
					if (i < 0 || i > totalcourses)
					{
						system("cls");
						cout << "invalid input!!\n";
						Sleep(3000);
						goto d;
					}
					cout << "\nFor which course you want to mark attendance = ";
					cin >> i;
				} while (i < 0 || i > totalcourses);
				courses[i].MarkAttendance();
				Sleep(3000);
				goto start;
			}
			else if (in == 3)
			{
				this->mainmenu();
			}
		}
		else if (i == 4)
		{
			cout << "\t1 - display marks(subject wise)\n";
			cout << "\t2 - assign marks.\n";
			cout << "\t3 - back\n";
			cin >> in;
			if (in > 3 || in == 0)
			{
				system("cls");
				cout << "invalid input!!\n";
				Sleep(3000);
				goto start;
			}
			else if (in == 1)
			{
				int i = 0;
			e:
				system("cls");
				cout << "\t\"Available course\"\n\n";
				for (int j = 0; j < totalcourses; j++)
				{
					cout << "\t" << j << " - ";
					courses[j].Availablecourse();
				}
				do
				{
					if (i < 0 || i > totalcourses)
					{
						system("cls");
						cout << "invalid input!!\n";
						Sleep(3000);
						goto e;
					}
					cout << "\nFor which course you want to display marks = ";
					cin >> i;
				} while (i < 0 || i > totalcourses);
				courses[i].DisplayMarks();
				Sleep(3000);
				goto start;
			}
			else if (in == 2)
			{
				int i = 0;
			f:
				system("cls");
				cout << "\t\"Available course\"\n\n";
				for (int j = 0; j < totalcourses; j++)
				{
					cout << "\t" << j << " - ";
					courses[j].Availablecourse();
				}
				do
				{
					if (i < 0 || i > totalcourses)
					{
						system("cls");
						cout << "invalid input!!\n";
						Sleep(3000);
						goto f;
					}
					cout << "\nFor which course you want to assign marks = ";
					cin >> i;
				} while (i < 0 || i > totalcourses);
				courses[i].AssignMarks();
				Sleep(3000);
				goto start;
			}
			else if (in == 3)
			{
				this->mainmenu();
			}
		}
		else if (i == 5)
		{
			cout << "\t1 - enrolled courses\n";
			cout << "\t2 - drop a course\n";
			cout << "\t3 - back\n";
			cin >> in;
			if (in > 3 || in == 0)
			{
				system("cls");
				cout << "invalid input!!\n";
				Sleep(3000);
				goto start;
			}
			else if (in == 3)
			{
				this->mainmenu();
			}*/
		}
		Sleep(100);
	}
};
#endif // !SYSTEM_H
