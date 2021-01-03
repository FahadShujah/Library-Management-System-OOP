#include <iostream>
using namespace std;
class book
{
private:
	int id;
	char name[200];
	char author[30];
	char status[20];
	char cnic[20];
public:
	book();
	void operator++();
	void operator--();
	book(const book &obj);
	void display();
	void checkStatus(int id);
	void setId(int id);
	void setName(char*);
	void setAuthor(char*);
	void setStatus(char*);
	void setCnic(char*);
	int getId();
	char* getName();
	char* getAuthor();
	char* getStatus();
	char* getCnic();
	void bookInput();
};