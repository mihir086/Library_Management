
LIBRARY MANAGEMENT SYSTEM

//header files

#include<iostream>
#include<string>
#include<conio.h>
using namespace std;

int scode= 1001;						//student ID code
int fcode= 5409;						//Faculty ID code
int libcode=9099;						//Librarian ID code
int tb;								//total number of books
static int bnum=0; 						//current book position


class Book
{
    
    string author;
    int status=0;
    int edition;
    int bookId;
    int d;
    int m;
    int y;
    int price;

    public:
    string name;

    void displayBookDetails();					
    void updateStatus();
    void getbook();
    void displayStatus();
    void getdetails();
    void DisplayBookDetails();

};

class journals: public Book
{

};

class magazines: public Book
{

};

class studybooks: public Book
{

};

class Librarian
{
    public:
    int searchbook();
    void issuebook();
    void calcfine();
    void bill();
    void retbook();
};

class MemberRecord: public Book
{
    public:

    int memberId;
    string type;
    int d,m,y;
    int numofissued;
    string name;
    int phone;
        
    void display();
    void ret();
    void issue();
    void incbooks();
    void decbooks();
};

class student: public MemberRecord
{
    public:
    
};

class faculty: public MemberRecord
{
    public:
    
};

class Transaction: public MemberRecord
{
    int transId;
    int d,m,y;
    int dd,mm,yy;

    public:

    void createTransaction();
    void displayTransaction();

};

class Bill: public Transaction
{
    int billNo;
    int d1,d2,d3;
    int amt;

    public:
    void billcreate();
    void displaybill();
};


Book b;                                         // global declaration objects of all classes
Librarian lb;
MemberRecord mr;
Transaction t;
Bill bl;
student s;
faculty f;

int Librarian:: searchbook()
{
    system("cls");
    string b_name;
    int a=0;

    cout<<"\nEnter Name of the book: ";
    b_name= b.name;

    for(int i=0; i<tb; i++)
    {
        if(b_name==b.name)
        {
            cout<<"\nBook Found!!\n Book number: "<<bnum;
            a++;
            bnum=i;
        }
    }

    if(a==0)
    {
        cout<<"\nNo such record found!!!";
        cout<<"\n\nRedirecting....\npress any key to continue...";
		getch();
    }

    return bnum;
}

void Librarian::issuebook()
{
    system("cls");
    
    int x= searchbook();
    cout<<"\nBook Issued";
    b.updateStatus();
}

void Librarian::calcfine()
{   
    system("cls");
    int d;

    cout<<"\nEnter number of days by which return is late: ";
    cin>>d;

    cout<<"\nFine is "<<d*3<<"rs";
}

void Librarian:: bill()
{
    system("cls");
    bl.billcreate();
}

void Librarian:: retbook()
{
    system("cls");

    int y=searchbook();
    cout<<"\nBook Returned";
    b.updateStatus();
}


void Book:: getbook()
{
    system("cls");                                                 

    b.getdetails();
}

void Book:: getdetails()
{
    system("cls");

    cout<<"\nEnter name: ";
    cin>>name;

    cout<<"\nEnter author: ";
    cin>>author;

    cout<<"\nEnter Book ID: ";
    cin>>bookId;

    cout<<"\nEnter Status: ";
    cin>>status;

    cout<<"\nEnter Edition: ";
    cin>>edition;

    cout<<"\nEnter Date of purchase: ";
    cout<<"\n(Enter in order date->month->year)\n ";
    cin>>d>>m>>y;

    cout<<"\nEnter price: ";
    cin>>price;
}

void Book::DisplayBookDetails()
{
    system("cls");
    
    cout<<"\nName: ";
    cout<<name;

    cout<<"\nAuthor: ";
    cout<<author;

    cout<<"\nBook ID: ";
    cout<<bookId;

    cout<<"\nStatus: ";
    cout<<status;

    cout<<"\nEdition: ";
    cout<<edition;

    cout<<"\nDate of purchase: ";
    cout<<"\n(order of date->month->year)\n ";
    cout<<d<<m<<y;

    cout<<"\nPrice: ";
    cout<<price;
}

