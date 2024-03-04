#include <stddef.h>
#include "ll_cycle.h"


int ll_has_cycle(node *head) {
    // If the list is empty or has only one node, it cannot have a cycle
    if (head == NULL || head->next == NULL) {
        return 0;
    }

    // Initialize two pointers: fast_ptr and slow_ptr
    node *fast_ptr = head;
    node *slow_ptr = head;

    // Iterate through the list until fast_ptr reaches the end (or NULL)
    while (fast_ptr != NULL && fast_ptr->next != NULL) {
        // Move fast_ptr by two nodes and slow_ptr by one node
        fast_ptr = fast_ptr->next->next;
        slow_ptr = slow_ptr->next;

        // If fast_ptr and slow_ptr meet, the list has a cycle
        if (fast_ptr == slow_ptr) {
            return 1;
        }
    }

    // If fast_ptr reaches the end (NULL), the list is acyclic
    return 0;
}

