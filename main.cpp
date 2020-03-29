#include "Student.h"
#include "StudentClass.h"
#include <iostream>
#include< iomanip >




bool ascending(int a, int b)
{
	if (a <= b)
		return true;
	else
		return false;

}

bool descending(int a, int b)
{
	if (a >= b)
		return true;
	else
		return false;
}


int main()
{
	//********************************************************************************************************************************************************************
	//����Student��ĺ���
	//����Ĭ�Ϲ��캯��
	Student defaultstudent;
	//���÷�Ĭ�Ϲ��캯��
	Student studentarray[3] = { (Student(333,"Bob")),(Student(111,"John")),(Student(222,"Alice")) };

	//����Addcourse�����ֹ���ʼ������Student����
	studentarray[0].Addcourse("Robotics", 90);
	studentarray[0].Addcourse("C++", 95);
	studentarray[0].Addcourse("Math", 85);
	studentarray[1].Addcourse("Robotics", 85);
	studentarray[1].Addcourse("C++", 95);
	studentarray[1].Addcourse("Math", 90);
	studentarray[2].Addcourse("Robotics", 95);
	studentarray[2].Addcourse("C++", 80);
	studentarray[2].Addcourse("Math", 100);

	//����ShowGrades����չʾ�ĸ�Student����
	defaultstudent.ShowGrades();
	studentarray[0].ShowGrades();
	studentarray[1].ShowGrades();
	studentarray[2].ShowGrades();
	cout << endl;
	
	//����setid��setname����
	defaultstudent.setid(444);
	defaultstudent.setname("LiHua");
	defaultstudent.Addcourse("C++", 100);
	defaultstudent.ShowGrades();
	cout << endl;

	//����getname��getid��GetGrade����
	cout << "defaultstudent's name:" << defaultstudent.getname() << endl;
	cout << "defaultstudent's id:" << defaultstudent.getid() << endl;
	cout << "defaultstudent's grade:\n" << "C++:" << defaultstudent.GetGrade("C++") << endl;
	cout << endl;

	//����SetGrade����
	defaultstudent.SetGrade("C++", 95);
	defaultstudent.ShowGrades();
	cout << endl;

	//���ÿ������캯��
	Student copystudent(defaultstudent);
	copystudent.ShowGrades();




	//***************************************************************************************************************************************************************************************
	//����StudentClass��ĺ���
	//����Ĭ�Ϲ��캯��
	StudentClass defaultClass;
	//���÷�Ĭ�Ϲ��캯��
	StudentClass Class1("sysu201901", studentarray, 3);

	//����ShowStudentByIdOrde����������������
	bool (*function_pointer)(int, int);
	function_pointer = ascending;
	cout << "�����������к�" << endl;
	Class1.ShowStudentsByIdOrder(function_pointer);
	cout << endl;

	//���ÿ������캯��
	StudentClass copy_class(Class1);
	copy_class.ShowStudentsByIdOrder(function_pointer);
	cout << endl;

	//����setcode��getcode����
	Class1.setcode("sysu202001");
	cout << "Class1 's code :" << Class1.getcode() << endl;
	cout << endl;

	//����getstudent����
	Student get_student = Class1.getstudent(111);
	get_student.ShowGrades();
	cout << endl;

	//����AddStudent����
	Class1.AddStudent(&(defaultstudent));
	Class1.ShowStudentsByIdOrder(function_pointer);
	cout << endl;

	//����ShowStudent����
	Class1.ShowStudent(222);
	cout << endl;

	//����ShowStudentsByIdOrder�������н�������
	function_pointer = descending;
	cout << "���н������к�" << endl;
	Class1.ShowStudentsByIdOrder(function_pointer);
	cout << endl;

	//����showStudentCount������ʾ���ж�����ѧ��
	StudentClass::showStudentCount();


	return 0;
}
