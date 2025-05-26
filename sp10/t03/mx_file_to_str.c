#include "file_to_str.h"
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

char *mx_file_to_str(const char *filename) {
    if (!filename) return NULL;

    int fd = open(filename, O_RDONLY);
    if (fd < 0) return NULL;

    int size = 0;
    char buf;
    while (read(fd, &buf, 1) > 0) size++;
    close(fd);

    if (size == 0) return NULL;

    char *str = mx_strnew(size);
    if (!str) return NULL;

    fd = open(filename, O_RDONLY);
    if (fd < 0) { free(str); return NULL; }

    if (read(fd, str, size) < 0) { free(str); close(fd); return NULL; }
    close(fd);

    return str;
}
