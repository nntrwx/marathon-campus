#include <errno.h>
#include <string.h>
#include "printerr.h"

void print_error(const char *msg, const char *file) {
    mx_printerr(msg);
    mx_printerr(file);
    mx_printerr(": ");
    mx_printerr(strerror(errno));
    mx_printerr("\n");
}

