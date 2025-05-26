void mx_printchar(char c);

void mx_print_alphabet(void) {
	for (int i = 0; i < 26; i++) {
		if (i % 2 == 0) {
			mx_printchar('A' + i);
		} else {
			mx_printchar('a' + i);
		}
	}
	mx_printchar('\n');
}

