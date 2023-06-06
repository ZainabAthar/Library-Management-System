#pragma once
#include<iostream>
#include<fstream>
#include "student.h"
#include"Person.h"
using namespace std;
class book: public Person,public DataIO
{
private:
	string bid;           //Book ID
	string nop;          //No. of pages
	string bn;          //Book name
	string an;         //Author name
	string in;        //Issuer name
	
public:
	void add();
	void modify();
   void search();
	void Delete();
	void display();
};

