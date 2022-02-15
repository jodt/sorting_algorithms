#include "sort.h"

/**
 *cocktail_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Cocktail shaker sort algorithm.
 * @list: pointer address of the first node in the list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current, *the_next;
	int swap = TRUE;


	if (!list || !*list || (!(*list)->next && !(*list)->prev))
		return;
	current = *list, the_next = current->next;
	if (!the_next->next)
	{
		if (current->n > the_next->n)
			swap_node(list, current, the_next);
		print_list(*list);
		return;
	}
	while (swap)
	{
		while (the_next->next)
		{
			swap = FALSE;
			if (current->n > the_next->n)
			{
				swap_node(list, current, the_next);
				print_list(*list);
				reset_position_pointer(&current, &the_next);
				swap = TRUE;
			}
			the_next = the_next->next, current = current->next;
		}
		while (current->prev)
		{
			swap = FALSE;
			if (current->n > the_next->n)
			{
				swap_node(list, current, the_next);
				print_list(*list);
				reset_position_pointer(&current, &the_next);
				swap = TRUE;
			}
			current = current->prev, the_next = the_next->prev;
		}
	}
}

/**
 * swap_node - swap two values in the linked list
 * @list: pointer address of the first node in the list
 * @node1: first node
 * @node2: second node
 */
void swap_node(listint_t **list, listint_t *node1, listint_t *node2)
{
	list = list;
	node2->prev = node1->prev;
	if (!node1->prev)
		*list = node2;
	if (node1->prev)
		node1->prev->next = node2;
	node1->next = node2->next;
	if (node2->next)
		node2->next->prev = node1;
	node2->next = node1;
	node1->prev = node2;
}

/**
 * reset_position_pointer - after a swap, restore current
 * and next to their initial position
 * @current: current node
 * @next: the next node
 */
void reset_position_pointer(listint_t **current, listint_t **next)
{
	listint_t *temp;

	temp = *next;
	*next = *current;
	*current = temp;
}
