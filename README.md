# xmc1400_button_control_led_UART_transmit



This repository contains a xmc1400 application developed using the DAVE IDE. The application handles pushbuttons, LEDs, and UART communication. It provides different LED modes based on button presses and can transmit data over UART.

## Prerequisites

Before using this application, ensure you have the following:

- DAVE IDE or compatible development environment.
- An XMC microcontroller compatible with the provided code.
- Appropriate hardware setup with pushbuttons, LEDs, and UART interface.

## Features

- Multiple LED modes based on pushbutton presses.
- UART communication to transmit data.
- Flexible code structure for easy customization.

## Usage

1. Clone or download this repository to your development environment.
2. Open the project in your DAVE IDE and configure it for your target hardware.
3. Build and flash the application to your XMC microcontroller.

### Pushbutton Functionality

- Press the pushbutton connected to `DIGITAL_IO_2` to cycle through LED modes.
- In LED mode 1, press `DIGITAL_IO_0` or `DIGITAL_IO_1` to trigger specific actions.

### LED Modes

- **LED Mode 1**: Based on pushbutton presses.
- **LED Mode 2**: Customizable for other functionality.

### UART Communication

- The application transmits data over UART. Configure UART parameters as needed.



## Author

- Nishadh Hussain nishadh2000@gmail.com

## Contributing

If you'd like to contribute to this project, please follow these steps:

1. Fork this repository.
2. Create a new branch for your feature or bug fix.
3. Make your changes and commit them to your branch.
4. Create a pull request to submit your changes for review.

## Contact

If you have any questions or need assistance with this project, feel free to contact the maintainers:

-Nishadh Hussain nishadh2000@gmail.com

## Acknowledgments

This project is built on top of the DAVE IDE and the XMC microcontroller platform.


