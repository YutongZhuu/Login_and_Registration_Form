/*Yutong Zhu
Login and registration page
*/
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void file_checker();
void login();
void registration();
void forgot_password();

int main()
{ 
	system("cls");
	ofstream FileOut_e ("records.txt", ios::app);
	FileOut_e.close();
	
	ifstream FileIn ("records.txt", ios::in);
	char x;
	FileIn>>x;
	bool check_empty=0;
	if (FileIn.eof())
	{
		check_empty=1;
	}
	FileIn.close();
	
	if (check_empty==1)
	{
		ofstream FileOut ("records.txt", ios::app);
		FileOut<<"*** ***"<<endl;
		FileOut.close();
		
	}
	
	//Another file
	ofstream FO_e ("security_questions.txt", ios::app);
	FileOut_e.close();
	
	ifstream FI ("security_questions.txt", ios::in);
	char y;
	FI>>y;
	bool check_e=0;
	if (FI.eof())
	{
		check_e=1;
	}
	FI.close();
	
	if (check_e==1)
	{
		ofstream FO ("security_questions.txt", ios::app);
		FO<<"*** *** *** ***"<<endl;
		FO.close();
	}
	
	cout<<"_________________________WELCOME_________________________"<<endl<<
	"LOGIN(0)"<<endl<<"REGISTRATION(1)"<<endl<<"FORGOT PASSWORD(2)"<<endl<<
	"EXIT(3)";
	int q=0;
	cin>>q;
	if (q==1)
	registration();
	else if (q==0)
	login();
	else if (q==2)
	forgot_password();
	else
	{	
		system("cls");
		cout<<"Thank you for using this program!";
		
		return EXIT_SUCCESS;	
	}
}


void registration()//function for register.
{
	string username=" ";
	string password=" ";
	bool match=0;
	
	do//Create a username, and check if the username has been occupied.
	{
		system("cls");
		cout<<"_________________________REGISTER_________________________"<<endl;
		cout<<"CREATE A USERNAME: ";
		cin>>username;
		ifstream FileIn ("records.txt");
		string username_r=" ";
		string password_r=" ";
		
		while (FileIn>>username_r>>password_r)
		{
			if (username_r!=username)
			{
				match=1;
			}
			else
			{
				cout<<"THIS USERNAME HAS BEEN OCCUPIED!"<<endl
				<<"Enter 1 TO CONTINUE!";
				bool x=1;
				cin>>x;
				if (x==1);
				registration();
			}
		}
		FileIn.close();
	}while (match==0);
	
	bool successful=0;
	do//Create a password, check if the user entered the same password twice.
	{
		system("cls");
		cout<<"_________________________REGISTER_________________________"<<endl;
		cout<<"CREATE A USERNAME: "<<username;
		cout<<endl<<"CREATE A PASSWORD: ";
		cin>>password;
		cout<<"CONFIRM YOUR PASSWORD: ";
		string password_r=" ";
		cin>>password_r;
		if (password_r==password)
		successful=1;
		else
		{
			cout<<endl<<"TWO PASSWORDS DID NOT MATCH, TRY AGAIN."<<endl<<
			"ENTER 1 TO CONTINUE."<<endl;;
			bool x=0;
			cin>>x;
			if (x==1)
			registration();
		}
	}while (successful==0);
	
	ofstream FileOut2 ("records.txt", ios::app);
	FileOut2<<username<<' '<<password<<endl;
	FileOut2.close();
	
	system("cls");//Setting a security question.
	cout<<"________________________SECURITY_QUESTION__________________________"
	<<endl<<"LET US SET A SECURITY QUESTION"<<
	endl<<endl<<"ENTER A QUESTION ABOUT SOMETHING ONLY YOU KNOW: ";
	string question=" ";
	cin>>question;
	cout<<endl<<"ENTER THE ANSWER: ";
	string answer=" ";
	cin>>answer;
	ofstream FO ("security_questions.txt", ios::app);
	FO<<username<<' '<<question<<' '<<answer<<' '<<password<<endl;

	cout<<"______________________REGISTERED SUCCESSFULLY______________________"
	<<endl<<"LOGIN?(0)"<<endl<<"GO BACK TO MAIN MENU?(1)";
	bool choice=0;
	cin>>choice;
	if (choice==0)
	login();
	else
	main();
	
}


void forgot_password()//function of finding password
{
	system("cls");
	cout<<"___________________________PASSWORD RESET___________________________"
	<<endl;
	
	cout<<"ENTER YOUR USERNAME: ";//check if the account exist
	string username= " ";
	cin>>username;
	ifstream FileIn("security_questions.txt");
	
	bool match=0;
	string username_s; string question_s; string answer_s; string password_s;
	while (FileIn>>username_s>>question_s>>answer_s>>password_s)
	{
		if (username==username_s)
		{
			match=1;
			string question=question_s;
			string answer=answer_s;
		}
	} 
	if (match!=1)
	{
		system("cls");
		cout<<"USERNAME DOES NOT EXIST!"<<endl<<"TRY AGIAN?(0)"<<endl<<
		"BACK TO THE MAIN MENU.(1)"<<endl;
		bool x = 0;
		cin>>x;
		if (x==0)
		forgot_password();
		else 
		main();
	}
	else
	{
		bool c=0;
		do//check if the answer matches the answer recorded before
		{
			cout<<"ANSWER THE SECURITY QUESTION BELOW."<<endl<<question_s<<endl;
			string answer_u;
			cin>>answer_u;
			if(answer_u==answer_s)
			{
				cout<<"Your password is "<<password_s<<endl<<"Login?(0)"<<"BACK TO THE MAIN MENU?(1)"<<endl;
				bool y;
				cin>>y;
				if (y==1)
				login();
				else
				main(); 
			}
			else
			{
				cout<<"INCORRECT ANSWER!"<<endl<<"RETRY?(0)"<<"BACK TO THE MAIN MENU?(1)"<<endl;
				cin>>c;
				if (c==1)
				main();
			} 
		}while (c==0);
		
	}
	FileIn.close();
}


void login()//function for login
{
	int choice=-1;
	do
	{
		system("cls");
		cout<<"__________________________LOGIN__________________________"<<endl;
		string username=" ";
		string password=" ";
		cout<<"ENTER USERNAME: ";
		cin>>username;
		cout<<endl<<"ENTER PASSWORD: ";
		cin>>password;
		
		
		ifstream FileIn("records.txt"); 
		string username_r=" ";
		string password_r=" ";
		bool matching=0;
		
		
		while (FileIn>>username_r>>password_r)//check if the password matches the password recorded
		{
			if (username_r==username&&password_r==password)
			matching=1;
			else
			matching=0;
		}
		
		
		if (matching==1)
		{
			system("cls");
			cout<<"___________________LOGIN SECCESSFULLY___________________"
			<<endl;
			break;
		}
		else
		{
		cout<<"INCORRECT PASSWORD OR USERNAME!"<<endl<<"RETYPE(0)"<<
		endl<<"CREATE A NEW ACCOUNT?(1)"<<endl<<"FORGOT PASSWORD?(2)"<<
		endl<<"BACK TO MAIN MENU?(3)"<<endl; 
		cin>>choice;
		}
		FileIn.close();
	}while (choice==0);
	if (choice==1)
	registration();
	else if (choice ==2)
	forgot_password();
	else if(choice==3)
	main();
}
