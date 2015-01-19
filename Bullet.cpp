// 弾クラス

#include "DxLib.h"

#ifndef __INCLUDE_BULLET
#define __INCLUDE_BULLET
#include "Bullet.h"
#endif

#ifndef __INCLUDE_MATH
#define __INCLUDE_MATH
#include <math.h>
#endif

#ifndef __INCLUDE_INITDEFINE
#define __INCLUDE_INITDEFINE
#include "initDefine.h"
#endif

#ifndef __INCLUDE_CAMERA
#define __INCLUDE_CAMERA
#include "Camera.h"
#endif

#ifndef __INCLUDE_MAP
#define __INCLUDE_MAP
#include "map.h"
#endif

#ifndef __INLCUDE_MYLIB
#define __INLCUDE_MYLIB
#include "mylib.h"
#endif


Bullet::Bullet(float charX, float charY, float radi, CharType chartype) {
    radian = radi + PI * 1.5;      // 発射方向を入力   なぜか角度修正しないと正しい方向から発射しない
    x = charX + 16;          // 発射キャラクタの座標を入力
    y = charY + 16;
    shotChar = chartype;     // 発射したキャラクタのタイプ 当たり判定の時使います
    speed = 15;             // 弾丸の速度

    size = 24;          // 大きさ(正方形)当たり判定の時に使います
    aliveTime = 300;      // 生存時間の設定(フレーム数)

    alive = false;       // 最初は死んでる

    hBullet = LoadGraph("bullet.bmp");  // 描画用画像データ、弾丸を生成する度にロードするのは違う気がします.



}

void Bullet::Update(Map &map) {
    Move(map);
    Hit(map);
    Kill(map);
}

bool Bullet::isAlive() {
    return alive;
}

void Bullet::setAlive() {
    alive = true;
}

int Bullet::Hit(Map &map) {
    // 何かに当たったら弾を消す
    if(map.HitMapObj(x, y, size)) {    // Mapとの当たり判定
        return 1;   // 何かに当たったら１を返す
    }
    /*
     * プレイヤーとの当たり判定
    if(shotChar == C_Enemy) {
        if(mylib::HitObj(x, y, size, player.GetX(), player.GetY(), 64) == 1) {
            player.Hit();
            return 1;
        }
    }
    */
    return 0;
}


void Bullet::Move(Map &map) {

    x += speed * cos(radian);
    y += speed * sin(radian);

    aliveTime--;    // 生存時間を減らす
    
}

bool Bullet::Kill(Map &map) {
    if((aliveTime < 0) || (x < 0) || (x > MAP_SIZE_X * MAP_CHIP_SIZE) || (y < 0) || (y > MAP_SIZE_Y * MAP_CHIP_SIZE)||(Hit(map)))  {
        alive = false;      // 弾の生存時間がなくなったり、マップ外に出た場合
    return false;
    }
    else return true;
}

void Bullet::Draw(Camera &camera) {
    DrawX = x - camera.showCameraX();
    DrawY = y - camera.showCameraY();
    DrawGraph(DrawX, DrawY, hBullet, TRUE);
}

void Bullet::DebugDraw() {
    for(int i=0; i<10; i++) {
        DrawFormatString(500, i*20, GetColor(128, 0, 0), "Bullet[%d] Alive:%d, x:%d, y:%d", i, alive, x, y);
    }
}
