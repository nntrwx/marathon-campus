#include <stdlib.h>

int mx_count_words(const char *str, char delimiter);
char *mx_strnew(const int size);
void mx_strdel(char **str);
char* mx_strncpy(char *dst, const char *src, int len);

char **mx_strsplit(char const *s, char c) {
    if (!s) return NULL;

    int words_count = mx_count_words(s, c);
    if (words_count <= 0) return NULL;

    char **result = (char **)malloc((words_count + 1) * sizeof(char *));
    if (!result) return NULL;

    int word_index = 0;
    int start = 0;
    int end = 0;

    while (s[end]) {
	if (s[end] == c) {
	    if (end > start) {
		int word_len = end - start;
		result[word_index] = mx_strnew(word_len);
		mx_strncpy(result[word_index], &s[start], word_len);
		word_index++;
	    }
	    start = end + 1;
	}
	end++;
    }

    if (end > start) {
	int word_len = end - start;
	result[word_index] = mx_strnew(word_len);
	mx_strncpy(result[word_index], &s[start], word_len);
	word_index++;
    }

    result[word_index] = NULL;

    return result;
}

