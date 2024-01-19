#include<bits/stdc++.h>
#include <sqlite3.h>
#include "dbtab.h"
#include "reg.h"
#include "professor.h"
#include "student.h"
using namespace std;


sqlite3* DB;
int main()
{
	
	int exit = 0;
    	exit = sqlite3_open("example.db", &DB);
    	string fk = "PRAGMA foreign_keys = ON";
    	sqlite3_exec(DB, fk.c_str(), NULL, 0, NULL);
    
  
    	if (exit) 
    	{
        	std::cerr << "Error open DB " << sqlite3_errmsg(DB) << std::endl;
        	return 0;
    	}
    	tables(DB);
    	
	cout<<"Enter number according to your roles:\n";
	cout<<"1 : Registrar\n2 : Student\n3 : Professor\n";
	int num;
	cin>>num;
	if(num == 1)
	{
		// check login credentials of registrar and then ask for functionality;
			// check login credentials of registrar and then ask for functionality;
		int temp = 0;
		string id, password;
		while(true)
		{
			cout<<"Enter ID\n";
			cin>>id;
			cout<<"Enter Password\n";
			cin>>password;
			bool check = checkregistrar(id , password , DB);
			if(check)
			{
				break;
			}
			else
			{
				cout<<"Incorrect credentials\nRe-enter\n";
			}
		}
		int inp = 0;
		while(inp != -1)
		{
			cout<<"Enter the number corresponding to the task to be performed\n";
			cout<<"1:Add Registrar\n2:Add Student\n3:Add Professor\n4:Show all registrars\n5:Show all students\n6:Show all professors\n7:Show all courses\n8:Delete a registrar\n9:Delete a Student\n10:Delete a Professor\n11:Add course\n12:Add student to a Course\n-1: Terminate\n";
			cin>>inp;
			switch (inp) 
			{
			
			  case 1:
			  {
			  	string rid,rname,remail,rpass;
			  	cout<<"Enter Registrar id , name , email and password \n";
			  	cin>>rid>>rname>>remail>>rpass;
			  	addregistrar(rid , rname , remail , rpass , DB);
			  	break;
			  	
			  }
			  case 2:
			  {
			  	string sid , sname , semail , spass, ssem, sdepar;
			  	cout<<"Enter student id , name , email , password , semester , department\n";
			  	cin>>sid>>sname>>semail>>spass>>ssem>>sdepar;
			  	addstudent(sid , sname , semail , spass , ssem , sdepar , DB);
			  	break;
			  	
			  }
			  case 3:
			  {
			  	string pid , pname , pemail , ppass, pdepar;
			  	cout<<"Enter professor id , name , email , password, department\n";
			  	cin>>pid>>pname>>pemail>>ppass>>pdepar;
			  	addprof(pid , pname , pemail , ppass , pdepar , DB);
			  	break;
			  }
			  case 4:
			  {
			  	showregistrar(DB);
			  	break;
			  }
			  case 5:
			  {
			   	showstudent(DB);
			   	break;
			  }
			  case 6:
			  {
			  	showprof(DB);
			  	break;
			  }
			  case 7:
			  {
			  	showcourses(DB);
			  	break;
			  }
			  case 8:
			  {
			  	string rid;
			  	cout<<"Enter the id of registrar to be deleted\n";
			  	cin>>rid;
			  	deleteregist(rid , DB);
			  	break;
			  }
			  case 9:
			  {
			  	string sid;
			  	cout<<"Enter the id of student to be deleted\n";
			  	cin>>sid;
			  	deletestudent(sid , DB);
			  	break;
			  }
			  case 10:
			  {
			  	string pid;
			  	cout<<"Enter the id of professor to be deleted\n";
			  	cin>>pid;
			  	deleteprof(pid , DB);
			  	break;
			  }
			  case 11:
			  {
			       string cid,name,profid;
			       string credit , nc;
			       cout << "Enter course id : \n";
			       cin >> cid ;
			       cout << "Enter course name : \n";
			       cin >> name ;
			       cout << "Enter credits : \n";
			       cin >> credit ;
			       cout << "Enter professor's id : \n";
			       cin >> profid ;
			       cout << "Enter number of classes : \n";
			       cin >> nc ;
			       add_course(cid,name,credit,profid,nc,DB);
			       break;
			  }
			  case 12:
			  {
			        string cid,sid;
			        cout << "Enter Student id and course id \n";
			        cin >> sid >> cid ;
			        add_student_in_course(cid,sid,"0","0",DB);
			        break;
			  }
			  
			  case -1:
			  {
			  	cout<<"*****************************************************************\n\n";
			  	cout<<"Have a great day\n\n";
			  	cout<<"*****************************************************************\n\n";
			  	break;
			  }
			  default:
			    cout << "Invalid Input \n";
			}
  
		
			
		}
		
	}
	else if(num == 2)
	{
		// student activity first login check as student then all functionality
		// check login credentials of student and then ask for functionality;
		int temp = 0;
		string id, password;
		while(true)
		{
			cout<<"Enter ID\n";
			cin>>id;
			cout<<"Enter Password\n";
			cin>>password;
			bool check = checkstudent(id , password , DB);
			if(check)
			{
				break;
			}
			else
			{
				cout<<"Incorrect credentials\nRe-enter";
			}
		}
		int inp = 0;
		while(inp!=-1){
		      cout<<"Enter the number corresponding to the task to be performed\n";
			cout<<"1:Show Attendance\n2:Show Alloted Courses\n3:Show Marks\n4:Show all Offered Courses\n-1:Terminate\n";
			cin>>inp;
			switch (inp) 
			{
			
			  case 1:
			  {
			        string cid;
			        cout<<"Enter the course id whose attendence to be shown: \n";
			        cin>>cid;
			  	showattendance(cid,id, DB);
			  	break;
			  	
			  }
			  case 2:
			  {
			  	showMycourses(id, DB);
			  	break;
			  	
			  }
			  case 3:
			  {
			        string cid;
			        cout<<"Enter the course id whose marks to be shown:\n";
			        cin>>cid;
			  	showmarks(cid,id,DB);
			  	break;
			  }
			  case 4:
			  {
			  	showOfferedCourses(DB);
			  	break;
			  }
			  case -1:
			  {
			  	cout<<"*****************************************************************\n\n";
			  	cout<<"Have a great day\n\n";
			  	cout<<"*****************************************************************\n\n";
			  	break;
			  }
			  default:
			    cout << "Invalid Input \n";
			}
		}
		
	}
	else if(num == 3)
	{
		// professor activity first login check as professor then all functionality
		// check login credentials of prof and then ask for functionality;
		int temp = 0;
		string id, password;
		while(true)
		{
			cout<<"Enter ID\n";
			cin>>id;
			cout<<"Enter Password\n";
			cin>>password;
			bool check = checkprof(id , password , DB);
			if(check)
			{
				break;
			}
			else
			{
				cout<<"Incorrect credentials\nRe-enter";
			}
		}
		int inp = 0;
		while(inp != -1)
		{
			cout<<"Enter the number corresponding to the task to be performed\n";
			cout<<"1:Update Attendance\n2:Update Marks\n3:Finish a course\n4:See all Offered Courses\n-1:Terminate\n";
			cin>>inp;
			switch (inp) 
			{
			
			  case 1:
			  {
			  	string sid,cid, at;
			  	cout<<"Enter Student id , Course Id , Attendance\n";
			  	cin>> sid >> cid >> at;
			  	updateattendance(sid,cid,at,DB);
			  	break;
			  	
			  }
			  case 2:
			  {
			  	string sid,cid , mr;
			  	cout<<"Enter Student id , Course Id , marks\n";
			  	cin>> sid >> cid >> mr;
			  	updatemarks(sid,cid,mr,DB);
			  	break;
			  	
			  }
			  case 3:
			  {
			  	string cid;
			  	cout<<"Enter the course you want to finish\n";
			  	cin>>cid;
			  	finishcourse(cid , DB);
			  	break;
			  }
			  case 4:
			  {
			  	showOfferedCourses(DB);
			  	break;
			  }
			  
			  case -1:
			  {
			  	cout<<"*****************************************************************\n\n";
			  	cout<<"Have a great day\n\n";
			  	cout<<"*****************************************************************\n\n";
			  	break;
			  }
			  default:
			    cout << "Invalid Input \n";
			}
	}}
	closedb(DB);
	return 0;
}	
