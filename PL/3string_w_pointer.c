/*
 ============================================================================
Roll no.:23103
Name:Abhishek Agashe
Class:SE-9
Batch:E-9
Problem Statement:Perform following String operations with pointers to arrays
(without using the library functions):
a) substring
b) palindrome
c) compare
d) copy
e) Reverse.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int length(char *s)
{
	int len=0;
	int i=0;

	while(*(s+i)!='\0')
	{
		len=len+1;
		i++;
	}

	return len;
}

void copy(char *s2,char *s1)
{
	int len=length(&s1[0]);
	int i;

	for(i=0;i<len;i++)
	{
		*(s2+i)=*(s1+i);
	}

	*(s2+i)='\0';
}

void reverse(char *s1)
{
	int len=length(&s1[0]);
	char s2[len];

	copy(&s2[0],&s1[0]);

	int i,j=len-1;

	for(i=0;i<len;i++)
	{
		*(s1+i)=*(s2+(j--));
	}
}

void palin(char *s1)
{
	int len=length(&s1[0]);
	char s2[len];

	copy(&s2[0],&s1[0]);

	reverse(&s2[0]);

	int i,flag=0;

	for(i=0;i<len;i++)
	{
		if(*(s2+i)!=*(s1+i))
		{
			flag=1;
			break;
		}
	}

	if(flag==1)
	{
		printf("%s is not a palindrome string\n",s1);
	}

	else if(flag==0)
	{
		printf("%s is a palindrome string\n",s1);
	}

}

int compare(char *s1,char *s2)
{
	int i,flag=1;

	int len1=length(&s1[0]);
	int len2=length(&s2[0]);
	int len;

	if(len1>=len2)
	{
		len=len2;
	}

	else
	{
		len=len1;
	}

	for(i=0;i<len;i++)
	{
		if(*(s1+i)!=*(s2+i))
		{
			flag=0;
			return ((int)*(s1+i)-(int)*(s2+i));
		}
	}

	if(flag==1)
	{
		return 0;
	}
}

void subString(char *s1,char *s2)
{
	int len1=length(&s1[0]);
	int len2=length(&s2[0]);
	int i,j=0,c=0;

	for(i=0;i<len1;i++)
	{
		if(j==len2)
		{
			break;
		}
		if(*(s1+i)==*(s2+i))
		{
			j++;
		}
		else
		{
			j=0;
			i=c;
			c++;
		}
	}
	if(j==len2)
	{
		printf("%s is a part of %s\n\n",s2,s1);
	}
	else
	{
		printf("%s is not a part of %s\n\n",s2,s1);
