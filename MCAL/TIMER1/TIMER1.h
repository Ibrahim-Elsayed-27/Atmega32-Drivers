/*
 * TIMER1.h
 *
 * Created: 9/30/2023 2:15:47 AM
 *  Author: himah
 */ 


#ifndef TIMER1_H_
#define TIMER1_H_

#include "../../Std_Macros.h"


/*Registers*/
#define SREG_REG *((volatile uint8*) 0x5F)
#define TIMSK_REG *((volatile uint8*) 0x59)
#define TIFR_REG *((volatile uint8*) 0x58)
#define TCCR1A_REG *((volatile uint8*) 0x4F)
#define TCCR1B_REG *((volatile uint8*) 0x4E)
#define TCNT1_REG *((volatile uint16*) 0x4C)
#define OCR1A_REG *((volatile uint16*) 0x4A)
#define OCR1B_REG *((volatile uint16*) 0x48)
#define ICR1_REG *((volatile uint16*) 0x46)




/*SREG BITS*/
#define I_BIT 7


/*TCCR1A BITS*/
#define WGM10_BIT	0
#define WGM11_BIT	1
#define FOC1B_BIT	2
#define FOC1A_BIT	3
#define COM1B0_BIT	4
#define COM1B1_BIT	5
#define COM1A0_BIT	6
#define COM1A1_BIT	7


/*TCCR1B BITS*/
#define CS10_BIT	0
#define CS11_BIT	1
#define CS12_BIT	2
#define WGM12_BIT	3
#define WGM13_BIT	4

#define ICES1_BIT	6
#define ICNC1_BIT	7


/*TIMSK BITS*/
#define TOIE1_BIT   2
#define OCIE1B_BIT  3
#define OCIE1A_BIT  4
#define TICIE1_BIT  5



/*TIFR BITS*/
#define TOV1_BIT   2
#define OCF1B_BIT  3
#define OCF1A_BIT  4
#define ICF1_BIT   5

#define FALLING_TRIGGER 0
#define RISING_TRIGGER	1


#define NO_CLOCK			0
#define NO_PRESCALAR		1
#define PRESCALAR_8			2
#define PRESCALAR_64		3
#define PRESCALAR_256		4
#define PRESCALAR_1024		5
#define EXTERNAL_FALLING	6
#define EXTERNAL_RISING		7


void timer1_init();
void timer1_enable();
void timer1_disable();
void timer1_set_callback(void (*callback) (void));
void timer1_set_clock(uint8 configuration);
void timer1_set_trigger(uint8 trigger);




#endif /* TIMER1_H_ */