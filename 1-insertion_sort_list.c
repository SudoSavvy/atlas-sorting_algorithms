#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm.
 * @list: Double pointer to the head of the list.
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *current, *key;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    current = (*list)->next;

    while (current != NULL)
    {
        key = current;
        current = current->next;

        while (key->prev != NULL && key->n < key->prev->n)
        {
            swap_nodes(list, key->prev, key);
            print_list(*list);  /* Print the list after swapping */
        }
    }
}

/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 * @list: Double pointer to the head of the list.
 * @node1: Pointer to the first node.
 * @node2: Pointer to the second node.
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
    if (node1 == NULL || node2 == NULL || node1 == node2)
        return;

    if (node1->prev != NULL)
        node1->prev->next = node2;
    if (node2->next != NULL)
        node2->next->prev = node1;
    node2->prev = node1->prev;
    node1->next = node2->next;
    node1->prev = node2;
    node2->next = node1;

    if (*list == node1)
        *list = node2;
}
