#ifndef REG_H
#define REG_H

#include<bits/stdc++.h>
#include <sqlite3.h>

using namespace std;
string origpassreg = "{}";

static int callback(void* data, int argc, char** argv, char** azColName)
{
    int i;
  
    for (i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    
    printf("\n\n");
    return 0;
}

static int passvaluereg(void* data, int argc, char** argv, char** azColName)
{
    int i;
    if(argc != 1)
    	return 0;
    for (i = 0; i < argc; i++) {
        origpassreg = argv[i];
    }
    
    printf("\n\n");
    return 0;
}

bool checkregistrar(string id , string password , sqlite3* DB)
{
	string query = "select password from registrar where id='"+ id +"';";
	sqlite3_exec(DB, query.c_str(), passvaluereg, NULL, NULL);
	return (origpassreg == password);
}

void addregistrar(string rid ,string rname ,string remail ,string rpass ,sqlite3* DB)
{
   char* messaggeError;
    int exit ;
    string sql = "insert into registrar values('" + rid +"', '" + rname  + "', '"+ remail +"' , '"+ rpass+"');";
    
   cout<<"*****************************************************************\n\n";
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);
    if (exit != SQLITE_OK) {
        std::cerr << "Error Insert" << std::endl;
        sqlite3_free(messaggeError);
    }
    else
        std::cout << "Records created Successfully!" << std::endl;
     cout<<"*****************************************************************\n\n";

}

void addstudent(string sid ,string sname ,string semail ,string spass ,string ssem , string sdepar ,sqlite3* DB)
{
   char* messaggeError;
    int exit ;
    string sql = "insert into student values('" + sid +"', '" + sname  + "', '"+ semail +"' , '"+ spass+"' , "+ssem+" , '" +sdepar +"');";
    
   cout<<"*****************************************************************\n\n";
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);
    if (exit != SQLITE_OK) {
        std::cerr << "Error Insert" << std::endl;
        sqlite3_free(messaggeError);
    }
    else
        std::cout << "Records created Successfully!" << std::endl;
     cout<<"*****************************************************************\n\n";

}

void addprof(string pid ,string pname ,string pemail ,string ppass , string pdepar ,sqlite3* DB)
{
   char* messaggeError;
    int exit ;
    string sql = "insert into professor values('" + pid +"', '" + pname  + "', '"+ pemail +"' , '"+ ppass+"' , '" +pdepar +"');";
    
   cout<<"*****************************************************************\n\n";
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);
    if (exit != SQLITE_OK) {
        std::cerr << "Error Insert" << std::endl;
        sqlite3_free(messaggeError);
    }
    else
        std::cout << "Records created Successfully!" << std::endl;
     cout<<"*****************************************************************\n\n";

}

void showregistrar(sqlite3* DB)
{
	string query = "select id,name,email from registrar;";
	cout<<"*****************************************************************\n\n";
	sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);
	cout<<"*****************************************************************\n\n";
}

void showprof(sqlite3* DB)
{
	string query = "select id,name,email,department from professor;";
	cout<<"*****************************************************************\n\n";
	sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);
	cout<<"*****************************************************************\n\n";
	
}

void showstudent(sqlite3* DB)
{
	string query = "select id,name,email,semester,department from student;";
	cout<<"*****************************************************************\n\n";
	sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);
	cout<<"*****************************************************************\n\n";
}

void showcourses(sqlite3* DB)
{
	string query = "select * from course;";
	cout<<"*****************************************************************\n\n";
	sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);
	cout<<"*****************************************************************\n\n";
}

void deleteprof(string pid , sqlite3* DB)
{
    int exit;
    char* messaggeError;
    cout<<"*****************************************************************\n\n";
    string sql = "delete from professor where id = '" + pid+"';";
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);
    if (exit != SQLITE_OK) {
        std::cerr << "Error DELETE" << std::endl;
        sqlite3_free(messaggeError);
    }
    else
        std::cout << "Record deleted Successfully!\n";
    cout<<"*****************************************************************\n\n";
}


void deletestudent(string sid , sqlite3* DB)
{
    int exit;
    char* messaggeError;
    string sql = "delete from student where id = '" + sid+"';";
    cout<<"*****************************************************************\n\n";
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);
    if (exit != SQLITE_OK) {
        std::cerr << "Error DELETE" << std::endl;
        sqlite3_free(messaggeError);
    }
    else
        std::cout << "Record deleted Successfully!\n";
    cout<<"*****************************************************************\n\n";
}

void deleteregist(string rid , sqlite3* DB)
{
    int exit;
    char* messaggeError;
    cout<<"*****************************************************************\n\n";
    string sql = "delete from registrar where id = '" + rid+"';";
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);
    if (exit != SQLITE_OK) {
        std::cerr << "Error DELETE" << std::endl;
        sqlite3_free(messaggeError);
    }
    else
        cout << "Record deleted Successfully!\n";
    cout<<"*****************************************************************\n\n";
}
void add_student_in_course(string cid,string sid,string at,string mr,sqlite3* DB)
{
  char* messaggeError;
    int exit ;
    
   string sql = "insert into sturegist values('" + cid +"', '" + sid + "', "+ at +" , "+ mr +" );";
    
   cout<<"*****************************************************************\n\n";
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);
    if (exit != SQLITE_OK) {
        std::cerr << "Error Insert" << std::endl;
        sqlite3_free(messaggeError);
    }
    else
        std::cout << "Student registered in course Successfully!" << std::endl;
     cout<<"*****************************************************************\n\n";
}

void add_course(string id,string name,string credit,string profid,string nc,sqlite3* DB)
{
    char* messaggeError;
    int exit ;
    string sql = "insert into course values('" + id +"', '" + name+ "', "+ credit +" , '"+ profid +"' , " + nc + ");";
    
   cout<<"*****************************************************************\n\n";
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);
    if (exit != SQLITE_OK) {
        std::cerr << "Error Insert" << std::endl;
        sqlite3_free(messaggeError);
    }
    else
        std::cout << "Course added Successfully!" << std::endl;
     cout<<"*****************************************************************\n\n";
}


#endif
