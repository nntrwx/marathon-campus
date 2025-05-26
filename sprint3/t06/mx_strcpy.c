char* mx_strcpy(char* dst, const char* src) {
	char* i = dst;

	while (*src != '\0') {
		*i = *src;
		src++;
		i++;
	}

	*i = '\0';
	return dst;
}

