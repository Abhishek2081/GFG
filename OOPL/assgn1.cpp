#include<iostream>
using namespace std;
class Weather
{
	public:
        int m,j;
	int day,mon,snow,hight,lowt,amtr;
        
	Weather()
	{
		snow=hight=lowt=amtr=0;
	}
	void input(int d,int m)
	{
		day=d;
		mon=m;
		cout<<"Enter snow"<<endl;
		cin>>snow;
		cout<<"Enter high temp"<<endl;
		cin>>hight;
		cout<<"Enter low temp"<<endl;
		cin>>lowt;
		cout<<"Enter amount of rain"<<endl;
		cin>>amtr;
	}
};
void display(Weather arr[][31])
{
	int i,j,m;
	cout<<"Enter month"<<endl;
	cin>>m;
	
		cout<<"Date\t"
			<<"Month\t "
			<<"Snow \t"
			<<"High temp\t "
			<<"Low temp\t"
			<<"Rain \t"<<endl;
		if(m==2)
		{
				for(j=1;j<29;j++)
				{
					arr[m][j].day=j;
					arr[m][j].mon=m;
					cout<<arr[m][j].day<<"\t"<<arr[m][j].mon<<"\t"<<arr[m][j].snow<<"\t"<<arr[m][j].hight<<"\t\t"<<arr[m][j].lowt<<"\t\t"<<arr[m][j].amtr<<endl;

				}
				return;
		}
		if(m<8)
		{
			if(m%2==0)
			{
				for(j=1;j<31;j++)
				{
					arr[m][j].day=j;
					arr[m][j].mon=m;
					cout<<arr[m][j].day<<"\t"<<arr[m][j].mon<<"\t"<<arr[m][j].snow<<"\t"<<arr[m][j].hight<<"\t\t"<<arr[m][j].lowt<<"\t\t"<<arr[m][j].amtr<<endl;
				}
				return;
			}
			else
			{
				for(j=1;j<32;j++)
				{
					arr[m][j].day=j;
					arr[m][j].mon=m;
					cout<<arr[m][j].day<<"\t"<<arr[m][j].mon<<"\t"<<arr[m][j].snow<<"\t"<<arr[m][j].hight<<"\t\t"<<arr[m][j].lowt<<"\t\t"<<arr[m][j].amtr<<endl;
				}
				return;

			}
		}
		else
		{
			if(m%2==0)
			{
				for(j=1;j<32;j++)
				{
					arr[m][j].day=j;
					arr[m][j].mon=m;
					cout<<arr[m][j].day<<"\t"<<arr[m][j].mon<<"\t"<<arr[m][j].snow<<"\t"<<arr[m][j].hight<<"\t\t"<<arr[m][j].lowt<<"\t\t"<<arr[m][j].amtr<<endl;
				}
				return;
			}
			else
			{
				for(j=1;j<31;j++)
				{
					arr[m][j].day=j;
					arr[m][j].mon=m;
					cout<<arr[m][j].day<<"\t"<<arr[m][j].mon<<"\t"<<arr[m][j].snow<<"\t"<<arr[m][j].hight<<"\t\t"<<arr[m][j].lowt<<"\t\t"<<arr[m][j].amtr<<endl;
				}
				return;

			}

		}
}

void average(Weather arr[][31])
{
 int namtr=0,nsnow=0,nhight=0,nlowt=0,t=0; 
 float avgamtr,avgsnow,avghight,avglowt;
 int i=0,j=0;

  cout<<"Enter The Month For Average Data"<<endl;
  cin>>i;
  
  for(j=1;j<32;j++)
   {
    namtr+=arr[i][j].amtr;
    nsnow+=arr[i][j].snow;
    nhight+=arr[i][j].hight;
    nlowt+=arr[i][j].lowt;
    t++;
    
    if(arr[i][j].amtr==arr[i][j].snow==arr[i][j].hight==arr[i][j].lowt==0)
    { 
       t--;
    }
   } 

  avgamtr=namtr/t;
  avgsnow=nsnow/t;
  avghight=nhight/t;
  avglowt=nlowt/t;
  
  cout<<"Average Amount OF Rain"<<avgamtr<<endl;
  cout<<"Average Snow Fall"<<avgsnow<<endl;
  cout<<"Average High Temperature"<<avghight<<endl;
  cout<<"Average Low Temperature"<<avglowt<<endl;
}

int main()
{
	Weather arr[31],tot;
        int snow,hight,lowt,amtr;
	int d,m,i,x;

	do
	{
		cout<<"1.Input"<<endl
			<<"2.Display"<<endl
			<<"3.Average"<<endl
			<<"4.Exit"<<endl;
		cin>>x;
		switch(x)
		{
			case 1: cout<<"Enter date"<<endl;
				cin>>d;
				cout<<"Enter Month"<<endl;
				cin>>m;
				arr[m][d].input(d,m);
				break;
			case 2: display(arr);
				break;
			case 3: average(arr);
			        break;
			case 4: return 0;

		}
	}while(1);
        return 0;
}


