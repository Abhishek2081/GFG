/*
 ============================================================================
 Name        : eleventh.c
 Author      : Abhishek Agashe
 Assignment  : 11
 problem     : Accept input as a string and construct a Doubly Linked
               List for the input string with each node contains, as a data
               one character from the string and perform:
               a) Insert
               b) Delete,
               c) Display forward
               d) Display backward.
 ============================================================================
*/

#include <stdio.h>
#include <stdlib.h>

struct student
{
	char name[20];
	int roll_no;
	float per;
};

struct node
{
	struct student s;
	struct node *prev;
	struct node *next;
};

struct node *getnode(struct node *nev)
{
	nev=(struct  node *)malloc(sizeof(struct node));
	nev->next=NULL;
	return nev;
};

struct node *create(struct node *head,int n);
void display(struct node *p);
struct node *Delete(struct node *head, int pos);
void reverse(struct node *p);
struct node *insert(struct node *head, int pos);

int main(void) {

	struct node *head=NULL;
	int n,ch,pos,data;

	printf("Enter the no. of nodes:-\n");
	scanf("%d",&n);
	head=create(head, n);
	display(head);
do
{
	printf("\n\n*****DLL operations*****\n");
	printf("1. Insert\n");
	printf("2. Delete\n");
	printf("3. Display Reverse\n");
	printf("4. Exit\n");
	printf("Enter choice-\n");
	scanf("%d", &ch);

	switch(ch)
	{
		case 1: printf("Enter the position you want to enter data-\n");
                scanf("%d", &pos);
                head=insert(head, pos);
				display(head);
				break;

		case 2: printf("Enter position you want to delete-\n");
				scanf("%d", &pos);
				head=Delete(head, pos);
				if(head==NULL)
                    printf("Linked list is empty\n");
                else
                    display(head);
				break;

		case 3: reverse(head);
				break;

		case 4: break;

		default: printf("Invalid choice\n");
	}
}while(ch!=4);

return 0;
}

struct node *create(struct node *head,int n)
{
	int i,count=1;

	struct node *nev;
	struct node *last;
	nev=getnode(nev);

	printf("\nEnter data for node %d: ", count);
	printf("\nEnter name-\n");
	scanf("\n");
	scanf("%s", nev->s.name);
	printf("Enter roll_no-\n");
	scanf("%d", &nev->s.roll_no);
	printf("Enter percentage-\n");
	scanf("%f", &nev->s.per);

	if(head==NULL)
	{
		head=nev;
        head->prev=NULL;
        head->next==NULL;
		last=nev;
	}

	for(i=1; i<n; i++)
	{
		count++;
		nev=getnode(nev);

		printf("Enter data for node %d: ", count);
		printf("\nEnter name-\n");
		scanf("\n");
		scanf("%s", nev->s.name);
		printf("Enter roll_no-\n");
		scanf("%d", &nev->s.roll_no);
		printf("Enter percentage-\n");
		scanf("%f", &nev->s.per);

		last->next=nev;
		nev->prev=last;
		last=nev;
		last->next=NULL;
	}

return head;
}

void display(struct node *p)
{
	int count=1;

	printf("Linked list-\n");
	printf("Sr.no\t Name\t Roll_no\t Percentage\t Previous\t Next\n\n");

	while(p!=NULL)
	{
		printf("%d\t %s\t %d\t\t %.2f\t\t %u\t\t %u\n", count, p->s.name, p->s.roll_no, p->s.per, p->prev, p->next);

		p=p->next;
		count++;
	}
}

struct node *insert(struct node *head, int pos)
{
	struct node *nev;
	struct node *p; //previous node w.r.t nev
	struct node *n; //next node w.r.t nev

    nev=getnode(nev);

    printf("\nEnter data for node %d: ", pos);
	printf("\nEnter name-\n");
	scanf("\n");
	scanf("%s", nev->s.name);
	printf("Enter roll_no-\n");
	scanf("%d", &nev->s.roll_no);
	printf("Enter percentage-\n");
	scanf("%f", &nev->s.per);

	if(head==NULL) //for new 1
    {
        head=nev;
        head->prev=NULL;
        head->next=NULL;
    }

    else
    {
        if(pos==1) //for list not empty
        {
            p=head;
            n=head;

            nev->prev=NULL;
            nev->next=n;
            n->prev=nev;

            head=nev;

            return head;
        }

        p=head;
        n=head;

        int i=1;


        while(i<pos) //for insert last, prev points to last
        {
            i++;
            if(i!=pos)
            {
                p=p->next;
                n=n->next;
            }

            if(p->next==NULL) //if p points to last
            {
                p->next=nev;
                nev->prev=p;

                return head;
            }
        }

        //if insert in between
        n=n->next;

        p->next=nev;
        nev->prev=p;
        nev->next=n;
        n->prev=nev;

return head;
    }
}

struct node *Delete(struct node *head, int pos)
{
     int i=1;

    struct node *temp;
    struct node *p;
    struct node *n;

    temp=head;
    n=head;
    p=NULL;

    if(pos==1)
    {
        if(n->next==NULL) //for pos 1 and list has 1 node only
        {
            return NULL; //head=insert(); head=NULL
        }
        else //for pos 1 but list is filled
        {
            n=n->next;
            head=n;
            n->prev=NULL;
            free(temp);
            return head;
        }
    }

    //for delete in between
    else
    {
        p=head;
        while(i<pos)
        {
            n=n->next;
            temp=temp->next;
            i++;
            if(i!=pos)
                p=p->next;
        }

        if(temp->next==NULL)
        {
            p->next=NULL;
            free(temp);

            return head;
        }

    n=n->next;

	p->next=n;
	n->prev=p;
	free(temp);
    }
return head;
}

void reverse(struct node *p)
{
    int count=1;

    while(p->next!=NULL)
        p=p->next;

    printf("The reverse linked list is-\n");
    printf("Sr.no\t Name\t Roll_no\t Percentage\t Previous\t Next\n\n");

    while(p!=NULL)
    {
        printf("%d\t %s\t %d\t\t %.2f\t\t %u\t\t %u\n", count, p->s.name, p->s.roll_no, p->s.per, p->prev, p->next);
        count++;
        p=p->prev;
    }
}
