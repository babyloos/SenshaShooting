#ifndef __INCLUDE_USERIF
#define __INCLUDE_USERIF
#include "UserIF.h"
#endif

InputMode UserIF::GetInputMode() {
   return inputMode; 
}

void UserIF::ChangeInputMode(InputMode im) {
   inputMode = im;
}

