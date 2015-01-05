// Player.h
// プレイヤークラス
#ifndef __INCLUDE_MAP
#define __INCLUDE_MAP
#include "map.h"
#endif

#ifndef __INCLUDE_CAMERA
#define __INCLUDE_CAMERA
#include "Camera.h"
#endif

#ifndef __INCLUDE_BULLET
#define __INCLUDE_BULLET
#include "Bullet.h"
#endif

#ifndef __INCLUDE_USERIF
#define __INCLUDE_USERIF
#include "UserIF.h"
#endif


class Player {
        int MouseX, MouseY;
protected:
        CharType chartype;  // キャラクタのタイプ   
        float x, y;   // 座標
        int HitPoint; // 耐久力
        int DrawX, DrawY; // 実際に描画する座標
        float vx, vy; // 移動速度
        float acceleration; // 加速度
        float friction;     // 減速度 
        int hPlayer, hHoutou;
        float HoutouKakudo; // 砲塔の角度
        int Speed;          // 移動速度


        // 弾丸関連
        Bullet bullet[100];     // 弾丸用の配列を１００個作っとく

public:
        Player();
        virtual void Shoot();       // 弾丸発射処理
        virtual void BulletUpdate(Map &map);    // 弾丸処理
        float GetX();               // X座標を返す
        float GetY();               // Y座標を返す
        void Update(Map &map);      // Playerの毎フレームの処理
        void Move(Map &map);        // 移動処理
        virtual void Hit();         // 被弾したときの処理
        void Draw(Camera &camera);  // 描画処理
        virtual void BulletDraw(Camera &camera); // 弾丸描画処理
        void DebugInfo();           // デバッグ用の情報を画面に表示
};
