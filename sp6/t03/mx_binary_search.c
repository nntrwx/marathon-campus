int mx_strcmp(const char *s1, const char *s2);

int mx_binary_search(char **arr, int size, const char *s, int *count) {
    *count = 0;
    int left = 0, right = size - 1;
    
    while (left <= right) {
        (*count)++;
        int mid = (left + right) / 2;
        int cmp = mx_strcmp(arr[mid], s);
        if (cmp == 0) return mid;
        if (cmp < 0) left = mid + 1;
        else right = mid - 1;
    }
    
    *count = 0;
    return -1;
}
