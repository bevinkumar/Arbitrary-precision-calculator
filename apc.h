#ifndef APC_H
#define APC_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define SUCCESS 0
#define FAILURE -1
#define EQUAL 1
extern int sign_flag;
typedef struct node
{
	struct node *prev;
	int data;
	struct node *next;
}Dlist;

/* Include the prototypes here */
int read_and_validate(int argc, char *argv[]);

//int check_operands(int argc,char *argv[],Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,int *sign_flag);//
/*store the operands into the list */
void insert_digit(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,char *argv[]);

int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);


/*to print list*/
/* Function to print the linked list */
void print_list(Dlist *headR);

/*Addition */
int addition(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR);

/*subtraction*/
int check_operands(int argc, char *argv[], Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, int *sign_flag);

/*Multiplication*/
int multiplication(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR,char *argv[]);
int result_node(Dlist **headR, Dlist **tailR, int data);
//void free_list(Dlist **head);
int insert_zero(Dlist **head, Dlist **tail);
void free_list(Dlist **head, Dlist **tail);

/*Division */
int division(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR,char *argv[]);
int finding_the_largest_number(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2);
#endif
