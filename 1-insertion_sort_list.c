#include "sort.h"
/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: pointer address of the first node in the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *temp2, *position;

	if (list == NULL || *list == NULL)
		return;
	if (!(*list)->next && !(*list)->prev)
		return;
	position = *list;
	temp = (*list)->next;
	if (!temp->next)
	{
		if (temp->n < (*list)->n)
		{
			(*list)->next = NULL;
			(*list)->prev = temp;
			temp->prev = NULL;
			temp->next = *list;
			*list = temp;
			print_list(*list);
		}
		return;
	}
	while (position)
	{
		while (temp && (temp->n > temp->prev->n))
		{
			if (!temp->next)
				return;
			temp = temp->next;
		}
		position = temp->next;
		while (temp->prev && temp->n < temp->prev->n)
		{

			temp2 = temp->prev;
			swap(list, temp2, temp);
			print_list(*list);
		}
		temp = position;
	}
}

/**
 * swap - reverse two nodes
 * @list: pointer address of the first node in the list
 * @node1: first node
 * @node2: second node
 */
void swap(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1->prev && node2->next)
	{
		node2->next->prev = node1;
		node1->next = node2->next;
		node1->prev->next = node2;
		node2->prev = node1->prev;
		node2->next = node1;
		node1->prev = node2;
	}
	else if (node1->prev && node2->next == NULL)
	{
		node1->next = node2->next;
		node1->prev->next = node2;
		node2->prev = node1->prev;
		node2->next = node1;
		node1->prev = node2;
	}
	else if (node1->prev == NULL && node2->next)
	{

		node2->prev = NULL;
		node2->next->prev = node1;
		node1->next = node2->next;
		node2->next = node1;
		node1->prev = node2;
		*list = node2;
	}
}
