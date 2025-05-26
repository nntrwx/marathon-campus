#include <stddef.h>

char *mx_strchr(const char *s, int c);

int mx_strlen(const char *s);

int mx_strncmp(const char *s1, const char *s2, int n);

char *mx_strstr(const char *s1, const char *s2) {
    if (!s1 || !s2 || *s2 == '\0') {
        return (char *)s1;
    }

    char *current = (char *)s1;
    int sub_len = mx_strlen(s2);
    
    while ((current = mx_strchr(current, s2[0])) != NULL) {
	if (mx_strncmp(current, s2, sub_len) == 0) {
            return current;
        }
        current++;
    }

    return NULL;
}

