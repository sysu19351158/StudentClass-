#ifndef	 _XXXX_
#define  _XXXX_

#include <iostream>
#include< iomanip >
using namespace std;


class Student {


private:
	friend class StudentClass;
	static const int maxCourses = 3;
	int id_;
	std::string name_;
	std::string courseNames[maxCourses];
	double grades_[maxCourses];
public:
	//Ĭ�Ϲ��캯��
	Student();
	//��Ĭ�Ϲ��캯��
	Student(int id, std::string name);
	//�������캯��
	Student(const Student& stu);
	void setid(int id);
	void setname(std::string name);
	int getid() const { return id_; }
	std::string getname() const { return name_; }

	bool Addcourse(const std::string& courseName, double grade);
	void SetGrade(const std::string& courseName, double grade);
	double GetGrade(const std::string courseName)const;
	void ShowGrades()const;


};

#endif