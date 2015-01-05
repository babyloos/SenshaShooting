// Player.cpp

#ifndef __INCLUDE_PLAYER
#define __INCLUDE_PLAYER
#include "Player.h"
#endif

#ifndef __INCLUDE_DXLIB
#define __INCLUDE_DXLIB
#include "DxLib.h"
#endif

#ifndef __INCLUDE_MYLIB
#define __INCLUDE_MYLIB
#include "mylib.h"
#endif

#ifndef __INCLUDE_MATH
#define __INCLUDE_MATH
#include <math.h>
#endif

#ifndef __INCLUDE_INITDEFINE
#define __INCLUDE_INITDEFINE
#include "InitDefine.h"
#endif

#ifndef __INCLUDE_BULLET
#define __INCLUDE_BULLET
#include "Bullet.h"
#endif

#ifndef __INCLUDE_USERIF
#define __INCLUDE_USERIF
#include "UserIF.h"
#endif

#ifndef __INCLUDE_MAP
#define __INCLUDE_MAP
#include "map.h"
#endif



Player::Player() {

        hPlayer = LoadGraph("player.bmp");
        hHoutou = LoadGraph("houtou.bmp");
        chartype = C_Player;
        x = 100; y = 100; 
        HitPoint = 100;
        vx = 0;                     // ‘¬“x
        vy = 0;
        acceleration = 0.5;         // ‰Á‘¬“x
        friction = 0.92;
        Speed = 5;

        Bullet bullet[100];
}

void Player::Shoot() {
        Bullet* BulletPoint = new Bullet(x, y, HoutouKakudo, chartype);
        for(int i=0; i<100; i++) {
            if(!bullet[i].isAlive()) {
                bullet[i] = *BulletPoint;
                bullet[i].setAlive();
                break;
            }
        }
        // ’eŠÛ‚ðƒZƒbƒg(”­ŽË)‚Å‚«‚È‚©‚Á‚½ê‡
        return;
}

void Player::Move(Map &map) {
}

void Player::Hit() {
    HitPoint--;
}

void Player::Update(Map &map) {    //ƒLƒƒƒ‰ƒNƒ^‚Ì–ˆƒtƒŒ[ƒ€Ž–‚Ìˆ—
    
//    if(interface.GetInputMode() == Shooting) {
        if((CheckHitKey(KEY_INPUT_W) != 0 )&&(!map.HitMapObj(x, y-Speed, 64))) y-=Speed;
        if((CheckHitKey(KEY_INPUT_S) != 0 )&&(!map.HitMapObj(x, y+Speed, 64))) y+=Speed;
        if((CheckHitKey(KEY_INPUT_A) != 0 )&&(!map.HitMapObj(x-Speed, y, 64))) x-=Speed;
        if((CheckHitKey(KEY_INPUT_D) != 0 )&&(!map.HitMapObj(x+Speed, y, 64))) x+=Speed;

        // ¶ƒNƒŠƒbƒN‚Å’eŠÛ”­ŽË
        if(GetMouseInput() & MOUSE_INPUT_LEFT) Shoot();
//   }

//        Move(map);
        
        BulletUpdate(map);

        // Œ¸‘¬
        vx = vx * friction;
        vy = vy * friction;
        
        x += vx;        // ˆÚ“®‘¬“x•ªŽÀÛ‚ÉˆÚ“®‚³‚¹‚é
        y += vy;

        GetMousePoint(&MouseX, &MouseY);
        HoutouKakudo = atan2(MouseY - DrawY, MouseX - DrawX) + PI/2;
        
}

void Player::BulletUpdate(Map &map) {
        // ’eŠÛ‚Ìˆ—
        for(int i=0; i<100; i++) {
            if(bullet[i].isAlive()) {
                bullet[i].Update(map);
               }
            
        }

}

float Player::GetX() {
    return x;
}

float Player::GetY() {
    return y;
}

void Player::Draw(Camera &camera){


        DrawX = x - camera.showCameraX();
        DrawY = y - camera.showCameraY();
            
        //’eŠÛ‚Ì•`‰æ
        BulletDraw(camera);

        //Player‚Ì•`‰æ
        DrawGraph(DrawX, DrawY, hPlayer, TRUE);
        DrawString(MouseX, MouseY, "*", GetColor(40,0,255));         // ‚±‚ê‚Í‚±‚±‚Å•`‰æ‚·‚é‚ñ‚¶‚á‚È‚­‚Äƒ†[ƒU[IF‚Ì•”•ª‚Åˆ—‚µ‚½‚Ù‚¤‚ª‚¢‚¢‚©‚à
        DrawRotaGraph(DrawX + 32, DrawY + 32, 1.0, HoutouKakudo, hHoutou, TRUE, FALSE);       // –C“ƒ‚Ì•`‰æ 



}

void Player::BulletDraw(Camera &camera) {
        // ’eŠÛ‚Ì•`‰æ:
        for(int i=0; i<100; i++) {
            if(bullet[i].isAlive()) {
                bullet[i].Draw(camera);
            }
        }
}

void Player::DebugInfo() {

       DrawFormatString(10, 10, GetColor(255, 0, 0), "Player.x : %f  Player.y : %f", x, y);
       DrawFormatString(10, 30, GetColor(20, 50, 12), "DrawX : %d  DrawY : %d", DrawX, DrawY);
       DrawFormatString(10, 40, GetColor(42, 120, 12), "HoutouKakudo : %f", HoutouKakudo);
       DrawFormatString(10, 100, GetColor(255, 255, 255), "vx : %f vy : %f", vx, vy);
       bullet[0].DebugDraw();
       
}
