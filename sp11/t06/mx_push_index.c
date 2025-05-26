#include "list.h"

void mx_push_index(t_list **list, void *data, int index) {
    if (!list)
	return;
    if (index <= 0) {
	mx_push_front(list, data);
	return;
    }
    t_list *new_node = mx_create_node(data);
    if (!new_node)
	return;
    t_list *temp = *list;
    for (int i = 1; temp && i < index; i++)
	temp = temp->next;
    if (!temp) {
	mx_push_back(list, data);
	return;
    }
    new_node->next = temp->next;
    temp->next = new_node;
}

