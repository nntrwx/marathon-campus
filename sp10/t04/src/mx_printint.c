#include "../inc/minilibmx.h"

void mx_printint(int n) {
    if (n == -2147483648) {
        write(1, "-2147483648", 11);
        return;
    }
    if (n == 0) {
        write(1, "0", 1);
        return;
    }
    
    if (n < 0) {
        write(1, "-", 1);
        n = -n;
    }
    
    int num = n, len = 0;
    char buffer[10];
    
    while (num > 0) {
        buffer[len++] = (num % 10) + '0';
        num /= 10;
    }
    
    while (--len >= 0) {
        write(1, &buffer[len], 1);
    }
}

