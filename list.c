#include "apc.h"
int read_and_validate(int argc,char *argv[])
{
  int i;
  if(argc!=4)
	  {
		return FAILURE;
	  }
	for(i=0;argv[1][i]!='\0';i++)
	  {
    if(!isdigit(argv[1][i]))
		{
			return FAILURE;
		}
	  }	
  if (argv[2][1] != '\0' || (argv[2][0] != '+' && argv[2][0] != '-' && argv[2][0] != 'x' && argv[2][0] != '/')) 
    {
        return FAILURE;
    }

   for(i=0;argv[3][i]!='\0';i++)
	  {
		if(!isdigit(argv[3][i]))
		{
			return FAILURE;;
		}
    }
    return SUCCESS;
}
int check_operands(int argc,char *argv[],Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,int *sign_flag)//,int *sign_flag)
{
  //int sign_flag;
  int oper2= strlen(argv[3]);
  int oper1= strlen(argv[1]);
  if(oper1 > oper2)
  {
     //*sign_flag=1;
     insert_digit(head1,tail1,head2,tail2,argv);
  }
  else if(oper2 > oper1)
  {
     *sign_flag=-1;
    insert_digit(head2,tail2,head1,tail1,argv);
  }
  else
  {
    if(strcmp(argv[1],argv[3])>0)
    {
     //*sign_flag=1;
      insert_digit(head1,tail1,head2,tail2,argv); 
    }
    else if(strcmp(argv[1],argv[3])<0)
    {
      *sign_flag=-1;
      insert_digit(head2,tail2,head1,tail1,argv);
    }
    else 
    {
      insert_digit(head1,tail1,head2,tail2, argv); // Equal numbers
    }
  }
     return SUCCESS;
}

void insert_digit(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,char *argv[])
{
  int i; 
  for(i=0;i<argv[1][i]!='\0';i++)
  {
    Dlist *new=malloc(sizeof(Dlist));
    new->data=argv[1][i]-48;
    new->next=NULL;
    new->prev=*tail1;

    if(*tail1!=NULL)
    {
      (*tail1)->next=new;
    }
    else
    {
       *head1=new;
    }
    *tail1=new;
  }
  for(i=0;i<argv[3][i]!='\0';i++)
  {
    Dlist *new=malloc(sizeof(Dlist));
    new->data=argv[3][i]-48;
    new->next=NULL;
    new->prev=*tail2;

    if(*tail2!=NULL)
    {
      (*tail2)->next=new;
    }
    else
    {
       *head2=new;
    }
    *tail2=new;
  }
}
//int result_node(Dlist **headR, Dlist **tailR, int data)
int result_node(Dlist **headR, Dlist **tailR, int data) 
{
    Dlist *new_node = malloc(sizeof(Dlist));
    if (new_node == NULL)
        return FAILURE; // Memory allocation failed

    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;

    if (*headR == NULL)
     { // Empty list case
        *headR = new_node;
        *tailR = new_node;
    } 
    else
     { // Insert at the head
        new_node->next = *headR;
        (*headR)->prev = new_node;
        *headR = new_node;
    }

    return SUCCESS;
}

int insert_zero(Dlist **head, Dlist **tail)
{
    Dlist *new_node = malloc(sizeof(Dlist));
    if (new_node == NULL)
        return FAILURE; // Memory allocation failed

    new_node->data = 0;
    new_node->prev = NULL;
    new_node->next = NULL;

    if (*head == NULL) { // Empty list case
        *head = new_node;
        *tail = new_node;
    } else { // Append to the tail
        (*tail)->next = new_node;
        new_node->prev = *tail;
        *tail = new_node;
    }

    return SUCCESS;
}

void free_list(Dlist **head, Dlist **tail)
{
    Dlist *temp;
    while (*head != NULL)
    {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
    *tail = NULL;
}

void print_list(Dlist *headR)
{
  Dlist *temp=headR;
  while(temp!=NULL)
  {
    printf("%d",temp->data);
    temp=temp->next;
  }
  printf("\n");
}/*
int remove_zeros(char *opr)
{
  int i=0;
  int j;
  while(opr[i]!='\0')
  {
    if(opr[i]!='0')
    {
      break;
    }
    if((opr[i]=='0'))
    {
      for(j=i;opr[j];j++)
      {
        opr[j]=opr[j+1];       
      }
    }
    else
    i++;
  }
}*/
int finding_the_largest_number(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2)
{
	int size1 = 0;
	int size2 = 0;

	Dlist *temp1 = *head1;
	while (temp1 != NULL)
	{
		size1++;
		temp1 = temp1->next;
	}

	Dlist *temp2 = *head2;
	while (temp2 != NULL)
	{
		size2++;
		temp2 = temp2->next;
	}

	if (size1 > size2)
	{
		return SUCCESS;
	}

	if (size2 > size1)
	{
		return FAILURE;
	}

	temp1 = *head1;
	temp2 = *head2;

	while (temp1 != NULL && temp2 != NULL)
	{
		if (temp1->data > temp2->data)
		{
			return SUCCESS;
		}
		else if (temp1->data < temp2->data)
		{
			return FAILURE;
		}

		temp1 = temp1->next;
		temp2 = temp2->next;
	}

	return EQUAL;
}
