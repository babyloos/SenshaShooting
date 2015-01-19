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
        ChangeWindowMode(TRUE), SetDrawScreen( DX_SCREEN_BACK ); //初期化と裏画面設定
        SetWindowSizeChangeEnableFlag(TRUE);            // ウィンドウサイズを自由に変更できるようにする。
        SetGraphMode( WINDOW_SIZE_X, WINDOW_SIZE_Y , 32);

        DxLib_Init();
        SetMouseDispFlag(FALSE);         // マウスポインタ表示するかどうか

        GameMain();

        DxLib_End();    // DXライブラリの終了
        return 0;
}
