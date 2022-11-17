//contact management system
#include<iostream>
#include<conio.h>
#include<vector>
#include<string>
#include<iomanip>
#include<windows.h>
#include <bits/stdc++.h>

using namespace std;

int choice1;

struct entry
{
     string name;
     long long int number;
     string mail;
};

void printdot();
void new_contact();
void display();
void add_contact();
void delete_contact();
void edit_contact();
void search_contact();
void check_null();



vector<entry> entries;




void display()
{
    
    if(entries.size()==0)
    {
        cout<<"\a no contacts available to display!!!"<<endl;
        cout<<"do you want to add a new contact?(y/n)"<<endl;
        char u;
        cin>>u;
        if(u=='y' || u=='Y')
        {
            new_contact();
        } 
        else
      {
        cout<<"taking you back to previous window ";
        
        printdot();
      
      }
        
    }
    else
    {
    
    for(auto &user: entries)
{
    cout<<user.name<<"-"<<user.number<<endl;

}
}
}
void add_contact()
{  int choice2;
    
    cout<<"1. create a new contact"<<endl;
    cout<<"2. update existing"<<endl;
    cin>>choice2;
    switch(choice2)
    {
        case 1:
        new_contact();
        break;
        case 2:
        edit_contact();
        break;

    }
    

}

void new_contact()
{
    system("CLS");
    entry x; 
    char c;

    cout<<"enter name: ";
    getline(cin>>ws,x.name);
    cout<<endl;

    cout<<"enter contact no: ";
    cin>>x.number;
    cout<<endl;

    cout<<"enter mail-id: ";
    getline(cin>>ws,x.mail);
    cout<<endl;
      
      cout<<"creating contact";
      printdot();
cout<<endl;
    entries.push_back(x);

    cout<<"**contact created**"<<endl;
    printdot();
      cout<<"do you want to add more contact?(y/n)"<<endl;
      cin>>c;
      if(c=='y' || c=='Y')
      {
        new_contact();
      }
      else
      {
        cout<<"taking you back to previous window "<<endl;
        printdot();
      
      }


    
}

void delete_contact()
{
    string x;
    char y;
    long long int no;
    

    cout<<"enter the name of the contact you want to delete"<<endl;
    cin>>x;
    cout<<endl;
    cout<<"searching for the contact"<<endl;
    printdot();
      for(int j=0;j<entries.size();j++)
      {
        if(x==entries[j].name)
        {
            cout<<"match found"<<endl;
        cout<<"deleting the element"<<endl;
        printdot();
        entries.erase(entries.begin()+j);
        cout<<"element deleted"<<endl; 

        }
        else
    {
        cout<<"no such contact exist: do you want to search with contact number?(y/n)"<<endl;
        cin>>y;
        cout<<endl;
        if(y=='y')
        {
            cout<<"enter the no you want to search: ";
            cin>>no;
            cout<<"searching for the no";
            printdot();
            if(no==entries[j].number)
            {
                cout<<"match found!!!"<<endl;
                cout<<"deleting the contact"<<endl;
               printdot();
                entries.erase(entries.begin()+j);
        cout<<"element deleted"<<endl; 

      }
        }
        else
        {
            delete_contact();
        }
    }
      }
}

