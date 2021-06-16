/*				ASSGN 5(A) INPUT
 ============================================================================
Name       : Abhishek Dilip Agashe
Class        : SE09
 Batch      : E09
 Roll No.  : 23103
Problem Statement: Create a Database using array of structures and perform
                                	following operations on it:
                               	 a) Create Database
                               	 b) Display Database
                                	c) Add record
                                	d) Search a record
                                	e) Modify a record.
                                	f) Delete a record. ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define max 50
struct date
{
    int d,m,y;
};

typedef struct
 {
	 char name[20];
	 char pass_id[20];
	 unsigned long int mob_no;
	 char address[30];
	 int fare;
	 struct date dt;
 }booking;

 void create(FILE *fp,int n,int *id)
 {
     fp=fopen("file1.bin","w");
     booking b;
     int i;
        for(i=0;i<n;i++)
     {
		 printf("\nEnter users name:");
		 scanf("\n");
		 gets(b.name);
		 for(;;)
		 {
			 printf("\nEnter users mob. no:");
			 scanf("%ld",&b.mob_no);
     //        if(b.mob_no>999999999 && b.mob_no<10000000000)
			  break;
              printf("**Enter valid mob.no\n");
		 }
		 printf("\nEnter users address:");
		 scanf("\n");
		 gets(b.address);
		 printf("\nEnter the Date(dd mm yyyy)");
		 scanf("%d %d %d",&b.dt.d,&b.dt.m,&b.dt.y);
		 printf("\nEnter the Fare:");
		 scanf("%d",&b.fare);
		 set_id(&b,id);
		 fwrite(&b,sizeof(b),1,fp);
		 (*id)++;
     }
     fclose(fp);
 }

 void display(FILE *fp)
 {
    fp=fopen("file1.bin","r");
    booking b;
	 int i;
	 printf("Passenger Id\tName\t\tMobile\t\tFare\tAddress\t\tDate\n");
	 while(fread(&b,sizeof(b),1,fp))
	 {
		 printf("%s\t\t%s\t   %ld \t\t%d\t%s\t  ",b.pass_id,b.name,b.mob_no,b.fare,b.address);
		 printf(" %.2d-%.2d-%.4d\n",b.dt.d,b.dt.m,b.dt.y);
	 }
	 fclose(fp);
 }

 void add(int n,FILE *fp,int *id)
 {
     booking b;
	 fp=fopen("file1.bin","a");
	  printf("\nEnter users name:");
		 scanf("\n");
		 gets(b.name);
		 for(;;)
		 {
			 printf("\nEnter users mob. no:");
			 scanf("%ld",&b.mob_no);
		//	 if(b.mob_no>999999999 && b.mob_no<10000000000)
			  break;
              printf("**Enter valid mob.no\n");
		 }
		 printf("\nEnter users address:");
		 scanf("\n");
		 gets(b.address);
		 printf("\nEnter the Date(dd mm yyyy)");
		 scanf("%d %d %d",&b.dt.d,&b.dt.m,&b.dt.y);
		 printf("\nEnter the Fare:");
		 scanf("%d",&b.fare);
         set_id(&b,id);
         (*id)++;
         fwrite(&b,sizeof(b),1,fp);
         fclose(fp);
 }

 void modify(FILE *fp,int n,char key[])
 {
     int index,i=0,ch;
    FILE *fp2;
    booking b;
    fp=fopen("file1.bin","r");
    fp2=fopen("file2.bin","w");
    while(fread(&b,sizeof(b),1,fp))
    {
        printf("Modify\n");
        i++;
        if(strcmp(key,b.pass_id)==0)
        {
            do{
            printf("Enter value to be modified\n1.Name\n2.Fare\n3.Address\n4.Mobile no.\n5.Exit\nEnter choice:");
            scanf("%d",&ch);
            switch(ch)
            {
                case 1:printf("Enter Name:");
                       scanf("\n%[^\n]s",b.name);break;
                case 2:printf("Enter Fare:");
                       scanf("%d",&b.fare);break;
                case 3:printf("Enter Address:");
                       scanf("\n%[^\n]s",b.address);break;
                case 4:
                        for(;;)
                        {
                            printf("Enter Mobile No.:");
                            scanf("%ld",&b.mob_no);
                            if(b.mob_no>999999999 && b.mob_no<10000000000)
                                break;
                            printf("Invalid Mobile No.\n");
                        }
                        break;
                case 5:printf("EXIT");break;
            }
            }while(ch!=5);
            fwrite(&b,sizeof(b),1,fp2);
            }
            else
            {
                fwrite(&b,sizeof(b),1,fp2);
            }
    }
    fclose(fp);fclose(fp2);
    remove("file1.bin");
    rename("file2.bin","file1.bin");
    }
 int search(FILE *fp,char key[])
 {
     int e=-1,i=0;
     booking b;
    fp=fopen("file1.bin","r");
        while(fread(&b,sizeof(b),1,fp))
	 {
	     i++;
         if(strcmp(key,b.pass_id)==0)
            {
                return i;
                break;
            }
	 }
	 fclose(fp);
        return e;
 }
void Delete(FILE *fp,int *n,char key[])
{
    int index,i=0;
    FILE *fp2;
    booking b;
    fp=fopen("file1.bin","r");
    fp2=fopen("file2.bin","w");
    while(fread(&b,sizeof(b),1,fp))
    {
        if(strcmp(key,b.pass_id)!=0)
        {
            fwrite(&b,sizeof(b),1,fp2);
        }
        else
            *n--;
    }
    fclose(fp); fclose(fp2);
    remove("file1.bin");
    rename("file2.bin","file1.bin");

}
void set_id(booking *b,int *id)
{

    char b1[15];
    strcpy(b->pass_id,"PASS");
    sprintf(b1,"%.3d",*id);
    strcat(b->pass_id,b1);
}
int main()
{
    booking b;
    FILE *fp;
    int ch,n=0,a,i,id=1,x,temp;
 	char key[15];
	do{
	printf("***DataBase***\n");
	printf("1.Create DataBase\n2.Display DataBase\n3.Add Record\n4.Search Record\n5.Delete Record\n6.Modify Record\n7.Exit\n");
	printf("Enter your Choice:");
	scanf("%d",&ch);
    if(n=0&&ch!=1&&ch!=3&&ch!=7)
    {
        printf("DataBase Empty\n");
    }
    else
{
	switch (ch)
	{
	 case 1:printf("CREATE DATABASE\n");
                printf("Enter no. of entries:");
                scanf("%d",&n);
                create(fp,n,&id);
                break;
	 case 2:printf("DISPLAY DATABASE\n");
                display(fp);
                break;
	 case 3:printf("ADD RECORD\n");
	 	    	add(n,fp,&id);
                break;
	 case 4:printf("SEARCH RECORD\n");
                //setbuff(stdin,NULL);
                scanf("%d",&temp);
                sprintf(key,"PASS%.3d",temp);
                a=search(fp,key);
                    if(a>=0)
                    {
                        printf("\nEntered String found\n");
                    }
                    else
                    printf("\nEntered String NOT found\n");
                break;
	 case 5:printf("DELETE RECORD\n");
                printf("Enter Record to be deleted:");
                //setbuf(stdin,NULL);
                scanf("%d",&temp);
                sprintf(key,"PASS%.3d",temp);
                Delete(fp,&n,key);

                break;

	 case 6:printf("MODIFY RECORD\n");
                printf("Enter Record to be modified:");
               // setbuf(stdin,NULL);
                scanf("%d",&temp);
                sprintf(key,"PASS%.3d",temp);
                modify(fp,n,key);
                break;
	case 7: return 0;
	}
	}
}while(1);
}
