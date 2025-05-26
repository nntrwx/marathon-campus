#include <stddef.h>

int mx_strlen(const char *s) {
    int size = 0;
    
    if (s) {
	for (; s[size] != '\0'; size++);
    }
    
    return size;
}

