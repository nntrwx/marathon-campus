#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include "printerr.h"

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        mx_printerr("usage: ./mx_cp [source_file] [destination_file]\n");
        exit(1);
    }

    int src_fd = open(argv[1], O_RDONLY);
    if (src_fd == -1) {
        print_error("mx_cp: ", argv[1]);
        exit(1);
    }

    int dest_fd = open(argv[2], O_CREAT | O_EXCL | O_WRONLY, 0644);
    if (dest_fd == -1) {
        print_error("mx_cp: ", argv[2]);
        close(src_fd);
        exit(1);
    }

    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;
    while ((bytes_read = read(src_fd, buffer, BUFFER_SIZE)) > 0) {
        if (write(dest_fd, buffer, bytes_read) != bytes_read) {
            print_error("mx_cp: write error", "");
            close(src_fd);
            close(dest_fd);
            exit(1);
        }
    }

    if (bytes_read == -1) {
        print_error("mx_cp: read error", argv[1]);
    }

    close(src_fd);
    close(dest_fd);
    return 0;
}

