#include<iostream>
using namespace std;

class shape
{
	protected:
		double l1,l2;
		
	public:
		virtual void compute_area()=0;
};

class triangle:public shape
{
	public:
	
	void compute_area()
	{
		double ar;
		cout<<"Enter dimensions of triangle"<<endl;
		
		cout<<"Height :"<<endl;
		cin>>l1;
		cout<<"Base :"<<endl;
		cin>>l2;
		
		ar=l1*l2/2;
		cout<<"Area of triangle ="<<ar<<endl;
	}
};

class rectangle:public shape
{
	public:
	void compute_area()
	{
		double ar;
		cout<<"Enter dimensions of rectangle"<<endl;
		
		cout<<"Length : ";
		cin>>l1;
		cout<<"Breadth : ";
		cin>>l2;
		
		ar=l1*l2;
		cout<<"Area of rectangle ="<<ar<<endl;
	}
};

int main()
{
	shape *ptr;
	triangle T;
	rectangle R;
	int ch;
	
	do
	{
	    cout<<"Enter your choice"<<endl
	    		<<"1.Triangle"<<endl
	    		<<"2.Rectangle"<<endl
	    		<<"3.Exit"<<endl;
	    cin>>ch;
	    
	    switch(ch)
	    {
		    case 1: ptr=&T;
		            ptr->compute_area();
		            break;
		        
		    case 2: ptr=&R;
		    	    ptr->compute_area();
		            break;
		        
		    case 3: return 0;
		    
		    default: cout<<"Enter valid choice ";  
	    }
	    
	}while(1);
	
	return 0;
}
