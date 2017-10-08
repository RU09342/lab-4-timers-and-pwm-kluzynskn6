#include <msp430.h> 
#include <config.h>

int count=5;

void main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    //PM5CTL0 &= ~LOCKLPM5; //disables high impedence mode

    LED1INIT;
    LED2INIT;
    LED2OFF;
    BTN1INIT;

    P1SEL2&=~BIT6;
    P1SEL|=BIT6;
    P1DIR|=BIT6;

    TA0CTL = TASSEL_2 + MC_1; //Sets Timer A0 to SMCLK

    TA0CCTL0 = CCIE; //Enables CCR0 interrupt
    TA0CCR0 = 1000; //Sets CCR0 to 1 kHz

    TA0CCTL1 = CCIE+OUTMOD_7; //Enables CCR1 interrupt
    TA0CCR1 = 500; //Sets CCR1 to .5 kHz

    _BIS_SR(LPM0_bits+GIE);

    while(1);

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
            //TA0CCR1 = exp(count)/44; //exponentially increases CCR1
        }

    LED1SWITCH;

    BTN1CLR;//clear ifg
}
#pragma vector=TIMER0_A0_VECTOR
__interrupt void timerA (void)
{
    TA0IV=0;
}
#pragma vector=TIMER0_A1_VECTOR
__interrupt void timerA1 (void)
{
    TA0IV=0;
}
