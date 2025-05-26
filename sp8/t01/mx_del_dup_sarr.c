#include "duplicate.h"

t_intarr *mx_del_dup_sarr(t_intarr *src) {
    if (!src || !src->arr || src->size <= 0) return NULL;

    int *new_arr = (int *)malloc(src->size * sizeof(int));
    
    if (!new_arr) return NULL;

    int new_size = 0;
    
    for (int i = 0; i < src->size; i++) {
	int found = 0;
	for (int j = 0; j < new_size; j++) {
    	    if (new_arr[j] == src->arr[i]) {
		found = 1;
		break;
	    }
	}
	if (!found) new_arr[new_size++] = src->arr[i];
    }

    t_intarr *new_struct = (t_intarr *)malloc(sizeof(t_intarr));
    
    if (!new_struct) {
	free(new_arr);
	return NULL;
    }
    
    new_struct->arr = mx_copy_int_arr(new_arr, new_size);
    new_struct->size = new_size;
    free(new_arr);
    
    return new_struct;
}

