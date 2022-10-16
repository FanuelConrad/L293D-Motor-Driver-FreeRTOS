# L293D Motor Driver - FreeRTOS

## Table of Contents

- [About](#about)
- [Getting Started](#getting_started)
- [Usage](#usage)
- [Contributing](../CONTRIBUTING.md)

## About <a name = "about"></a>

This project is all about spinning a small motor using L923D Motor driver and FreeRTOS.

We will create the SpinClockwise and the SpinAntiClockwise function. These functions will do their respective jobs of spinnig the motor in clockwise and anticlockwise directions.

For Task1 we want the motor to spin in clockwise direction. This function takes in a single global argument called a parameter. First, we will display on the serial monitor the core ID on which the particular task is running. Next, we will use ```for(;;)``` to create an infinite loop where the motor will spin in clockwise direction every 1 second. This will be achieved by using the ```digitalWrite()``` function and passing the GPIO pin connected to pin ```In1``` of the motor driver and ```HIGH``` or ```LOW``` as the second parameter.

## Getting Started <a name = "getting_started"></a>

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes. See [deployment](#deployment) for notes on how to deploy the project on a live system.

### Prerequisites

What things you need to have the project up and running.

```
Visual Studio Code
PlatformIO
ESP32 development board
Breadboard
Motor
Jumper wires

```


## Usage <a name = "usage"></a>

Add notes about how to use the system.
