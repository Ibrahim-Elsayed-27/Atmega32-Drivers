/*
 * I2C.h
 *
 * Created: 10/12/2023 4:42:12 PM
 *  Author: himah
 */ 


#ifndef I2C_H_
#define I2C_H_

#include "../../Std_Macros.h"


#define TWBR_REG  *((volatile uint8*) 0x20)
#define TWSR_REG   *((volatile uint8*) 0x21)
#define TWAR_REG   *((volatile uint8*) 0x22)
#define TWDR_REG   *((volatile uint8*) 0x21)
#define TWCR_REG   *((volatile uint8*) 0x56)


/*TWAR BITS*/
#define TWPS0_BIT	0
#define TWPS1_BIT	1

/*TWCR BITS*/
#define TWIE_BIT	0
#define TWEN_BIT	2
#define TWWC_BIT	3
#define TWSTO_BIT	4
#define TWSTA_BIT	5
#define TWEA_BIT	6
#define TWINT_BIT	7


#define PRESCALAR   1


#define MASTER_WRITE  0
#define MASTER_READ  1

void i2c_master_init(uint32 scl_clock , uint32 cpu_freq, uint8 master_adress);
void i2c_master_send_address(uint8 adress,uint8 read_or_write);
void i2c_master_send_start();
void i2c_master_send_stop();
void i2c_master_send_data(uint8  data);
void i2c_master_recieve_data(uint8 * recieved_data);

void i2c_slave_init(uint8 slave_adress);
void i2c_slave_send_data(uint8  data);
void i2c_slave_recieve_data(uint8 * recieved_data);


void i2c_error();




#endif /* I2C_H_ */