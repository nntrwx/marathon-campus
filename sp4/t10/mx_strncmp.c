int mx_strncmp(const char *s1, const char *s2, int n) {
    int i = 0;

    while (*s1 == *s2 && *s1 != '\0' && *s2 != '\0' && i < n) {
        i++;
        s1++;
        s2++;
    }

    if (i == n || (*s1 == '\0' && *s2 == '\0')) {
        return 0;
    }

    return (*s1 > *s2) ? 1 : -1;
}

