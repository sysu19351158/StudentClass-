#include "Student.h"
#include "StudentClass.h"
#include <iostream>
#include< iomanip >



int StudentClass::studentCount_ = 0;


StudentClass::StudentClass()
{
	code_ = "";
	students_num = 0;
	for (int i = 0; i < maxStudents_; i++)
	{
		this->students_[i] = new Student;
	}
}

StudentClass::StudentClass(string code, Student* stu, int n) :code_{ code }, students_num{0}
{
	for (int i = 0; i < maxStudents_; i++)
	{
		if (i < n && studentCount_ <= maxStudents_)
		{
			this->students_[i] = new Student(*(stu + i));
			studentCount_++;
			students_num++;
		}
		//ѧ������Խ��ʱ��������ѧ��������ӽ��ð༶
		else if (i<n && studentCount_ > maxStudents_)
		{
			cout << "���ù��캯��ʱѧ������Խ�磬ѧ��" << (stu + i)->name_ << "δ����ӽ�" << code_ << "�༶" << endl;
			this->students_[i] = new Student;
		}
		else
			this->students_[i] = new Student;

	}
}


StudentClass::StudentClass(const StudentClass& stuc) :code_{ stuc.code_ }, students_num{0}
{
	if ((studentCount_ + stuc.students_num) <= maxStudents_)
	{
		for (int i = 0; i < maxStudents_; i++)
			this->students_[i] = new Student(*stuc.students_[i]);
		studentCount_ += stuc.students_num;
		students_num = stuc.students_num;
	}
	else
	{
		cout << "���ÿ������캯��ʱѧ������Խ�磬�Զ�ת��ΪĬ�Ϲ���" << endl;
		code_ = "";
		for (int i = 0; i < maxStudents_; i++)
		{
			this->students_[i] = new Student;
		}
	}
}

StudentClass::~StudentClass()
{
	for (int i = 0; i < maxStudents_; i++)
		delete this->students_[i];
}


void StudentClass::setcode(std::string code) { code_ = code; }



Student StudentClass::getstudent(int id)const
{
	for (int i = 0; i < maxStudents_; i++)
		if (this->students_[i]->id_ == id)
		{
			return *(this->students_[i]); break;
		}
}



bool StudentClass::AddStudent(const Student* student)
{
	if (studentCount_ + 1 <= maxStudents_)
	{
		*(this->students_[students_num]) = *student;
		students_num++;
		studentCount_++;
		return true;
	}
	else
	{
		cout << "�������ѧ������ʱѧ������Խ�磬ѧ��" << student->name_ << "δ����ӽ�" << code_ << "�༶" << endl;
		return false;
	}
}


void StudentClass::ShowStudent(int id) const
{
	int judge = 0;
	for (int i = 0; i < studentCount_; i++)
		if (this->students_[i]->id_ == id)
		{
			this->students_[i]->ShowGrades();
			judge = 1;
		}
	if (judge == 0)
		cout << "�༶" << code_ << "��û��ѧ��Ϊ" << id << "��ѧ��" << endl;
}



void StudentClass::ShowStudentsByIdOrder(bool (*compare)(int, int))
{
	Student replace_student;
	for (int i = 0; i < students_num; i++)
	{
		for (int j = i + 1; j < students_num; j++)
			if (!compare(this->students_[i]->id_, this->students_[j]->id_))
			{
				replace_student = *(this->students_[i]);
				*(this->students_[i]) = *(this->students_[j]);
				*(this->students_[j]) = replace_student;
			}
	}
	cout << "class��" << code_ << "��:" << endl;
	for (int i = 0; i < students_num; i++)
	{
		this->students_[i]->ShowGrades();
	}


}
