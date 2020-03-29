
#include "Student.h"
#include <iostream>
#include< iomanip >



class StudentClass {

	//ͨ����̬�������������ѧ���� maxStudents_ Ϊ20
	static const int maxStudents_ = 20;
	//ͨ����̬��������ѧ���������studentCount_
	static int studentCount_;
	//�༶��
	std::string code_; 
	Student* students_[maxStudents_];
	//���ǵ�ĳЩ��������Ҫ����˶���һ������������ͳ��һ���༶�ڵ�ѧ������
	int students_num;

public: 
	//���캯����ͨ��new��ʵ��students_[maxStudents_]�ĳ�ʼ������ÿһ���������˳�ʼ��
	//Ĭ�Ϲ��캯��
	StudentClass();
	//��Ĭ�Ϲ��캯����stu������ĵ�ַ��n������ĳ��ȣ��ڹ���༶ʱһ�ν�nλѧ����ӽ��ð༶
	StudentClass(std::string code, Student* stu, int n);
	//�������캯��
	StudentClass(const StudentClass& stuc);
	//������������new�������ڴ�ȫ��delete��
	~StudentClass();
	void setcode(std::string code);
	std::string getcode()const { return code_; }
	//����student����ĺ���
	Student getstudent(int id)const;



	bool AddStudent(const Student* student);
	void ShowStudent(int id) const;
	void ShowStudentsByIdOrder(bool (*compare)(int, int));
	static void showStudentCount() { cout << "�ֹ���" << studentCount_ << "λѧ��" << endl; }
};

