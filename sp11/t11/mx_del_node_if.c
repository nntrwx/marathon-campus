#include "list.h"

void mx_del_node_if(t_list **list, void *del_data, bool (*cmp)(void *a, void *b)) {
    if (!list || !*list || !cmp)
	return;

    while (*list && cmp((*list)->data, del_data)) {
	t_list *temp = *list;
	*list = (*list)->next;
	free(temp);
    }

    t_list *current = *list;
    while (current && current->next) {
	if (cmp(current->next->data, del_data)) {
	    t_list *temp = current->next;
	    current->next = temp->next;
	    free(temp);
	} else {
	    current = current->next;
        }
    }
}

