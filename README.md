# PIC16-LM35-LCD-Library

A modular and professional C implementation of a digital thermometer using the **PIC16F877** microcontroller, an **LM35** temperature sensor, and a **16x2 LCD** display.



## 📌 Project Overview
This project demonstrates how to interface an analog temperature sensor (LM35) with a PIC microcontroller using modular programming. Instead of a single messy file, the project is divided into dedicated drivers for the ADC and the LCD, making the code reusable for other embedded applications.

## 🛠️ Hardware Specifications
- **Microcontroller**: PIC16F877
- **Sensor**: LM35 (Linear +10mV/°C)
- **Display**: 16x2 Alphanumeric LCD (8-bit mode)
- **Clock**: 20MHz Crystal Oscillator

## 📁 File Structure
- `src/main.c`: Core logic and temperature processing.
- `src/adc.c` & `inc/adc.h`: Modular driver for the Analog-to-Digital Converter.
- `src/lcd.c` & `inc/lcd.h`: Modular driver for the LCD display.
- `inc/config.h`: Microcontroller configuration bits and system clock definition.

## ⚙️ Technical Details
### ADC Configuration
To ensure accuracy and stability in Proteus and real hardware:
- **Tad**: Configured to $F_{OSC}/32$ to respect the minimum $1.6\mu s$ requirement.
- **Acquisition Time**: A $20\mu s$ delay is implemented before each conversion to properly charge the sampling capacitor.

### Formula
The temperature is derived using:
$$\text{Temperature (°C)} = \frac{\text{ADC Value} \times (5000\text{mV} / 1023)}{10\text{mV/°C}} \approx \text{ADC Value} \times 0.4887$$

## 🚀 How to Use
1. Clone the repository.
2. Open the project in **MPLAB X IDE**.
3. Compile using the **XC8 Compiler**.
4. Load the generated `.hex` file into your PIC16F877A (Proteus or real hardware).

## 📝 License
This project is licensed under the MIT License.

## 🧪 Simulation
Below is a preview of the project running in **Proteus**. This simulation demonstrates the real-time interaction between the LM35 sensor, the PIC16F877A microcontroller, and the 16x2 LCD display.

![Simulation Screenshot](https://github.com/mmekki96/PIC16-Thermosense/blob/d32f249a81850f3803df240820362ad2e46d01ee/Simulation.PNG)
