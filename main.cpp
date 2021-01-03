#include "student.h"
#include <conio.h>
#include <fstream>
#include <iostream>
#include <windows.h>
using namespace std;
int u_count=0;
int b_count=0;
user* users[2000]; 
book* books[2000];
void assignBook(int &b_index,int &u_index,char* type,bool &g_check);
int deAssignBook();
bool checkUser(char*,int&);
void displayBooks(char* str1);

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}





void m()
{system("COLOR 02");
char a=char(219);
cout<<a;
}
 
		 //*****************************************************************
		 //                           LOGIN FUNCTION      login()
		 //****************************************************************
void login()

{
	float i;
	char user[10]="Ahmad";
	char password[10]="12345";
	char password1[10];
	char username[10];
	system("COLOR 06");
	
	

	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t ENTER USER NAME:");
	gets(username);
	
	
	printf("\n\t\t ENTER PASSWORD:");
		
	gets(password1);
	if(strcmp(user,username)==0 && strcmp(password,password1)==0)
	{
		gotoxy(35,24);
		printf(" Access guranted ....");
		Sleep(1);
		gotoxy(5,3);
		printf("\n\t\t        PROCESSING LIBRARY MANAGEMENT SYSTEM......");
		gotoxy(0,9);
			printf("-------------------------------------------------------------------------------\n");
			
			
			
			
			printf("\n-------------------------------------------------------------------------------");
			
	
			
			
			gotoxy(0,10);
			for(i=1;i<=80;i++)
			{
				m();
				
				Sleep(100);
			}
			
			//textcolor(WHITE);
			
		
		gotoxy(5,7);
		
		printf(" Completed... 100");
		printf("\n Progress is finished................. ");
		Sleep(2000);
		system("cls");
	}
	else
	{
		gotoxy(5,20);
		printf(" Invalid user name or Password.");
		exit(0);
		
	}
	
}
 

