#include <msp430.h> 
#include <config.h>
#include <math.h>

int count=5;

void main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5; //disables high impedence mode

    LED1INIT;
    LED2INIT;
    LED2OFF;
    BTN1INIT;

    TB0CTL = TBSSEL_2 + MC_1; //Sets Timer A0 to SMCLK

    TB0CCTL0 = CCIE; //Enables CCR0 interrupt
    TB0CCR0 = 1000; //Sets CCR0 to 1 kHz

    TB0CCTL1 = CCIE; //Enables CCR1 interrupt
    TB0CCR1 = 500; //Sets CCR1 to .5 kHz

    _BIS_SR(LPM0_bits+GIE);

}

#pragma vector=PORT1_VECTOR
__interrupt void button (void)
{

        if(count==10)
        {
            count=0;
            TB0CCR1=0;
        }
        else
        {
            count++;
            TB0CCR1 = count*100; //Increments CCR1 by .1 kHz
            //TB0CCR1 =  2^count; //Increments CCR1 exponentially
        }

    LED2SWITCH;

    BTN1CLR;//clear ifg
}

#pragma vector=TIMER0_B0_VECTOR
__interrupt void timerA (void)
{
    if(count!=0)
        LED1ON;
}
#pragma vector=TIMER0_B1_VECTOR
__interrupt void timerA1 (void)
{
    if(count!=10)
        LED1OFF;
    TB0IV=0;
}
