#include <limits.h>

int mx_factorial_iter(int n) {
    if (n < 0 || n > 12) {
        return 0;
    }
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

