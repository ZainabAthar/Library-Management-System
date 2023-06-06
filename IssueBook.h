#pragma once
#include<iostream>
#include<fstream>
#include"book.h"
#include"student.h"
using namespace std;
class Issuebook
{
private:
	string fbid;
	string fsid;
	string bid;
	string nop;
	string an;
	string isn;
	int in ;
public:
	
	void issue();
	void validity();
	void lim_check();
	void search();
	void search2();
};
