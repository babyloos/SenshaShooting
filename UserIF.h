// ���[�U�C���^�[�t�F�[�X�i�}�E�X�A�L�[�̓��́j���i��N���X

#ifndef __INCLUDE_INITDEFINE
#define __INCLUDE_INITDEFINE
#include "initDefine.h"
#endif

// ����Ƃ����̓��[�h���V���[�e�B���O��RTS���[�h�ɐ؂�ւ��邾��

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
