/*
 ============================================================================
 Name        : eight.c
 Author      : Abhishek Agashe
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#define SIZE 20

typedef struct
{
	int r;
	int c;
	int v;
}table;

void inp_mat(int (*mat)[SIZE],int row,int col)
{
	int t;
	int r,c,v;
	while(1)
	{
		printf("Enter how many data u want to store in matrix:");
		scanf("%i",&t);
		if(t<(row*col)/2)
			break;
		else
			printf("The value %i is not less than 50 percnt of %i\n",t,row*col);
	}
	for(int i=0;i<t;i++)
	{
		printf("Enter data for %i inp\n",i+1);
		while(1)
		{
			while(1)
			{
				printf("Enter row:");
				scanf("%i",&r);
				printf("Enter col:");
				scanf("%i",&c);

				if(c<0 || c>=col || r<0 ||r>=row)
				{
					printf("This is Invalid value for r or c\n");
					continue;
				}
				else
					break;
			}
			if(mat[r][c]==0)
			{
				while(1)
				{
					printf("Enter value:");
					scanf("%i",&v);
					if(v>0)
					{
						mat[r][c]=v;
						break;
					}
					else
						printf("Enter a valid value greater than zero\n");
				}
				break;
			}
			else
			{
				printf("There is already a non zero element at [%i][%i]\n",r,c);
				printf("----Re-enter again-------------\n");
			}
		}
	}
}

void display_mat(int (*mat)[SIZE],int row,int col)
{
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			printf("%i ",mat[i][j]);
		}
		printf("\n");
	}
}

void create_table(int (*mat)[SIZE],int row,int col,table *t)
{
	int k=1;
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			if(mat[i][j])
			{
				t[k].r=i;
				t[k].c=j;
				t[k].v=mat[i][j];
				k++;
			}
		}
	}
	t[0].r=row;
	t[0].c=col;
	t[0].v=k-1;
}

void display_table(table* t,int n)
{
	printf("ROW  COL  VALUE\n");
	for(int i=0;i<=n;i++)
		printf("%-3i  %-3i %-3i\n",t[i].r,t[i].c,t[i].v);
}

void transpose(table *t,table *result)
{
	result[0].r=t[0].c;
	result[0].c=t[0].r;
	result[0].v=t[0].v;
	int k=1;
	for(int i=0;i<t[0].c;i++)
	{
		for(int j=1;j<=t[0].v;j++)
		{
			if(t[j].c==i)
			{
				result[k].c=t[j].r;
				result[k].r=t[j].c;
				result[k].v=t[j].v;
				k++;
			}
		}
	}
	printf("The algorithm simple transpose works in time O(%i)\n",t[0].c*t[0].v);
}

void fast_transpose(table *t,table *result)
{
	result[0].r=t[0].c;
	result[0].c=t[0].r;
	result[0].v=t[0].v;

	int *row_terms=(int*)calloc(t[0].c,sizeof(int));

	for(int i=1;i<=t[0].v;i++)
		row_terms[t[i].c]++;

	int *st_pt=(int*)calloc(t[0].c,sizeof(int));
	st_pt[0]=1;

	for(int i=1;i<t[0].c;i++)
	{
		st_pt[i]=st_pt[i-1]+row_terms[i-1];
	}

	for(int i=1;i<=t[0].v;i++)
	{
		result[st_pt[t[i].c]].r=t[i].c;
		result[st_pt[t[i].c]].c=t[i].r;
		result[st_pt[t[i].c]].v=t[i].v;
		st_pt[t[i].c]++;
	}
	printf("The algorithm fast transpose works in time O(%i)\n",t[0].c+t[0].v);
}

void add(table *t,table* t1,table *result)
{
	int i=1,j=1,k=1;
	if(t[0].r != t1[0].r || t[0].c != t1[0].c)
	{
		printf("Incompatibe matrices...addition not possible\n");
		return;
	}

	while(i<=t[0].v && j<=t1[0].v)
	{
		if(t[i].r<t1[j].r)
		{
			result[k]=t[i];
			k++;
			i++;
		}
		else if(t[i].r>t1[j].r)
		{
			result[k]=t1[j];
			k++;
			j++;
		}
		else if(t[i].r==t1[j].r && t[i].c<t1[j].c)
		{
			result[k]=t[i];
			k++;
			i++;
		}
		else if(t[i].r==t1[j].r && t[i].c>t1[j].c)
		{
			result[k]=t1[j];
			k++;
			j++;
		}
		else
		{
			result[k]=t[i];
			result[k].v+=t1[j].v;
			i++;
			j++;
			k++;
		}
	}

	while(i<=t[0].v)
	{
		result[k]=t[i];
		k++;
		i++;
	}

	while(j<=t1[0].v)
	{
		result[k]=t1[j];
		k++;
		j++;
	}

	result[0].c=t[0].c;
	result[0].r=t[0].r;
	result[0].v=k-1;
}

void menu()
{
	printf("Select the option from menu\n");
	printf("1.Create sparse matrix\n");
	printf("2.Simple transpose\n");
	printf("3.Fast transpose\n");
	printf("4.Addition\n");
	printf("5.Exit\n");
	printf("Select option:");
}

int main(void)
{
	int mat[SIZE][SIZE]={0};
	int mat1[SIZE][SIZE]={0};
	table t[50],t1[50];
	table result[50];
	int row,col;
	int opt;
	int row1,col1;
	printf("Enter row for sparse matrix:");
	scanf("%i",&row);
	printf("Enter column for sparse matrix:");
	scanf("%i",&col);
	while(1)
	{
		menu();
		scanf("%i",&opt);

		switch(opt)
		{
			case 1:
				inp_mat(mat,row,col);
				printf("Matrix 2 is :\n");
				display_mat(mat,row,col);
				break;
			case 2:
				create_table(mat,row,col,t);
				printf("Table 1 is :\n");
				display_table(t,t[0].v);
				transpose(t,result);
				printf("Simple Transpose :\n");
				display_table(result,result[0].v);
				break;
			case 3:
				create_table(mat,row,col,t);
				display_table(t,t[0].v);
				fast_transpose(t,result);
				display_table(result,result[0].v);
				break;
			case 4:
				printf("Table 1 is :\n");
				create_table(mat,row,col,t);
				display_table(t,t[0].v);

				printf("Enter row for sparse matrix 2:");
				scanf("%i",&row1);
				printf("Enter column for sparse matrix 2:");
				scanf("%i",&col1);

				inp_mat(mat1,row1,col1);
				printf("Matrix 2 is :\n");
				display_mat(mat1,row1,col1);
				printf("Table 2 is :\n");
				create_table(mat1,row1,col1,t1);
				display_table(t1,t1[0].v);
				add(t,t1,result);
				printf("Addition table :\n");
				display_table(result,result[0].v);
				break;

			case 5:	return 0;

			default: printf("INVALID option Entered\n");
		}
	}
}

