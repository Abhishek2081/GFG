/*
 ============================================================================
 Name        : ninth.c
 Author      : Abhishek Agashe
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}node;

node *getnode(struct node *nev)
{
	nev=(node*)malloc(1*sizeof(node));
	nev->next=NULL;

	return nev;
}

node *create(node *head,int n)
{
	node *nev,*last;
	last=NULL;
	nev=NULL;

	nev=getnode(nev);
	printf("Enter Data for First node\n");
	scanf("%d",&nev->data);

	if(head==NULL)
	{
		head=nev;
		last=nev;
	}

	int i=1;
	while(i<n)
	{
		nev=getnode(nev);
		printf("Enter Data for next node\n");
		scanf("%d",&nev->data);
		last->next=nev;
		last=nev;
		i++;
	}

	return head;
}

void display(node *head)
{
	node *nev;
	int count=1;

	nev=head;

	if(head==NULL)
	{
		printf("List is Empty\n");
	}
	while(nev!=NULL)
	{
		printf("Node %d= %d->%p\n",count,nev->data,nev);
		count++;
		nev=nev->next;
	}
}

void display_reverse(node *nev,int i)
{
	if(nev!=NULL)
	{
		i++;
		display_reverse(nev->next,i);
		printf("Node %d= %d->%p\n",i,nev->data,nev);
	}
}

void display_rev(node *head)
{
	node *nev;
	int count=1;

	nev=head;

	if(head==NULL)
	{
		printf("List is Empty\n");
	}
	display_reverse(nev->next,count);
	printf("Node %d= %d->%p\n",count,nev->data,nev);
}

void search(node *head,int data)
{
	node *nev;

	nev=head;

	while(nev!=NULL)
	{
		if(data==nev->data)
		{
			printf("Data is found: ");
			printf("%d->%p\n",nev->data,nev);
		}
		nev=nev->next;
	}
}

int count(node* head)
{
	node *nev;
	nev=head;
	int count=0;

	while(nev!=NULL)
	{
		count++;
		nev=nev->next;
	}

	return count;
}

node* add_at_beg(node *head)
{
	node *nev;
	nev=getnode(nev);
	printf("Enter Data for First node\n");
	scanf("%d",&nev->data);

	if(head==NULL)
	{
		head=nev;
	}
	else
	{
		nev->next=head;
		head=nev;
	}
	return head;
}

node *add_node(node *head,int pos)
{
	node *nev,*p;
	nev=head;
	int c=count(head);

	if(pos<1||pos>c+1)
	{
		printf("Invalid Position\n");	
	}
	if(pos==1)
	{
		head=add_at_beg(head);
	}
	else
	{
		p=getnode(p);
		printf("Enter Data for node\n");
		scanf("%d",&p->data);
		int i=1;
		while(i<pos-1)
		{
			nev=nev->next;
			i++;
		}
		p->next=nev->next;
		nev->next=p;
	}

	return head;
}

node *delete_at_beg(node *head)
{
	node *p;
	
	if(head==NULL)
	{
		printf("List is Empty\n");
	}
	else
	{
		p=head;
		head=head->next;
		free(p);
	}

	return head;
}

node *delete_node(node *head,int pos)
{
	node *p,*q;
	int c=count(head);
	
	if(pos<1||pos>c)
	{
		printf("Invalid Position\n");	
	}
	if(pos==1)
	{
		head=delete_at_beg(head);
	}
	else
	{
		p=head;
		int i=1;
		while(i<pos-1)
		{
			p=p->next;
			i++;
		}
		q=p->next;
		p->next=p->next->next;
		free(q);
	}
	
	return head;
}

int main(void)
{
	node *head;
	int n,ch,data,pos;

	head=NULL;

	printf("Enter Number of elements to enter\n");
	scanf("%d",&n);

	do
	{
		printf("\nEnter Your Choice\n"
				"1.Create List\n"
				"2.Display List\n"
				"3.Search node\n"
				"4.Add a Node\n"
				"5.Delete Node\n"
				"6.Display Reverse List\n"
				"7.Exit\n");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1: head=create(head,n);
				break;

			case 2: display(head);
				break;

			case 3: printf("Enter Data to Search\n");
				scanf("%d",&data);
				search(head,data);
				break;

			case 4: printf("Enter Position to Add node\n");
				scanf("%d",&pos);
				head=add_node(head,pos);
				printf("Updated List is :\n");
				display(head);
				break;

			case 5: printf("Enter Node Number to be Deleted\n");
				scanf("%d",&pos);
				head=delete_node(head,pos);
				printf("Updated List is :\n");
				display(head);
				break;
				
			case 6: display_rev(head);
					break;
			
			case 7: return 0;

			default: printf("Invalid choice\n");
		}
	}while(1);

	return EXIT_SUCCESS;
}
