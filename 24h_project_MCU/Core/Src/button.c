/*
 * button.c
 *
 *  Created on: Nov 5, 2022
 *      Author: legolas
 */

#include "math.h"
#include "main.h"
#include "button.h"
#include "global.h"
#include "display7seg.h"
#include "software_timer.h"
int button_flag[NO_OF_BUTTONS]={0};
int KeyReg0[NO_OF_BUTTONS] = {NORMAL_STATE};
int KeyReg1[NO_OF_BUTTONS] = {NORMAL_STATE};
int KeyReg2[NO_OF_BUTTONS] = {NORMAL_STATE};
int KeyReg3[NO_OF_BUTTONS] = {NORMAL_STATE};
int FlagFor3secPressed[NO_OF_BUTTONS] = {0};
int TimeForKeyPress = 300;

int isButtonPressed3Sec(int index){
	if(index>=NO_OF_BUTTONS) return 0;
	return (FlagFor3secPressed[index]==1);
}
void PressedMoreThan3secKeyProcess(int index){
	switch (index){
	case 1:
		HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
		counter++;
		if(counter>=10) counter=0;
		led7seg(counter);
		break;
	default:
		break;
	}
}
void PressedKeyProcess(int index){
	switch (index){
	case 0:
		button_flag[0]=1;
		led7seg(0);
		counter=0;
		break;
	case 1:
		button_flag[1]=1;
		led7seg(counter++);
		if(counter>=10) counter=0;
		break;
	case 2:
		button_flag[2]=1;
		led7seg(counter--);
		if(counter<0) counter=9;
		break;
	default:
		break;
	}

}

void getKeyInput(){
for(int i=0;i<3;i++){
	KeyReg0[i]=KeyReg1[i];
	KeyReg1[i]=KeyReg2[i];
	KeyReg2[i]=HAL_GPIO_ReadPin(GPIOC, RESET_Pin*pow(2,i));
	if((KeyReg0[i]==KeyReg1[i])&&(KeyReg1[i]==KeyReg2[i])){
		if(KeyReg3[i]!=KeyReg2[i]){
			KeyReg3[i]=KeyReg2[i];
			if(KeyReg2[i]==PRESSED_STATE){
				PressedKeyProcess(i);
				//after 3 sec button change to pressed_more_than_3sec_state
				TimeForKeyPress=300;
				}
		}else{
			TimeForKeyPress--;
			if(TimeForKeyPress==0) {
				//pressed_more_than_3sec_state

				if(KeyReg2[i]==PRESSED_STATE) PressedKeyProcess(i);
				TimeForKeyPress=100;
				}
			}
	}//end if
}//end for

}
