/*
 * I2C.c
 *
 * Created: 10/12/2023 4:41:25 PM
 *  Author: himah
 */ 

#include "I2C.h"


void i2c_master_init(uint32 scl_clock , uint32 cpu_freq, uint8 master_adress){
		TWAR_REG = master_adress | 0x01;
		
		TWBR_REG = (uint8)(((cpu_freq/scl_clock)-16) / 2*PRESCALAR);
		
		switch(PRESCALAR){
			case 1:
				CLR_BIT(TWSR_REG,TWPS0_BIT);
				CLR_BIT(TWSR_REG,TWPS1_BIT);
				break;
			case 4:
				SET_BIT(TWSR_REG,TWPS0_BIT);
				CLR_BIT(TWSR_REG,TWPS1_BIT);
				break;
			case 16:
				CLR_BIT(TWSR_REG,TWPS0_BIT);
				SET_BIT(TWSR_REG,TWPS1_BIT);
				break;
			case 64:
				SET_BIT(TWSR_REG,TWPS0_BIT);
				SET_BIT(TWSR_REG,TWPS1_BIT);
				break;
		}
}

void i2c_master_send_start(){
		TWCR_REG = (1<<TWINT_BIT) | (1<<TWEN_BIT) | (1<<TWSTA_BIT);
		while(GET_BIT(TWCR_REG,TWINT_BIT) == 0);
		if ((TWSR_REG & 0xF8) != 0x08){
			i2c_error();
		}
}


void i2c_master_send_address(uint8 adress,uint8 read_or_write){
	switch(read_or_write){
		case  MASTER_WRITE:
				TWDR_REG = adress ;
				CLR_BIT(TWDR_REG,BIT0);
				TWCR_REG = (1<<TWINT_BIT) | (1<<TWEN_BIT);
				while(GET_BIT(TWCR_REG,TWINT_BIT) == 0);
				if ((TWSR_REG & 0xF8) != 0x18){
					i2c_error();
				}
				break;
		case MASTER_READ:
				TWDR_REG = adress;
				SET_BIT(TWDR_REG,BIT0);
				TWCR_REG = (1<<TWINT_BIT) | (1<<TWEN_BIT);
				while(GET_BIT(TWCR_REG,TWINT_BIT) == 0);
				if ((TWSR_REG & 0xF8) != 0x40){
					i2c_error();
				}
				break;
	}
}
void i2c_master_send_stop(){
	TWCR_REG = (1<<TWINT_BIT) | (1<<TWEN_BIT) | (1<<TWSTO_BIT);
}

void i2c_master_send_data(uint8 data){
		TWDR_REG = data;
		TWCR_REG = (1<<TWINT_BIT) | (1<<TWEN_BIT);
		while(GET_BIT(TWCR_REG,TWINT_BIT) == 0);
		if ((TWSR_REG & 0xF8) != 0x28){
			i2c_error();
		}
}
void i2c_master_recieve_data(uint8 * recieved_data){
		TWCR_REG = (1<<TWINT_BIT) | (1<<TWEN_BIT) | (1<<TWEA_BIT);
		while(GET_BIT(TWCR_REG,TWINT_BIT) == 0);
		if ((TWSR_REG & 0xF8) != 0x50){
			i2c_error();
		}
		*recieved_data = TWDR_REG;
}


void i2c_slave_init(uint8 slave_adress){
	TWAR_REG = slave_adress | 0x01;
}
void i2c_slave_send_data(uint8  data){
		TWCR_REG = (1<<TWINT_BIT) | (1<<TWEN_BIT) | (1<<TWEA_BIT);
		while(GET_BIT(TWCR_REG,TWINT_BIT) == 0);
		if ((TWSR_REG & 0xF8) != 0xA8){
			i2c_error();
		}
		TWDR_REG = data;
		TWCR_REG = (1<<TWINT_BIT) | (1<<TWEN_BIT) | (1<<TWEA_BIT);
		while(GET_BIT(TWCR_REG,TWINT_BIT) == 0);
		if ((TWSR_REG & 0xF8) != 0xB8){
			i2c_error();
		}
}
void i2c_slave_recieve_data(uint8 * recieved_data){
		TWCR_REG = (1<<TWINT_BIT) | (1<<TWEN_BIT) | (1<<TWEA_BIT);
		while(GET_BIT(TWCR_REG,TWINT_BIT) == 0);
		if ((TWSR_REG & 0xF8) != 0x60){
			i2c_error();
		}
		TWCR_REG = (1<<TWINT_BIT) | (1<<TWEN_BIT) | (1<<TWEA_BIT);
		while(GET_BIT(TWCR_REG,TWINT_BIT) == 0);
		if ((TWSR_REG & 0xF8) != 0x80){
			i2c_error();
		}
		*recieved_data = TWDR_REG;
}

void i2c_error(){
	;
}