/*
 ============================================================================
Roll no.:23103
Name:Abhishek Agashe
Class:SE-9
Batch:E-9
Problem Statement: Create a Database using array of structures and perform
		   following operations on it:
		   a) Create Database
		   b) Display Database
		   c) Add record
		   d) Search a record
		   e) Modify a record.
		   f) Delete a record.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 50
int k;


struct travel
{
	char name[MAX];
	int ticketno;
	int PNR;
	int mobno[11];
	char add[MAX];
	int date,month,year;
	float fare;
};
struct travel t[MAX];

void input(struct travel t[MAX],int i)
{

		printf("Enter Name of Passenger:");
		scanf("%s",t[i].name);
		printf("Enter Address of Passenger:");
	    scanf("%s",t[i].add);
		printf("Enter Mobile Number of Passenger:");
		scanf("%ls",t[i].mobno);
		printf("Enter Date Of Journey of Passenger(dd_mm_yyyy):");
		scanf("%d",&t[i].date);
		scanf("%d",&t[i].month);
		scanf("%d",&t[i].year);
}

void generate(struct travel t[MAX],int i,int *tn,int *pn)
{
		static int c,d;

		c=*tn;
		d=*pn;

		printf("\nYour Ticket Is Sucessfully Booked");
    	printf("\nYour Ticket Number for Your Journey is:%d",c);
    	printf("\nYour PNR Number for Your Journey is:PASS00%d",d);
    	c++;
    	d++;
    	*tn=c;
    	*pn=d;
}

void display(struct travel t[MAX],int i)
{

	      printf("\nYour Booking Is As Follows:");
          printf("\nPNR No.:PASS%d",t[i].PNR);
          printf("\nTicket No.:%d",t[i].ticketno);
          printf("\nName:%s",t[i].name);
          printf("\nAddress:%s",t[i].add);
          printf("\nMobile No.:%ls",t[i].mobno);
          printf("\nDate of Journey:%d/%d/%d",t[i].date,t[i].month,t[i].year);
}

int search(struct travel t[MAX])
{
		int i,c;

		printf("\nEnter ticket Number:");
		scanf("%d",&c);

		for(i=0;i<MAX;i++)
		{
			if(c==t[i].ticketno)
			{
				printf("\nBooking Found");
				display(t,i);
			}
		}
		return i;
}

void modify(struct travel t[MAX])
{
		printf("\nEnter Booking Details to Modify");
		k=search(t);
		printf("\nEnter All New Details");
		input(t,k);
}

void cancel(struct travel t[MAX])
{
	printf("\nEnter Booking Details to Cancel");
	k=search(t);

	for(i=k;i<MAX;i++)
	{
		t[i]=t[i+1];
	}
	N--;
}

int main(void)
{

	int c=0,n=0,i,tn=2019001,pn=1;
	printf("Enter Number of seats you wish to Book:");
    scanf("%d",&n);

    do
    {
	printf("Enter Your Choice\n"
    		"1.Book Travel Bus\n"
			"2.Display Booking\n"
			"3.Search Booking\n"
    		"4.Modify Booking\n"
    		"5.Cancel Booking\n"
			"6.Exit\n");

    scanf("%d",&c);

    switch(c)
    {
       case 1: for(i=0;i<n;i++)
    	   	   {
    	   	   	   printf("\nEnter Details of Booking %d\n",i+1);
    	   	   	   input(t,i);
    	   	   	   generate(t,i,&tn,&pn);
    	   	   	   t[i].ticketno=tn;
    	   	   	   t[i].PNR=pn;
    	   	   }
               break;

       case 2: for(i=0;i<n;i++)
       	   	   {
    	   	   	   display(t,i);
       	   	   }
               break;

       case 3: k=search(t);
               break;

       case 4: modify(t);
       	   	   break;

       case 5: cancel(t);
       	   	   break;

       case 6: return 0;

       default: printf("Enter Correct Choice\n");
                break;
    }
    printf("\nDo u wanna continue?(1/0)");
    scanf("%d",&c);
    }while(c==1);


	return EXIT_SUCCESS;
}

