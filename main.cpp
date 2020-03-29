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
	//调用Student类的函数
	//调用默认构造函数
	Student defaultstudent;
	//调用非默认构造函数
	Student studentarray[3] = { (Student(333,"Bob")),(Student(111,"John")),(Student(222,"Alice")) };

	//调用Addcourse函数手工初始化三个Student对象
	studentarray[0].Addcourse("Robotics", 90);
	studentarray[0].Addcourse("C++", 95);
	studentarray[0].Addcourse("Math", 85);
	studentarray[1].Addcourse("Robotics", 85);
	studentarray[1].Addcourse("C++", 95);
	studentarray[1].Addcourse("Math", 90);
	studentarray[2].Addcourse("Robotics", 95);
	studentarray[2].Addcourse("C++", 80);
	studentarray[2].Addcourse("Math", 100);

	//调用ShowGrades函数展示四个Student对象
	defaultstudent.ShowGrades();
	studentarray[0].ShowGrades();
	studentarray[1].ShowGrades();
	studentarray[2].ShowGrades();
	cout << endl;
	
	//调用setid，setname函数
	defaultstudent.setid(444);
	defaultstudent.setname("LiHua");
	defaultstudent.Addcourse("C++", 100);
	defaultstudent.ShowGrades();
	cout << endl;

	//调用getname，getid，GetGrade函数
	cout << "defaultstudent's name:" << defaultstudent.getname() << endl;
	cout << "defaultstudent's id:" << defaultstudent.getid() << endl;
	cout << "defaultstudent's grade:\n" << "C++:" << defaultstudent.GetGrade("C++") << endl;
	cout << endl;

	//调用SetGrade函数
	defaultstudent.SetGrade("C++", 95);
	defaultstudent.ShowGrades();
	cout << endl;

	//调用拷贝构造函数
	Student copystudent(defaultstudent);
	copystudent.ShowGrades();




	//***************************************************************************************************************************************************************************************
	//调用StudentClass类的函数
	//调用默认构造函数
	StudentClass defaultClass;
	//调用非默认构造函数
	StudentClass Class1("sysu201901", studentarray, 3);

	//调用ShowStudentByIdOrde函数进行升序排序
	bool (*function_pointer)(int, int);
	function_pointer = ascending;
	cout << "进行升序排列后：" << endl;
	Class1.ShowStudentsByIdOrder(function_pointer);
	cout << endl;

	//调用拷贝构造函数
	StudentClass copy_class(Class1);
	copy_class.ShowStudentsByIdOrder(function_pointer);
	cout << endl;

	//调用setcode，getcode函数
	Class1.setcode("sysu202001");
	cout << "Class1 's code :" << Class1.getcode() << endl;
	cout << endl;

	//调用getstudent函数
	Student get_student = Class1.getstudent(111);
	get_student.ShowGrades();
	cout << endl;

	//调用AddStudent函数
	Class1.AddStudent(&(defaultstudent));
	Class1.ShowStudentsByIdOrder(function_pointer);
	cout << endl;

	//调用ShowStudent函数
	Class1.ShowStudent(222);
	cout << endl;

	//调用ShowStudentsByIdOrder函数进行降序排序
	function_pointer = descending;
	cout << "进行降序排列后：" << endl;
	Class1.ShowStudentsByIdOrder(function_pointer);
	cout << endl;

	//调用showStudentCount函数显示共有多少名学生
	StudentClass::showStudentCount();


	return 0;
}
