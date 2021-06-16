#include<iostream>
#include<string.h>
using namespace std;

class B1
{
	protected :
		char name[20];
		int day,month,year;
		char bloodgrp[5];
		
	public :
		void input();
};

void B1::input()
{
    cout<<"\nEnter name : ";
    cin.ignore();
    cin.getline(name,19);
    cout<<"Enter date of birth\nDay : ";
    cin>>day;
    cout<<"Month : ";
    cin>>month;
    cout<<"Year : ";
    cin>>year;
    cout<<"Blood Group : ";
    cin.ignore();
    cin.getline(bloodgrp,4);
}

class B2
{
	protected :
		float height;
		float weight;
		
	public :
		void input();
};

void B2::input()
{
    cout<<"Height : ";
    cin>>height;
    cout<<"Weight : ";
    cin>>weight;
}

class B3
{
	protected :
		int policyno;
		char address[20];
		
	public:
		void input();
};

void B3::input()
{
    cout<<"Policy number : ";
    cin>>policyno;
    cout<<"Address : ";
    cin.ignore();
    cin.getline(address,19);
}

class D:public B1,public B2,public B3
{
	char telno[15],licenseno[10];
	
	public :
		void input();
		void display(int);
		int search(char []);
		void edit();
};

void D::input()
{
    B1::input();
    B2::input();
    B3::input();
    
    cout<<"Telephone number :";
    cin.getline(telno,15);
    cout<<"License Number :";
    cin.getline(licenseno,10);
}

void D::display(int i)
{
		cout<<++i<<"."<<endl
			<<"License No.: "<<licenseno<<endl
			<<"Name: "<<name<<endl
			<<"Date: "<<day<<"/"<<month<<"/"<<year<<endl
			<<"Blood Grp.: "<<bloodgrp<<endl
			<<"Height: "<<height<<endl
			<<"Weight: "<<weight<<endl
			<<"Policy No.:"<<policyno<<endl
			<<"Address: "<<address<<endl
			<<"Telephone No.: "<<telno<<endl;
}

int D::search(char s[20])
{
	int j;
	j=strcmp(s,licenseno);
	return j;
}

void D::edit()
{
	int ch;
	cout<<"What you want to edit:"<<endl
		<<"1 - Name"<<endl
		<<"2 - Policy Number"<<endl
		<<"3 - Address"<<endl
		<<"4 - Telephone Number"<<endl;
	cin>>ch;
	
	switch(ch)
	{
		case 1: cin.ignore();
  			cout<<"Enter name :"<<endl;
  			cin.getline(name,19);
  			break;
  			  
		case 2: cout<<"Policy number :"<<endl;
			cin>>policyno;
    			break;
    			
		case 3: cin.ignore();
    			cout<<"Address :"<<endl;
    			cin.getline(address,19);
    			break;
    			
		case 4: cin.ignore();
  			cout<<"Telephone number :"<<endl;
   			cin.getline(telno,14);
   			break;
   			
		default : cout<<"Invalid Choice"<<endl;  
	}
}

int main()
{
	D a[50];
	int i,l,ch,n,count;
	char licnsno[10],edit1[10],sc[10];
	
	do{
		cout<<"\nMENU:"<<endl
			<<"1.Build master table"<<endl
			<<"2.Display Record"<<endl
			<<"3.Insert a record"<<endl
			<<"4.Delete a record"<<endl
			<<"5.Edit a record"<<endl
			<<"6.Search a record"<<endl
			<<"7.exit"<<endl;
		cin>>ch;
		
		
		switch(ch)
		{
			case 1:	cout<<"Enter no of records to be added : "<<endl;
   				cin>>n;
   				for(i=0;i<n;i++)
      				{
        				a[i].input();
       				}
    				break;
    
			case 2:	for(i=0;i<n;i++)
        			  a[i].display(i);
    				break;
    
			case 3: cout<<"How many records you want to add : "<<endl;
    				cin>>count;
   				for(i=n;i<(n+count);i++)
      				{
     				    	a[i].input();
     				}
   				n=n+count;
   				break;
    
			case 4: cout<<"Enter License number to delete : "<<endl;
    				cin>>licnsno; 
   				for(i=0;i<n;i++)
    				{
   					if(!a[i].search(licnsno))
   					{
   						cout<<"Record Found and deleted"<<endl;
   						for(l=i;l<n-1;l++)
   							a[l]=a[l+1];
  						n--;
   						break;
   					}
    				}
   				if(i==n)
      				{
      					cout<<"Record not found"<<endl;
      				}
   				break;
    
			case 5: cout<<"Enter license number to edit :"<<endl;
    				cin>>edit1;
    				for(i=0;i<n;i++)
    				{
    					if(!a[i].search(edit1))
   					{
   						cout<<"Record Found"<<endl;
    						a[i].edit();
    						break;
   				 	}
    				}
   				if(i==n)
    				{
    					cout<<"Record not Found"<<endl;
    				}
    				break;
    
			case 6: cout<<"Enter license no to be searched :"<<endl;
				cin>>sc;
    				for(i=0;i<n;i++)
    				{
    					if(!a[i].search(sc))
    					{
    						cout<<"Record Found"<<endl;
    						break;
    					}
    				}
   				if(i==n)
   				{
    					cout<<"Record not Found"<<endl;
    				}
    				break;
    
			case 7: return 0;
    
			default: cout<<"Invalid choice"<<endl;
    
		}
	}while(1);
	
return 0;
}
