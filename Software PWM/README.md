# Software PWM
#### Nick Kluzynski
PWMs are used to control the amount of time a signal is passed through per period. This can be used in a variety of ways, but here, it is used to dim an LED. On the MSP430, the timer modules have a PWM mode, but not all microcontrollers do. Here, a PWM is made using the timer module in normal mode, along with code that ties it all together. A button is used to control the PWM settings, and it is outputted onto an LED.

## Usage
The base frequency of the LED is 1kHz. The PWM starts at 50%, and is incremented by 10% on every button press. After reaching 100%, another press will loop it down to 0%. To notify button bounces, the other LED is toggled on button press.

### Implementation
In order for the PWM to operate, 2 interrupts are used on the same timer. The first interrupt turns the LED off, unless it is set to 100%. The second interrupt turns the LED back on again, unless it is at 0%. By leaving the second interrupt at 1 kHz, the first interrupt can be have its compare register altered. This makes the LED turn on and off at different intervals, all while leaving the overall frequency at 1kHz. 

The button has 2 functions: it toggles the LED, and changes the compare register on the first interrupt.
