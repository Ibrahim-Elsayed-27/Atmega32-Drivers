# ATmega32 Drivers Library

Welcome to the ATmega32 Drivers Library! This repository contains a comprehensive collection of drivers tailored for interfacing with the ATmega32 microcontroller, one of the most popular 8-bit AVR microcontrollers from Atmel. These drivers aim to simplify development tasks by providing an easy-to-use API for accessing the fundamental hardware features and peripherals of the ATmega32.

## Repository Structure

This repository is organized into three main directories:

### 1. MCAL (Microcontroller Abstraction Layer)
This layer provides direct interaction with the ATmega32 hardware and includes drivers for all basic microcontroller peripherals.

- **ADC** - Analog-to-Digital Converter
- **DIO** - Digital Input/Output
- **EEPROM** - Electrically Erasable Programmable Read-Only Memory
- **EXTERNAL INTERRUPT** - External Interrupts Handling
- **I2C** - Inter-Integrated Circuit Communication
- **SPI** - Serial Peripheral Interface
- **TIMER0, TIMER1, TIMER2** - Timers and Counters
- **USART** - Universal Synchronous and Asynchronous Serial Receiver and Transmitter
- **WATCHDOG** - Watchdog Timer

### 2. HAL (Hardware Abstraction Layer)
This layer includes modules that provide simplified interfaces to common hardware components.

- **7-SEG** - Seven Segment Display
- **Buzzer**
- **KEYPAD**
- **LCD** - Liquid Crystal Display
- **LED**
- **LM35** - Temperature Sensor
- **Switch**

### 3. LIB
This directory includes common libraries and macros used across different modules.

- **Std_Macros.h** - Standard macros for bit manipulation, etc.

### Prerequisites
Ensure you have a suitable development environment for ATmega32, such as Atmel Studio, AVR-GCC compiler, and an AVR programmer (like USBasp).

### Installation
1. Clone the repository to your local machine:
   ```bash
   git clone https://github.com/Ibrahim-Elsayed-27/Atmega32-Drivers
