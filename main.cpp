// Including header files
#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;

//global varibles
string fname;
string lname;
string phone_num;

//functions
void addcontact();
void searchcontact();
void help();
void selfexit();
bool checkdigit(string x);
bool checknum(string x);

int main()
{
    short int choice;
    system("cls");
    system("color 0B");
    cout<<"\n\n\n\t\t\tContact Managment";
    cout<<"\n\n\t1. Add Contact\n\t2. Search Contact\n\t3. Help\n\t4. Exit\n\t> ";
    cin>>choice;
    switch(choice)
    {
        case 1:
            addcontact();
            break;
        case 2:
            searchcontact();
            break;
        case 3:
            help();
            break;
        case 4:
            selfexit();
            break;
        default :
            cout<<"\n\n\tInvalid Input !";
            cout<<"\n\tPress any key to continue..";
            getch();
            main();
    }
}

void addcontact()
{
    ofstream phone ("number.txt",ios::app);
    system("cls");
    cout<<"\n\n\tEnter First Name : ";
    cin>>fname;
    cout<<"\n\n\tEnter Last Nmae : ";
    cin>>lname;
    cout<<"\n\n\tEnter 10-Digit Phone Number : ";
    cin>>phone_num;
    if(checkdigit(phone_num)==true)
    {
        if(checknum(phone_num)==true)
        {
            if(phone.is_open())
            {
                phone<<fname<<" "<<lname<<" "<<phone_num<<endl;
                cout<<"\n\tcontact saved successfully !";
            }else
            {
                cout<<"\n\tError opening file";
            }   
        }else
        {
            cout<<"\n\tA Phone Number must contain Numbers Only !";
        }
        
    }else
    {
        cout<<"\n\tA Phone Number must contain 10 Digits !";
    }
    phone.close();
}

void searchcontact()
{
    bool found=false;
    ifstream myfile("number.txt");
    string keyword;
    cout<<"\n\tEnter Name to search : ";
    cin>>keyword;
    system("cls");
    while(myfile>>fname>>lname>>phone_num)
    {
        if(keyword==fname || keyword==lname || keyword==(fname+" "+lname))
        {
            cout<<"\n\tContact Details....\n";
            cout<<"\n\tFirst Name : "<<fname;
            cout<<"\n\tLast Name : "<<lname;
            cout<<"\n\tPhone Number : "<<phone_num;
            cout<<"\n\n\n";
            found=true;
        }
    }
    if(found==false)
        cout<<"\n\tNo such Contact found...";
}

void help()
{
    system("cls");
    cout<<"\n\n\n\tThis will show help Details.";
    cout<<"\n\n\tEnter your choice:\n\t1. Main Menu\n\t2. Exit\n\t> ";
    int n;
    cin>>n;
    switch(n)
    {
        case 1:
            main();
            break;
        case 2:
            selfexit();
            break;
        default:
            cout<<"\n\n\tInvalid Input !";
            cout<<"\n\tPress any key to continue..";
            getch();
            main();
    }
}

void selfexit()
{
    system("cls");
    cout<<"\n\n\n\t\tThank you for using !\n\n\n";
    exit(1);
}

bool checkdigit(string s)
{
    if(s.size()==10) return true;
    return false;
}

bool checknum(string s)
{
    for(auto x:s)
        if((int)x<48 || (int)x>57) return false;
    return true;    
}