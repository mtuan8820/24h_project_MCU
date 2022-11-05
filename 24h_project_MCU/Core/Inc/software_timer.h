/*
 * software_timer.h
 *
 *  Created on: Nov 5, 2022
 *      Author: legolas
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_
//timer1 is used to increase/decrease counter every sec
//when a button is pressed for more than 3 secs
extern int timer1_flag;
extern int timer1_counter;
//timer 2 is used for  time-out 10 secs event
extern int timer2_flag;
extern int timer2_counter;

void setTimer1(int duration);
void cleanTimer1();
void timer1_run();

void setTimer2(int duration);
void cleanTimer2();
void timer2_run();
#endif /* INC_SOFTWARE_TIMER_H_ */
