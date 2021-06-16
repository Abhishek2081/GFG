#include <iostream>
#include <fstream>
using namespace std;
class student
{
	protected:
	char name[40],sub[40],Rno[10];
};
class edu: public student
{
	char subco[10];
	int inmark,unimark;
	public:
		void getdata()
		{
			ofstream fout;
			fout.open("Database.txt",ios::app);
			cin.ignore();
			cout<<"Enter name              :";
			cin.getline(name,38);
			fout<<"  "<<name;
			cout<<"Enter subject           :";
			cin.getline(sub,38);
			fout<<"\t\t"<<sub;
			cout<<"Enter Roll no           :";
			cin.getline(Rno,38);
			fout<<"\t\t"<<Rno;
			cout<<"Enter internal marks    :";
			cin>>inmark;
			fout<<"\t\t"<<inmark;
			cout<<"Enter university marks  :";
			cin>>unimark;
			fout<<"\t\t"<<unimark;
			fout<<endl;
			fout.close();
		}	
		void putdata()
		{
			char str[100];
			ifstream fin("Database.txt");
			while(fin)
			{
				fin.getline(str,98);
				cout<<str<<endl;
			}
			cout<<endl;
		}
};
int main()
{
	int ch;
	edu E;
	do
	{
		cout<<"	1.Create record\n";
		cout<<"	2.Show record\n";
		cout<<"	0.EXIT\n";
		cout<<"Enter your choice :";
		cin>>ch;
		switch(ch)
		{
			case 1:
			{
				int i,N;
				cout<<"Enter number of students :";
				cin>>N;
				for(i=0;i<N;i++)
				E.getdata();
			}break;
			case 2:
			{
			cout<<"   Name    Subject     RollNO    Int.marks   Uni. marks \n";
			E.putdata();
			}break;
		}
	}while(ch);
	return 0;
}


