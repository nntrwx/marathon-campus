int mx_sqrt(int x) {
    if (x <= 0) return 0;
    
    int i = 1;
    
    while (x > i * i) {
        i ++;
    }
    
    if (i * i == x) return i;
    return 0;
}

