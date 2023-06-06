#include<iostream>
#include<fstream>
#include<conio.h>
#include<Windows.h>
#include<iomanip>  
#include"book.cpp"
#include"student.cpp"
#include"IssueBook.cpp"
#include"returnbook.cpp"

using namespace std;
int main()
{

	system("COLOR 2F");
	cout << "*****************************************************************LIBRARY MANAGEMENT SYSTEM*****************************************************************" << endl;
	cout << endl << endl;
	book c;
	Student s;
	Issuebook u;
	return_book r;
	string p = "DAWN";
	string inputPassword;
	char ch;
	cout << "__________________________________________________________________________PASSWORD_________________________________________________________________________"  << endl<< endl<< endl;
	
	xyz:	cout <<  "ENTER PASSWORD:                                                              ";
	 while (true) {
        ch = _getch();
        while (ch != 13) {
            inputPassword.push_back(ch);
            cout << '*';
            ch = _getch();
        }
        cout << endl << endl;

        if (inputPassword == p) {
	{
		cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>WELCOME TO THE LIBRARY<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
		cout << endl;
	    cout<<"	                                                         ***************************"<<endl;
    cout<<"                                                                 *     *   * *   *   *     *"<<endl;
    cout<<"                                                                 *   * *   * *   * * *   * *"<<endl;
    cout<<"                                                                 * * * *   * *   * * * * * *"<<endl;
    cout<<"                                                                 * * * *   * *   * * * * * *"<<endl;
    cout<<"                                                                 * * * *   * *   * * * * * *"<<endl;
    cout<<"                                                                 * * * *   * *   * * * * * *"<<endl;
    cout<<"                                                                 * * * *   * *   * * * * * *"<<endl;
    cout<<"                                                                 *     *   * *   *     *   *"<<endl;
    cout<<"                                                                 *     *   * *   *     *   *"<<endl;
    cout<<"                                                                 * * * *   * *   * * * * * *"<<endl;
    cout<<"                                                                 * * * *   * *   * * * * * *"<<endl;
    cout<<"                                                                 * * * *   * *   * * * * * *"<<endl;
    cout<<"                                                                 * * * *   * *   * * * * * *"<<endl;
    cout<<"                                                                 * * * *   * *   * * * * * *"<<endl;
    cout<<"                                                                 * * * *   * *   * * * * * *"<<endl;
    cout<<"                                                                 *       INFINITY UNDER    *"<<endl;
    cout<<"                                                                 *           A ROOF        *"<<endl;
    cout<<"                                                                 ***************************"<<endl;

		cout<<"                                                               ";system("pause");
		int cho;
		do
		{
			system("cls");
			cout << "                                                             LIBRARY MANAGEMENT SYSTEM" << endl;
			cout << "\n                                                                 MAIN MENU" << endl<<endl;
			cout << "                                                             [0] CREATE BOOK RECORD" << endl;
			system("COLOR 9F");
			cout << endl;
			cout << "                                                             [1] MODIFY BOOK RECORD " << endl;
			cout << endl;
			cout << "                                                             [2] SEARCH BOOK RECORD " << endl;
			cout << endl;
			cout << "                                                             [3] DELETE BOOK RECORD " << endl;
			cout << endl;
			cout << "                                                             [4] ADD STUDENT RECORD" << endl;
			cout << endl;
			cout << "                                                             [5] MODIFY STUDENT RECORD" << endl;
			cout << endl;
			cout << "                                                             [6] SEARCH STUDENT RECORD" << endl;
			cout << endl;
			cout << "                                                             [7] DELETE STUDENT RECORD" << endl;
			cout << endl;
			cout << "                                                             [8] VALIDITY OF RECORD BEFORE ISSUANCE" << endl;
			cout << endl;
			cout << "                                                             [9] LIMIT TO ISSUE A BOOK" << endl;
			cout << endl;
			cout << "                                                             [10] ISSUE BOOK" << endl;
			cout << endl;
			cout << "                                                             [11] RETURN BOOK" << endl;
			cout << endl;
			cout << "                                                             [12] DISPLAY STUDENT RECORD" << endl;
			cout << endl;
			cout << "                                                             [13] DISPLAY BOOK RECORD" << endl;
			cout << endl;
			cout << "                                                             [14] EXIT TO MAIN MENU!!" << endl;
			cout << endl;
			cout << "                                                                  CHOICE: " ;
			cin >> cho;
			system("cls");
			try{
			switch (cho)
			{
			case 0:
				c.add();
				break;
			case 1:
				c.modify();
				break;
			case 2:
				c.search();
				break;
			case 3:
				c.Delete();
				break;
			case 4:
				s.add();
				break;
			case 5:
				s.modify();
				break;
			case 6:
				s.search();
				break;
			case 7:
				s.Delete();
				break;
			case 8:
				u.validity();
				break;
			case 9:
				u.lim_check();
				break;
			case 10:
				u.issue();
				break;
			case 11:
				r.ret_book();
				break;
			case 12:
				s.display();
				break;
			case 13:
				c.display();
				break;
			case 14:
				break;
			default:
				cout << "\n                                                             INVALID CHOICE" << endl;
			}
		}
			catch (const char*e ){
					cout<<e;
				}
			cout << endl;
			system("Pause");
			system("cls");
		} while (cho >= 0 && cho < 14);
	}}
	 if(inputPassword != p) {
            cout << "                                                              INCORRECT PASSWORD__TRY AGAIN" << endl;
            inputPassword.clear();  // Clear the entered password
        }
    }
    goto xyz;
}
