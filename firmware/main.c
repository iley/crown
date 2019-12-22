#include <stdbool.h>

#include <avr/io.h>
#include <util/delay.h>

int main() {
    DDRB = 0xff;
    DDRC = 0xff;
    DDRD = 0xff;

    while (true) {
        PORTB = 0x00;
        PORTC = 0x00;
        PORTD = 0x00;
        _delay_ms(500);

        PORTB = 0xff;
        PORTC = 0xff;
        PORTD = 0xff;
        _delay_ms(500);
    }
}
