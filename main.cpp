#include <iostream>

#ifndef __INCLUDE_DXLIB
#define __INCLUDE_DXLIB
#include "DxLib.h"
#endif

#ifndef __INCLUDE_STDLIB
#define __INCLUDE_STDLIB
#include <stdlib.h>
#endif

#ifndef __INCLUDE_MYLIB
#define __INCLUDE_MYLIB
#include "mylib.h"
#endif

#ifndef __INCLUDE_GAMEMAIN
#define __INCLUDE_GAMEMAIN
#include "GameMain.h"
#endif

#ifndef __INCLUDE_INITDEFINE
#define __INCLUDE_INITDEFINE
#include "initDefine.h"
#endif


#ifndef __INCLUDE_MAP
#define __INCLUDE_MAP
#include "map.h"
#endif






using namespace std;
int WINAPI WinMain(HINSTANCE,HINSTANCE,LPSTR,int){
        ChangeWindowMode(TRUE), SetDrawScreen( DX_SCREEN_BACK ); //�������Ɨ���ʐݒ�
        SetWindowSizeChangeEnableFlag(TRUE);            // �E�B���h�E�T�C�Y�����R�ɕύX�ł���悤�ɂ���B
        SetGraphMode( WINDOW_SIZE_X, WINDOW_SIZE_Y , 32);

        DxLib_Init();
        SetMouseDispFlag(FALSE);         // �}�E�X�|�C���^�\�����邩�ǂ���

        GameMain();

        DxLib_End();    // DX���C�u�����̏I��
        return 0;
}
