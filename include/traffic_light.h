#ifndef TRAFFIC_LIGHT_H
#define TRAFFIC_LIGHT_H

#define DELAY(iterations) \
    do { \
        volatile long pause = 0; \
        for (pause = 0; pause < (iterations * 1000000); pause++) { \
            pause = pause; \
        } \
    } while (0)

// Port B addresses
#define MY_PORT_B *(unsigned char*)0x25 // Port B Data Register
#define MY_PORT_B_DDR *(unsigned char*)0x24 // Port B Data Direction Register

// Pin definitions for traffic lights
#define NS_RED (1 << 0)     // PB0 - 1 << 0 = 0b00000001 = 1    - North/South Red LED
#define NS_YELLOW (1 << 1)  // PB1 - 1 << 1 = 0b00000010 = 2    - North/South Yellow LED
#define NS_GREEN (1 << 2)   // PB2 - 1 << 2 = 0b00000100 = 4    - North/South Green LED
#define EW_RED (1 << 3)     // PB3 - 1 << 3 = 0b00001000 = 8    - East/West Red LED
#define EW_YELLOW (1 << 4)  // PB4 - 1 << 4 = 0b00010000 = 16   - East/West Yellow LED
#define EW_GREEN (1 << 5)   // PB5 - 1 << 5 = 0b00100000 = 32   - East/West Green LED

// Configure traffic light pins (PB0 to PB5) as outputs in the Data Direction Register (DDR).
// The bitwise OR operation combines the pin masks to produce 0b00111111 (63 in decimal),
// setting only the relevant bits in MY_PORT_B_DDR to 1 and leaving other pins unchanged.
#define SET_TRAFFIC_LIGHT_PINS_OUTPUT() (MY_PORT_B_DDR |= (NS_RED | NS_YELLOW | NS_GREEN | EW_RED | EW_YELLOW | EW_GREEN))

#endif // TRAFFIC_LIGHT_H
