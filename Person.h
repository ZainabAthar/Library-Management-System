#pragma once
#include<iostream>
#include<fstream>
using namespace std;
class Person{//Base Class
	protected:
		string name;
		public:
		virtual	void add()=0;
	    virtual void modify()=0;
	    virtual void search()=0;
     	virtual void Delete()=0;
    	virtual void display()=0; 
};
class DataIO{//Base Class
	protected:
	ifstream input1;
	ofstream output1;	
};
