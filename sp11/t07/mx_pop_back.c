#include "list.h"

void mx_pop_back(t_list **list) {
    if (!list || !*list)
	return;
    t_list *temp = *list;
    if (!temp->next) {
	free(temp);
	*list = NULL;
	return;
    }
    while (temp->next->next)
	temp = temp->next;
    free(temp->next);
    temp->next = NULL;
}

