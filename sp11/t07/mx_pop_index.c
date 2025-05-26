#include "list.h"

void mx_pop_index(t_list **list, int index) {
    if (!list || !*list)
	return;
    if (index <= 0) {
	mx_pop_front(list);
	return;
    }
    t_list *temp = *list;
    for (int i = 1; temp->next && i < index; i++)
	temp = temp->next;
    if (!temp->next) {
	mx_pop_back(list);
	return;
    }
    t_list *del_node = temp->next;
    temp->next = del_node->next;
    free(del_node);
}

