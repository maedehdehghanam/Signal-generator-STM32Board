# SPI Communication between Two STM32 Boards using Proteus and Keil

This project demonstrates the communication between two STM32 microcontroller boards using the Serial Peripheral Interface (SPI) protocol. The SPI protocol allows for full-duplex, synchronous communication between a master and one or more slave devices. The project utilizes Proteus for simulation and Keil as the development environment, along with the STM32 HAL (Hardware Abstraction Layer) library for firmware development.

## Hardware Requirements

- Two STM32 microcontroller boards (e.g., STM32F4 Discovery boards).
- Jumper wires for connecting the boards.
- USB cables for power and programming.

## Software Requirements

- Proteus for simulation (Proteus Professional and ISIS software).
- Keil MDK (Microcontroller Development Kit) for firmware development.
- STM32Cube firmware package for the respective STM32 boards.
![image](https://github.com/maedehdehghanam/Signal-generator-STM32Board/assets/81408402/689c816c-c2f5-42b0-8b94-c5310deb279e)

## Configuration

1. In the firmware code, configure one board as the SPI master and the other as the SPI slave using the STM32 HAL library.
   - Set the SPI master's NSS pin as output and keep it high when not using the bus.
   - Configure the SPI slave's NSS pin as an input.
   - Configure the data frame format, clock polarity, and clock phase according to the desired settings using the HAL library functions.

2. Implement the corresponding SPI initialization and communication routines on both boards using the HAL library.
   - Initialize the SPI peripheral with the appropriate settings using the HAL library functions.
   - Implement functions to send and receive data over SPI using the HAL library functions.

## Usage

1. Upon successful setup and configuration, the master board can send SPI commands or data to the slave board.
   - Use the master board to initiate communication by sending commands or data using the HAL library functions.
   - Implement appropriate handling on the slave board to receive and process the commands or data using the HAL library functions.

2. Customize the firmware to perform the desired actions based on the received commands or data.
   - Implement the necessary logic on both boards to interpret and respond to the received SPI messages.
   - Handle any error conditions or exceptional cases during SPI communication.

## Resources

- STM32Cube firmware package and examples: [Link to STM32Cube firmware package](https://www.st.com/en/embedded-software/stm32cube.html)
- Proteus software for simulation: [Link to Proteus software](https://www.labcenter.com/)
- Keil MDK for firmware development: [Link to Keil MDK](https://www.keil.com/)

## License

This project is licensed under the [MIT License](LICENSE). You are free to use, modify, and distribute the codebase as per the terms of the license.
