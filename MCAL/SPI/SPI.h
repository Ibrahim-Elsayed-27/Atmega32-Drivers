/*
 * SPI.h
 *
 * Created: 10/6/2023 7:16:13 AM
 *  Author: himah
 */ 


#ifndef SPI_H_
#define SPI_H_

#include "../../Std_Macros.h"


#define SPCR_REG  *((volatile uint8*) 0x2D)
#define SPSR_REG   *((volatile uint8*) 0x2E)
#define SPDR_REG   *((volatile uint8*) 0x2F)


/*SPCR BITS*/
#define SPR0_BIT	0
#define SPR1_BIT	1
#define CPHA_BIT	2
#define CPOL_BIT	3
#define MSTR_BIT	4
#define DORD_BIT	5
#define SPE_BIT		6
#define SPIE_BIT	7



/*SPSR BITS*/
#define SPI2X_BIT	0
#define WCOL_BIT	6
#define SPIF_BIT	7

void spi_master_init();
void spi_slave_init();
void spi_master_transceiver(uint8 *send_data, uint8 *received_data);
void spi_master_string_transceiver(uint8 *send_data, uint8 *received_data);
void spi_slave_transceiver(uint8 *send_data, uint8 *received_data);

#endif /* SPI_H_ */