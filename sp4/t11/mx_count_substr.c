#include <stddef.h>

char *mx_strstr(const char *s1, const char *s2);

int mx_strlen(const char *s);

int mx_count_substr(const char *str, const char *sub) {
    if (!str || !sub || mx_strlen(sub) == 0) {
        return 0;
    }

    int count = 0;
    char *current = (char *)str;

    while ((current = mx_strstr(current, sub)) != NULL) {
        count++;
        current++;
    }

    return count;
}

