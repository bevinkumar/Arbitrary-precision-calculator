#include "apc.h"

int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{

    int carry = 0, num1, num2, sum = 0, data;
    Dlist *temp1 = *tail1;  
    Dlist *temp2 = *tail2;  

   while (!(temp1 == NULL && temp2 == NULL && carry == 0)) 
   {
        if (temp1 != NULL) 
        {
            num1 = temp1->data;
        } else 
        {
            num1 = 0;
        }

        if (temp2 != NULL) 
        {
            num2 = temp2->data;
        } else 
        {
            num2 = 0;
        }

        sum = num1 + num2 + carry; 
        data = sum % 10;           
        carry = sum / 10;          

        Dlist *new_node = (Dlist *)malloc(sizeof(Dlist));
        if (new_node == NULL) {
            printf("Memory allocation failed!\n");
            return FAILURE;
        }
        new_node->data = data;
        new_node->prev = NULL;
        new_node->next = *headR;

        if (*headR) 
        {
            (*headR)->prev = new_node; 
        } else 
        {
            *tailR = new_node; 
        }
        *headR = new_node; 

      
        if (temp1) 
        {
          temp1 = temp1->prev;
        }
        if(temp2) 
        {
           temp2 = temp2->prev;
        }
    }
    return SUCCESS;
    

    
}
