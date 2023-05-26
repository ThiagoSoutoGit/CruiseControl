# Cruise Control System

## Overview

The Cruise Control System is an Esterel-based system designed to manage the speed of a vehicle automatically. The project uses Esterel v6.1 for defining the reactive behavior of the system. The system's context diagram can be viewed [here](./Figures/CruiseControl%20-%20Context.png).

## Prerequisites

The system needs Esterel v6.1 to compile the `.strl` files into C. Please make sure you have it installed and correctly set up on your system.

## How to Compile and Run

After making sure Esterel is installed, you can compile the main program by running the following command:

```bash
make CruiseControl.xes
```

This will create the executable file `CruiseControl.xes` which you can then run with:

```bash
./CruiseControl.xes
```

## Testing

The system also includes a test suite written in C. You can compile and run the test suite using:

```bash
make test_cruise_control
./test_cruise_control
```
This will output any failed assertions during the tests, helping to verify the system's correctness.

## Test Suite

The test suite `test_cruise_control.c` includes various scenarios to validate the functionality of the Cruise Control System. It asserts the behavior of the system in different scenarios and helps identify any deviations from the expected output.
## Contributing

Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.
