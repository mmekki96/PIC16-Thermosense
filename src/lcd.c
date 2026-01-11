#include <xc.h>
#include "config.h"
#include "lcd.h"

// --- LCD Macros ---
#define LCD_DATA_PORT PORTC
#define LCD_TRIS_DATA TRISC

#define RS PORTDbits.RD0
#define RW PORTDbits.RD1
#define EN PORTDbits.RD2

#define RS_TRIS TRISDbits.TRISD0
#define RW_TRIS TRISDbits.TRISD1
#define EN_TRIS TRISDbits.TRISD2

// --- Functions Definition ---
void lcd_command(unsigned char cmd) {
    LCD_DATA_PORT = cmd;
    RS = 0;
    RW = 0;
    EN = 1;
    __delay_ms(1);
    EN = 0;
    __delay_ms(3);
}

void lcd_char(unsigned char data) {
    LCD_DATA_PORT = data;
    RS = 1;
    RW = 0;
    EN = 1;
    __delay_ms(1);
    EN = 0;
    __delay_ms(3);
}

void lcd_string(const char *str) {
    while((*str) != '\0') {
        lcd_char(*str);
        str++;
    }
}

void lcd_init(void) {
    LCD_TRIS_DATA = 0x00;
    RS_TRIS = 0;
    RW_TRIS = 0;
    EN_TRIS = 0;
    __delay_ms(10); // LCD power-up
    lcd_command(0x38); // 8-bit mode, 2 lines and 5x7 matrix
    lcd_command(0x0C); // Display on, Cursor off
    lcd_command(0x18); // Shift the display to the left
    lcd_command(0x01); // Clear display
    __delay_ms(2);
}
