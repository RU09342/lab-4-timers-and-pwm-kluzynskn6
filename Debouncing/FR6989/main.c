#include <msp430.h> 
#include <config.h>

int test;
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5; //disables high impedence mode

    LED1INIT;
    LED2INIT;
    BTN1INIT;
    BTN2INIT;

    TA0SET(6);
    TA0STOP; //Stops timer
    TA0R=0;

    _BIS_SR(LPM0_bits+GIE);

	return 0;
}
#pragma vector=PORT1_VECTOR
__interrupt void Debouncer (void)
{

    if(TA0R==0)
    {
        if(!BTN1UP) //If that button is pressed
        {
            LED1SWITCH;
            //Whatever you want on the button press
        }
        else if(!BTN2UP)
        {
            LED2SWITCH;
            //Whatever you want on the button press
        }
    }
    BTN1CLR;
    BTN2CLR;
    P1IE  &= ~BIT1;
    P1IE  &= ~BIT2;

       TA0CTL = TASSEL_2 + MC_1 + ID_3;
}

#pragma vector=TIMER0_A0_VECTOR
__interrupt void timerA (void)
{
    TA0STOP;
    P1IE |= BIT1;
    P1IE |= BIT2;
    TA0R=0;
}
