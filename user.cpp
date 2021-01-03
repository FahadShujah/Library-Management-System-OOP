#include "user.h"
#include <iostream>
using namespace std;
user::user()
{

}
void user::setType(char *type)
{
	strcpy_s(this->type,type);
}
void user::setName(char* name)
{
	strcpy_s(this->name,name);
}
void user::setCnic(char *cnic)
{
	strcpy_s(this->cnic,cnic);
}
void user::setName(int age)
{
	this->age=age;
}
void user::setSex(char *sex)
{
	strcpy_s(this->sex,sex);
}
char* user::getType()
{
	return this->type;
}
char* user::getName()
{
	return this->name;
}
char* user::getCnic()
{
	return this->cnic;
}
char* user::getSex()
{
	return this->sex;
}
int user::getAge()
{
	return this->age;
}

void user::userinput()
{
	cout<<"Enter the Name: ";
	cin>>name;
	fflush(stdin);
	cout<<"Enter the Cnic: ";
	cin>>cnic;
	cout<<"Enter the Sex: ";
	cin>>sex;
	cout<<"Enter the Age: ";
	cin>>age;
}