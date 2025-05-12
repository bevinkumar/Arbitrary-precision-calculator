#include "apc.h"

int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
    int borrow = 0, num1 = 0, num2 = 0, diff = 0;
    Dlist *temp1 = *tail1;
    Dlist *temp2 = *tail2;

    while (temp1 != NULL || temp2 != NULL || borrow != 0)
    {
        if (temp1 != NULL)
        {
            num1 = temp1->data;
            temp1 = temp1->prev;
        }
        else
        {
            num1 = 0;
        }

        if (temp2 != NULL)
        {
            num2 = temp2->data;
            temp2 = temp2->prev;
        }
        else
        {
            num2 = 0;
        }

        // Perform subtraction
        diff = num1 - num2 - borrow;
        if (diff < 0)
        {
            diff += 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }

        // Create a new node for the result
        Dlist *new = malloc(sizeof(Dlist));
        if (!new)
        {
            printf("Memory allocation failed!\n");
            return FAILURE;
        }
        new->data = diff;
        new->prev = NULL;
        new->next = *headR;

        // Update result list
        if (*headR != NULL)
        {
            (*headR)->prev = new;
        }
        else
        {
            *tailR = new;
        }
        *headR = new;
    }

    // Remove leading zeros
    while (*headR != NULL && (*headR)->data == 0 && (*headR)->next != NULL)
    {
        Dlist *temp = *headR;
        *headR = (*headR)->next;
        (*headR)->prev = NULL;
        free(temp);
    }
     
   // print_list(*headR);

    return SUCCESS;
}
