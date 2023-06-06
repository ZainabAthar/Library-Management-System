#include<conio.h>
#include<Windows.h>
#include<iostream>
#include<fstream>
#include"book.h"
using namespace std;
class return_book
{
private:
	string rbid;//book id
	string rsid;//student id
	int Idcheck, rcheck;
	string bid, n, nop, an, in, stdid;//book id,?,num of pages,author name,issuer name,student id
	int np , t , Uid, Urno;
	int ID, Rno, noib;
	string Bkname, Stdname, Aname, Iname, Dep, semster;
	int n1 , n2;
public:
	void ret_book();
};
