#include <stdbool.h>

void mx_sort(int *arr, int size, bool (*f)(int, int)) {
    if (!arr || size <= 0 || !f)
	return;
    for (int i = 0; i < size - 1; i++) {
	for (int j = 0; j < size - 1 - i; j++) {
	    if (f(arr[j], arr[j + 1])) {
		int temp = arr[j];
		arr[j] = arr[j + 1];
		arr[j + 1] = temp;
	    }
	}
    }
}

