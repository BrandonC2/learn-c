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

	uint8_t status = 0;
	
	// TODO: Turn ON POWER_OK and LINK_UP.
	// Do not modify the other bits.
	
	status |= (STATUS_POWER_OK | STATUS_LINK_UP);

	print("Status: %u\n", (unsigned)status);

	return 0;
};
