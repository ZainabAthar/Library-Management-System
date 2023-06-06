#include<iostream>
#include<fstream>
#include<conio.h>
#include<Windows.h>
#include<string>
#include"Issuebook.h"
using namespace std;
string Idcheck, rcheck;
void Issuebook::search()
{system("COLOR 8F");
     cout << "                                                    LIBRARY MANAGEMENT SYSTEM" << endl;
    cout << endl;

    string bid, nop, bn, an, in;
    string searchId;
    int found = 0;

    cout << "BOOK ID TO BE SEARCHED: ";
    cin >> searchId;

    ifstream input("book.txt");
    if (!input)
    {
        cout << "FILE CAN NOT BE OPENED" << endl;
        return;
    }

    while (getline(input, bid))
    {
        getline(input, nop);
        getline(input, bn);
        getline(input, an);
        getline(input, in);
        
        if (bid == searchId)
        {
            found = 1;
            cout << "RECORD:" << endl;
            cout << "BOOK ID: " << bid << endl;
            cout << "PAGES: " << nop << endl;
            cout << "BOOK NAME: " << bn << endl;
            cout << "AUTHOR NAME: " << an << endl;
            cout << "ISSUER NAME: " << in << endl;
            cout << endl;
        }
    }

    input.close();

    if (found == 0)
    {
        cout << "ID DOES NOT EXIST" << endl;
        cout << endl;
    }
}

void Issuebook::search2()        // For searching a student present in the class.
{system("COLOR 8F");
	cout << "                                                     LIBRARY MANAGEMENT SYSTEM" << endl;
    cout << endl;
    string sid, name, dname, sem, nib;
    int found = 0;
    string x;
    cin.ignore();
    cout << "STUDENT ID TO BE SEARCHED: ";
    getline(cin,x);
    cout << endl;
    ifstream input1("student.txt");
    if (!input1)
    {
        cout << "FILE CAN NOT BE OPENED" << endl;
        return;
    }
    while (getline(input1, sid))
    {
        getline(input1, name);
        getline(input1, dname);
        getline(input1, sem);
        getline(input1, nib);


        if (sid == x)
        {
            found = 1;
            cout << "RECORD OF THE ID:" << endl;
            cout << "NAME: " << name << "\nDEPARTMENT: " << dname << "\nSEMESTER: " << sem << "\nISSUED BOOKS: " << nib << "\n";
        }
    }
    input1.close();
    if (found == 0)
    {
        cout << "RECORD DOES NOT EXIST" << endl;
    }

}
void Issuebook::issue()
{system("COLOR 8F");
    cout << "                                                            LIBRARY MANAGEMENT SYSTEM" << endl;
    cout << endl;
    int n, t, noib;
    string Uid, Urno,NOIB;
    string ID, Rno, nop;
    string Bkname, Stdname, Aname, Iname, Dep, semster;
    cin.ignore();
    cout << "BOOK ID\t:";
    getline(cin, Uid);
    cout << endl;
    ifstream input1("book.txt");
    if (!input1)
    {
        cout << "ERROR";
    }
    else
    {
        n = 0;
        t = 0;
        while (getline(input1, ID))
        {
            getline(input1, nop);
            getline(input1, Bkname);
            getline(input1, Aname);
            getline(input1, Iname);

            if (Uid == ID)
            {
                n = 1;
                cout << "ID FOUND" << endl << endl;
             
                cout << "STUDENT ID\t:";
                getline(cin, Urno);
                cout << endl;
                ifstream input2("student.txt");
                if (!input2)
                {
                    cout << "ERROR";
                }
                else
                {
                    while (getline(input2, Rno))
                    {
                        getline(input2, Stdname);
                        getline(input2, Dep);
                        getline(input2, semster);
						getline (input2, NOIB);
                    
                        
                     if (Urno==Rno)
                        { cout<<"\nNO if already Issued Books --> "<<NOIB;
                            cout << "\nAVAILABLE" << endl << endl;
                            t = 1;
                            if (NOIB.compare("0") == 0)
                            {
                                cout << "Book CAN be issued" << endl << endl;
                                int chk;
                                cout << "ENTER 1 TO CONFIRM ISSUANCE\t:";
                                cin >> chk;
                                if (chk == 1)
                                {
                                    ofstream issue("issuancebook.txt", ios::app);
                                    if (!issue)
                                    {
                                        cout << "ERROR";
                                    }
                                    else
                                    {  cout<<">>>>>>>>>>>> Writing to issuancebook.txt>>>>>>>>>>>>>>>\n";
                                        issue << ID << "\n" << nop << "\n" << Bkname << "\n" << Aname << "\n" << Iname << "\n" << Rno<<"\n" ;
                                        cout << endl << endl << "BOOK ISSUED";
                                        Idcheck = ID;
                                        rcheck = Rno;
                                    }
                                    issue.close();
                                }
                            }
                            else
                            {
                                cout << "BOOK CAN NOT BE ISSUED" << endl;
                            }
                        break;
                        }
                    }
                }
                input2.close();
            }
        }
    }
    input1.close();

    if (n != 1)
    {
        cout << "BOOK NOT FOUND" << endl;
    }
    else if (t != 1)
    {
        cout << "STUDENT NOT FOUND" << endl;
    }

    ifstream indel("book.txt");
    if (!indel)
    {
        cout << "ERROR";
    }
    else
    {
        ofstream outdel("temp2.txt", ios::out);
        if (!outdel)
        {
            cout << "ERROR";
        }
        else
        {
            while (getline(indel, ID))
            {
                getline(indel, nop);
                getline(indel, Bkname);
                getline(indel, Aname);
                getline(indel, Iname);

                if (Idcheck == ID)
                {
                    cout << endl << "DELETING.... (book.txt UPDATED)" << endl;
                }
                else
                {
                    outdel << ID << "\n" << nop << "\n" << Bkname << "\n" << Aname << "\n" << Iname << "\n";
                }
            }
        }
        outdel.close();
    }
    indel.close();
    remove("book.txt");
    rename("temp2.txt", "book.txt");

    // change student
    ifstream indel1("student.txt");
    if (!indel1)
    {
        cout << "Error";
    }
    else
    {
        ofstream outdel1("temp3.txt", ios::out);
        if (!outdel1)
        {
            cout << "ERROR";
        }
        else
        {
            while (getline(indel1, Rno))
            {
                getline(indel1, Stdname);
                getline(indel1, Dep);
                getline(indel1, semster);
                indel1 >> noib;
                indel1.ignore();

                if (rcheck == Rno)
                {
                    cout << endl << "CHANGING.... (student.txt FILE UPDATED)" << endl;
                   // outdel1 << Rno << "\n" << Stdname << "\n" << Dep << "\n" << semster << "\n" << 1 << "\n";
                }
                else
                {
                    outdel1 << Rno << "\n" << Stdname << "\n" << Dep << "\n" << semster << "\n" << noib << "\n";
                }
            }
        }
        outdel1.close();
    }
    indel1.close();
    remove("student.txt");
    rename("temp3.txt", "student.txt");
}


