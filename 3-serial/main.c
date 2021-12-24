/*
 * main.c - Example using TinySoftSerial for ATtiny with Updates
 *          for use with the Digispark ATTINY85 development board.
 * 
 * Created:          5/8/2018 3:47:42 PM
 * Original Author:  Michael Shimniok
 * 
 * Updated:          12/24/2021 12:51:00 PM
 * Author :          Matthew MacGregor
 *
 */

/*
LICENSE TinySoftSerial is Licensed GPL v2.1, as is this example. 

 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU Lesser General Public
 License as published by the Free Software Foundation; either
 version 2.1 of the License, or (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 Lesser General Public License for more details.

 You should have received a copy of the GNU Lesser General Public
 License along with this library; if not, write to the Free Software
 Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include <avr/io.h>
#include <util/delay.h>
#include "SoftwareSerial.h"

#define BLOCK_SIZE 12
#define BAUD_RATE 38400

// incoming buffer
volatile char *inbuf[32];
// outgoing buffer
volatile char *outbuf[32];

int main()
{
	DDRB 	|= 	(1 << PB1);	// Set pin to output

	softSerialBegin(BAUD_RATE);
	for (int i = 0;;i++) {
		if (softSerialAvailable()) {
			int c = softSerialRead();
			// Every BLOCK_SIZE RX/TX cycles, flash the onboard LED
			if (i % BLOCK_SIZE == 0) {
				PORTB 	^= 	(1 << PB1);
			}
			_delay_ms(10);
			softSerialWrite(c);
		} else {
			PORTB &= ~(1 << PB1);
			i = 0;
		}
	}
}

