#include <stdlib.h>

int *mx_copy_int_arr(const int *src, int size) {
    if (!src || size <= 0) return NULL;
    
    int *arr = (int *)malloc(size * sizeof(int));
    
    if (!arr) return NULL;
    
    for (int i = 0; i < size; i++) {
	arr[i] = src[i];
    }
    
    return arr;
}

