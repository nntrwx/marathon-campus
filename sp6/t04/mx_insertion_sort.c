int mx_strlen(const char *s);

int mx_insertion_sort(char **arr, int size) {
    int shifts = 0;
    for (int i = 1; i < size; i++) {
        char *key = arr[i];
        int j = i - 1;
        while (j >= 0 && mx_strlen(arr[j]) > mx_strlen(key)) {
            arr[j + 1] = arr[j];
            j--;
            shifts++;
        }
        arr[j + 1] = key;
    }
    return shifts;
}

