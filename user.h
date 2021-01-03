#include <iostream>
using namespace std;
#include "book.h"
class user 
{
protected:
	char name[30];
	char cnic[40];
	int age;
	char sex[2];
	char type[10];
public:
	user();
	void setName(char* );
	void setCnic(char*);
	void setName(int age);
	void setSex(char*);
	void setType(char*);
	char* getType();
	char* getName();
	char* getCnic();
	char* getSex();
	int getAge();
	void userinput();
	virtual void display()=0;
	virtual void bookDisplay(book **arr,int count)=0;
};