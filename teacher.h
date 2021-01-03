#include "user.h"
class teacher: public user
{
private:
	char department[30];
	char position[20];
public:
	teacher();
	void setDepartment(char* department);
	void setPosition(char* position);
	char* getDepartment();
	char* getPosition();
	void teacherinput();
	void display();
	void setData(teacher *t1);
	void bookDisplay(book **arr,int count);
};