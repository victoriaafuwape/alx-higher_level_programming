#include "lists.h"

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: double pointer to the head of the list
 * Return: 0 if not palindrome, 1 if palindrome
 */
int is_palindrome(listint_t **head)
{
    listint_t *tmp = *head;
    int nodes = 0, i = 0, j = 0;
    int *arr;

    if (!head || !(*head) || !((*head)->next))
        return (1);

    while (tmp)
    {
        nodes++;
        tmp = tmp->next;
    }

    arr = malloc(sizeof(int) * nodes);
    if (!arr)
        return (0);

    tmp = *head;
    while (tmp)
    {
        arr[i++] = tmp->n;
        tmp = tmp->next;
    }

    for (i = 0, j = nodes - 1; i < j; i++, j--)
    {
        if (arr[i] != arr[j])
        {
            free(arr);
            return (0);
        }
    }

    free(arr);
    return (1);
}
