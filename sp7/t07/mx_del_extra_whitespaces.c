#include <stdlib.h>
#include <stdbool.h>

bool mx_isspace(char c);
void mx_strdel(char **str);
int mx_strlen(const char *s);
char* mx_strncpy(char *dst, const char *src, int len);
char *mx_strnew(const int size);
char *mx_strtrim(const char *str);

char *mx_del_extra_whitespaces(const char *str) {
    if (!str) return NULL;
    
    char *trimmed = mx_strtrim(str);
    
    if (!trimmed) return NULL;
    
    char *res = mx_strnew(mx_strlen(trimmed));
    
    if (!res) {
        mx_strdel(&trimmed);
        return NULL;
    }
    
    int j = 0;
    
    for (int i = 0; trimmed[i]; i++) {
        if (!mx_isspace(trimmed[i]) || (i > 0 && !mx_isspace(trimmed[i - 1]))) {
            res[j++] = trimmed[i];
        }
    }
    
    mx_strdel(&trimmed);
    
    return res;
}

