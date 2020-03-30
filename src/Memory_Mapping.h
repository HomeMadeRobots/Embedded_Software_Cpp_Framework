#ifndef MEMORY_MAPPING_H
#define MEMORY_MAPPING_H

#if defined(__AVR__)
    #include <avr/pgmspace.h>
#else
    #define PROGMEM
    #define pgm_read_byte( byte_adrr ) (*(byte_adrr))
#endif

#endif