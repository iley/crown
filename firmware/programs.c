#include "programs.h"

#include "colors.h"

int program_count = 5; // Length of the array below.
program_t programs[] = {
    {
        .len = 1,
        .body = (uint8_t []){
            CLR_RED, CLR_RED, CLR_RED, CLR_RED, CLR_RED, CLR_RED,
        }
    },
    {
        .len = 1,
        .body = (uint8_t []){
            CLR_GREEN, CLR_GREEN, CLR_GREEN, CLR_GREEN, CLR_GREEN, CLR_GREEN,
        }
    },
    {
        .len = 1,
        .body = (uint8_t []){
            CLR_BLUE, CLR_BLUE, CLR_BLUE, CLR_BLUE, CLR_BLUE, CLR_BLUE,
        }
    },
    {
        .len = 3,
        .body = (uint8_t []){
            CLR_RED, CLR_RED, CLR_RED, CLR_RED, CLR_RED, CLR_RED,
            CLR_GREEN, CLR_GREEN, CLR_GREEN, CLR_GREEN, CLR_GREEN, CLR_GREEN,
            CLR_BLUE, CLR_BLUE, CLR_BLUE, CLR_BLUE, CLR_BLUE, CLR_BLUE,
        }
    },
    {
        .len = 18,
        .body = (uint8_t []){
              CLR_RED,         0,         0,         0,         0,         0,
                    0,   CLR_RED,         0,         0,         0,         0,
                    0,         0,   CLR_RED,         0,         0,         0,
                    0,         0,         0,   CLR_RED,         0,         0,
                    0,         0,         0,         0,   CLR_RED,         0,
                    0,         0,         0,         0,         0,   CLR_RED,
             CLR_BLUE,         0,         0,         0,         0,         0,
                    0,  CLR_BLUE,         0,         0,         0,         0,
                    0,         0,  CLR_BLUE,         0,         0,         0,
                    0,         0,         0,  CLR_BLUE,         0,         0,
                    0,         0,         0,         0,  CLR_BLUE,         0,
                    0,         0,         0,         0,         0,  CLR_BLUE,
            CLR_GREEN,         0,         0,         0,         0,         0,
                    0, CLR_GREEN,         0,         0,         0,         0,
                    0,         0, CLR_GREEN,         0,         0,         0,
                    0,         0,         0, CLR_GREEN,         0,         0,
                    0,         0,         0,         0, CLR_GREEN,         0,
                    0,         0,         0,         0,         0, CLR_GREEN,
        }
    },
};
