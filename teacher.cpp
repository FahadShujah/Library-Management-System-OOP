#include "teacher.h"
#include <iostream>
using namespace std;
teacher::teacher()
{

}
void teacher::teacherinput()
{
	userinput();
	strcpy_s(this->type,"teacher");
	cout<<"Enter the Department: ";
	cin>>department;
	cout<<"Enter the Position: ";
	cin>>position;
}
void teacher::display()
{
	cout<<"Teacher Name: "<<this->name<<endl;
	cout<<"Teacher Cnic: "<<this->cnic<<endl;
	cout<<"Teacher Sex: "<<this->sex<<endl;
	cout<<"Teacher Age: "<<this->age<<endl;
	cout<<"Teacher Department: "<<this->department<<endl;
	cout<<"Teacher Position: "<<this->position<<endl;
}
void teacher::bookDisplay(book **arr,int count)
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
void teacher::setData(teacher *t1)
{
	this->age=t1->age;
	strcpy_s(this->type,t1->type);
	strcpy_s(this->cnic,t1->cnic);
	strcpy_s(this->department,t1->department);
	strcpy_s(this->name,t1->name);
	strcpy_s(this->sex,t1->sex);
	strcpy_s(this->position,t1->position);
}
char* teacher::getDepartment()
{
	return this->department;
}

char* teacher::getPosition()
{
	return this->position;
}

void teacher::setDepartment(char* department)
{
	strcpy_s(this->department,department);
}

void teacher::setPosition(char* position)
{
	strcpy_s(this->position,position);
}