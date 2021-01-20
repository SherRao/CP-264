/*
 --------------------------------------------------
 Project: CP264-a1q1
 File:    caseflip.c
 Author:  Nausher Rao
 Version: 2021-01-18
 --------------------------------------------------
 */
#include <stdio.h>

int main() {
	char input = 0;
	char temp;

	printf("Please enter a character\n");
	scanf("%c", &input);
	while (input != '*') {
		do {
			scanf("%c", &temp);
			if (temp == '\n')
				break;

		} while (1);

		if (input >= 'a' && input <= 'z') {
			printf("%c:%d,%c", input, input, input - 32);

		} else if(input >= 'A' && input <= 'Z'){
			printf("%c:%d,%c", input, input, input + 32);

		} else
			printf("%c:invalid", input);

		printf("\nPlease enter a character\n");
		scanf("%c", &input);

	}

	printf("%c:quit\n", input);
	return 0;

}
