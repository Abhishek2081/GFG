/*				ASSGN 6 INPUT
 ============================================================================
Name       : Abhishek Dilip Agashe
Class        : SE09
 Batch      : E09
 Roll No.  : 23103
Problem Statement: Accept student information (e.g. RollNo, Name, Percentage
etc.).
a) Display the data in ascending order of name (Bubble Sort)
b) Display the data in descending order of name (Selection sort)
c) Display data for Roll No specified by user (Binary search)
d) Display the number of passes and comparisons for different test cases (Worst, Average, Best case).
============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct student
{
	char name[20];
	int roll_no;
	float percent;

}student;

void create(student s[],int n);
void display(student s[],int j,int n);
void bubble_sort(student s[],int n);
void selection_sort(student s[],int n);
int binary_search(student s[],int key,int low,int high);
void swap(student s[],int i,int j);
void duplicate(student s[],int n);

int main()
{
	student s[20];
	int n,choice,roll;
	printf("Enter the no of students :\n");
	scanf("%d",&n);

	printf("Enter List Details:\n");
	create(s,n);

	do
	{
		printf("\n1.Bubble sort"
			"\n2.Selection sort"
			"\n3.Binary search"
			"\n4.EXIT"
			"\nEnter your choice :\n");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1: bubble_sort(s,n);
			        display(s,0,n);
			        break;

			case 2: selection_sort(s,n);
				display(s,0,n);
				break;
	
			case 3: bubble_sort(s,n);
				printf("Enter roll no you want to search : ");
				scanf("%d",&roll);
				int x;
				x=binary_search(s,roll,0,n-1);
				if(x==-1)
				{
				  printf("Student not present\n");
				}
				break;

			case 4: return 0;
		}
	}while(1);
	
	return 0;
}

void create(student s[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("Enter students's name : ");
		setbuf(stdin,NULL);
		fgets(s[i].name,20,stdin);
		printf("Enter students's roll_no. :");
		scanf("%d",&s[i].roll_no);
		duplicate(s,i);
		printf("Enter students's percentage :");
		scanf("%f",&s[i].percent);
	}

}
void display(student s[],int j,int n)
{
	int i;
	printf("------------------------------------------\n");
	printf("  NAME\t\tROLL NO\t\tPERCENTAGE\n");
	printf("------------------------------------------\n");

	for( i=j;i<n;i++)
	{
		printf("%s",s[i].name);
		printf("\t\t");
		printf("%d\t",s[i].roll_no);
		printf("\t\t");
		printf("%f",s[i].percent);
		printf("\n");
	}
}
void bubble_sort(student s[],int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(s[j].roll_no>s[j+1].roll_no)
			{
				swap(s,j,j+1);
			}
		}
	}
}
void selection_sort(student s[],int n)
{
	int i,j,x,min;
	
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(strcmp(s[min].name,s[j].name)>0)
			{
			  min=j;
			  if(s[min].name!=s[i].name)
			  {
				swap(s,i,min);
			  }
			}
		}
	}

}
int binary_search(student s[],int temp_roll,int low,int high)
{

	int flag=0;
	int mid;
	mid=(low+high)/2;

	if(temp_roll==s[mid].roll_no)
	{
		display(s,mid,mid+1);
		flag=1;
	}
	else if(temp_roll<s[mid].roll_no)
	{
		binary_search(s,temp_roll,0,mid-1);
	}
	else if(s[mid].roll_no<temp_roll)
	{
		binary_search(s,temp_roll,mid+1,high-1);
	}
	if(flag==0)
	{
		return -1;
	}
}
void swap(student s[],int i,int j)
{
	student t;

	t=s[i];
	s[i]=s[j];
	s[j]=t;
}
void duplicate(student s[],int n)
{
	int i=0;

	while(i<n)
	{
		if(s[n].roll_no==s[i].roll_no)
		{
			printf("ROLL no already exist\n");
			printf("Try another roll no. : ");
			scanf("%d",&s[n].roll_no);			
			duplicate(s,n);
		}
		i++;
	}
}
