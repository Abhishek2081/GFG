/*
 ============================================================================
 Name        : assnfifth(b).c
 Author      : Abhishek
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char *argv[])
{
	FILE *f1, *f2;
	char c;
	
	if (argc == 2)
	{
		f1=fopen(argv[1],"r");
		
		if(f1==NULL)
		{
			printf("***Cannot Open File '%s'***\n",argv[1]);
		}
		else
		{
			printf("File Contents (%s) :\n",argv[1]);
			while((c=getc(f1))!=EOF)
			{
				printf("%c",c);
			}
			fclose(f1);
		}
	}
	
	if (argc == 3)
	{
		f1=fopen(argv[1],"r");
		f2=fopen(argv[2],"a");
		
		if(f1==NULL)
		{
			printf("***Cannot Open File***\n");
		}
		else
		{
			while((c=getc(f1))!=-1)
			{
				putc(c,f2);
			}
			printf("Contents of File '%s' copied in file '%s'\n",argv[1],argv[2]);
			fclose(f1);
			fclose(f2);
		}
	}

    return EXIT_SUCCESS;
}
