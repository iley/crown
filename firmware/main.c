#include <stdbool.h>
#include <stdint.h>

#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>

#include "colors.h"
#include "programs.h"

#define NLEDS 6

#define COLOR_CHANGE_MS 500
#define DEBOUNCE_MS 500

// Start timer at 65536-1000 for 1ms delay at 8MHz with prescaler 8.
#define TIMER_START 64536

// Milliseconds since boot.
uint32_t millis = 0;

ISR(TIMER1_OVF_vect) {
    millis++;
    TCNT1 = TIMER_START;
}

// Takes an array of NLEDS colors.
void set_colors(int8_t *colors) {
    PORTC = colors[1] | (colors[0] << 3);
    PORTB = colors[2] << 3 | (colors[4]&1) << 6 | 0b00000001; // Keep the pull-up on PB0.
    PORTD = (colors[5]&0b100) >> 2 | (colors[5]&0b010) | (colors[5]&1) << 2 |
            (colors[4]&0b100) << 1 | (colors[4]&0b010) << 3 |
            (colors[3]&0b100) << 3 | (colors[3]&0b010) << 5 | (colors[3]&1) << 7;
}

int main() {
    // Set up timer 1 to trigger an interrupt every millisecond.
    TCCR1A = 0x00;
    TIMSK1 = (1 << TOIE1) ; // Timer 1 overflow interrupt.
    TCNT1 = TIMER_START;
    TCCR1B = (1<<CS11);    // Prescaler 8 => 1MHz
    sei();

    // Set up I/O.
    DDRD = 0b11111111; // PD0-PD7 are outputs.
    DDRC = 0b00111111; // PC0-PC5 are outputs.
    DDRB = 0b01111000; // PB3-PB6 are outputs.

    PORTB = 0b00000001; // Enable pull-up on PB0.

    // Time tracking.
    uint32_t last_color_change_ms = 0;
    uint32_t last_button_press_ms = 0;

    int program_index = 0;
    int program_step = 0;
    while (true) {
        // Button is active low.
        bool button_pressed = (PINB & 1) == 0;

        if (button_pressed && millis - last_button_press_ms > DEBOUNCE_MS) {
            program_index = (program_index + 1) % program_count;
            last_button_press_ms = millis;
        }

        if (millis - last_color_change_ms > COLOR_CHANGE_MS) {
            uint8_t *body = programs[program_index].body;
            set_colors(&body[NLEDS*program_step]);
            program_step = (program_step + 1) % programs[program_index].len;
            last_color_change_ms = millis;
        }
    }
}
