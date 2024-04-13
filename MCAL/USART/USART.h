/*
 * USART.h
 *
 * Created: 10/4/2023 6:32:15 PM
 *  Author: himah
 */ 


#ifndef USART_H_
#define USART_H_

#include "../../Std_Macros.h"


#define UBRRH_REG  *((volatile uint8*) 0x40)
#define UBRRL_REG   *((volatile uint8*) 0x29)
#define UCSRC_REG   *((volatile uint8*) 0x40)
#define UCSRB_REG   *((volatile uint8*) 0x2A)
#define UCSRA_REG   *((volatile uint8*) 0x2B)

#define UDR_REG   *((volatile uint8*) 0x2C)

      
/*UCSRA BITS*/
#define MPCM_BIT	0
#define U2X_BIT		1
#define PE_BIT		2
#define DOR_BIT		3
#define FE_BIT		4
#define UDRE_BIT	5
#define TXC_BIT		6
#define RXC_BIT		7

       
/*UCSRB BITS*/
#define TXB8_BIT		0
#define RXB8_BIT		1
#define UCSZ2_BIT		2
#define TXEN_BIT		3
#define RXEN_BIT		4
#define UDRIE_BIT		5
#define TXCIE_BIT		6
#define RXCIE_BIT		7

    
/*UCSRC BITS*/
#define UCPOL_BIT		0
#define UCSZ0_BIT		1
#define UCSZ1_BIT		2
#define USBS_BIT		3
#define UPM0_BIT		4
#define UPM1_BIT		5
#define UMSEL_BIT		6
#define URSEL_BIT		7


void uart_init(uint32 baud_rate, uint32 freq);
void uart_send_char(uint8 data);
void uart_send_string(uint8 *ptr);
void uart_receive_char(uint8 *data);
void uart_set_callback( void (*callback) (uint8) );


#endif /* USART_H_ */