void Book:: updateStatus()
{
    system("cls");
    int s;

    cout<<"\nEnter new status of the book";
    cin>>s;

    status=s;
}

void Book:: displayStatus()
{
    system("cls");
    cout<<status;
}

void Transaction:: createTransaction()
{
    system("cls");

    cout<<"\nEnter transaction ID: ";
    cin>>transId;

    cout<<"\nEnter Date of Issue: ";
    cout<<"\n(order of date->month->year)\n ";
    cout<<d<<m<<y;

    cout<<"\nEnter Due Date: ";
    cout<<"\n(order of date->month->year)\n ";
    cout<<dd<<mm<<yy;
}

void Transaction::displayTransaction()
{
     system("cls");

    cout<<"\nTransaction ID: ";
    cin>>transId;

    cout<<"\nDate of Issue: ";
    cout<<"\n(order of date->month->year)\n ";
    cout<<d<<m<<y;

    cout<<"\nDue Date: ";
    cout<<"\n(order of date->month->year)\n ";
    cout<<dd<<mm<<yy;
}

void Bill:: billcreate()
{
    cout<<"\nEnter bill number: ";
    cin>>billNo;
}

void Librarianmenu()
{
    int ch,lcode;
    
    cout<<"\nEnter ID: ";
    cin>>lcode;

    if(lcode==libcode)
    {   
        cout<<"\nLogin Successful!!";
		cout<<"\n\nRedirecting....\npress any key to continue...";
		getch();
        while(1)
        {
            system("cls");
            cout<<"\n        -----MAIN MENU-----         \n";
            cout<<"\n        1.Search Book                 ";
            cout<<"\n        2.Issue Book                  ";
            cout<<"\n        3.Calculate Fine              ";
            cout<<"\n        4.Create Bill                 ";
            cout<<"\n        5.Return Book                 ";
            cout<<"\n        6.Return to main menu         ";
        
            cout<<"\n\nEnter choice  :";
            cin>>ch;
        
            switch(ch)
            {
                case 1:
                    lb.searchbook();
                    break;

                case 2:
                    lb.issuebook();
                    break;
                
                case 3:
                    lb.calcfine();
                    break;

                case 4:
                    bl.billcreate();
                    break;

                case 5:
                    lb.retbook();
                    break;

                case 6:
                    cout<<"\n\nRedirecting....\npress any key to conitnue...";
                    getch();
                    return;
                
                default:
                    cout<<"\n\nInvalid Choice!!!";
                    cout<<"\n\nRedirecting....\npress any key to continue...";
                    getch();
                    
            }

        }
    }

    else
    {
        cout<<"\nLogin Failed!!!";
		cout<<"\n\nRedirecting....\npress any key to continue...";
		getch();
		return;
    }

}
void facultymenu()
{

    int ch,code;

    

    cout<<"\nEnter Faculty ID: ";
    cin>>code;

    if(code==fcode)
    {   
        cout<<"\nLogin Successful!!";
		cout<<"\n\nRedirecting....\npress any key to continue...";
		getch();

        while(1)
        {
            system("cls");
            cout<<"\n          ---MAIN MENU---           \n";
            cout<<"\n        1.Display Details             ";
            cout<<"\n        2.Issue Book                  ";
            cout<<"\n        3.Return Book                 ";
            cout<<"\n        4.Increase issued books       ";
            cout<<"\n        5.Decrease issued books       ";
            cout<<"\n        6.Pay Bill                    ";
            cout<<"\n        7.Return to main menu         ";
        
            cout<<"\n\nEnter choice  :";
            cin>>ch;
        
            switch(ch)
            {
                case 1:
                    f.display();
                    break;

                case 2:
                    f.issue();
                    break;
                
                case 3:
                    f.ret();
                    break;

                case 4:
                    f.incbooks();
                    break;

                case 5:
                    f.decbooks();
                    break;

                case 6:
                    bl.billcreate();
                    break;

                case 7:
                    cout<<"\n\nRedirecting....\npress any key to conitnue...";
                    getch();
                    return;
                
                default:
                    cout<<"\n\nInvalid Choice!!!";
                    cout<<"\n\nRedirecting....\npress any key to continue...";
                    getch();
                    
            }

        }
    }

    else
    {
        cout<<"\nLogin Failed!!!";
		cout<<"\n\nRedirecting....\npress any key to continue...";
		getch();
		return;
    }

}

