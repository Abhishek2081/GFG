#include<iostream>
#include<string.h>
using namespace std;

class book
{
	public:
	char *title,*author,*publisher;
        int *avstock;
        float *price;
        static int succt,unsucct;
        
        void add();
        void display();
        int search(char name1[],char name2[]);
        int Update();
        int purchase();
        
	book()
   	{
     		avstock=new int;
     		price=new float;
    	 	title=new char[20];
     		author=new char[20];
     		publisher=new char[20];
   	}
   	
	static void trans()
	{
	    cout<<"Sucessful Transactions="<<succt<<endl;
	    cout<<"Unsucessful Transactions="<<unsucct<<endl;
	}
};
	
void book::add()
{        
         cin.ignore();
         cout<<"Enter Book Details"<<endl;
         cout<<"Enter Title"<<endl;
         cin.getline(title,20);
         cout<<"Enter Author"<<endl;
         cin.getline(author,20);
         cout<<"Enter Publisher"<<endl;
         cin.getline(publisher,20);
         cout<<"Enter Price"<<endl;
         cin>>*price;
         cout<<"Enter Available Stock of Books"<<endl;
         cin>>*avstock;
         
}

void book::display()
{
         cout<<"\nTITLE:"<<title<<endl;
         cout<<"AUTHOR:"<<author<<endl;
         cout<<"PUBLISHER:"<<publisher<<endl;
         cout<<"PRICE:"<<*price<<endl;
         cout<<"AVAILABLE STOCK:"<<*avstock<<endl;
}

int book::search(char name1[20],char name2[20])
{
   int s1,s2;
   
   s1=strcmp(name1,title);
   s2=strcmp(name2,author);
   
   if((s1==0)&&(s2==0))
   {
   	return 1;
   }
   
   else 
   { 
   	return 0; 
   }
   
}

int book::purchase()
{
   	int copies;  			
  	succt++;	   
	cout<<"\nEnter No. of Copies You Want =";
	cin>>copies;
        if(copies<=*avstock)
	{
		*avstock-=copies;
        	cout<<"\nPurchased Succesfully"<<endl;
    	        cout<<"\nTotal Amount ="<<(*price)*copies<<endl;		    
     	}
     	else 
     	{ 
     		unsucct++;
     		cout<<"\nRequired Copies Not Available"<<endl;
     	}  
   	return 0;
}

int book::Update()
{
        succt++;
  	cout<<"\nEnter  New  Cost of One Book=";
  	cin>>*price;
  	cout<<"\nEnter  New  Available Stock=";
  	cin>>*avstock; 
         
}

int book::succt;
int book::unsucct;

int menu()
{ int x;
cout<<"\n1.Add A Book"<<endl
                        <<"2.Display A Book"<<endl
			<<"3.Search A Book"<<endl
			<<"4.Purchase A Book"<<endl
			<<"5.Update A Book"<<endl
			<<"6.Update Transaction"<<endl
			<<"7.Exit"<<endl;
 cin>>x;
 return x;
	
}

int main()
{
        book arr[20];
        char title[20],author[20],publisher[20],name1[20],name2[20];
        int choice,copies;
        int i,n;

	do
	{
		choice=menu();
		
		switch(choice)
		{
			case 1: cout<<"Enter Number of Books To Add ="<<endl;
			        cin>>n;
			        for(i=0;i<n;i++)
			          arr[i].add();
				break;
			case 2: for(i=0;i<n;i++)
			         arr[i].display();
				break;
			case 3: cin.ignore();
   				cout<<"Enter Name of Book To Search"<<endl;
   				cin.getline(name1,20);
   				cout<<"Enter Authors Name Of Above Book To Search"<<endl;
  				cin.getline(name2,20);
			        for(i=0;i<n;i++)
                                {
                                  if(arr[i].search(name1,name2))
                                  {
                                       cout<<"BOOK FOUND"<<endl;
                                       arr[i].display();
                                       break;
                                  }
                                  if(i==n)
                                  {
                                       cout<<"BOOK NOT FOUND"<<endl;
                                  }
                                 }
                                break;
			case 4: cin.ignore();
				cout<<"\nEnter Name of Book to Buy=";
				cin.getline(name1,20);
				cout<<"\nEnter Name of Author=";
				cin.getline(name2,20);
				for(i=0;i<n;i++) 
				{
  				 	if (arr[i].search(name1,name2))		 
   	    	     			{
	   	    	     		cout<<"\nBook Found"<<endl;
			 		arr[i].display();
			 		arr[i].purchase();
			 		break;
			     		}
		        	}
				if(i==n)
			 	cout<<"\nNot found"<<endl;        
				break;
			case 5: cin.ignore();
				cout<<"\nEnter Name of Book to Update Data=";
			        cin.getline(name1,20);
			        cout<<"\nEnter Name of Author=";
			        cin.getline(name2,20);
				for(i=0;i<n;i++) 
  				{
  				 	if (arr[i].search(name1,name2))		 
     					{
		   	    	     		cout<<"\nBook Found"<<endl;
				 		arr[i].display();
			 			arr[i].Update();
		         			break;
		         		}
		        	} 	
			 	if(i==n)
			  	cout<<"\nNot Found"<<endl; 
			case 6: book::trans();
			        break;
			case 7: return 0;

		}
	}
	while(1);
        return 0;

}
