#include <limits.h>
#include <stdbool.h>

bool mx_isdigit(int c);

bool mx_isspace(char c);

int mx_atoi(const char* src) {
    int n = 0;
    int sign = 1;

    while (mx_isspace(*src)) {
        src++;
    }

    if (*src == '-' || *src == '+') {
        if (*src == '-') {
            sign = -1;
        }
        src++;
    }

    while (mx_isdigit(*src)) {
        int digit = *src - '0';

        if (n > (INT_MAX - digit) / 10) {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }

        n = n * 10 + digit;
        src++;
    }

    return n * sign;
}

