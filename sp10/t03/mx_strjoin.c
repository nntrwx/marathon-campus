#include "file_to_str.h"

char *mx_strjoin(char const *s1, char const *s2) {
    if (!s1 && !s2) return NULL;
    if (!s1) return mx_strdup(s2);
    if (!s2) return mx_strdup(s1);
    
    int len = mx_strlen(s1) + mx_strlen(s2);
    char *res = mx_strnew(len);
    
    if (!res) return NULL;
    
    mx_strcpy(res, s1);
    mx_strcat(res, s2);
    
    return res;
}

