#include <stdbool.h>
#include <stdint.h>

#include <avr/io.h>
#include <util/delay.h>

#define CLR_RED     ((uint8_t)0b001)
#define CLR_GREEN   ((uint8_t)0b010)
#define CLR_BLUE    ((uint8_t)0b100)
#define CLR_YELLOW  ((uint8_t)0b011)
#define CLR_MAGENTA ((uint8_t)0b101)
#define CLR_CYAN    ((uint8_t)0b110)
#define CLR_WHITE   ((uint8_t)0b111)

// Takes an array of 6 colors.
void set_colors(int8_t *colors) {
    PORTC = colors[1] | (colors[0] << 3);
    PORTB = colors[2] << 3 | (colors[4]&1) << 6;
    PORTD = (colors[5]&0b100) >> 2 | (colors[5]&0b010) | (colors[5]&1) << 2 |
            (colors[4]&0b100) << 1 | (colors[4]&0b010) << 3 |
            (colors[3]&0b100) << 3 | (colors[3]&0b010) << 5 | (colors[3]&1) << 7;
}

int program_len = 3;
int8_t program[][6] = {
    {  CLR_RED,   CLR_RED,   CLR_RED,   CLR_RED,   CLR_RED,   CLR_RED},
    {CLR_GREEN, CLR_GREEN, CLR_GREEN, CLR_GREEN, CLR_GREEN, CLR_GREEN},
    { CLR_BLUE,  CLR_BLUE,  CLR_BLUE,  CLR_BLUE,  CLR_BLUE,  CLR_BLUE},
};

int main() {
    DDRD = 0b11111111; // PD0-PD7 are outputs.
    DDRC = 0b00111111; // PC0-PC5 are outputs.
    DDRB = 0b01111000; // PB3-PB6 are outputs.

    int i = 0;
    while (true) {
        set_colors(program[i]);
        _delay_ms(500);
        i = (i + 1) % program_len;
    }
}
