#include "apc.h"
int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR,char *argv[]) 
{
    Dlist *temp1, *temp2;
    int carry, product, zeros = 0;

    // Result list for intermediate sums
    Dlist *tempHead = NULL, *tempTail = NULL;

    // Check for multiplication with zero
    if ((*head1 == NULL || *head2 == NULL) || 
        ((*head1)->data == 0 && (*head1)->next == NULL) ||
        ((*head2)->data == 0 && (*head2)->next == NULL)) {
        result_node(headR, tailR, 0);
        return SUCCESS;
    }

    temp2 = *tail2;

    // Traverse the second number from LSB to MSB
    while (temp2 != NULL) 
    {
        temp1 = *tail1;
        carry = 0;

        // Intermediate result list for each digit multiplication
        Dlist *currentHead = NULL, *currentTail = NULL;

        // Multiply each digit of the first number with the current digit of the second number
        while (temp1 != NULL) {
            product = temp1->data * temp2->data + carry;
            carry = product / 10;
            result_node(&currentHead, &currentTail, product % 10);
            temp1 = temp1->prev;
        }

        // Add carry if any
        if (carry > 0) {
            result_node(&currentHead, &currentTail, carry);
        }

        // Add zeros to the result based on the position of the digit being multiplied
        for (int i = 0; i < zeros; i++) {
            insert_zero(&currentHead, &currentTail);
        }
        zeros++;

        // Add current intermediate result to the main result
        if (*headR == NULL) {
            *headR = currentHead;
            *tailR = currentTail;
        } else {
            addition(headR, tailR, &currentHead, &currentTail, &tempHead, &tempTail);
            free_list(&currentHead, &currentTail);
            free_list(headR, tailR);
            *headR = tempHead;
            *tailR = tempTail;
        }

        temp2 = temp2->prev;
    }

    // Remove leading zeros from the result
    while (*headR != NULL && (*headR)->data == 0 && (*headR)->next != NULL) {
        Dlist *temp = *headR;
        *headR = (*headR)->next;
        if (*headR != NULL) {
            (*headR)->prev = NULL;
        }
        free(temp);
    }

    return SUCCESS;
}
