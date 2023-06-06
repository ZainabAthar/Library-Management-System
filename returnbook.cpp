#include"ReturnBook.h"
using namespace std;
void return_book::ret_book()
{system("COLOR 8F");
    cout << "                                                      LIBRARY MANAGEMENT SYSTEM" << endl;
    cout << endl;

    int found = 0;
    ifstream issuBookReader("issuancebook.txt", ios::in);
    ofstream tempWriter("temp1.txt", ios::out);

    cout << "Book ID to be Returned: ";
    cin.ignore();
    getline(cin, rbid);
    cout << endl;

    if (!issuBookReader)
    {
        throw "\nFILE DOES NOT EXIST";
    }
    else
    {
        string bid, nop, n, an, in,st_id;

        while (getline(issuBookReader, bid))
        {
            getline(issuBookReader, nop);
            getline(issuBookReader, n);
            getline(issuBookReader, an);
            getline(issuBookReader, in);
            getline (issuBookReader, st_id);
            cout<<"Already issued book(s) record is here";
            cout<<bid<<" "<<nop<<"  "<<n<<" "<<an<<"  "<<in<<" "<<st_id<<endl;
            if (rbid.compare(bid) == 0)
            {
                found = 1;
                cout << "BOOK RETURNED SUCCESSFULLY" << endl;

                ofstream BookOutput;
                BookOutput.open("book.txt", ios::app);
                if (!BookOutput)
                {
                    throw "FILE DOES NOT EXIST";
                }
                else
                {
                    BookOutput << bid << "\n" << nop << "\n" << n << "\n" << an << "\n" << in << "\n";
                    cout << "BOOK UPDATED SUCCESSFULLY" << endl;
                    BookOutput.close();
                    cout<<">>>>>> Book file is successfully updated >>>>>>>>>>";
                }
            }
            else
            {  cout<<"Writing in temp file"<<endl;
                tempWriter << bid << "\n" << nop << "\n" << n << "\n" << an << "\n" << in << "\n";
            }
	    }

        issuBookReader.close();
        tempWriter.close();

        if (found == 0)
        {
            cout << "\nBOOK DOES NOT EXIST" << endl;
        }

        remove("issuancebook.txt");
        rename("temp1.txt", "issuancebook.txt");
    }
    
}

