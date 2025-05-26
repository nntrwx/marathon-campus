#ifndef DUPLICATE_H
#define DUPLICATE_H

#include <stdlib.h>

typedef struct s_intarr {
    int *arr;
    int size;
} t_intarr;

t_intarr *mx_del_dup_sarr(t_intarr *src);
int *mx_copy_int_arr(const int *src, int size);

#endif

