#include "student.h"
#include <iostream>
#include< iomanip >

using namespace std;


Student::Student() :courseNames{ "\0" }, grades_{ 0 }
{
	id_ = 100001;
	name_ = "无名氏";
}

Student::Student(int id, string name) :id_{ id }, name_{ name }, courseNames{ "\0" }, grades_{ 0 }{}


Student::Student(const Student& stu) : id_{ stu.id_ }, name_{ stu.name_ }, courseNames{ "\0" }, grades_{ 0 }
{
	for (int i = 0; i < maxCourses; i++)
	{
		courseNames[i] = stu.courseNames[i];
		grades_[i] = stu.grades_[i];
	}
}

void Student::setid(int id) { id_ = id; }

void Student::setname(string name) { name_ = name; }


bool Student::Addcourse(const std::string& courseName, double grade)
{
	int i = 0;
	for (i = 0; i < maxCourses; i++)
	{
		if (courseNames[i] == "\0")
		{
			courseNames[i] = courseName;
			grades_[i] = grade;
			break;
		}
	}
	if (i == maxCourses)
		return false;
	else
		return true;

}



void Student::SetGrade(const std::string& courseName, double grade)
{
	int i = 0;
	for (i = 0; i < maxCourses; i++)
	{
		if (courseNames[i] == courseName)
		{
			grades_[i] = grade;
			break;
		}
	}
	if (i == maxCourses)
		cout << "该学生并没有添加此课程" << endl;
}


double Student::GetGrade(const std::string courseName)const
{
	int i = 0;
	double result = 0;
	for (i = 0; i < maxCourses; i++)
	{
		if (courseNames[i] == courseName)
		{
			result = grades_[i];
		}
	}
	return result;
}

void Student::ShowGrades()const
{
	int count = 0;
	cout << setw(10) << setiosflags(ios::left) << "name" << setw(10) << setiosflags(ios::left) << "id";
	for (count = 0; count < maxCourses; count++)
	{
		if (courseNames[count] != "\0")
			cout << setw(10) << setiosflags(ios::left) << courseNames[count];
		else
			break;
	}
	cout << endl;
	cout << setw(10) << setiosflags(ios::left) << name_ << setw(10) << setiosflags(ios::left) << id_;
	for (int i = 0; i < count; i++)
	{
		cout << setw(10) << setiosflags(ios::left) << grades_[i];
	}
	cout << endl;
}