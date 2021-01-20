/*
 --------------------------------------------------
 Project: CP264-a1q2
 File:    factorial.c
 Author:  Nausher Rao
 Version: 2021-01-18
 --------------------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *args[]) {
	int n = 0;
	int fact = 1;

	if (argc > 1) {
		n = atoi(args[1]);
		printf("%11d", fact);
		if (n >= 1) {
			for (int i = 2; i <= n; i++) {
				fact *= i;
				printf("%11d", fact);
				if (fact > INT_MAX / i) {
					printf("\noverflow:13!\n");
					return 0;

				} else {
					if (i % 4 == 0)
						printf("\n");
				}
			}
		
			printf("\n%d!:%d\n", n, fact);

		} else {
			printf("%s:Invalid argument!\n", args[1]);

		}

	} else {
		printf("No arguments!");

	}

	return 0;

}
