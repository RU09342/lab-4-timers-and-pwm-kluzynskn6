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

    TA0CTL = TASSEL_2 + MC_1; //Sets Timer A0 to SMCLK

    TA0CCTL0 = CCIE; //Enables CCR0 interrupt
    TA0CCR0 = 1000; //Sets CCR0 to 1 kHz

    TA0CCTL1 = CCIE; //Enables CCR1 interrupt
    TA0CCR1 = 500; //Sets CCR1 to .5 kHz

    _BIS_SR(LPM0_bits+GIE);

}

#pragma vector=PORT1_VECTOR
__interrupt void button (void)
{

        if(count==10)
        {
            count=0;
            TA0CCR1=0;
        }
        else
        {
            count++;
            TA0CCR1 = count*100; //Increments CCR1 by .1 kHz
            //TA0CCR1 = exp(count)/44; //Increments CCR1 by .1 kHz
        }

    LED2SWITCH;

    BTN1CLR;//clear ifg
}

#pragma vector=TIMER0_A0_VECTOR
__interrupt void timerA (void)
{
    if(count!=0)
        LED1ON;
}
#pragma vector=TIMER0_A1_VECTOR
__interrupt void timerA1 (void)
{
    if(count!=10)
        LED1OFF;
    TA0IV=0;
}
