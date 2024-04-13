/*
 * WAYCHDOG.c
 *
 * Created: 9/30/2023 6:46:35 PM
 *  Author: himah
 */ 

#include "WATCHDOG.h"

void watchdog_init(uint8 configuration){
	WDTCR_REG |= configuration;
}
void watchdog_enable(){
	SET_BIT(WDTCR_REG,WDE_BIT);
}
void watchdog_disable(){
	SET_BIT(WDTCR_REG,WDE_BIT);
	SET_BIT(WDTCR_REG,WDTOE_BIT);
	CLR_BIT(WDTCR_REG,WDE_BIT);
}