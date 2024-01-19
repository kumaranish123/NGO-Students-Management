#ifndef PROF_H
#define PROF_H

#include<bits/stdc++.h>
#include <sqlite3.h>

using namespace std;
string origpassprof = "{}";

static int passvalueprof(void* data, int argc, char** argv, char** azColName)
{
    int i;
    if(argc != 1)
    	return 0;
    for (i = 0; i < argc; i++) {
        origpassprof = argv[i];
    }
    
    printf("\n\n");
    return 0;
}

bool checkprof(string id , string password , sqlite3* DB)
{      
       string query = "select password from professor where id='"+ id +"';";
	sqlite3_exec(DB, query.c_str(), passvalueprof, NULL, NULL);
	return (origpassprof == password);
}



void updateattendance(string sid, string cid,string at,sqlite3* DB)
{
       char* messaggeError;
       int exit ;
      string sql = "update sturegist set attendance = "+ at +" where studentid = '" + sid + "' and courseid = '" + cid + "';";
      
      cout<<"*****************************************************************\n\n";
    exit = sqlite3_exec(DB, sql.c_str(), NULL, NULL, &messaggeError);
    if (exit != SQLITE_OK) {
        std::cerr << "Error Update" << std::endl;
        sqlite3_free(messaggeError);
      // throw std::exception();
    }
    else
        std::cout << "Attendance Updated Successfully!" << std::endl;
     cout<<"*****************************************************************\n\n";

      
}


void updatemarks(string sid, string cid,string mr,sqlite3* DB)
{
       char* messaggeError;
       int exit ;
      string sql = "update sturegist set marks = " + mr + " where studentid= '" + sid + "' and courseid= '" + cid + "';";
      
      cout<<"*****************************************************************\n\n";
    exit = sqlite3_exec(DB, sql.c_str(), 0, NULL, &messaggeError);
    if (exit != SQLITE_OK) {
        std::cerr << "Error Update" << std::endl;
        sqlite3_free(messaggeError);
    }
    else
        std::cout << "Marks Updated Successfully!" << std::endl;
     cout<<"*****************************************************************\n\n";
     
}

void finishcourse(string cid , sqlite3* DB)
{
	int exit;
    char* messaggeError;
    cout<<"*****************************************************************\n\n";
    string sql = "delete from sturegist where courseid = '" + cid+"';";
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);
    if (exit != SQLITE_OK) {
        std::cerr << "Error DELETE" << std::endl;
        sqlite3_free(messaggeError);
        return;
    }
    sql = "delete from course where id ='" + cid+"';";
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);
    if (exit != SQLITE_OK) {
        std::cerr << "Error DELETE" << std::endl;
        sqlite3_free(messaggeError);
    }
    else
    	std::cout<< "Course finished successfully\n";
    cout<<"*****************************************************************\n\n";
}

#endif
