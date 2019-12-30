#ifndef _PROGRAMS_H
#define _PROGRAMS_H

#include <stdint.h>

typedef struct {
    int len;
    int8_t *body;  // Body contains 6*len elements.
} program_t;

extern int program_count;
extern program_t programs[];

#endif // _PROGRAMS_H