void main()
{
	login();

	int function;
	// Reading the file from file teacher.text and converting the teacher into user and using dynamic input filling the function setData which is only present
	// in teacher class
	ifstream infile ("teacher.txt",ios::in|ios::binary);
	teacher *temp=new teacher(); 
	while(infile.read(reinterpret_cast<char* >( temp), sizeof(  teacher ) ))
	{
	users[u_count]=new teacher();
	dynamic_cast<teacher*>(users[u_count])->setData(temp);
	u_count++;
	}
	infile.close(); //closing the file

	// Reading the file from file student.text and converting the student into user and using dynamic input filling the function setData which is only present
	// in student class
	ifstream infile1 ("student.txt",ios::in|ios::binary);
	student *temp1=new student(); 
	while(infile1.read(reinterpret_cast<char* >( temp1), sizeof(  student ) ))
	{
	users[u_count]=new student();
	dynamic_cast<student*>(users[u_count])->setData(temp1);

	
	u_count++;
	}
	infile.close(); //closing the file
	
	// reading the book file and not using dynamic input as it is a seperate class

	ifstream infile2 ("book.txt",ios::in|ios::binary);
	book temp2;
	while(infile2.read(reinterpret_cast<char* >( &temp2), sizeof(  book ) ))
	{
	books[b_count]=new book(temp2);
	b_count++;
	}
	infile.close();//closing the file
	
	
	
	HANDLE  hConsole;
	int color;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	while(true)
	{
		color=3;
		SetConsoleTextAttribute(hConsole, color);
		cout<<"\n\t\t\tWelcome to Library Management System\n\n"
			<<"For Teacher Menu                 Press 1\n"
			<<"For Student Menu                 Press 2\n"
			<<"To Add a Book in the System      Press 3\n"
			<<"To Search a Book in the System   Press 4\n"
			<<"To Exit the Program              Press 5\n";
		
		
		
		cin>>function;
		while(function < 1 || function>6)
		{
			cout<< "Error!! please enter the option again."<<endl;
			cin>> function;
			
		}
	


	switch(function) //function is the variable in which the option is stored
	{
		case 1:
		{
			int t_function;
			system("cls");
			while(true)
			{
				color=3;
				SetConsoleTextAttribute(hConsole, color);
				cout<<"To Add Teacher in the System        Press 1\n"
					<<"To Assign Teacher a Book            Press 2\n"
					<<"To Deassign Teacher a Book          Press 3\n"
					<<"To Display the books of Teacher     Press 4\n"
					<<"To Display the info of Teacher      Press 5\n"
					<<"To Go to Main Menu                  Press 6\n";
			
				
			cin>> t_function;
			while(t_function < 1 || t_function>6)
		    {
			cout<< "Error!! please enter the option again."<<endl;
			cin>> t_function;
			
		    }
			
			
			
			
			
			if(t_function==1) //To Add Teacher in the System
				{
					ofstream outfile ("teacher.txt",ios::out|ios::binary|ios::app);
					teacher *temp=new teacher(); 
					//dynamic_cast<teacher*>(temp)->teacherinput();
					temp->teacherinput();
					
					outfile.write(reinterpret_cast<const char*>( temp), sizeof( teacher ) );
					outfile.close();
					users[u_count]=temp;//pointer user[2000] stores the pointer temp which has the teacher input
					u_count++;
					
					
					color=2;
					SetConsoleTextAttribute(hConsole, color);
					cout<<"\n\nThe Teacher "<<temp->getName()<<" is added to System\n\n";
				}
			
			
			
			else if(t_function==2)
				{
					bool g_check=false;
					int b_index; //book index
					int u_index;
					assignBook(b_index,u_index,"teacher",g_check);
					if(g_check)
					{
						(*books[b_index])++;
						books[b_index]->setCnic(users[u_index]->getCnic());
						fstream outfile ("book.txt",ios::out|ios::binary|ios::in);
						int pos=b_index*sizeof( book );
						outfile.seekp(pos, ios::beg);
						outfile.write(reinterpret_cast<const char*>( books[b_index]), sizeof( book ) );
						outfile.close();
						color=2;
						SetConsoleTextAttribute(hConsole, color);
						cout<<"\n\nThe Teacher "<<users[u_index]->getName()<<" occupied Book "<<books[b_index]->getName()<<"\n\n";
					}
				}
				else if(t_function==3)
				{
					int b_index=deAssignBook();
					int deAssignBook();

					fstream outfile ("book.txt",ios::out|ios::binary|ios::in);
					int pos=b_index*sizeof( book );
					outfile.seekp(pos, ios::beg);
					outfile.write(reinterpret_cast<const char*>( books[b_index]), sizeof( book ) );
					outfile.close();
					color=2;
					SetConsoleTextAttribute(hConsole, color);
					cout<<"\n\nThe Book "<<books[b_index]->getName()<<" has been deassigned\n\n";

				}
				else if(t_function==4)
				{
					char option;
					bool u_check=false;
					int u_index;
					do
					{
						u_check=false;
						option='n';
						char cnic[40];
						cout<<"Enter the Cnic of Teacher: ";
						cin>>cnic;
						if(!checkUser(cnic,u_index))
						{
							cout<<"No teacher exist in the system with this Cnic\n";
							cout<<"To enter the id again press y else press n\n";
							cin>>option;
						}
						else
						{
							u_check=true;
						}
					}while(option=='y'||option=='Y');
					if(u_check)
					{
						color=2;
						SetConsoleTextAttribute(hConsole, color);
						users[u_index]->bookDisplay(books,b_count);
						cout<<"\n\n";
					}
				}
				else if(t_function==5)
				{
					char option;
					bool u_check=false;
					int u_index;
					do
					{
						u_check=false;
						option='n';
						char cnic[40];
						cout<<"\n\nEnter the Cnic of Teacher: ";
						cin>>cnic;
						if(!checkUser(cnic,u_index))
						{
							cout<<"No teacher exist in the system with this Cnic\n";
							cout<<"To enter the id again press y else press n\n";
							cin>>option;
						}
						else
						{
							u_check=true;
						}
					}while(option=='y'||option=='Y');
					if(u_check)
					{
						color=2;
						SetConsoleTextAttribute(hConsole, color);
						users[u_index]->display();
						cout<<"\n\n";
					}
				}
				else if(t_function==6)
				{
					break;
				}
			}	
		
		break;
		}
		case 2:
		{
			int t_function1;
			
			system("cls");
			while(true)
			{
				cout<<"To Add Student in the System        Press 1\n"
					<<"To Assign Student a Book            Press 2\n"
					<<"To Deassign Student a Book          Press 3\n"
					<<"To Display the books of Student     Press 4\n"
					<<"To Display the info of Student      Press 5\n"
					<<"To Go to Main Menu                  Press 6\n";
				cin>> t_function1;
				while(t_function1 < 1 || t_function1>6)
		    {
			cout<< "Error!! please enter the option again."<<endl;
			cin>> t_function1;
			
		    }
				if(t_function1==1)
				{
					ofstream outfile ("student.txt",ios::out|ios::binary|ios::app);
					student *temp=new student(); 
					temp->studentinput(); 
					outfile.write(reinterpret_cast<const char*>( temp), sizeof( student ) ); //write temp in the file
					outfile.close();
					users[u_count]=temp;
					u_count++;
					
					
					color=2;
					SetConsoleTextAttribute(hConsole, color);
					cout<<"\n\nThe Student "<<temp->getName()<<" is added to System\n\n";
				}
				else if(t_function1==2)
				{
					bool g_check=false;
					int b_index;
					int u_index;
					assignBook(b_index,u_index,"student",g_check);
					if(g_check)
					{
						(*books[b_index])++;
						books[b_index]->setCnic(users[u_index]->getCnic());
						fstream outfile ("book.txt",ios::out|ios::binary|ios::in);
						int pos=b_index*sizeof( book );
						outfile.seekp(pos, ios::beg);
						outfile.write(reinterpret_cast<const char*>( books[b_index]), sizeof( book ) );
						outfile.close();
						color=2;
						SetConsoleTextAttribute(hConsole, color);
						cout<<"\n\nThe Student "<<users[u_index]->getName()<<" occupied Book "<<books[b_index]->getName()<<"\n\n";
					}
				}
				else if(t_function1==3)
				{
					int b_index=deAssignBook();
					fstream outfile ("book.txt",ios::out|ios::binary|ios::in);
					int pos=b_index*sizeof( book );
					outfile.seekp(pos, ios::beg);
					outfile.write(reinterpret_cast<const char*>( books[b_index]), sizeof( book ) );
					outfile.close();
					color=2;
					SetConsoleTextAttribute(hConsole, color);
					cout<<"\n\nThe Book "<<books[b_index]->getName()<<" has been deassigned\n\n";

				}
				else if(t_function1==4)
				{
					char option;
					bool u_check=false;
					int u_index;
					do
					{
						u_check=false;
						option='n';
						char cnic[40];
						cout<<"Enter the Cnic of Student: ";
						cin>>cnic;
						if(!checkUser(cnic,u_index))
						{
							cout<<"No Student exist in the system with this Cnic\n";
							cout<<"To enter the id again press y else press n\n";
							cin>>option;
						}
						else
						{
							u_check=true;
						}
					}while(option=='y'||option=='Y');
					if(u_check)
					{
						color=2;
						SetConsoleTextAttribute(hConsole, color);
						users[u_index]->bookDisplay(books,b_count);
						cout<<"\n\n";
					}
				}
				else if(t_function1==5)
				{
					char option;
					bool u_check=false;
					int u_index;
					do
					{
						u_check=false;
						option='n';
						char cnic[40];
						cout<<"\n\nEnter the Cnic of Student: ";
						cin>>cnic;
						if(!checkUser(cnic,u_index))
						{
							cout<<"No Student exist in the system with this Cnic\n";
							cout<<"To enter the id again press y else press n\n";
							cin>>option;
						}
						else
						{
							u_check=true;
						}
					}while(option=='y'||option=='Y');
					if(u_check)
					{
						color=2;
						SetConsoleTextAttribute(hConsole, color);
						users[u_index]->display();
						cout<<"\n\n";
					}
				}
				else if(t_function1==6)
				{
					break;
				}
			}	
		}
			break;
		case 3:
		{
			ofstream outfile ("book.txt",ios::out|ios::binary|ios::app);
			book temp;
			temp.bookInput();
			outfile.write(reinterpret_cast<const char*>( &temp), sizeof( book ) );
			outfile.close();
			books[b_count]=new book(temp);
			b_count++;
		}
			break;
		case 4:
		{
			char str[50];
			cout<<"Enter the keyword: ";
			cin>>str;
			color=2;
			SetConsoleTextAttribute(hConsole, color);
			displayBooks(str);
		}
			break;
		case 5:
		{
			exit(0);
		}
			break;
		}
	}
}
int deAssignBook()
{
		    int id;
			char option;
			bool g_check=false;
			int b_index;
			do
			{
				option='n';
				bool b_check=false;
				bool a_check=false;
				cout<<"\nInput the book ID: ";
				cin>>id;
				for(int i=0;i<b_count;i++)
				{
					if(id==books[i]->getId())
					{
						if(strcmp(books[i]->getStatus(),"occupied"))
						{
							cout<<"The book is not occupied\n";
						}
						else
						{
							g_check=true;
							a_check=true;
							b_index=i;
						}
						b_check=true;
						break;
					}
				}
				if(!b_check)
				{
					cout<<"Book doesnot exist in system\n";
				}
				if(!a_check)
				{
					cout<<"Want to input the id again press y else press n\n";
					option=getch();
				}
				cout<<"\n";
			}while(option=='y' ||option=='Y');
			if(g_check)
			{
				(*books[b_index])--;
				books[b_index]->setCnic("");
			}
			return b_index;
}
bool checkUser(char* cnic,int &index)
{
	for(int i=0;i<u_count;i++)
	{
		if(!strcmp(users[i]->getCnic(),cnic))
		{
			index=i;
			return true;
		}
	}
	return false;
}
void assignBook(int &b_index,int &u_index,char *type,bool &g_check)
{
			int id;
			char option;
			do
			{
				option='n';
				bool b_check=false;
				bool a_check=false;
				cout<<"\nInput the book ID: ";
				cin>>id;
				for(int i=0;i<b_count;i++)
				{
					if(id==books[i]->getId())
					{
						if(strcmp(books[i]->getStatus(),"available"))
						{
							cout<<"The book is occupied\n";
						}
						else
						{
							g_check=true;
							a_check=true;
							b_index=i;
						}
						b_check=true;
						break;
					}
				}
				if(!b_check)
				{
					cout<<"Book doesnot exist in system\n";
				}
				if(!a_check)
				{
					cout<<"Want to input the id again press y else press n\n";
					option=getch();
				}
				cout<<"\n";
			}while(option=='y' ||option=='Y');
			if(g_check)
			{
				g_check=false;
				char cnic[40];
				bool u_check=false;
				char option;
				do
				{
					option='n';
					cout<<"\nEnter the Cnic of "<<type<<": ";
					cin>>cnic;
					for(int i=0;i<u_count;i++)
					{
						if(!strcmp(users[i]->getType(),type))
						{
							if(!strcmp(users[i]->getCnic(),cnic))
							{
								u_index=i;
								u_check=true;
								g_check=true;
							}
						}
					}
					if(!u_check)
					{
						cout<<type<<" doesnot exist in system\n";
						cout<<"Want to input the id again press y else press n\n";
						option=getch();
					}
				}while(option=='y' ||option=='Y');
			}
}
void displayBooks(char* str1)
{
	str1=strlwr(str1);
	bool mycheck=false;
	for(int i=0;i<b_count;i++)
	{
		char *str2=strlwr(books[i]->getName());
		string s1=str1;
		string s2=str2;
		if (s2.find(s1) != string::npos) 
		{
			books[i]->display();
			mycheck=true;
		}
	}
	if(!mycheck)
		cout<<"\nNo book found for given keyword\n";
}