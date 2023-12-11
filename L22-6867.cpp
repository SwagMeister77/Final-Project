#include<iostream>
#include<fstream>
#include"FileHandler.h"
#include"System.h"
#include"Student.h"
#include"Course.h"
void Student::enroll()
{
	system("cls");
	cout << "Name : ";
	cin >> name;
	cout << "Age : ";
	cin >> age;
	cout << "Roll num : ";
	cin >> roll_num;
	cout << "Contact : ";
	cin >> contact;
	FileHandler obj;
	obj.open("read.txt", ios::app);
	obj << name;
	obj << age;
	obj << roll_num;
	obj << contact;
	obj.close();
	Sleep(3000);
}
int main()
{
	System s;
	s.Mainmenu();
	return 0;
}