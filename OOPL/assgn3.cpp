#include<iostream>
using namespace std;
class complex
{
	double r,i;

	public:
	void input(int);
	void output();
	friend complex operator +(complex,complex);
	friend complex operator -(complex,complex);
	complex operator *(complex);
	complex operator /(complex);
};
int main()
{
	int ch=0;
	complex a,b,ans;

	a.input(1);
	b.input(2);

	do
	{
		cout<<"Enter the Choice"<<endl;
		cout<<"1.Addition"<<endl
                       <<"2.Subtraction"<<endl
                       <<"3.Multiplication"<<endl
                       <<"4.Division"<<endl
                       <<"5.Exit"<<endl
                       <<"Your Choice= ";
		cin>>ch;
		switch (ch)
		{
			case 1: ans=a+b;
				ans.output();
				break;
		
			case 2: ans=a-b;
				ans.output();
				break;

			case 3: ans=a*b;
				ans.output();
				break;

			case 4: ans=a/b;
				ans.output();
				break;

			case 5: return 0;

			default: cout<<"Wrong Choice!\n";
				 break;
		}
	}while(ch=1);
return 0;
}

void complex::input(int n)
{
	cout<<"Enter Complex Number "<<n<<":"<<endl;
	cout<<"\tReal Part=";
	cin>>r;
	cout<<"\tImaginary Part=";
	cin>>i;
	
	cout<<"Complex No. = ("<<r<<")+("<<i<<")i\n"<<endl;
}
void complex::output()
{
	cout<<"\tAnswer = ("<<r<<") + ("<<i<<")i\n"<<endl;
}
complex operator +(complex a,complex b)
{
	complex k;
	k.r=a.r+b.r;
	k.i=a.i+b.i;
	return k;
}
complex operator -(complex a,complex b)
{
	complex k;
	k.r=a.r-b.r;
	k.i=a.i-b.i;
	return k;
}
complex complex::operator *(complex b)
{
	complex k;
	double r1,r2,i1,i2;

	r1=(r*b.r);
	r2=(i*b.i);
	k.r=r1-r2;

	i1=(r*b.i);
	i2=(i*b.r);
	k.i=i1+i2;
	return k;
}
complex complex::operator /(complex b)
{
	complex k;
	double r1,r2,i1,i2;
	r1=(r*b.r)+(i*b.i);
	r2=(b.r*b.r)-(b.i*b.i);
	k.r=r1/r2;

	i1=(i*b.r)-(r*b.i);
	i2={(b.r*b.r)-(b.i*b.i)};
	k.i=i1/i2;
	return k;
}

