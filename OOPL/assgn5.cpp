#include<iostream>
using namespace std;

class Personal_Rec
{
	protected :
		char name[20];
		int day,month,year;
		char bloodgrp[4];
		
	public :
		void input1();
};

void Personal_Rec::input1()
{
    cout<<"\nEnter name :"<<endl;
    cin.ignore();
    cin.getline(name,19);
    cout<<"Enter date of birth\nDay :"<<endl;
    cin>>day;
    cout<<"Month :"<<endl;
    cin>>month;
    cout<<"Year :"<<endl;
    cin>>year;
    cout<<"Blood Group :"<<endl;
    cin.ignore();
    cin.getline(bloodgrp,3);
}

class Profession_Rec
{
	protected :
		int exp;
		char skills[30];
		
	public :
		void input2();
};

void Profession_Rec::input2()
{
    cout<<"Previous Work Experience in years :"<<endl;
    cin>>exp;
    cout<<"Skills :"<<endl;
    cin.ignore();
    cin.getline(skills,30);
}

class Academic_Rec
{
	protected :
		float percentile;
		
	public :
		void input3();
};

void Academic_Rec::input3()
{
    cout<<"Degree Percentile :"<<endl;
    cin>>percentile;
}

class Resume:public Personal_Rec,public Profession_Rec,public Academic_Rec
{
	public:
		void display();
		
		void input()
		{
			Personal_Rec::input1();
			Profession_Rec::input2();
			Academic_Rec::input3();
		}
};

void Resume::display()
{
	cout<<"\tRESUME"<<endl
		<<"Name            :  "<<name<<endl
		<<"Date of birth   :  "<<day<<"/"<<month<<"/"<<year<<endl
		<<"Blood Group     :  "<<bloodgrp<<endl
		<<"Work Experience :  "<<exp<<endl
		<<"Skills          :  "<<skills<<endl
		<<"Degree Percent  :  "<<percentile<<endl;
}

int main()
{
	Resume D;
	int ch;
	
	do
	{
		cout<<"Enter your choice"<<endl
			<<"1 - Input"<<endl
			<<"2 - Display"<<endl
			<<"3 - Exit"<<endl;
		cin>>ch;

		switch(ch)
		{
			case 1: D.input();
				break;
				
			case 2: D.display();
				break;
				
			case 3: return 0;
				
			default: cout<<"Invalid choice"<<endl;
		}
	}while(1);
	
return 0;
}
