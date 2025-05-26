#include <stdbool.h>

int mx_strlen(const char *s);

int mx_strcmp(const char *s1, const char *s2);

int mx_selection_sort(char **arr, int size) {
    int swaps = 0;
    for (int i = 0; i < size - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < size; j++) {
            if (mx_strlen(arr[j]) < mx_strlen(arr[min_idx])) min_idx = j;
            else if (mx_strlen(arr[j]) == mx_strlen(arr[min_idx]) && mx_strcmp(arr[j], arr[min_idx]) < 0)
                min_idx = j;
        }
        if (min_idx != i) {
            char *temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
            swaps++;
        }
    }
    return swaps;
}

