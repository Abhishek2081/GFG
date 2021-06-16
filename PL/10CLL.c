*/
 ============================================================================
Assignment  : 10
 Problem     :  Implement polynomial using CLL and perform
 Statement      a) Addition of  Polynomials
                b) Multiplication of  polynomials
                c) Evaluation of  polynomial
 ============================================================================
 */

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node
{
    int exp;
    int coeff;
    struct node *next;
};

struct node *getnode(struct node *nev)
{
    nev=(struct node *)malloc(sizeof(struct node));
    nev->next=NULL;
    return nev;
}

struct node *insert(struct node *head, int exp1, float coeff1);
struct node *create(struct node *head, int n);
void display(struct node *head);
struct node *add(struct node *p1, struct node *p2);
struct node *mul(struct node *p1, struct node *p2);
float eval(struct node *head,float x);

int main()
{
    struct node *head1=NULL;
    struct node *head2=NULL;
    struct node *head3=NULL;
    int ch,n,n2,x;
    float value;

    printf("How many terms do you want in your polynomial-\n");
    scanf("%d", &n);
    head1=create(head1,n);
    printf("\nThe circular linked list is-\n");
    display(head1);

do
{
    printf("\n\n*********Polynomial Operations*********\n");
    printf("1. Addition\n");
    printf("2. Multiplication\n");
    printf("3. Evaluation of first polynomial-\n");
    printf("4. Exit\n");
    printf("Enter your choice-\n");
    scanf("%d", &ch);

    switch(ch)
    {
        case 1: printf("Create another polynomial-\n");
                printf("Terms in another polynomial-\n");
                scanf("%d", &n2);
                head2=create(head2,n2);
                display(head2);
                head3=add(head1,head2);
                printf("\nThe Polynomial addition is-\n");
                display(head3);
                break;

        case 2: printf("Create another polynomial-\n");
                printf("Terms in another polynomial-\n");
                scanf("%d", &n2);
                head2=create(head2,n2);
                display(head2);
                head3=mul(head1,head2);
                printf("\n\nThe Polynomial multiplication is-\n");
                display(head3);
                break;

        case 3: printf("Enter value of x: ");
                scanf("%d",&x);
                value=eval(head1,x);
                printf("\nEvaluated value = %.2f", value);
                break;

        case 4: break;

        default: printf("Invalid choice\n");
    }
}while(ch!=4);

return 0;
}

struct node *create(struct node *head, int n)
{
    int i,coeff,exp;
    for(i=0; i<n; i++)
    {
        printf("\nEnter the coefficient for node %d: ",i+1);
        scanf("%d", &coeff);
        printf("Enter the exponent for node %d: ",i+1);
        scanf("%d", &exp);
        head=insert(head,exp,coeff);
    }
return head;
}

struct node *insert(struct node *head, int exp1, float coeff1)
{
    struct node *temp=head;

    struct node *nev;
    nev=getnode(nev);

    nev->exp=exp1;
    nev->coeff=coeff1;

    if(head==NULL)
    {
        head=nev;
        head->next=head;
        return head;
    }

    if(head->exp < exp1)
    {
        nev->next=head;

        while(temp->next!=head)
            temp=temp->next;

        temp->next=nev;
        head=nev;
        return head;
    }

//for head->exp > exp1
    while(temp->next!=head && exp1< temp->next->exp)
        temp=temp->next;    //temp points to polynomial of same exp or exp greater than exp1
    if(nev->exp==temp->exp)
        temp->coeff= temp->coeff+coeff1;
    else //temp points to term with exp greater than exp1
    {
        if(temp->next->exp!=exp1)
            {
                nev->next=temp->next;
                temp->next=nev;
            }
        else
            temp->next->coeff=temp->next->coeff + coeff1;
    }
    return head;
}

void display(struct node *head)
{
    struct node *p;
    p=head;

    while(p->next!=head)
    {
        printf("%dx^%d ", p->coeff,p->exp);
        if(p->next!=head)
            printf("+ ");

        p=p->next;
    }
    printf("%dx^%d ", p->coeff,p->exp);
}

struct node *add(struct node *p1, struct node *p2)
{
    struct node *head=NULL;
    struct node *p;

    p=p1->next;
    do
    {
        head=insert(head,p->exp,p->coeff);
        p=p->next;
    }while(p!=p1->next);

    p=p2->next;
    do
    {
        head=insert(head,p->exp,p->coeff);
        p=p->next;
    }while(p!=p2->next);

return head;
}

struct node *mul(struct node *p1, struct node *p2)
{
    struct node *head1,*head2;
    struct node *head=NULL;

    head2=p2->next;
    do
    {
        head1=p1->next;
        do
        {
            head=insert(head,head1->exp+head2->exp,head1->coeff*head2->coeff);
            head1=head1->next;
        }while(head1!=p1->next);

    head2=head2->next;
    }while(head2!=p2->next);

return head;
}


float eval(struct node *head, float x)
{
    float value=0;
    struct node *p;
    p=head->next;
    do
    {
        value= value + p->coeff*pow(x,p->exp);  //x^(p->exp);

        p=p->next;
    }while(p!=head->next);

return value;
}
