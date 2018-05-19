/*
 * timerA0.h
 *
 *  Created on: 24 Feb 2017
 *      Author: aevans
 */

#ifndef INCLUDES_TIMERA0_H_
#define INCLUDES_TIMERA0_H_

//defines

#define HALF_SECOND_DELAY 16383U
#define TASSEL_ACLK (0x0100U)
#define ID_NO_DIVIDE ~(0x00C0U)
#define IDEX_NO_DIVIDE ~(0x0007U)
#define MODE_CONTROL_UP (0x0010U)
#define TIMER_A0_INTERRUPT_DISABLE ~(0x0002U)
#define TIMER_A0_INTERRUPT_FLAG (0x0001U)
#define TIMER_A0_CLEAR_INTERRUPT_FLAG ~(0x0001U)
#define TIMER_A0_START_TIMER (0x0004U)

//function prototypes

void timerA0Init(void);



#endif /* INCLUDES_TIMERA0_H_ */
