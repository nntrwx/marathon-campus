#include <stdbool.h>

bool mx_islower(int c);

bool mx_isupper(int c);

int mx_tolower(int c);

int mx_toupper(int c);

void mx_reverse_case(char*c) {
    int ind = 0;
    while (c[ind] != '\0') {
        if (mx_islower(c[ind])) c[ind] = mx_toupper(c[ind]);
        else if (mx_isupper(c[ind])) c[ind] = mx_tolower(c[ind]);
        if(c[ind] != '\0') ind++;
    }
}

