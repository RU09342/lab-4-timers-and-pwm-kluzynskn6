#include <msp430.h>

//Timer macros
//TA0
#define TA0SET(x) TA0CCTL0 = CCIE;TA0CTL = TASSEL_2 + MC_1 + ID_3; TA0CCR0 = 125000/x;
#define TA0STOP TA0CTL=MC_0
#define TA0START TA0CTL = TASSEL_2 + MC_1 + ID_3
//TA1
#define TA1SET(x) TA1CCTL0 = CCIE;TA1CTL = TASSEL_2 + MC_1 + ID_3; TA1CCR0 = 125000/x;
#define TA1STOP TA1CTL=MC_0;
#define TA1START TA1CTL = TASSEL_2 + MC_1 + ID_3
//TB0
#define TB0SET(x) TB0CCTL0 = CCIE;TB0CTL = TBSSEL_2 + MC_1 + ID_3; TB0CCR0 = 125000/x;
#define TB0STOP TB0CTL=MC_0
#define TB0START TB0CTL = TBSSEL_2 + MC_1 + ID_3
//TB1
#define TB1SET(x) TB1CCTL0 = CCIE;TB1CTL = TBSSEL_2 + MC_1 + ID_3; TB1CCR0 = 125000/x;
#define TB1STOP TB1CTL=MC_0;
#define TB1START TB1CTL = TBSSEL_2 + MC_1 + ID_3

//Pin marcos per board
#ifdef __MSP430F5529__
	#define LED1INIT P1SEL&=~BIT0; P1DIR|=BIT0
	#define LED1ON P1OUT |= BIT0
	#define LED1OFF P1OUT &=~BIT0
	#define LED1SWITCH P1OUT ^=BIT0

	#define LED2INIT P4SEL&=~BIT7; P4DIR|=BIT7
	#define LED2ON P4OUT |= BIT7
	#define LED2OFF P4OUT &=~BIT7
	#define LED2SWITCH P4OUT ^=BIT7

	#define BTN1INIT P2DIR &= 0xFD;P2REN |= 0x02;P2OUT |= 0x02;P2IE |= 0x02; P2IES |= 0x02;P2IFG &= 0xFD;
	#define BTN1UP ((P2IN & BIT1) == BIT1)
	#define BTN1CLR P2IFG &=~BIT1
	#define BTN1SWAP P2IES ^= BIT1

	#define BTN2INIT P1DIR &= 0xFD;P1REN |= 0x02;P1OUT |= 0x02;P1IE |= 0x02; P1IES |= 0x02;P1IFG &= 0xFD;
	#define BTN2UP ((P1IN & BIT1) == BIT1)
	#define BTN2CLR P1IFG &=~BIT1
	#define BTN2SWAP P1IES ^= BIT1
#endif // _MSP430F5529_

#ifdef __MSP430G2553__
	#define LED1INIT P1SEL&=~BIT0; P1DIR|=BIT0
	#define LED1ON P1OUT |= BIT0
	#define LED1OFF P1OUT &=~BIT0
	#define LED1SWITCH P1OUT ^=BIT0

	#define LED2INIT P1SEL&=~BIT6; P1DIR|=BIT6
	#define LED2ON P1OUT |= BIT6
	#define LED2OFF P1OUT &=~BIT6
	#define LED2SWITCH P1OUT ^=BIT6

	#define BTN1INIT P1DIR &= ~BIT3; P1REN |= BIT3; P1OUT |= BIT3; P1IE |= BIT3; P1IES |= BIT3;P1IFG &= ~BIT3
	#define BTN1UP ((P1IN & BIT3) == BIT3)
	#define BTN1CLR P1IFG &=~BIT3
	#define BTN1SWAP P1IES ^= BIT3
#endif // _MSP430G2553_

#ifdef __MSP430FR5994__
	#define LED1INIT P1SEL0 &=~BIT0; P1DIR|=BIT0
	#define LED1ON P1OUT |= BIT0
	#define LED1OFF P1OUT &=~BIT0
	#define LED1SWITCH P1OUT ^=BIT0

	#define LED2INIT P1SEL0&=~BIT1; P1DIR|=BIT1
	#define LED2ON P1OUT |= BIT1
	#define LED2OFF P1OUT &=~BIT1
	#define LED2SWITCH P1OUT ^=BIT1

	#define BTN1INIT P5DIR &= ~BIT6;P5REN |= BIT6;P5OUT |= BIT6;P5IE |= BIT6; P5IES |= BIT6;P5IFG &=~BIT6;
	#define BTN1UP ((P5IN & BIT6) == BIT6)
	#define BTN1CLR P5IFG &=~BIT6
	#define BTN1SWAP P5IES ^= BIT6

	#define BTN2INIT P5DIR &= ~BIT5;P5REN |= BIT5;P5OUT |= BIT5;P5IE |= BIT5; P5IES |= BIT5;P5IFG &=~BIT5;
	#define BTN2UP ((P5IN & BIT5) == BIT5)
	#define BTN2CLR P5IFG &=~BIT5
	#define BTN2SWAP P5IES ^=BIT5
#endif // _MSP430FR5994_

#ifdef __MSP430FR2311__
	#define LED1INIT P1SEL0 &=~BIT0; P1DIR|=BIT0
	#define LED1ON P1OUT |= BIT0
	#define LED1OFF P1OUT &=~BIT0
	#define LED1SWITCH P1OUT ^=BIT0

	#define LED2INIT P2SEL0 &=~BIT0; P2DIR|=BIT0
	#define LED2ON P2OUT |= BIT0
	#define LED2OFF P2OUT &=~BIT0
	#define LED2SWITCH P2OUT ^=BIT0

	#define BTN1INIT P1DIR &= ~BIT1;P1REN |= BIT1;P1OUT |= BIT1;P1IE |= BIT1; P1IES |= BIT1;P1IFG &=~BIT1
	#define BTN1UP ((P1IN & BIT1) == BIT1)
	#define BTN1CLR P1IFG &=~BIT1
	#define BTN1SWAP P1IES ^= BIT1

#endif // _MSP430FR2311_

#ifdef __MSP430FR6989__
	#define LED1INIT P1SEL0 &=~BIT0; P1DIR|=BIT0
	#define LED1ON P1OUT |= BIT0
	#define LED1OFF P1OUT &=~BIT0
	#define LED1SWITCH P1OUT ^=BIT0

	#define LED2INIT P9SEL0 &=~BIT7; P9DIR|=BIT7
	#define LED2ON P9OUT |= BIT7
	#define LED2OFF P9OUT &=~BIT7
	#define LED2SWITCH P9OUT ^=BIT7

	#define BTN1INIT P1DIR &= ~BIT1;P1REN |= BIT1;P1OUT |= BIT1;P1IE |= BIT1; P1IES |= BIT1;P1IFG &=~BIT1;
	#define BTN1UP ((P1IN & BIT1) == BIT1)
	#define BTN1CLR P1IFG &=~BIT1
	#define BTN1SWAP P1IES ^= BIT1

	#define BTN2INIT P1DIR &= ~BIT2;P1REN |= BIT2;P1OUT |= BIT2;P1IE |= BIT2; P1IES |= BIT2;P1IFG &=~BIT2;
	#define BTN2UP ((P1IN & BIT2) == BIT2)
	#define BTN2CLR P1IFG &=~BIT2
	#define BTN2SWAP P1IES ^= BIT2


#endif // _MSP430FR6989_
