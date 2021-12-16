#include <avr/io.h>
#include <util/delay.h>

// Digispark LED is on Pin 1 for newer versions
#define LED		PB1
#define DELAY_MS	1000

int main(void) {
	DDRB 	|= 	(1 << LED);	// Set pin to output
	PORTB 	|= 	(1 << LED);	// Set pin to high

	for (;;) {
		PORTB ^= (1 << LED);
		_delay_ms(DELAY_MS);
	}

	return 0;
}
