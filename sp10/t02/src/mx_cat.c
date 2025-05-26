#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include "printerr.h"

#define BUFFER_SIZE 1024

void mx_cat(const char *filename) {
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        mx_printerr("mx_cat: ");
        mx_printerr(filename);
        mx_printerr(": ");
        mx_printerr(strerror(errno));
        mx_printerr("\n");
        return;
    }

    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;
    while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0) {
        write(1, buffer, bytes_read);
    }

    close(fd);
}

