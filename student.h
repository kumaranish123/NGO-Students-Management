#ifndef STUDENT_H
#define STUDENT_H

#include<bits/stdc++.h>
#include <sqlite3.h>

using namespace std;

string origpassstu = "{}";

static int passvaluestu(void* data, int argc, char** argv, char** azColName)
{
    int i;
    if(argc != 1)
    	return 0;
    for (i = 0; i < argc; i++) {
        origpassstu = argv[i];
    }
    
    printf("\n\n");
    return 0;
}

bool checkstudent(string id , string password , sqlite3* DB)
{      
       string query = "select password from student where id='"+ id +"';";
	sqlite3_exec(DB, query.c_str(), passvaluestu, NULL, NULL);
	return (origpassstu == password);
}

void showattendance(string cid,string sid,sqlite3* DB){
   
        string sql = "select attendance from sturegist where courseid='" +cid+ "' and studentid ='" + sid + "';";
      // string sql = "select * from sturegist;";
        cout<<"*****************************************************************\n\n";
	sqlite3_exec(DB, sql.c_str(), callback, NULL, NULL);
	cout<<"*****************************************************************\n\n";

}

void showMycourses(string sid, sqlite3* DB){
   
      string sql = "select course.id as course_id ,course.name as course_name from sturegist join course on courseid = course.id where studentid = '"+ sid+"';";
      
      cout<<"*****************************************************************\n\n";
	sqlite3_exec(DB, sql.c_str(), callback, NULL, NULL);
	cout<<"*****************************************************************\n\n";
}
void showOfferedCourses(sqlite3* DB)
{
	string query = "select course.id as CourseID, course.name as CourseName , credit as CourseCredit , no_of_classes , professor.id as ProfID , professor.name as ProfName , professor.email as ProfessorEmail , department  from course join professor on course.prof_id = professor.id;";
	cout<<"*****************************************************************\n\n";
	sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);
	cout<<"*****************************************************************\n\n";
}

void showmarks(string cid,string sid,sqlite3* DB){
   
      string sql = "select marks from sturegist where courseid='" + cid + "' and studentid ='" + sid + "';";
      //string sql = "select * from sturegist;";
      cout<<"*****************************************************************\n\n";
	sqlite3_exec(DB, sql.c_str(), callback, NULL, NULL);
	cout<<"*****************************************************************\n\n";
}


#endif
