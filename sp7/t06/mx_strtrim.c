#include <stdlib.h>
#include <stdbool.h>

bool mx_isspace(char c);
void mx_strdel(char **str);
int mx_strlen(const char *s);
char* mx_strncpy(char *dst, const char *src, int len);
char *mx_strnew(const int size);

char *mx_strtrim(const char *str) {
    if (!str) return NULL;

    int len = mx_strlen(str);
    int start = 0;
    int end = len - 1;

    while (mx_isspace(str[start]) && start < len) start++;

    while (mx_isspace(str[end]) && end >= 0) end--;

    if (start > end) return mx_strnew(0);

    int new_len = end - start + 1;

    char *result = mx_strnew(new_len);
    if (!result) return NULL;

    mx_strncpy(result, &str[start], new_len);

    return result;
}