void Issuebook::validity()
{system("COLOR 8F");
	cout << "                                                    LIBARARY MANEGMENT SYSTEM" << endl;
	cout << endl;
	string a, b, c, d, e;
	fstream in;
	in.open("book.txt", ios::in);
	if (!in)
	{
		throw "CAN NOT OPEN FILE" ;
	}
	else
	{
		while (getline(in, a))
    {
        getline(in, b);
        getline(in, c);
        getline(in, d);
        getline(in, e);
		{
			search(); 
			break;
		}
		cout << endl;
	}
	string f, g, h, i, j, sidf;
	fstream inp;
	inp.open("student.txt", ios::in);
	if (!inp)
	{
		cout << "FILE OPENING ERROR" << endl;
	}
	else
	{
		while (getline(inp, f))
    {
        getline(inp, g);
        getline(inp, h);
        getline(inp, i);
        getline(inp, j);
		{
			search2();
			break;
		}
		cout << endl;
	}
}}}
void Issuebook::lim_check()
{system("COLOR 8F");
    cout << "                                                            LIBRARY MANAGEMENT SYSTEM" << endl;
    cout << endl;
    ifstream input1;
    string q;
    cout << "DATA FOR LIMIT CHECK:" << endl;
    cout << endl;
    cout << "ID\t:";
    cin >> q;
    cout << endl;
    input1.open("student.txt", ios::in);
    string bid, nop, bn, an, in;

    if (!input1)
    {
        cout << "FILE NOT OPENED" << endl;
    }
    else
    {
        while (getline(input1, bid))
        {
            getline(input1, nop);
            getline(input1, bn);
            getline(input1, an);
            getline(input1, in);
            
            if (in == "0" && bid == q)
            {
                cout << "THE STUDENT WITH ID: " << bid << " CAN GET A BOOK!" << endl;
            }
            if (in != "0" && bid == q)
            {
                cout << "SORRY, ID " << bid << " CAN NOT GET A BOOK(LIMIT IS OVER)!" << endl;
            }
        }
    }
    input1.close();
}
