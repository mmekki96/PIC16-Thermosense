/* 
 * File:   adc.h
 * Author: Mahmoud Mekki
 *
 * Created on 10 janvier 2026, 14:52
 */

#ifndef ADC_H
#define	ADC_H

#include <stdint.h>

// --- Function prototypes ---
void adc_init(void);
uint16_t adc_read(uint8_t channel);

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* ADC_H */

