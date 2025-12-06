/*******************************************************************************
 *
 * Description: Include file for application
 *
 * Author: Dang Vu
 *
 * Last Changed By:  $Author: Dang Vu $
 * Revision:         $Revision: 1.0 $
 * Last Changed:     $Date: 12/06/25 $
 *
 ******************************************************************************/

#ifndef DRIVERS_TIMEBASE_H_
#define DRIVERS_TIMEBASE_H_

#include <stdint.h>

void Timebase_Init(void);

uint32_t Millis(void);

void Delay_ms(uint32_t d);

#endif /* DRIVERS_TIMEBASE_H_ */
