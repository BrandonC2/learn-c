#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int *buffer = malloc(5 * sizeof(int));

	for (int i = 0; i < 5; i++) {
		buffer[i] = i + 1;
	}

	int *cursor = buffer + 2;

	*cursor = 99;
	cursor++;

	printf("%d\n", *cursor);

	free(buffer);
	buffer = NULL;

	return 0;
}
