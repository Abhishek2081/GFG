/*
============================================================================
Name        : globalized linked list.c
Author      : Abhishek Agashe
Version     :
Copyright   : 
Description : Hello World in C, Ansi-style
Problem Statement: Implement Generalized Linked List to create and display the book index.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct gll {

	int flag;
	struct gll *next;
	union {
		char data[MAX];
		struct gll *dlink;
	} u;

};

typedef struct gll node;

node* getNode(node*);
node* createGLL(node *head, char[]);
void disp(node *head);

int main() {

	char str[MAX], choice;
	node *head;
	head = NULL;

	do {
		printf("\n******GLL for book index*****\n\n");
		printf("Enter the string: \n");

		scanf("\n");
		gets(str);

		printf("\n\nThe book index: ");

		head = createGLL(head, str); //create the generalised list

		disp(head);

		printf("\n\nDO YOU WISH TO CONTINUE? IF YES, PRESS Y.");
		scanf("%c", &choice);
	} while (choice == 'y' || choice == 'Y');

	return 0;
}

node* getNode(node *nev) {
	nev = (node*) malloc(sizeof(node)); //synamic memory allocation

	nev->next = NULL;
	nev->u.dlink = NULL;

	return nev;
}

node* createGLL(node *head, char str[10]) {
	int i = 0, j;
	node *temp;

	for (i = 0; *str != '\0';) {

		if (*str == '(' && i == 0) //head node
				{
			head = getNode(head);
			temp = head;
		} else {
			temp->next = getNode(temp->next);
			temp = temp->next;
		}

		i++;
		str++;
		j = 0;

		while (*str != ',' && *str != '(' && *str != ')') { //create nodes on same level
			temp->u.data[j] = *str;
			i++;
			str++;
			j++;
		}

		temp->u.data[j] = '\0'; //end the string
		temp->flag = 0; //for atomic node

		if (*str == '(') {
			temp->next = getNode(temp->next);
			temp = temp->next;
			temp->flag = 1; //for sublist

			temp->u.dlink = createGLL(NULL, str); //recursively calling the same function

			while (*str != ')') {
				i++;
				str++;
			}
			str++;
			i++;
		}

		if (*str == ')')//end of a list or sublist
			return head;

	}
}

void disp(node *temp) {
	static int depth; //for recursive calling
	depth++;
	int i;

	if (temp == NULL) {
		if (depth == 1)
			printf("LIST IS EMPTY!");
		else {
			printf("SUBLIST IS EMPTY!");
		}
	}

	else
		while (temp != NULL) {

			if (temp->flag == 0) { //atomic node
				printf("\n");

				for (i = 1; i < depth; i++)

					printf("  ");
				printf("%s", temp->u.data); //list titles

			}

			else
				disp(temp->u.dlink); //move to down link and repeat
			temp = temp->next;

		}

	depth--;
}

