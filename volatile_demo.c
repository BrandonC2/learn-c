void wait_normal(int *status)
{
	while (*status == 0) {
		// Wait until ready
	}
}

void wait_volatile(volatile int *status)
{
	while(*status == 0){
		// Wait until ready
	}
}
