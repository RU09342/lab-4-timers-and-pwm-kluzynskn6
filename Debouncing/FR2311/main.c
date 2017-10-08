#include <msp430.h> 
#include <config.h>

int test;
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5; //disables high impedence mode

    LED1INIT;
    LED2INIT;
    BTN1INIT;

    TB0SET(4);
    TB0STOP; //Stops timer
    TB0R=0;

    _BIS_SR(LPM0_bits+GIE);

    return 0;
}
#pragma vector=PORT1_VECTOR
__interrupt void Debouncer (void)
{

    if(TB0R==0)
    {
        if(!BTN1UP)
        {
            LED1SWITCH;
            //Whatever you want on the button press
        }
    }
    BTN1CLR;
    P1IE  &= ~BIT1;

    TB0CTL = TBSSEL_2 + MC_1 + ID_3;
}

#pragma vector=TIMER0_B0_VECTOR
__interrupt void timerA (void)
{
    TB0STOP;
    P1IE |= BIT1;
    TB0R=0;
}
