// GameMain.cpp
// é¿ç€ÇÃÉQÅ[ÉÄì‡ÇÃèàóù
#ifndef __INCLUDE_GAMEINIT
#define __INCLUDE_GAMEINIT
#include "GameInit.h"
#endif

#ifndef __INCLUDE_GAMEEND
#define __INCLUDE_GAMEEND
#include "GameEnd.h"
#endif


#ifndef __INCLUDE_INITDEFINE
#define __INCLUDE_INITDEFINE
#include "initDefine.h"
#endif


#ifndef __INCLUDE_DXLIB
#define __INCLUDE_DXLIB
#include "DxLib.h"
#endif

#ifndef __INCLUDE_MYLIB
#define __INCLUDE_MYLIB
#include "mylib.h"
#endif

#ifndef __INCLUDE_PLAYER
#define __INCLUDE_PLAYER
#include "Player.h"
#endif

#ifndef __INCLUDE_CAMERA
#define __INCLUDE_CAMERA
#include "Camera.h"
#endif

#ifndef __INCLUDE_ENEMY
#define __INCLUDE_ENEMY
#include "Enemy.h"
#endif

#ifndef __INCLUDE_MAP
#define __INCLUDE_MAP
#include "map.h"
#endif

#ifndef __INCLUDE_USERIF
#define __INCLUDE_USERIF
#include "UserIF.h"
#endif




#define ENEMY_NUM 1


int GameMain() {

    UserIF userif;
    Map map;
    Player player;
    Camera camera;

    Enemy enemy[ENEMY_NUM];

    SetDrawScreen(DX_SCREEN_BACK);


    while(ScreenFlip() == 0 && ProcessMessage()==0 && ClearDrawScreen()==0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0){


        map.Draw(camera);
        player.Draw(camera);
        player.Update(map);
        camera.MoveCamera();

        for(int i=0; i<ENEMY_NUM; i++) {
            enemy[i].MoveAi(player, map);
            enemy[i].Draw(camera);
        }

    }
 
  return 0; 
}
