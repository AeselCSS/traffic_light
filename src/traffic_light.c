#include "traffic_light.h"

int main() {
    // Set traffic light pins as outputs
    SET_TRAFFIC_LIGHT_PINS_OUTPUT();

    while (1) {
        // North/South green, East/West red
        MY_PORT_B = (MY_PORT_B & ~(NS_RED | NS_YELLOW | EW_YELLOW | EW_GREEN)) | (NS_GREEN | EW_RED);
        DELAY(1); // Delay for ~1 second

        // North/South yellow, East/West red
        MY_PORT_B = (MY_PORT_B & ~(NS_RED | NS_GREEN | EW_YELLOW | EW_GREEN)) | (NS_YELLOW | EW_RED);
        DELAY(1); // Delay for ~1 second

        // All red (North/South and East/West)
        MY_PORT_B = (MY_PORT_B & ~(NS_YELLOW | NS_GREEN | EW_YELLOW | EW_GREEN)) | (NS_RED | EW_RED);
        DELAY(1); // Delay for ~1 second

        // North/South red, East/West green
        MY_PORT_B = (MY_PORT_B & ~(NS_YELLOW | NS_GREEN | EW_RED | EW_YELLOW)) | (NS_RED | EW_GREEN);
        DELAY(1); // Delay for ~1 second

        // North/South red, East/West yellow
        MY_PORT_B = (MY_PORT_B & ~(NS_YELLOW | NS_GREEN | EW_RED | EW_GREEN)) | (NS_RED | EW_YELLOW);
        DELAY(1); // Delay for ~1 second

        // All red (North/South and East/West)
        MY_PORT_B = (MY_PORT_B & ~(NS_YELLOW | NS_GREEN | EW_YELLOW | EW_GREEN)) | (NS_RED | EW_RED);
        DELAY(1); // Delay for ~1 second
    }

    return 0;
}
