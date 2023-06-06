#pragma once
#include"Person.h"
#include<iostream>
#include<fstream>
using namespace std;

 class Student:  public Person,public DataIO
{
private:
	string sid;        //Student ID.
	string dname;       //Degree name.
	string sem;         // Semester.
	string nib;         //NO. Of Issued books.
public:
	     void add();
	     void modify();
	     void search();
     	 void Delete();
    	 void display(); 
};
