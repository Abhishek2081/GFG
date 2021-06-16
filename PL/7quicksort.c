/*			ASSGN 7  INPUT
 ============================================================================
Name       : Abhishek Dilip Agashe
Class        : SE09
 Batch      : E09
 Roll No.  : 23103
Problem Statement: Accept Mobile user information (e.g. MobileNo, Name,
			BillAmount etc.).
			a) Display the data in descending order of Name (Quicksort, 				recursive)
			b) Display the data in ascending order of MobileNo (Quicksort
			nonrecursive)
			c) Display pivot position and its corresponding list in each pass.
			d) Display the number of passes and comparisons for different test 			cases (Worst, Average, Best case).
============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student
{
	char name[20];
	long long int mob_no;
	int bill;

}student;

void create(student s[],int n);
void display(student s[],int n);
int partition(student s[],int low,int up);
void quick_sort(student s[],int low,int up);
void swap(student s[],int i,int j);

int main()
{
	int n,k,k1,k2;
	
	printf("Enter the number of students : ");
	scanf("%d",&n);

	student s[n];
	create(s,n);
	
	printf("\n\nEntered Array is As Follows:\n");
	printf("\nNAME\t\tMobile No\t\tBill\n");
	display(s,n);

	quick_sort(s,0,n-1);
	printf("\n\nSorted Array is As Follows:\n");
	printf("\nNAME\t\tMobile No\t\tBill\n");
	display(s,n);
	
	return 0;
}

void create(student s[],int n)
{
	int i,j;
	char ch;
	
	for(i=0;i<n;i++)
	{
		setbuf(stdin,NULL);
		printf("\nEnter name : ");
		fgets(s[i].name,20,stdin);
		printf("Enter mobile no : ");
		scanf("%lli",&s[i].mob_no);
		printf("Ener bill : ");
		scanf("%d",&s[i].bill);
	}
}
void display(student s[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{

		printf("%s",s[i].name);
		printf("\t\t");
		printf("%lli",s[i].mob_no);
		printf("\t\t");
		printf("%d",s[i].bill);
		printf("\n");
	}
}
int  partition(student s[],int low,int up)
{
	int pivot,temp,p,q;
	pivot=low;
	p=low+1;
	q=up;
		
	while (p<q)
	{
		while(strcmp(s[p].name,s[pivot].name)<0&&p<=up)
		{
			p++;
		}
		while(strcmp(s[q].name,s[pivot].name)>0)
		{
			q--;
		}
		if(p<q)
		{
			swap(s,p,q);
		}
	}
		
	swap(s,q,low);
	
	return q;

}
void quick_sort(student s[],int low,int up)
{
	int k;
	if(low<=up)
	{
		k=partition(s,low,up);
		quick_sort(s,low,k-1);
		quick_sort(s,k+1,up);
	}
}
void swap(student s[],int i,int j)
{
	student temp;
	
	temp=s[i];
	s[i]=s[j];
	s[j]=temp;
}
