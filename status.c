#include <stdint.h>
#include <stdio.h>

enum {
	STATUS_POWER_OK = 1u << 0,
	STATUS_LINK_UP = 1u << 1,
	STATUS_ERROR = 1u < 2,
	STATUS_RX_READY = 1u << 3
};

int main(void)
{

	uint8_t status = STATUS_POWER_OK |
			 STATUS_LINK_UP  |
			 STATUS_RX_READY;

	printf("Status: %u\n", (unsigned)status);

	if (status & STATUS_LINK_UP) {
		printf("Network connected\n");
	}

	uint8_t required = STATUS_POWER_OK | STATUS_LINK_UP;

	if((status & required) == required){
		printf("Ready to transmit\n");
	}

	status &= ~STATUS_RX_READY;

	printf("After: %u\n", (unsigned)status);

	return 0;
}
