// ユーザインターフェース（マウス、キーの入力）を司るクラス

#ifndef __INCLUDE_INITDEFINE
#define __INCLUDE_INITDEFINE
#include "initDefine.h"
#endif

// 今んとこ入力モードをシューティングとRTSモードに切り替えるだけ

class UserIF {
    InputMode inputMode;
public:
    UserIF() {
        inputMode = Shooting;
    }
    UserIF(InputMode inputmode) {
        inputMode = inputmode;
    }
    InputMode GetInputMode();
    void ChangeInputMode(InputMode im);
};
