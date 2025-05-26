#include <stdlib.h>

char *mx_strcat(char *s1, const char *s2);
char* mx_strcpy(char* dst, const char* src);
char *mx_strnew(const int size);
int mx_strlen(const char *s);
char *mx_strdup(const char *str);
char *mx_strjoin(char const *s1, char const *s2);
void mx_strdel(char **str);

char *mx_concat_words(char **words) {
    if (!words || !*words) return NULL;

    char *result = mx_strnew(0);
    if (!result) return NULL;

    for (int i = 0; words[i]; i++) {
	char *temp = mx_strjoin(result, words[i]);
	mx_strdel(&result);
	result = temp;

	if (words[i + 1]) {
	    temp = mx_strjoin(result, " ");
	    mx_strdel(&result);
	    result = temp;
	}
    }

    return result;
}

