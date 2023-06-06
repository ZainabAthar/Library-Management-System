#include"book.h"
#include<fstream>
#include<iostream>
#include<string>
#include <sstream>
#include<iomanip>
#include<conio.h>
#include<Windows.h>

using namespace std;
void book::add()
{system("COLOR 8F");
	cout << " LIBRARY MANEGMENT SYSTEM" << endl;
	cout << endl;
	string bid, nop, bn, an, in;
	cout << "ATTRIBUTES OF THE BOOK YOU WANT TO CREATE: " << endl;
	cout << endl;
	cout << "ID:";
	cin >> bid;
	cout << "NUMBER OF PAGES\t:";
	cin >> nop;
	cin.ignore();
	cout << "BOOK NAME\t:";
	getline(cin>>ws,bn);
	cout << "AUTHOR NAME\t:";
	getline(cin>>ws,an);
	cout << "ISSUER NAME\t:";
	getline(cin>>ws,in);
	output1.open("book.txt", ios::app);//append
	if (!output1)
	{
		throw "FILE CAN NOT BE OPENED";
	}
	else
	{
		output1 << bid << "\n" << nop << "\n" << bn << "\n" << an << "\n" << in << "\n";//writes data
		cout << endl;
		output1.close();
		cout << "\nSUCCESSFULLY CREATED A BOOK" << endl;
	}
}
void book::modify()
{system("COLOR 8F");
    cout << "                                                            LIBRARY MANAGEMENT SYSTEM" << endl;
    cout << endl;

    string cid, bid, nop, bn, an, in;
    int found = 0;
    ifstream input("book.txt");//READ
    ofstream output("temp.txt");//WRITE

    cout << "ENTER THE BOOK ID YOU WANT TO MODIFY: ";
    cin >> cid;
    cout << endl;

    if (!input)
    {
       throw "INPUT FILE FAILED TO OPEN" ;
    }
    else
    {
        if (!output)
        {
            cout << "OUTPUT FILE FAILED TO OPEN" << endl;
            input.close();
            return;
        }

        while (getline(input, bid))
        {
            getline(input, nop);
            getline(input, bn);
            getline(input, an);
            getline(input, in);

            if (bid == cid)
            {
                found = 1;
                cout << "ATTRIBUTES OF BOOK TO BE MODIFIED:" << endl;
                cout << "\nID: ";
                cin >> bid;
                cout << "NUMBER OF PAGES: ";
                cin >> nop;
                cout << "BOOK NAME: ";
                cin.ignore();
                getline(cin,bn);
                cout << "AUTHOR NAME: ";
                cin.ignore();
                getline(cin,an);
                cout << "ISSUER NAME: ";
                cin.ignore();
                getline(cin,in);

                output << bid << "\n" << nop << "\n" << bn << "\n" << an << "\n" << in << "\n";

                cout << "SUCCESSFULLY MODIFIED THE BOOK" << endl;
                cout << endl;
            }
            else
            {
                output << bid << "\n" << nop << "\n" << bn << "\n" << an << "\n" << in << "\n";
            }
        }

        input.close();
        output.close();

        if (found == 0)
        {
            cout << "\nCAN NOT MODIFY_THE BOOK DOES NOT EXIST" << endl;
            cout << endl;
        }

        remove("book.txt");
        rename("temp.txt", "book.txt");
    }
}

void book::search()
{system("COLOR 8F");
    cout << "                                                              LIBRARY MANAGEMENT SYSTEM" << endl;
    cout << endl;

    string bid, nop, bn, an, in;
    string searchId;
    int found = 0;

    cout << "ENTER THE BOOK ID TO BE SEARCHED: ";
    cin >> searchId;

    ifstream input("book.txt");
    if (!input)
    {
        throw"FILE CAN NOT BE OPENED" ;
        return;
    }

    while (getline(input, bid)&&found==0)
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
    input.clear();              // Clear the end-of-file state
    input.seekg(0, ios::beg);
    input.close();

    if (found == 0)
    {
        cout << "THE ENTERED BOOK ID DOES NOT EXIST IN LIBRARY" << endl;
        cout << endl;
    }
}

void book::display()
{   system("COLOR 8F");
    cout << "                                                              LIBRARY BOOK RECORD" << endl;
    cout << endl;

   ifstream input("book.txt");//read 
    
    if (!input) {
        throw  "FAILED TO OPEN THE FILE" ;
    }

    int maxBidWidth = 0, maxNopWidth = 0, maxBnWidth = 0, maxAnWidth = 0, maxInWidth = 0;
    string bid, nop, bn, an, in;

    while (getline(input, bid)) {
        getline(input, nop);
        getline(input, bn);
        getline(input, an);
        getline(input, in);

        
        maxBidWidth = max(maxBidWidth, static_cast<int>(bid.length()));
        maxNopWidth = max(maxNopWidth, static_cast<int>(nop.length()));
        maxBnWidth = max(maxBnWidth, static_cast<int>(bn.length()));
        maxAnWidth = max(maxAnWidth, static_cast<int>(an.length()));
        maxInWidth = max(maxInWidth, static_cast<int>(in.length()));
    }

    input.clear();                
    input.seekg(0, ios::beg);    
    cout<<"BOOK ID\t\t  PAGES\t\t                BOOK NAME\t\t                     AUTHOR NAME\t\t\t     ISSUER NAME"<<endl;
    while (getline(input, bid)) {
        getline(input, nop);
        getline(input, bn);
        getline(input, an);
        getline(input, in);

        cout << setw(maxBidWidth) << bid << " \t\t| "
             << setw(maxNopWidth) << nop << " \t\t| "
             << setw(maxBnWidth) << bn << " \t\t| "
             << setw(maxAnWidth) << an << " \t\t| "
             << setw(maxInWidth) << in << endl;
    }

    input.close();

    
}


void book::Delete()
{system("COLOR 8F");
    cout << "                                                       LIBRARY MANAGEMENT SYSTEM" << endl;
    cout << endl;
    string bid, nop, bn, an, in;
    string eid;
    int found = 0;
    cout << "ENTER BOOK ID TO BE DELETED: ";
    cin.ignore();
    getline(cin, eid);
    cout << endl;
    ifstream input("book.txt");//READ
    ofstream output("temp.txt");//WRITE
    if (!input)
    {
        cout << "FILE DOES NOT EXIST" << endl;
    }
    else
    { 
        while (getline(input, bid))
        {
            getline(input, nop);
            getline(input, bn);
            getline(input, an);
            getline(input, in);
            if (bid == eid) 
            {
                found = 1;
                cout << "\nTHE RECORD HAS BEEN DELETED" << endl;
            }
            else
            {
                output << bid << "\n" << nop << "\n" << bn << "\n" << an << "\n" << in << "\n"; 
            }
        }
        input.close();
        output.close();
        if (found == 0)
        {
            cout << "ID NOT FOUND_CAN NOT DELETE" << endl;
        }

        remove("book.txt");
        rename("temp.txt", "book.txt");
    }
}

