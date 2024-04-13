/*
 * uart.c
 *
 * Created: 10/4/2023 6:32:04 PM
 *  Author: himah
 */ 
#include "USART.h"

#include <avr/interrupt.h>

static void (*uart_callback) (uint8 ) = NULL;
void uart_init(uint32 baud_rate, uint32 freq){
	/*Setting baud rate*/
	uint16 ubbr = (freq / (16*baud_rate))-1;
	UBRRL_REG = (uint8) ubbr;
	UBRRH_REG = (uint8) (ubbr >> 8);
	/*Enabling Tx and Rx*/
	SET_BIT(UCSRB_REG, RXEN_BIT);
	SET_BIT(UCSRB_REG, TXEN_BIT);
	
	/*Enabling the recieving interrupt*/
	SET_BIT(UCSRB_REG,RXCIE_BIT);
	/*Setting 8 bits for data frame and one stop bit*/

	UCSRC_REG = (1<<URSEL_BIT) | (1<<UCSZ0_BIT) | (1<<UCSZ1_BIT);

}
void uart_send_char(uint8 data){
		while(GET_BIT(UCSRA_REG,UDRE_BIT) == 0);
		UDR_REG = data;
}
void uart_send_string(uint8 *ptr){
	
	while(*ptr != 0){
		while(GET_BIT(UCSRA_REG,UDRE_BIT) == 0);
		UDR_REG = *ptr;
		ptr++;
	}
}
void uart_receive_char(uint8 *data){
	while(GET_BIT(UCSRA_REG,RXC_BIT) == 0);
	*data = UDR_REG;
}



void uart_set_callback( void (*callback) (uint8) ){
	uart_callback = callback;
}

ISR(USART_RXC_vect){
	uint8 data;
	data=UDR_REG;
	uart_callback(data);
}