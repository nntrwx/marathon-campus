#include "calculator.h"
#include "minilibmx.h"

int main(int argc, char *argv[]) {
    if (argc != 4) {
	mx_printstr("usage: ./calc [operand1] [operation] [operand2]\n");
	return 1;
    }

    int a = mx_atoi(argv[1]);
    int b = mx_atoi(argv[3]);
    char op = argv[2][0];

    t_operation operations[] = {
	{'+', mx_add},
	{'-', mx_sub},
	{'*', mx_mul},
	{'/', mx_div},
	{'%', mx_mod}
    };

    int result = 0;
    bool valid_op = false;

    for (int i = 0; i < 5; i++) {
	if (operations[i].op == op) {
	    if ((op == '/' || op == '%') && b == 0) {
		mx_printstr("error: division by zero\n");
		return DIV_BY_ZERO;
	    }
	    result = operations[i].f(a, b);
	    valid_op = true;
	    break;
	}
    }

    if (!valid_op) {
	mx_printstr("error: invalid operator\n");
	return INCORRECT_OPERATION;
    }

    mx_printint(result);
    mx_printchar('\n');
    return 0;
}

