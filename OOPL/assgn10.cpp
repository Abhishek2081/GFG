#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstring>
using namespace std;
typedef struct Student
{
	
}Student;
int create()
{
	char id[10],age[10];
	char name[100];

	fstream fout;
	fout.open("Database.dat",ios::app);

	int n,i;
	cout<<"Enter number of students :";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"Student ID: ";
		cin>>id;
		fout<<"\t"<<id;
		cout<<"Name      :";
		cin.ignore();
		cin.getline(name,100);;
		fout<<"\t"<<name;
		cout<<"Age       :";
		cin>>age;
		fout<<"\t"<<age;
	}
	fout.close();	
	return N;
}
void display()
{
	char id[10],age[10];
	char name[100];
	ifstream fin("Database.dat");
	
	cout<<"  ID     NAME     AGE \n";
	while(1)
	{
		fin>>id;
		fin>>name;
		fin>>age;
		cout<<"\t"<<id;
		cout<<"\t"<<name;
		cout<<"\t"<<age<<endl;	
		if(fin.eof())
		break;
	}
	fin.close();
}
int search(char ID[])
{
	char id[10],age[10];
	char name[100];
	ifstream fin("Database.dat");
	while(1)
	{
		fin>>id;
		fin>>name;
		fin>>age;
		
		if(!strcmp(ID,id))
		{
			fin.close();
			return 1;
		}	
		if(fin.eof())
		break;
	}
	
	fin.close();
	return 0;
}
void deleterec(char ID[],int N)
{
	char id[30],prev[30]="0",name[30],age[10];
	char str[100];
	ifstream fin("Database.dat");
	ofstream fout("Temp.dat");
	int c=0;	
	int F=search(ID);
	if(!F)
	{
		cout<<"Data NOT Found.......\n";
		return;
	}
	while(1)
	{
		if(fin.eof())
		break;
		c++;
		fin>>id;
		fin>>name;
		fin>>age;
		if(fin.eof())
		break;
		if(strcmp(id,ID)!=0)
		{
			fout<<"\t"<<id;
			fout<<"\t"<<name;
			fout<<"\t"<<age;
		}
		if(fin.eof())
		break;
	}
	fin.close();
	fout.close();
	
	fin.open("Temp.dat");
	fout.open("Database.dat");
	while(!fin.eof())
	{
		fin.getline(str,98);
		fout<<str<<"\n";
	}
	
	remove("Temp.dat");
	cout<<">>Deleted successfully......\n";
}
void modify(char key[],int N)
{
	char id[30],prev[30]="0",name[30],age[10];
	char str[100];
	ifstream fin("Database.dat");
	ofstream fout("Temp.dat");
	int c=0;	
	int F=search(key);
	if(!F)
	{
		cout<<"Data NOT Found.......\n";
		return;
	}
	while(1)
	{
		c++;
		fin>>id;
		fin>>name;
		fin>>age;
		if(fin.eof())
		break;
		if(strcmp(id,key)!=0)
		{
			fout<<setw(4)<<id;
			fout<<setw(10)<<name;
			fout<<setw(7)<<age;
		}
		else
		{
			cout<<"New Student ID: ";
			cin>>id;
			fout<<setw(4)<<id;
			cout<<"New Name      :";
			cin.ignore();
			cin.getline(name,98);;
			fout<<setw(10)<<name;
			cout<<"New Age       :";
			cin>>age;
			fout<<setw(7)<<age<<endl;
		}
	}
	fin.close();
	fout.close();
	
	fin.open("Temp.dat");
	fout.open("Database.dat");
	while(!fin.eof())
	{
		fin.getline(str,98);
		fout<<str<<"\n";
	}
	remove("Temp.dat");
	cout<<">>Record modified successfully....\n";
}
int main()
{
	int N,i,j,ch;
	int id,age;
	char name[100];

	do
	{
		cout<<"	1.Create record\n";
		cout<<"	2.Display records\n";
		cout<<"	3.Add records\n";
		cout<<"	4.Delete record\n";
		cout<<"	5.Modify record\n";
		cout<<"	6.Search record\n";
		cout<<"Enter your choice   :";
		cin>>ch;
		switch(ch)
		{
			case 1:	ofstream fout("Database.dat");
				fout.close();
				N=create();
				break;

			case 2:	display();
				break;

			case 3:	N=create();
				break;

			case 4:	char id[10];
				cout<<"Enter ID to be deleted :";
				cin.ignore();
				cin.getline(id,9);
				deleterec(id,N);
				break;

			case 5:	char id[10];
				cout<<"Enter ID to be modified :";
				cin.ignore();
				cin.getline(id,9);
				modify(id,N);
				break;

			case 6:	char id[10];
				int F;
				cout<<"Enter ID to be searched :";
				cin.ignore();
				cin.getline(id,9);
				F=search(id);
				if(F)
				{
					cout<<"Data Found.......\n";
				}
				else
					cout<<"Data NOT Found.......\n";
				break;
			case 0:break;

			default :cout<<"**Enter valid choice....\n";
		}
	}while(ch);
}


