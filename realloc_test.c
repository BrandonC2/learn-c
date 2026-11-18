#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int *buffer = malloc(3 * sizeof(int));

	if (buffer == NULL) {
		return 1;
	}

	buffer[0] = 10;
	buffer[1] = 20;
	buffer[2] = 30;

	int *temp = realloc(buffer, 5 * sizeof(int));

	if (temp == NULL) {
		free(buffer);
		buffer = NULL;
		return 1;
	}

	buffer = temp;

	buffer[3] = 40;
	buffer[4] = 50;

	printf("%d\n", buffer[2]);

	free(buffer);
	buffer = NULL;
	temp = NULL;
	return 0;
}
