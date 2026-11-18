#include <stdint.h>
#include <stdio.h>

#define STATUS_POWER_OK (1u << 0)
#define STATUS_LINK_UP  (1u << 1)
#define STATUS_RX_READY (1u << 3)

int is_link_up(const volatile uint8_t *status)
{
	return (*status & STATUS_LINK_UP) != 0;
}

void process_packets(void)
{
	static unsigned int packet_count;

	packet_count++;

	printf("Packets processed: %u\n", packet_count);
}

int main(void)
{
	volatile uint8_t register_value =
		STATUS_POWER_OK | STATUS_LINK_UP;

	volatile uint8_t *status = &register_value;

	printf("Link up: %d\n", is_link_up(status));

	for (int packet = 0; packet < 3; packet++) {

		unsigned int attempts = 0;

		while ((*status & STATUS_RX_READY) == 0){
			attempts++;

			printf("Polling attempt: %u\n", attempts);

			if (attempts == 3) {
				*status |= STATUS_RX_READY;
			}
		}

		printf("Packet received!\n");

		process_packets();

		*status &= ~STATUS_RX_READY;
	}

	return 0;
}
