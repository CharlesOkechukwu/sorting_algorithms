#include "sort.h"

/**
 * list_swap - swap nodes in a list
 * @list: list to swap its nodes
 *
 * Return: void
 */

void list_swap(listint_t *list)
{
	listint_t *first, *second;

	first = list;
	second = first->next;
	second->prev = first->prev;
	first->next = second->next;
	if (first->prev)
		first->prev->next =  second;
	if (second->next)
		second->next->prev = first;
	first->prev = second;
	second->next = first;
}

/**
 * insertion_sort_list -  insertion sort algorithm
 * @list: list to sort
 *
 * Return; void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *first, *sec;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	first = *list;
	while (first != NULL)
	{
		while (first->next && (first->n > first->next->n))
		{
			sec = first->next;
			list_swap(first);
			if (sec->prev)
				first = sec->prev;
			else
				*list = sec;
			print_list(*list);
		}
		first = first->next;
	}
}
