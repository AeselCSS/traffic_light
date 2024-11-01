# Traffic Light Control System for Arduino

This project simulates a traffic light control system using an Arduino and LEDs. It controls two sets of three LEDs (red, yellow, green) for North/South and East/West directions. The program includes a short delay between changes and an "all-red" phase for safe transitions.

## Prerequisites

- **Hardware**: Arduino (e.g., Arduino Uno), breadboard, 6 LEDs (2 red, 2 yellow, 2 green), resistors, and connecting wires.
- **Software**: 
  - macOS or Linux (other OSs may require adjustments to the Makefile)
  - `make` (to run the Makefile)
  - `avr-gcc` (to compile for AVR microcontrollers)
  - `avrdude` (to upload code to the Arduino)

To install the required software on macOS:
```sh
brew tap osx-cross/avr
brew install make avr-gcc avrdude
```

## Project Structure
```sh
traffic_light/
├── build/                   # Directory for compiled output files
├── include/
│   └── traffic_light.h      # Header file with pin definitions and macros
├── src/
│   └── traffic_light.c      # Main source file with setup and control logic
├── Makefile                 # Makefile for building and uploading the code
└── README.md                # Project documentation
```

## Using the Makefile
This project includes a `Makefile` to automate the build and upload process.

### Compile and Upload
1. Connect your Arduino to your computer via USB.
2. Run the following command to compile and upload the code:
   ```sh
   make all
   ```
   This will:
   - Compile the code into a HEX file.
   - Automatically detect the Arduino's serial port and upload the code using `avrdude`.
   - Clean up generated files

### Other Makefile Commands
#### Compile only
To only compile the code without uploading, run:
```sh
make compile
```

#### Clean up generated files
To delete compiled files in the `build` directory, run:
```sh
make clean
```

## How it works
- The program defines specific pins on Port B (PB0 to PB5) for controlling LEDs.
- The LEDs represent traffic lights for North/South and East/West directions, with an all-red transition phase for safety.
- The `DELAY` macro is used to introduce delays between each state.

## Development Environment
- **Machine Architecture**: x86_64 (Intel-based MacBook Pro)
- **Operating System**: macOS Sequoia 15.0.1
- **Compiler**: avr-gcc 14.1.0 (Homebrew AVR GCC 14.1.0_1)
- **Make Utility**: GNU Make 4.4.1 (installed via Homebrew)
- **Uploader**: avrdude (installed via Homebrew)
- **Target Microcontroller**: Arduino Uno R3 (ATmega328P)
- **USB Serial Port**: `/dev/tty.usbmodemXXXX` (detected automatically in the Makefile)
