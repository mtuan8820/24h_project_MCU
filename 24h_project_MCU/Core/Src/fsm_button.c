/*
 * fsm_button.c
 *
 *  Created on: Nov 5, 2022
 *      Author: legolas
 */


#include "fsm_button.h"
#include "main.h"
#include "display7seg.h"
#include "global.h"
#include "button.h"
#include "software_timer.h"
void fsm_simple_buttons_run(){
	switch (state){
		case INIT:
			led7seg(8);
			state=SETTING;
			break;
		case SETTING:
			led7seg(counter);
			if(button_flag[0]==1){//RESET BUTTON PRESSED
				button_flag[0]=0;//reset flag for reset_button
				setTimer2(10000);
			}
			else if (button_flag[1]==1){//INCREASE BUTTON PRESSED
				button_flag[1]=0;//reset flag for inc_button
				setTimer2(10000);
			}
			else if (button_flag[2]==1){//DECREASE BUTTON PRESSED
				button_flag[2]=0;//reset flag for dec_button
				setTimer2(10000);
			}

			if(timer2_flag==1) {
				timer2_flag=0;
				counter--;
				state = AUTO_DECREASE;
				setTimer1(1000);}
			break;
		case AUTO_DECREASE:
			led7seg(counter);
			if(timer1_flag==1) {
				counter--;
				if(counter>0) setTimer1(1000);
				else {led7seg(0);state=SETTING;}
			}
			break;
		default:
			break;

	}

}