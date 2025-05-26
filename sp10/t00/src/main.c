#include <fcntl.h>
#include <unistd.h>
#include "printerr.h"

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 2) {
	mx_printerr("usage: ./read_file [file_path]\n");
	return 1;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
	mx_printerr("error\n");
	return 1;
    }

    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;
    while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0) {
	write(1, buffer, bytes_read);
    }

    close(fd);
    return 0;
}

