/*
 * File:   main.c
 * Author: Mahmoud Mekki
 * Description: Digital Thermometer Project
 * Created on 10 janvier 2026, 00:41
 */


#include <xc.h>
#include <stdint.h>
#include <stdio.h>
#include "adc.h"
#include "config.h"
#include "lcd.h"

void main(void) {
    uint16_t adcValue;
    float temperature;
    char tempChar[8];
    
    adc_init();
    lcd_init();
    lcd_command(0x80); // Cursor first line
    lcd_string("SENSOR"); // Write "Sensor" at first line
    while(1) {
        adcValue = adc_read(0); // Read from channel AN0
        temperature = adcValue * 0.4887; // Convert to Celsius
        sprintf(tempChar, "%.2f", temperature);
        lcd_command(0xC0);
        lcd_string(tempChar);
        __delay_ms(250);
    }
    
    return;
}
