#include "apc.h"
int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR,char *argv[]) 
{
    int count = 0;
    int data;

    if ((*argv[3] == '1') && (strlen(argv[3]) == 1)) 
    {
        *headR = *head1;
        *tailR = *tail1;
        print_list(*headR);
        return SUCCESS;
    }
    Dlist *temphead1 = *head1;
    Dlist *temptail1 = *tail1;
    
    if ( finding_the_largest_number(head1, tail1, head2, tail2) == SUCCESS)
     {
        Dlist *temphead1 = *head1;
        Dlist *temptail1 = *tail1;

        while (finding_the_largest_number(&temphead1, &temptail1, head2, tail2) == SUCCESS) 
        {
          
            subtraction(&temphead1, &temptail1, head2, tail2, headR, tailR);
            
            
            temphead1 = *headR;
            temptail1 = *tailR;
            *headR = NULL;
            *tailR = NULL;

            count++;
        }

    
        if (finding_the_largest_number(&temphead1, &temptail1, head2, tail2) == EQUAL) 
        {
            count++;
        }
        printf("Division result :%d", count);
        return SUCCESS;

    } 
    else if (finding_the_largest_number(&temphead1, &temptail1, head2, tail2)  == EQUAL)
    {
        data = 1;
        result_node(headR, tailR, data);
       print_list(*headR);
        return SUCCESS;
    } 
    else
    {
        data = 0;
        result_node(headR, tailR, data);
        print_list(*headR);
        return SUCCESS;
    }
}