void edit_contact()
{   int w,choice5;
    string bname,newname,newmail;
    long long int newnumber,bno;
    system("CLS");
    start:
    cout<<"how do you want to search the contatc you want to edit?"<<endl;
    cout<<"1. name"<<endl<<"2. number"<<endl;
    cin>>w;
    switch (w)
    {
    case 1:
                 cout<<"enter the name of the contact: ";
                 cin>>bname;    
             cout<<"searching for the contact"<<endl;
               printdot();
      for(int j=0;j<entries.size();j++)
      {
        if(bname==entries[j].name)
        {
            cout<<"match found"<<endl<<"displaying current details of the contact:"<<endl;
            cout<<entries[j].name<<"-"<<entries[j].number<<":"<<entries[j].mail<<endl;
            start2:
            cout<<"what do you want to edit in the contact"<<endl;
            cout<<"1. name"<<endl<<"2. number"<<endl<<"3. mail"<<endl;
            cin>>choice5;
            switch(choice5)
            {
                case 1:
                cout<<"enter new name: ";
                cin>>newname; 
                cout<<"updating details";
                printdot();
                newname=entries[j].name;
                cout<<"name updated";
                break;

                case 2:
                cout<<"enter new number: ";
                cin>>newnumber;
                cout<<"updating details";
                printdot();
                newnumber=entries[j].number;
                cout<<"number updated";
                break;

                case 3:
                cout<<"enter new mail: ";
                cin>>newmail;
                cout<<"updating details";
                printdot();
                newmail=entries[j].mail;
                cout<<"mail updated";
                break;

                default:
                cout<<"\a please don't try to fuck with the system and select a valid choice";
                goto start2;
                break;

                
            }
        }
        else
        {
            cout<<"\a";
        }
      }

            
     /* constant-expression */
        /* code */
        break;
     
     case 2:
             cout<<"enter the number of the contact: ";
             cin>>bno;
             cout<<"searching for the contact"<<endl;
               printdot();
      for(int j=0;j<entries.size();j++)
      {
        if(bno==entries[j].number)
        {
            cout<<"match found"<<endl<<"displaying current details of the contact:"<<endl;
            cout<<entries[j].name<<"-"<<entries[j].number<<":"<<entries[j].mail<<endl;
            start3:
            cout<<"what do you want to edit in the contact"<<endl;
            cout<<"1. name"<<endl<<"2. number"<<endl<<"3. mail"<<endl;
            cin>>choice5;
            switch(choice5)
            {
                case 1:
                cout<<"enter new name: ";
                cin>>newname; 
                cout<<"updating details";
                printdot();
                newname=entries[j].name;
                cout<<"name updated";
                break;

                case 2:
                cout<<"enter new number: ";
                cin>>newnumber;
                cout<<"updating details";
                printdot();
                newnumber=entries[j].number;
                cout<<"number updated";
                break;

                case 3:
                cout<<"enter new mail: ";
                cin>>newmail;
                cout<<"updating details";
                printdot();
                newmail=entries[j].mail;
                cout<<"mail updated";
                break;

                default:
                cout<<"\a please don't try to fuck with the system!!";
                goto start3;
                break;

                
            }
        }
        else
        {
            cout<<"\a no such contact found with this name!!";
        }
      }

            
     /* constant-expression */
        /* code */
        break;



    default:
        cout<<"\a please don't fuck with the system and select a valid choice";
        goto start;

    }

}
    void search_contact()
    {
        int a=0;
             system("CLS");
             string temp_name;
              cout<<"enter the name of the contact you want to search: ";
              cin>>temp_name;
              for(int i=0;i<entries.size();i++)
              {
               if(temp_name==entries[i].name)
               {
                cout<<endl;
                cout<<entries[i].name<<"-"<<entries[i].number;
               }
               a++; 
              }
              if(a==entries.size())
               
               {
               cout<<"no such contact found "<<endl<<"do you want to try again?(y/n): ";
               char choice;
               cin>>choice;
               if(choice=='y' || choice=='Y')
                search_contact();
               
               
    }
              }


int main()

{    
    
      int choice;
      while(1)
      {
        system("CLS");
    
     cout<<"****************welcome to your phonebook*******************"<<endl<<endl;
    cout<<"1. display contact list"<<endl;
    cout<<"2. add a contact"<<endl;
    cout<<"3. delete a contact"<<endl;
    cout<<"4. edit contact"<<endl;
    cout<<"5. search contact"<<endl;
    cout<<"6. exit"<<endl;

    cin>>choice;

    
    switch(choice)
    {
        case 1:
         
        display();
        break;
        case 2:
        add_contact();
        break;
        case 3:
        delete_contact();
        break;
        case 4:
        edit_contact();
        break;
        case 5:
        search_contact();
        break;
        case 6:
        exit(0);
        break;
        default:
        cout<<"please enter a valid choice"<<endl;
    }
    }
    return 0;
}

void printdot()
{
    for(int i=0;i<3;i++)
    {
        cout<<".";
        Sleep(2000);
    }
}