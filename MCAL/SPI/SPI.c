/*
 * SPI.c
 *
 * Created: 10/6/2023 7:16:02 AM
 *  Author: himah
 */ 

#include "SPI.h"
#include "../DIO/DIO.h"


void spi_master_init(){
	
	/*Set master pins*/
	pin_init(PORT_B,PIN4,OUTPUT);
	pin_init(PORT_B,PIN5,OUTPUT);
	pin_init(PORT_B,PIN6,INPUT);
	pin_init(PORT_B,PIN7,OUTPUT);
	
	/*Enable spi*/
	SET_BIT(SPCR_REG,SPE_BIT);
	/*MSB First*/
	CLR_BIT(SPCR_REG,DORD_BIT);
	/*Master mode*/
	SET_BIT(SPCR_REG,MSTR_BIT);
	/*High idle*/
	//SET_BIT(SPCR_REG,CPOL_BIT);
	/*no phase shift*/
	CLR_BIT(SPCR_REG,CPHA_BIT);
	/*Fosc/16*/
	SET_BIT(SPCR_REG,SPR0_BIT);
	CLR_BIT(SPCR_REG,SPR1_BIT);
	CLR_BIT(SPSR_REG,SPI2X_BIT);
	
	pin_write(PORT_B,PIN4,HIGH);
	


}
void spi_slave_init(){
		/*Set slave pins*/
		pin_init(PORT_B,PIN4,INPUT);
		pin_init(PORT_B,PIN5,INPUT);
		pin_init(PORT_B,PIN6,OUTPUT);
		pin_init(PORT_B,PIN7,INPUT);
		
		/*Enable spi*/
		SET_BIT(SPCR_REG,SPE_BIT);
		/*MSB First*/
		CLR_BIT(SPCR_REG,DORD_BIT);
		/*Slave mode*/
		CLR_BIT(SPCR_REG,MSTR_BIT);
		/*High idle*/
		//SET_BIT(SPCR_REG,CPOL_BIT);
		/*no phase shift*/
		CLR_BIT(SPCR_REG,CPHA_BIT);


}
void spi_master_transceiver(uint8 *send_data, uint8 *received_data){
		/*enable slave*/
		pin_write(PORT_B,PIN4,LOW);
		/*sending char*/
		SPDR_REG = *send_data;
		while(GET_BIT(SPSR_REG,SPIF_BIT) == 0);
		*received_data = SPDR_REG;
}
void spi_master_string_transceiver(uint8 *send_data, uint8 *received_data){
			/*enable slave*/
			pin_write(PORT_B,PIN4,LOW);
			/*sending string*/
			while(*send_data != 0){
				SPDR_REG = *send_data;
				while(GET_BIT(SPSR_REG,SPIF_BIT) == 0);
				*received_data = SPDR_REG;
				send_data++;
			}
}
void spi_slave_transceiver(uint8 *send_data, uint8 *received_data){
			/*sending char*/
			SPDR_REG = *send_data;
			while(GET_BIT(SPSR_REG,SPIF_BIT) == 0);
			*received_data = SPDR_REG;
}