#include "file_to_str.h"

char *mx_strdup(const char *str) {
    if (!str) return NULL;
    
    char *dup = mx_strnew(mx_strlen(str));
    
    return dup ? mx_strcpy(dup, str) : NULL;
}

