void mx_arr_rotate(int *arr, int size, int shift) {
    if (size <= 0 || shift == 0) return;
    shift = shift % size;
    if (shift < 0) shift += size;

    int temp[shift];
    for (int i = 0; i < shift; i++) 
        temp[i] = arr[size - shift + i];
    for (int i = size - 1; i >= shift; i--)
        arr[i] = arr[i - shift];
    for (int i = 0; i < shift; i++)
        arr[i] = temp[i];
}

