#include "book.h"
book::book()
{

}
book::book(const book &obj)
{
	this->id=obj.id;
	strcpy_s(this->author,obj.author);
	strcpy_s(this->name,obj.name);
	strcpy_s(this->status,obj.status);
	strcpy_s(this->cnic,obj.cnic);
}
void book::bookInput()
{

	strcpy_s(this->cnic,"");
	strcpy_s(this->status,"available");
	cout<<"Enter the ID of book: ";
	cin>>id;
	fflush(stdin);
	cout<<"Enter the Name of book: ";
	cin.getline(name,100);
	cout<<"Enter the Author: ";
	cin.getline(author,30);
	cout<<"The book is added to the system\n";
}

void book::display()
{
	cout<<"\n";
	cout<<"The ID of Book: "<<this->id<<endl;
	cout<<"The Name of Book: "<<this->name<<endl;
	cout<<"The Author of Book: "<<this->author<<endl;
	cout<<"\n";
	
}
void book::operator++() 
{
	this->setStatus("occupied");
}

void book::operator--() 
{
	this->setStatus("available");
}

char* book::getCnic()
{
	return this->cnic;
}

int book::getId()
{
	return this->id;
}

char* book::getName()
{
	return this->name;
}

char* book::getStatus()
{
	return this->status;
}

char* book::getAuthor()
{
	return this->author;
}

void book::setId(int id)
{
	this->id=id;
}


void book::setCnic(char* cnic)
{
	strcpy_s(this->cnic,cnic);
}

void book::setName(char* name)
{
	strcpy_s(this->name,name);
}

void book::setStatus(char* status)
{
	strcpy_s(this->status,status);
}

void book::setAuthor(char* author)
{
	strcpy_s(this->author,author);
}

