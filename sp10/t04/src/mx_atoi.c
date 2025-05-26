#include "../inc/minilibmx.h"

int mx_atoi(const char* str) {
    int n = 0;
    int sign = 1;

    while (mx_isspace(*str)) {
        str++;
    }

    if (*str == '-' || *str == '+') {
        if (*str == '-') {
            sign = -1;
        }
        str++;
    }

    while (mx_isdigit(*str)) {
        int digit = *str - '0';

        if (n > (INT_MAX - digit) / 10) {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }

        n = n * 10 + digit;
        str++;
    }

    return n * sign;
}

