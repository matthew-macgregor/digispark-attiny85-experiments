#include <avr/io.h>
#include <util/delay.h>

// Digispark LED is on Pin 1 for newer versions
#define LED			PB1
#define BUTTON		PB0
#define DELAY_MS	50
#define HIGH		1

int main(void) {
	DDRB 	|= 	(1 << LED);	// Set pin to output
	
	for (;;) {	
		int pressed = PINB & (1 << BUTTON);
		if (pressed == HIGH) {
			PORTB |= (1 << LED); 	// Button Pressed, LED On 
		} else {
			PORTB &= (0 << LED);	// Alternatively PORTB &= ~(1 << LED);
		}
	}

	return 0;
}
