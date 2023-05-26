#include <stdbool.h>
#include "cruiseControl.h"

/* 
 * This function saturates the throttle input value based on predefined maximum and minimum values.
 * If the throttle input is greater than maximum, the maximum is returned and 'saturate' is set to true.
 * If the throttle input is less than minimum (0), 0 is returned and 'saturate' is set to true.
 * Otherwise, the throttle input is returned and 'saturate' is set to false.
 */
inline float saturateThrottle(float throttleIn, bool* restrict saturate)
{
	// Define maximum throttle saturation value
	static const float THROTTLESATMAX = 45.0;

	// Check if throttleIn is greater than maximum
	if (throttleIn > THROTTLESATMAX) {
		*saturate = true;
		return THROTTLESATMAX;
	}
	// Check if throttleIn is less than 0
	else if (throttleIn < 0) {
		*saturate = true;
		return 0;
	}
	// If throttleIn is within valid range
	else {
		*saturate = false;
		return throttleIn;
	}
}

/* 
 * This function calculates throttle value using proportional-integral (PI) controller.
 * If cruise control is activated, it resets integral term and sets 'saturate' to true.
 * It calculates the error term as the difference between the desired cruise speed and the actual vehicle speed.
 * Then, the proportional and integral actions are calculated and the sum is fed to the saturateThrottle function.
 */
float regulateThrottle(bool isGoingOn, float cruiseSpeed, float vehicleSpeed)
{
	// Define proportional and integral gains
	static const float KP = 8.113;
	static const float KI = 0.5;

	// Declare static variables for saturation status and integral term
	static bool saturate = true;
	static float iterm = 0;
	
	// Check if cruise control is activated
	if (isGoingOn) {
		// Reset integral term and set saturate to true
		iterm = 0;	
		saturate = true;	
	}

	// Calculate the error term
	float error = cruiseSpeed - vehicleSpeed;

	// Calculate the proportional action
	float proportionalAction = error * KP;

	// Update integral term based on saturation status
	iterm += (saturate ? 0 : error);

	// Calculate the integral action
	float integralAction = KI * iterm;

	// Return the saturated throttle value
	return saturateThrottle(proportionalAction + integralAction, &saturate);
}
