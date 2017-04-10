/* Project:	SmartModule
 * File:	button.h
 * Author:	Jonathan Ruisi
 * Created:	December 20, 2016, 7:52 PM
 */

#ifndef BUTTON_H
#define BUTTON_H

#include <stdbool.h>
#include "utility.h"

// DEFINITIONS-----------------------------------------------------------------
// Button timing (ms)
#define DEBOUNCE_DELAY	5
#define HOLD_DELAY		500

// TYPE DEFINITIONS------------------------------------------------------------

typedef enum
{
	BTN_PRESS, BTN_HOLD, BTN_RELEASE
} ButtonStates;

typedef struct ButtonInfo
{
	unsigned long int timestamp;
	ButtonStates currentState;
	unsigned isDebouncing : 1;
	unsigned isUnhandled : 1;
	unsigned currentLogicLevel : 1;
	unsigned previousLogicLevel : 1;
	Action pressAction;
	Action holdAction;
	Action releaseAction;
} ButtonInfo;

// FUNCTION PROTOTYPES---------------------------------------------------------
void ButtonInfoInitialize(volatile ButtonInfo* button,
						  Action pressAction, Action holdAction, Action releaseAction,
						  bool activeLogicLevel);
void CheckButtonState(volatile ButtonInfo* buttonInfo, bool currentLogicLevel);
void UpdateButton(volatile ButtonInfo* buttonInfo);
void ButtonPress(void);
void ButtonHold(void);
void ButtonRelease(void);

#endif