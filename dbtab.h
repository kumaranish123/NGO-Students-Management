#ifndef DBTABLE_H
#define DBTABLE_H

#include<bits/stdc++.h>
#include <sqlite3.h>

using namespace std;


void tables(sqlite3* DB)
{
	string regtable = "create table if not exists registrar("
	    "id       varchar(20) primary key    not null,"
	    "name     varchar(20)        not null,"
	    "email    varchar(50) unique not null,"
	    "password varchar(30)        not null);";
	int exit = 0;
    	char* messaggeError;
    	exit = sqlite3_exec(DB, regtable.c_str(), NULL, 0, &messaggeError);
  
 	if (exit != SQLITE_OK) 
 	{
        	cerr << "Error Create Table Registrar" << std::endl;
        	sqlite3_free(messaggeError);
    	}       
  
    string regone("INSERT INTO registrar VALUES('admin1', 'Jazz', 'jas@gmail.com', 'jas');");
    exit = sqlite3_exec(DB, regone.c_str(), NULL, 0, &messaggeError);
      
    //string query = "SELECT * FROM registrar;";
 
    //sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);
    
    string proftable = "create table if not exists professor("
    "id       varchar(20) primary key    not null,"
    "name     varchar(20)        not null,"
    "email    varchar(50) unique not null,"
    "password varchar(30)        not null,"
    "department varchar(20) not null);";
    
    exit = sqlite3_exec(DB, proftable.c_str(), NULL, 0, &messaggeError);
  
    if (exit != SQLITE_OK) 
    {
	cerr << "Error Create Table Student" << std::endl;
	sqlite3_free(messaggeError);
    }       
    
    string stutable = "create table if not exists student("
    "id       varchar(20) primary key    not null,"
    "name     varchar(20)        not null,"
    "email    varchar(50) unique not null,"
    "password varchar(30)        not null,"
    "semester int not null ,"
    "department varchar(20) not null);";
    
    exit = sqlite3_exec(DB, stutable.c_str(), NULL, 0, &messaggeError);
  
    if (exit != SQLITE_OK) 
    {
	cerr << "Error Create Table Student" << std::endl;
	sqlite3_free(messaggeError);
    }       
    
    
   string coursetable = "create table if not exists course("
    "id varchar(20) primary key    not null,"
    "name     varchar(20)        not null,"
    "credit int not null,"
    "prof_id varchar(20) not null,"
    "no_of_classes int not null,"
    "CONSTRAINT fk_prof_id FOREIGN KEY (prof_id) REFERENCES professor(id));";
    
    exit = sqlite3_exec(DB, coursetable.c_str(), NULL, 0, &messaggeError);
  
    if (exit != SQLITE_OK) 
    {
	cerr << "Error Create Table coursetable" << std::endl;
	sqlite3_free(messaggeError);
    }       
    
    string sturegtable = "create table if not exists sturegist("
    "courseid varchar(20) not null,"
    "studentid varchar(20) not null,"
    "attendance int not null,"
    "marks int not null,"
    "CONSTRAINT fk_courseid FOREIGN KEY (courseid) REFERENCES  course(id),"
    "CONSTRAINT fk_studentid FOREIGN KEY (studentid) REFERENCES  student(id),"
    "PRIMARY KEY (courseid, studentid));";
    
    exit = sqlite3_exec(DB, sturegtable.c_str(), NULL, 0, &messaggeError);
  
    if (exit != SQLITE_OK) 
    {
	cerr << "Error Create Table sturegist" << std::endl;
	sqlite3_free(messaggeError);
    }       
    
}



void closedb(sqlite3* DB)
{
	sqlite3_close(DB);
}



#endif
