#include "list.h"

void mx_foreach_list(t_list *list, void (*f)(t_list *node)) {
    while (list) {
	f(list);
	list = list->next;
    }
}

