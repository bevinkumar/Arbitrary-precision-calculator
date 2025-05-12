#include "apc.h"

int main(int argc, char *argv[])
{
	/* Declare the pointers */
      
	Dlist *head1=NULL, *tail1=NULL;
    Dlist *head2=NULL, *tail2=NULL; 
    Dlist *headR=NULL, *tailR=NULL;
	int sign_flag=1;
    
if(read_and_validate(argc,argv)==FAILURE)
{
 	printf("ERROR");
	return FAILURE;
}
//insert_digit(&head1, &tail1, &head2, &tail2, argv);

   // int sign_flag=1;
	char operator=argv[2][0];

      switch (operator)
		{
			case '+':
			    insert_digit(&head1, &tail1, &head2, &tail2, argv);
                if(addition(&head1,&tail1,&head2,&tail2,&headR,&tailR)==SUCCESS);
				{
				printf("Addition Result: ");
                print_list(headR);
				}
                /* call the function to perform the addition operation */
                break;
			case '-':
			    check_operands(argc,argv,&head1,&tail1,&head2,&tail2,&sign_flag);
				printf("Subtraction result: ");
                if ((sign_flag) == -1)
                {
                printf("-");
				}
			    if(subtraction(&head1,&tail1,&head2,&tail2,&headR,&tailR)==SUCCESS)
				{
					print_list(headR);
				}
				/* call the function to perform the subtraction operation */
				break;
			case 'x':
			    insert_digit(&head1, &tail1, &head2, &tail2, argv);
			   if(multiplication(&head1,&tail1,&head2,&tail2,&headR,&tailR,argv)==SUCCESS)
			   {
				 printf("Multiplication result:");
				 print_list(headR);
			   }
	            /* call the function to perform the multiplication operation */
				break;
			case '/':
			   insert_digit(&head1, &tail1, &head2, &tail2, argv);
			   if(division(&head1,&tail1,&head2,&tail2,&headR,&tailR,argv)==SUCCESS)
			   {
				print_list(headR);
			   }	
				/* call the function to perform the division operation */
				break;
			default:
				printf("Invalid Input:-( Try again...\n");
		}
	return 0;
}
