#include<iostream>
using namespace std;
template<class T>

class matrix
{
    T mat1[10][10],mat2[10][10],res[20][20];
    int row1,col1,row2,col2,row,col;

    public :
    void input()
    {
        int i,j;
        cout<<"Enter number of rows and coloumns of first matrix"<<endl;
        cin>>row1>>col1;
        
        cout<<"Enter elements"<<endl;
	    for(i=0;i<row1;i++)
	    	for(j=0;j<col1;j++)
	    		cin>>mat1[i][j];
	    		
	    cout<<"Enter number of rows and coloums for second matrix"<<endl;
	    cin>>row2>>col2;
	    
	    cout<<"Enter elements"<<endl;
	    for(i=0;i<row2;i++)
	    	for(j=0;j<col2;j++)
	    		cin>>mat2[i][j];
    }
    void display()
    {
        int i,j;
        
        cout<<"\nMatrix 1 is :"<<endl;
        for(i=0;i<row1;i++)
        {
	    	cout<<"|";
	    	for(j=0;j<col1;j++)
	    		cout<<mat1[i][j]<<"\t";
	    	cout<<"|";
	    	cout<<"\n";
	}
	
	cout<<"\nMatrix 2 is :"<<endl;
        for(i=0;i<row2;i++)
        {
	    	cout<<"|";
	    	for(j=0;j<col2;j++)
	    		cout<<mat2[i][j]<<"\t";
	    	cout<<"|";
	    	cout<<"\n";
	}
	 
	cout<<"\nAnswer is :"<<endl;
        for(i=0;i<row;i++)
        {
	    	cout<<"|";
	    	for(j=0;j<col;j++)
	    		cout<<res[i][j]<<"\t";
	    	cout<<"|";
	    	cout<<"\n";
	}
    }
    void addition()
    {
        int i,j;
        if(row1==row2 && col1==col2)
	    {
	        for(i=0;i<row1;i++)
	    		for(j=0;j<col1;j++)
	    		{
	    			res[i][j]=mat1[i][j]+mat2[i][j];
	    			row=row1;col=col1;
	    		}
	    }
	    else
	    cout<<"Dimensions do not match Hence Addition is not possible "<<endl;
    }
    void subtraction()
    {
        int i,j;
        if(row1==row2 && col1==col2)
	    {
	        for(i=0;i<row1;i++)
	    		for(j=0;j<col1;j++)
	    			res[i][j]=mat1[i][j]-mat2[i][j];
	    			row=row1;col=col1;
	    }
	    else
	    cout<<"Dimensions do not match Hence Subtraction is not possible "<<endl;
    }
    void multiply();
};
template<class T>void matrix<T>::multiply()
{
    int i,j,k,sum;
    if(col1==row2)
    {
        for(i=0;i<row1;i++)
            for(j=0;j<col2;j++)
            {
                res[i][j]=0;
                sum=0;
                
                for(k=0;k<col1;k++)
                {
                    sum+=mat1[i][k]*mat2[k][j];
                    res[i][j]=sum;
                }
            }
            row=col1;
            col=row2;
    }
    else
	    cout<<"Dimensions do not match Hence Multiplication is not possible "<<endl;
}
int main()
{
    int ch;
    matrix <float>a;
    
    do
    {
    	cout<<"Enter your choice"<<endl
    		<<"1.Input"<<endl
    		<<"2.Addition"<<endl
    		<<"3.Subtraction"<<endl
    		<<"4.Multiplication"<<endl
    		<<"5.Exit"<<endl;
    	cin>>ch;
   	 switch(ch)
	 {
	   	case 1: a.input();
		  	break;

	    	case 2: a.addition();
	            	a.display();
	            	break;

	    	case 3: a.subtraction();
	            	a.display();
	            	break;

	    	case 4: a.multiply();
	            	a.display();
	            	break;

	    	case 5: return 0;

	    	default: cout<<"Enter valid choice"<<endl;
	 }
    }while(1);
    
return 0;       
}
