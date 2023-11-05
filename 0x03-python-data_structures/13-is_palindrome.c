#include "lists.h"

/**
 * reverse - reverses the second half of the linked list
 * @head: double pointer to the head of the second half
 * Return: pointer to the head of the reversed list
 */
listint_t *reverse(listint_t **head)
{
	listint_t *prev = NULL, *next = NULL, *current = *head;

	while (current)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	return (prev);
}

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: double pointer to the head of the list
 * Return: 0 if not palindrome, 1 if palindrome
 */
int is_palindrome(listint_t **head)
{
	listint_t *slow = *head, *fast = *head, *second_half;

	if (!head || !(*head) || !((*head)->next))
		return (1);

	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}

	if (fast != NULL)
	{
		slow = slow->next;
	}

	second_half = slow;
	second_half = reverse(&second_half);

	while (second_half && (*head))
	{
		if (second_half->n != (*head)->n)
		{
			reverse(&second_half);
			return (0);
		}
		second_half = second_half->next;
		*head = (*head)->next;
	}

	reverse(&second_half);
	return (1);
}
