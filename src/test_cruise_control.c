#include "cruiseControl.h"
#include <stdio.h>

// Test function
void testCruiseControl() {
    // Initialize the system
    CruiseControl_reset();

    // Example scenario: Increase speed, expect the speed to be increased.
    // Note: replace with your actual input/output signal names
    CruiseControl_I_IncreaseSpeed = 1;
    CruiseControl_O_Speed = 0;
    CruiseControl_cycle();
    assert(CruiseControl_O_Speed == 1);
    CruiseControl_I_IncreaseSpeed = 0;

    // Add more test scenarios here...
}

int main() {
    printf("Running tests for CruiseControl...\n");
    testCruiseControl();
    printf("All tests passed.\n");

    return 0;
}
