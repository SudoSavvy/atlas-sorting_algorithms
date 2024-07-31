#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                        using the Insertion sort algorithm.
 * @list: A pointer to the pointer to the head of the doubly linked list.
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *current, *key, *next;
    int temp;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    current = (*list)->next;

    while (current != NULL)
    {
        key = current;
        next = current->next;

        // Move the key to its correct position
        while (key->prev != NULL && key->n < key->prev->n)
        {
            // Swap nodes
            swap_nodes(list, key->prev, key);
            print_list(*list); // Print list after each swap
        }

        current = next;
    }
}

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: A pointer to the pointer to the head of the doubly linked list.
 * @node1: The first node to swap.
 * @node2: The second node to swap.
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
    if (node1 == NULL || node2 == NULL || node1 == node2)
        return;

    // Swap node1 and node2
    if (node1->prev)
        node1->prev->next = node2;
    else
        *list = node2;

    if (node2->next)
        node2->next->prev = node1;

    node2->prev = node1->prev;
    node1->next = node2->next;
    node2->next = node1;
    node1->prev = node2;
}