void studentmenu()
{
    int ch, st_id=1101;
    
    cout<<"\nEnter student ID: ";
    cin>>st_id;

    if(st_id==scode)
    {   
        cout<<"\nLogin Successful!!";
		cout<<"\n\nRedirecting....\npress any key to continue...";
		getch();

        while(1)
        {
            system("cls");

            cout<<"\n          ---MAIN MENU---           \n";
            cout<<"\n        1.Display Details             ";
            cout<<"\n        2.Issue Book                  ";
            cout<<"\n        3.Return Book                 ";
            cout<<"\n        4.Increase issued books       ";
            cout<<"\n        5.Decrease issued books       ";
            cout<<"\n        6.Pay Bill                    ";
            cout<<"\n        7.Return to main menu         ";
        
            cout<<"\n\nEnter choice  :";
            cin>>ch;
        
            switch(ch)
            {
                case 1:
                    s.display();
                    break;

                case 2:
                    s.issue();
                    break;
                
                case 3:
                    s.ret();
                    break;

                case 4:
                    s.incbooks();
                    break;

                case 5:
                    s.decbooks();
                    break;

                case 6:
                    bl.billcreate();
                    break;

                case 7:
                    cout<<"\n\nRedirecting....\npress any key to conitnue...";
                    getch();
                    return;
                
                default:
                    cout<<"\n\nInvalid Choice!!!";
                    cout<<"\n\nRedirecting....\npress any key to continue...";
                    getch();
                    
            }

        }
    }

    else
    {
        cout<<"\nLogin Failed!!!";
		cout<<"\n\nRedirecting....\npress any key to continue...";
		getch();
		return;
    }

}
void membermenu()
{   
    int ch;
    
    while(1)
	{
		system("cls");
		cout<<"\n          ---MAIN MENU---          \n";
	    cout<<"\n        1.Login as a student         ";
	    cout<<"\n        2.Login as a faculty         ";
	    cout<<"\n        3.Return to main menu        ";
	
        cout<<"\n\nEnter choice  :";
	    cin>>ch;
    
		switch(ch)
		{
			case 1:
                studentmenu();
				break;

			case 2:
                facultymenu();
				break;

            case 3:
				cout<<"\n\nRedirecting....\npress any key to conitnue...";
				getch();
				return;

			default:
				cout<<"\n\nInvalid Choice!!!";
				cout<<"\n\nRedirecting....\npress any key to continue...";
				getch();
				
		}

	}
	
}


int main()
{
    system("cls");
	int choice;
    
    b.getbook();
	
	cout<<"\n------LIBRARY MANAGEMENT SYSTEM------\n";
	cout<<"\n    Project by - Mihir Tomar";
	cout<<"\n    Enrollment Number- A2305219392";
	cout<<"\n    Section - 3CSE-6X";
	cout<<"\n\nPress any key to continue...";
	getch();

    while(1)
	{
		system("cls");
		cout<<"\n--------------WELCOME--------------\n";
		cout<<"\n          ---MAIN MENU---          \n";
		cout<<"\n        1.Login as Member         ";
		cout<<"\n        2.Login as Librarian            ";
		cout<<"\n             3.Exit                 ";
		cout<<"\n\nEnter choice  :";
		cin>>choice;
		switch(choice)
		{
			case 1:
                membermenu();
				break;

			case 2:
                Librarianmenu();
				break;

			case 3:
				system("cls");
				cout<<"\n\nProgram exiting, press any key...";
				getch();
				return 1;

			default:
				cout<<"\n\nInvalid Choice!!!";
				cout<<"\n\nRedirecting....\npress any key to continue...";
				getch();
				
		}

	}

	return 1;
}