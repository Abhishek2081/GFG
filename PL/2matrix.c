/*
 ============================================================================
Roll no.:23103
Name:Abhishek Agashe
Class:SE-9
Batch:E-9
Problem Statement:Represent matrix using two dimensional arrays and
perform following operations without pointer.
a) Addition
b) Multiplication
c) Transpose
d) Saddle point
 ============================================================================
 */

#include <stdio.h>

#define max 10
void get_matrix(int a[max][max],int m, int n);
void print_matrix(int a[max][max],int m, int n);
void mult_matrix(int a[max][max],int b[max][max],int c[max][max],int m, int n, int );
void add_matrix(int a[max][max],int b[max][max],int c[max][max],int r1, int c2);
void transpose_matrix(int a[max][max],int c[max][max],int r1, int c2);
void saddlept_matrix(int a[max][max],int r1, int c1);

void get_matrix(int a[max][max],int m, int n)
{
	int i,j;
	for(i=0;i<m;i++)
	{
		for (j=0;j<n;j++)
		{
			printf("\nEnter element %d,%d :",i+1,j+1);
			scanf("%d",&a[i][j]);
		}
	}
}

void print_matrix(int a[max][max],int m, int n)
{
	int i,j;
	printf("\n");
	for(i=0;i<m;i++)
	{
		for (j=0;j<n;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n\n");
	}
}
void mult_matrix(int a[max][max],int b[max][max],int c[max][max],int r1, int c2,int c1)
{
	int i,j,k;
	for(i=0;i<r1;i++)
	{
		for(j=0;j<c2;j++)
		{
			c[i][j]=0;
			for(k=0;k<c1;k++)
			{
				c[i][j]+=b[k][j]*a[i][k];
			}
		}
	}
}
void add_matrix(int a[max][max],int b[max][max],int c[max][max],int r1, int c2)
{
	int i,j;
	for(i=0;i<r1;i++)
	{
		for (j=0;j<c2;j++)
		{
			c[i][j]=a[i][j]+b[i][j];
		}
	}
}
void transpose_matrix(int a[max][max],int c[max][max],int r1, int c2)
{
	int i,j;
	for(i=0;i<r1;i++)
	{
		for (j=0;j<c2;j++)
		{
			c[j][i]=a[i][j];
		}
	}
}
void saddlept_matrix(int a[max][max],int r1, int c1)
{
	int i,j,k,flag=0;
	int min,max_column;

	for(i=0;i<r1;i++)
	{
		min=a[i][0];
		for(j=0;j<c1;j++)
		{
			if(a[i][j]<min)		//Min in row
			{
				min=a[i][j];
				max_column=j;
				printf("\n%d %d",min,max_column);
			}
		}
		for(k=0;k<r1;k++)
		{
			if(a[k][max_column]>min)	//Whether Max in column
			{
				printf("%d",a[k][max_column]);
				break;
			}
		}
		if(k==c1)
			flag=0;
		break;
	}
	if(flag==0)
		printf("\nThe saddle point is %d",a[k][max_column]);
	else
		printf("\nNo saddle point.");
}

int main()
{
	int a[max][max]={0};
	int b[max][max]={0};
	int c[max][max]={0};
	int r1,c1,r2,c2,i,option=0;

	do
	{
		printf("Enter the option number corresponding to the         required operation\n");
		printf("1.Enter Matrices
                            \t2.Addition\n
                              3.Multiplication
                           \t4.Transpose\n
                              5.Saddle Point\t
                           \t0.Exit\n");
		scanf("%d",&option);
		switch(option)
		{
		case 1:
			while(c1!=r2)
			{printf("Enter the number of rows and columns of the first matrix\n");
			scanf("%d %d",&r1,&c1);
			get_matrix(a,r1,c1);
			printf("Enter the number of rows and columns of the second matrix\n");
			scanf("%d %d",&r2,&c2);
			get_matrix(b,r2,c2);
			}
			break;
		case 2:
			//for addition
			if(r1==c2)
			{
				add_matrix(a,b,c,r1,c2);
				print_matrix(c,r1,c2);
			}
			else
				{printf("Matrices cannot be added\n");
				printf("please check 1st matrix row and 2nd matric colume must be same:\n");}
			break;
		case 3:
			//For multiplication
			if(r2==c1)
			{
				mult_matrix(a,b,c,r1,c2,c1);
				print_matrix(c,r1,c2);
			}
			else
				printf("Matrices cannot be multiplied\n");
			break;

		case 4:
			//For transpose
			printf("Do you wish to find transpose of first-'1' or second-'2'?\nEnter your option number\n");
			scanf("%d",&i);
			if(i==1)
			{
				transpose_matrix(a,c,r1,c1);
				print_matrix(c,r1,c2);
			}
			else if(i==2)
			{
				transpose_matrix(b,c,r2,c2);
				print_matrix(c,r1,c2);
			}
			break;
		case 5:
			printf("Do you wish to find saddle point of 1.A or 2.B?\nEnter your option number\n");
			scanf("%d",&i);
			if(i==1)
			{
				saddlept_matrix(a,r1,c1);
			}
			else if(i==2)
			{
				saddlept_matrix(b,r2,c2);

			}
			break;
		case 0:
			break;
		default:
			printf("Wrong option entered. Try again\n");
		}
	}while(option!=0);
	return 0;
}
