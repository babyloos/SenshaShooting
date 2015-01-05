// Enemy.cpp
// “GƒLƒƒƒ‰ƒNƒ‰ƒX

#ifndef __INCLUDE_INITDEFINE
#define __INCLUDE_INITDEFINE
#include "initDefine.h"
#endif

#ifndef __INCLUDE_ENEMY
#define __INCLUDE_ENEMY
#include "Enemy.h"
#endif

#ifndef __INCLUDE_DXLIB
#define __INCLUDE_ENEMY
#include "DxLib.h"
#endif


Enemy::Enemy() {
   x = GetRand(WINDOW_SIZE_X + 100);  y = GetRand(WINDOW_SIZE_Y + 100);
   vx = 0; vy = 0;
   hPlayer = LoadGraph("tank.bmp");
   hHoutou = LoadGraph("tankHoutou2.bmp");
   Speed = 2;
   chartype = C_Enemy;
   
}

void Enemy::Move(Map &map, int Direction) {
   // “GˆÚ“®ŠÖ”
       if((Direction == Up )&&(!map.HitMapObj(x, y-Speed,64))) y-=Speed;
       if((Direction == Down )&&(!map.HitMapObj(x, y+Speed,64))) y+=Speed;
       if((Direction == Left )&&(!map.HitMapObj(x-Speed, y,64))) x-=Speed;
       if((Direction == Right )&&(!map.HitMapObj(x+Speed, y,64))) x+=Speed;
}

void Enemy::MoveAi(Player &player, Map &map) {
    // “GƒLƒƒƒ‰ƒNƒ^‚ÌˆÚ“®AI
    if(x < player.GetX()) Move(map, Right);
    if(x > player.GetX()) Move(map, Left);
    if(y < player.GetY()) Move(map, Down);
    if(y > player.GetY()) Move(map, Up);
    HoutouKakudo+=0.1;
    if(!GetRand(30))Shoot();
    BulletUpdate(map);
}

void Enemy::Draw(Camera &camera) {
    DrawX = x - camera.showCameraX();
    DrawY = y - camera.showCameraY();


    DrawGraph(DrawX, DrawY, hPlayer, TRUE);
    DrawRotaGraph(DrawX + 32, DrawY + 32, 1.0, HoutouKakudo, hHoutou, TRUE);       // –C“ƒ‚Ì•`‰æ 
    BulletDraw(camera);

    for(int i=0; i<10; i++) {
        DrawFormatString(0, 400 + i * 20, GetColor(0,255,0), "EnemyBullet[%d] alive : %d", i, bullet[i].isAlive());
    }
}

