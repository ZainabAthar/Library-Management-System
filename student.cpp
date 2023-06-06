#include<iostream>
#include<fstream>
#include<sstream>
#include<iomanip>
#include"student.h"
#include<conio.h>
#include<Windows.h>
using namespace std;
void Student::add()
{system("COLOR 8F");
	cout << "                                                         LIBARARY MANEGMENT SYSTEM" << endl;
	cout << endl;
	string sid, name, dname, sem, nib;
	cout << "\nATTRIBUTES OF STUDENT TO BE ADDED" << endl;
	cout << "STUDENT ID\t:";
	getline(cin>>ws,sid);
	cout << endl;
	cout << "NAME OF STUDENT\t:";
	getline(cin>>ws,name);
	cout << endl;
	cout << "DEGREE\t:";
	getline(cin>>ws,dname);
	cout << endl;
	cout << "SEMESTER\t:";
	getline(cin>>ws,sem);
	cout << endl;
	cout << "NUMBER OF BOOKS ISSUED\t:";
	getline(cin>>ws,nib);
	cout << endl;
	ofstream output1;
	output1.open("student.txt", ios::app);//to append
	if (!output1)
	{
		throw "STUDENT CAN NOT BE ADDED" ;
	}
	else
	{
		output1 << sid << "\n" << name << "\n" << dname << "\n" << sem << "\n" << nib << "\n";
		cout << endl;
		output1.close();
		cout << "\nSUCCESSFULLY ADDED" << endl;
	}
}
void Student::modify()
{system("COLOR 8F");
	cout << "                                                           LIBARARY MANEGMENT SYSTEM" << endl;
	cout << endl;
	string sid, name, dname, sem, nib, id;
	int found=0;//CHECK
	ifstream input("student.txt");//READ
	ofstream output("temp.txt");//WRITE
	cout << "\nSTUDENT ID TO BE MODIFIED\t:";
	cin >> id;
	cout << endl;
	if (!input)
	{
	throw "FILE FAILED TO OPEN\n";
	}
	else
	{
		if (!output)
        {
            throw "FILE FAILED TO OPEN" ;
            input.close();
            return;
        }

        while (getline(input, sid))
        {
            getline(input, name);
            getline(input, dname);
            getline(input, sem);
            getline(input, nib);
			if (id == sid)
			{   found=1;
				string sid, name, dname, sem, nib;
				cout << endl << "RECORD EXISTS!" << endl;
				cout << "\nATTRIBUTES OF THE STUDENT TO BE ADDED" << endl;
				cout << endl;
				cin.ignore();
				cout << "STUDENT ID\t:";
				getline(cin,sid);
				cout << "NAME OF STUDENT\t:";
				getline(cin,name);
				cout << "DEGREE\t:";
				getline(cin,dname);
				cout << "SEMESTER\t:";
				getline(cin,sem);
				cout << "NUMBER OF BOOKS ISSUED\t:" ;
				getline(cin,nib);
				output << sid << "\n" << name << "\n" << dname << "\n" << sem << "\n" << nib << "\n";
				cout << endl;
				cout << "SUCCESSFULLY MODIFIED" << endl;
			}
			else
			{
				output << sid << "\n" << name << "\n" << dname << "\n" << sem << "\n" << nib << "\n";
			}
		}
		input.close();
		output.close();
		if (found==0)
		{
			cout << "RECORD DOES NOT EXIST" << endl;
		}
		remove("student.txt");
		rename("temp.txt", "student.txt");
	}
}


void Student::search()
{system("COLOR 8F");
    cout << "                                                           LIBRARY MANAGEMENT SYSTEM" << endl;
    cout << endl;
    string sid, name, dname, sem, nib;
    int found = 0;
    string x;
    cin.ignore();
    cout << "ID TO BE SEARCHED: ";
    getline(cin,x);
    cout << endl;
    ifstream input1("student.txt");
    if (!input1)
    {
        cout << "CAN NOT OPEN FILE" << endl;
        return;
    }
    
	while (getline(input1, sid)&&found==0) 
    {   
        getline(input1, name);
        getline(input1, dname);
        getline(input1, sem);
        getline(input1, nib);
        if (sid == x)
        {   
            found = 1;
            cout << "RECORD OF ENTERED ID" << endl;
            cout << "NAME: " << name << "\nDEPARTMENT: " << dname << "\nSEMESTER: " << sem << "\nISSUED BOOKS: " << nib << "\n";
		}
    }
    input1.clear();             
    input1.seekg(0, ios::beg);
    input1.close();
    if (found == 0)
    {
        cout << "RECORD DOES NOT EXIST" << endl;
    }
}

void Student::display()
{system("COLOR 8F");
    cout << "                                                              LIBRARY STUDENT RECORD" << endl;
    cout << endl;

   ifstream input("student.txt"); 
    
    if (!input) {
        cerr << "FAILED TO OPEN THE INPUT FILE" << endl;
    }

    int maxSidWidth = 0, maxNameWidth = 0, maxDnameWidth = 0, maxSemWidth = 0, maxNibWidth = 0;
    string sid, name, dname, sem, nib;

    while (getline(input, sid)) {
        getline(input, name);
        getline(input, dname);
        getline(input, sem);
        getline(input, nib);

        // Update the maximum width for each field
        maxSidWidth = max(maxSidWidth, static_cast<int>(sid.length()));
        maxNameWidth = max(maxNameWidth, static_cast<int>(name.length()));
        maxDnameWidth = max(maxDnameWidth, static_cast<int>(dname.length()));
        maxSemWidth = max(maxSemWidth, static_cast<int>(sem.length()));
        maxNibWidth = max(maxNibWidth, static_cast<int>(nib.length()));
    }

    input.clear();                 // Clear the error flags
    input.seekg(0, ios::beg);      // Reset file pointer to the beginning
    cout<<"STUDENT ID\t\tSTUDENT NAME\t\t\tDEGREE\t\t\tSEMESTER\t\t    NUM OF ISSUED BOOKS"<<endl;
    while (getline(input, sid)) {
        getline(input, name);
        getline(input, dname);
        getline(input, sem);
        getline(input, nib);

        cout << setw(maxSidWidth) << sid << " \t\t| "
             << setw(maxNameWidth) << name << " \t\t| "
             << setw(maxDnameWidth) << dname << " \t\t| "
             << setw(maxSemWidth) << sem << " \t\t\t\t| "
             << setw(maxNibWidth) << nib << endl;
    }

    input.close();

    
}

void Student::Delete()
{system("COLOR 8F");
    cout << "                                                            LIBRARY MANAGEMENT SYSTEM" << endl;
    cout << endl;
    string sid, sn, dn, sen, nob;
    int found = 0;
    string fsid;
    cin.ignore();
    cout << "ID TO BE DELETED: ";
    getline(cin, fsid);
    ifstream input("student.txt");
    ofstream output("temp.txt");
    if (!input)
    {
        throw "FILES FAILED TO BE OPENED\n";
    }
    else
    {
        while (getline(input, sid))
        {
            getline(input, sn);
            getline(input, dn);
            getline(input, sen);
            getline(input, nob);
            if (sid == fsid)
            {
                found = 1;
                cout << "ID HAS BEEN DELETED" << endl;
            }
            else
            {
                output << sid << "\n" << sn << "\n" << dn << "\n" << sen << "\n" << nob << "\n";
            }
        }
        input.close();
        output.close();
        if (found == 0)
        {
            cout << "FAILED_RECORD DOES NOT EXIST" << endl;
            cout << endl;
        }
        remove("student.txt");
        rename("temp.txt", "student.txt");
    }
}

