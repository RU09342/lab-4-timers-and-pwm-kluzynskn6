# Hardware PWM
#### Nick Kluzynski
Now that the software version of PWM is done, the same thing needs to be done, but by utilizing the PWM mode on the timer peripheral. This had to be implemented uniquely on each board, since the PWM pin was different every time, and needed to be redirected to the LED on some boards. Heavy references are made to the software PWM [Here](https://github.com/RU09342/lab-4-timers-and-pwm-kluzynskn6/blob/master/Software%20PWM/README.md)

## Usage
The usage is the same as the software PWM. The overall frequency stays at 1kHz, upon startup, the PWM is set to 50%, and is increased by 10% on button press, looping when it reaches 100%.

## Implementation 
This is where the code differs from the software PWM. Here, the pin specified as TA0.1 is initialized as a peripheral by setting PxSELy, PxDIR. This pin matches the LED on certain boards. The button ISR has the same functionality as before, so on boards with matching PWM and LED pins, all the timer interrupts do is clear the interrupt flag. Disabling the timer interrupts was attempted, but even after resetting the interrupt enable pin, the interrupts continued to throw flags.

On the boards were the PWM pins did not match the LED, the LED pin was set to the PWM pin inside the ISR.

## Future Contributions
When able to, reroute the PWM pins to the LED pin. It is currently unknown as to how to do so, and will be added when known.
