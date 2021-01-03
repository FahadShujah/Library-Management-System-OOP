#include "student.h"
#include <iostream>
using namespace std;
student::student()
{

}
void student::display()
{
	cout<<"Student Name: "<<this->name<<endl;
	cout<<"Student Cnic: "<<this->cnic<<endl;
	cout<<"Student Sex: "<<this->sex<<endl;
	cout<<"Student Age: "<<this->age<<endl;
	cout<<"Student Degree: "<<this->degree<<endl;
	cout<<"Student RegNo: "<<this->regno<<endl;
}
void student::bookDisplay(book **arr,int count)
{
	cout<<"The Books of "<<this->name<<" are as follow\n\n";
	for(int i=0;i<count;i++)
	{
		if(!strcmp(arr[i]->getCnic(),this->cnic))
		{
			arr[i]->display();
		}
	}
}
void student::studentinput()
{
	userinput();
	strcpy_s(this->type,"student");
	cout<<"Enter the degree of student: ";
	cin>>degree;
	cout<<"Enter the Regno of student: ";
	cin>>regno;
}
void student::setData(student *t1)
{
	this->age=t1->age;
	strcpy_s(this->type,t1->type);
	strcpy_s(this->cnic,t1->cnic);
	strcpy_s(this->degree,t1->degree);
	strcpy_s(this->name,t1->name);
	strcpy_s(this->sex,t1->sex);
}
char* student::getRegno()
{
	return this->regno;
}

char* student::getDegree()
{
	return this->degree;
}

void student::setRegno(char* regno)
{
	strcpy_s(this->regno,regno);
}

void student::setDegree(char* degree)
{
	strcpy_s(this->degree,degree);
}