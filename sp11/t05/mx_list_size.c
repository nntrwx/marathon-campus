#include "list.h"

int mx_list_size(t_list *list) {
    int size = 0;
    while (list) {
	size++;
	list = list->next;
    }
    return size;
}

