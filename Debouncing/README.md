# Software Debouncing
#### Nick Kluzynski
On the MSP430 devices, the buttons avavailable on the device are being used consistently. They have a problem though: the button seems to pressed several times on a single button press. This is not always the case, and its randomness is a heavy concern in these labs. This code will debounce the button, eliminating multi-presses almost entirely

## Usage
Whenever either button is pressed, the LED on that side is toggled. If the button bounces, the LED will switch several times; this should not happen. 

### Implementation
A single timer is used for both buttons. Upon button press, it reads the timer register. If it is 0, then it goes further to check which button was pressed. Even on single button boards, the button ISR still checks to see if the button is pressed, preventing an execution on release.  Different code can be exectued on either button, but for now it toggles 2 different LEDs. After it executes the code. It clears the register flags, disables button interrupts, and starts the timer.

The timer will interrupt after a specified delay, in this case it is set to 1/6th or 1/5th of a second, depending on how bouncy the buttons are. Upon interrupting, the timer stops itself, clears its register again, and reenables button interrupt. 

This effectively creates a passive delay after the buttons are pressed, which waits out any button bouncing. This works for both buttons, and any other interrupt or main code can be executed while it is waiting.

## Known Problems
The timer had to have a very long delay, which may cause intentional double-clicks from passing through. In addition, about 1/15 presses, there is still a single bounce. This is still a major improvement compared to the 7/10 bounces from before, that could even bounce 3 to 4 times on a single press.

