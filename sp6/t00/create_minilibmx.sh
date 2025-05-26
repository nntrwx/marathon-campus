#!/bin/bash

LIB_NAME="minilibmx.a"

FUNCTIONS=("mx_printchar" "mx_printint" "mx_printstr" "mx_strcpy" "mx_strlen" "mx_strcmp" "mx_isdigit" "mx_isspace" "mx_atoi")

for func in "${FUNCTIONS[@]}"; do
    if [ ! -f "${func}.c" ]; then
        echo "Error: File ${func}.c not found!"
        exit 1
    fi
    gcc -Wall -Wextra -Werror -Wpedantic -c -o "${func}.o" "${func}.c"
done

ar rc $LIB_NAME *.o

ranlib $LIB_NAME

rm -f *.o

