
#include "Student.h"
#include <iostream>
#include< iomanip >



class StudentClass {

	//通过静态常变量定义最大学生数 maxStudents_ 为20
	static const int maxStudents_ = 20;
	//通过静态变量保持学生对象个数studentCount_
	static int studentCount_;
	//班级号
	std::string code_; 
	Student* students_[maxStudents_];
	//考虑到某些函数的需要，因此定义一个变量，用于统计一个班级内的学生人数
	int students_num;

public: 
	//构造函数均通过new来实现students_[maxStudents_]的初始化，且每一个都进行了初始化
	//默认构造函数
	StudentClass();
	//非默认构造函数，stu是数组的地址，n是数组的长度，在构造班级时一次将n位学生添加进该班级
	StudentClass(std::string code, Student* stu, int n);
	//拷贝构造函数
	StudentClass(const StudentClass& stuc);
	//析构函数，将new出来的内存全部delete掉
	~StudentClass();
	void setcode(std::string code);
	std::string getcode()const { return code_; }
	//返回student对象的函数
	Student getstudent(int id)const;



	bool AddStudent(const Student* student);
	void ShowStudent(int id) const;
	void ShowStudentsByIdOrder(bool (*compare)(int, int));
	static void showStudentCount() { cout << "现共有" << studentCount_ << "位学生" << endl; }
};

