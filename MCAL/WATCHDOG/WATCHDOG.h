/*
 * WATCHDOG.h
 *
 * Created: 9/30/2023 6:46:50 PM
 *  Author: himah
 */ 


#ifndef WATCHDOG_H_
#define WATCHDOG_H_

#include "../../Std_Macros.h"


/*Registers*/
#define WDTCR_REG *((volatile uint8*) 0x41)

/*BITS*/
    
#define WDP0_BIT	0
#define WDP1_BIT	1
#define WDP2_BIT	2
#define WDE_BIT		3
#define WDTOE_BIT	4




#define CYCLE_16_k		0
#define CYCLE_32_k		1
#define CYCLE_64_k		2
#define CYCLE_128_k		3
#define CYCLE_256_k		4
#define CYCLE_512_k		5
#define CYCLE_1024_k	6
#define CYCLE_2048_k	7

void watchdog_init(uint8 configuration);
void watchdog_enable();
void watchdog_disable();


#endif /* WATCHDOG_H_ */