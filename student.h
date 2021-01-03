#include "teacher.h"

class student: public user
{
private:
	char regno[20];
	char degree[30];
public:
	student();
	void setRegno(char*);
	void setDegree(char*);
	char* getRegno();
	char* getDegree();
	void input();
	void display();
	void setData(student *t1);
	void studentinput();
	void bookDisplay(book **arr,int count);
};