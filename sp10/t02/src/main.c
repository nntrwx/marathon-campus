#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include "printerr.h"

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc == 1) {
        char buffer[BUFFER_SIZE];
        ssize_t bytes_read;
        while ((bytes_read = read(0, buffer, BUFFER_SIZE)) > 0) {
            write(1, buffer, bytes_read);
        }
    } else {
        for (int i = 1; i < argc; i++) {
            mx_cat(argv[i]);
        }
    }
    return 0;
}

