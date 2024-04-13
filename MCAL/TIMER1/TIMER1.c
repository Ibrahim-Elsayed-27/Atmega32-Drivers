/*
 * TIMER1.c
 *
 * Created: 9/30/2023 2:15:36 AM
 *  Author: himah
 */ 

#include "TIMER1.h"
#include <avr/interrupt.h>

static void (* timer1_callback) (void) = NULL;



void timer1_init(){
	
	//clock source with no prescalar
	SET_BIT(TCCR1B_REG,CS10_BIT);
	CLR_BIT(TCCR1B_REG,CS11_BIT);
	CLR_BIT(TCCR1B_REG,CS12_BIT);

	//Normal mode
	CLR_BIT(TCCR1A_REG,WGM10_BIT);
	CLR_BIT(TCCR1A_REG,WGM11_BIT);
	CLR_BIT(TCCR1B_REG,WGM12_BIT);
	CLR_BIT(TCCR1B_REG,WGM13_BIT);	

	//Normal port operation
	CLR_BIT(TCCR1A_REG,COM1B0);
	CLR_BIT(TCCR1A_REG,COM1B1);
	CLR_BIT(TCCR1A_REG,COM1A0);
	CLR_BIT(TCCR1A_REG,COM1A1);	

	//capture on rising with noise cancel
	SET_BIT(TCCR1B_REG,ICNC1_BIT);
	SET_BIT(TCCR1B_REG,ICES1_BIT);

}

void timer1_enable(){
	SET_BIT(SREG_REG,I_BIT);

	SET_BIT(TIMSK_REG,TICIE1_BIT);
	
}

void timer1_disable(){

	CLR_BIT(TIMSK_REG,TICIE1_BIT);
}

void timer1_set_callback(void (*callback) (void)){
	timer1_callback = callback;
}


void timer1_set_clock(uint8 configuration){
	TCCR1B_REG |= configuration;
}

void timer1_set_trigger(uint8 trigger){
	switch(trigger){
		case RISING_TRIGGER:
			SET_BIT(TCCR1B_REG,ICES1_BIT);
			break;
		case FALLING_TRIGGER:
			CLR_BIT(TCCR1B_REG,ICES1_BIT);
			break;		
	}
}

ISR(TIMER1_CAPT_vect){
	timer1_callback();
}