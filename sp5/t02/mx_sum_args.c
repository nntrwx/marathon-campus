#include "unistd.h"
#include <stdbool.h>

int mx_atoi(const char* str);
bool mx_isspace(char c);
bool mx_isdigit(int c);
void mx_printchar(char c);
void mx_printint(int n);

int main(int argc, char *argv[]) {
    int sum = 0;
    int valid_args = 0;

    for (int i = 1; i < argc; i++) {
        char *arg = argv[i];
        int is_valid = 1;

        if ((arg[0] == '-' || arg[0] == '+') && arg[1] == '\0') {
            continue;
        }

        for (int j = 0; arg[j] != '\0'; j++) {
            if (!mx_isdigit(arg[j]) && !(j == 0 && (arg[j] == '+' || arg[j] == '-'))) {
                is_valid = 0;
                break;
            }
        }

        if (is_valid) {
            sum += mx_atoi(arg);
            valid_args++;
        }
    }

    mx_printint(valid_args == 0 ? 0 : sum);
    mx_printchar('\n');

    return 0;
}

