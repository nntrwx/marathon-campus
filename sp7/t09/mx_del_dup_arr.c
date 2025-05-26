#include <stdlib.h>
#include <stdbool.h>

int *mx_copy_int_arr(const int *src, int size);

int *mx_del_dup_arr(int *src, int src_size, int *dst_size) {
    if (!src || src_size <= 0 || !dst_size) return NULL;

    int *copy = mx_copy_int_arr(src, src_size);
    if (!copy) return NULL;

    int new_size = 0;
    
    for (int i = 0; i < src_size; i++) {
	bool is_duplicate = false;
	for (int j = 0; j < new_size; j++) {
	    if (copy[i] == copy[j]) {
	    is_duplicate = true;
	    break;
	    }
	}
	if (!is_duplicate) {
	    copy[new_size++] = copy[i];
	}
    }

    *dst_size = new_size;
    int *res = mx_copy_int_arr(copy, new_size);
    free(copy);

    return res;
}

