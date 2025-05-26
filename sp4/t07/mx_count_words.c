int mx_count_words(const char *str, char delimiter) {
    int count = 0;
    int in_word = 0;

    while (*str) {
        if (*str == delimiter) {
            in_word = 0;
        }
	else if (!in_word) {
            in_word = 1;
            count++;
        }
        str++;
    }
    return count;
}

