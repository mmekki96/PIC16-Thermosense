/* 
 * File:   lcd.h
 * Author: Mahmoud Mekki
 *
 * Created on 9 janvier 2026, 15:19
 */

#ifndef LCD_H
#define	LCD_H


#define LCD_DATA_PORT PORTC
#define LCD_TRIS_DATA TRISC

// --- Functions prototypes ---
void lcd_init(void);
void lcd_command(unsigned char cmd);
void lcd_char(unsigned char data);
void lcd_string(const char *str);

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* LCD_H */

