int mx_add(int a, int b) {
    return a + b;
}

int mx_sub(int a, int b) {
    return a - b;
}

int mx_mul(int a, int b) {
    return a * b;
}

int mx_div(int a, int b) {
    if (b == 0) return 0;
    return a / b;
}

int mx_mod(int a, int b) {
    if (b == 0) return 0;
    return a % b;
}

