#include "adc.h"
#include "config.h"
#include <xc.h>

void adc_init(void) {
    /* ADCON1 Configuration
     * Bit 7 : ADFM = 1 (right justified)
     * Bit 3-0 : PCFG = 1110 (AN0 as analog, others as digital)
    */
    ADCON1 = 0x8E;
    
    /* ADCON0 Configuration
     * Bit 7-6 : ADCS = 10 (Fosc = 1/32 for 20MHz to respect TAd > 1.6us)
     * Bit 0 : ADON = 1 (Turn ADC module)
    */
    ADCON0 = 0x81; 
}

uint16_t adc_read(uint8_t channel) {
    /* Channel Configuration
     * Clear the channel bits : bits 5-3
     * Set new channel
    */
    ADCON0 &= ~(7U << 3);
    ADCON0 |= (channel << 3);
    __delay_ms(20);
    ADCON0bits.GO = 1; // Start conversion
    while(ADCON0bits.GO_nDONE); // Wait the conversion to complete
    return (uint16_t)((ADRESH << 8) + ADRESL); // Return the 10-bit result
}
