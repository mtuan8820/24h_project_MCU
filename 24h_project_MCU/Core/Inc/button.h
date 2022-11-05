/*
 * button.h
 *
 *  Created on: Nov 5, 2022
 *      Author: legolas
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET

#define NO_OF_BUTTONS 3

extern int button_flag[NO_OF_BUTTONS];//flag for reset button
extern int FlagFor3secPressed[NO_OF_BUTTONS];
int isButtonPressed3Sec(int index);
void getKeyInput();
void PressedKeyProcess(int index);
void PressedMoreThan3secKeyProcess(int index);


#endif /* INC_BUTTON_H_ */
