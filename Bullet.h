// 弾丸クラス
//
// ほんとはオブジェクト指向で、弾丸を独自のオブジェクトとして扱いたんだけどよくわかんないから、プレイヤーの持つオブジェクトとしてプレイヤー内で処理するって自分で書いて意味わかんない

#ifndef __INCLUDE_MAP
#define __INCLUDE_MAP
#include "Map.h"
#endif

#ifndef __INCLUDE_CAMERA
#define __INCLUDE_CAMERA
#include "camera.h"
#endif


class Bullet {
     CharType shotChar; // 弾丸を発射したキャラクタのタイプ
     bool alive;    // 弾丸が生きているかどうか
     int size;     // サイズ 
     int x, y;      // 座標
     float radian;  // 方向
     int speed;     //  移動速度
     int aliveTime;     // 弾丸の生存時間(フレーム数)
     int DrawX, DrawY;      // 描画用
     int hBullet;       // 弾丸画像ハンドル

public:
     Bullet(){
        alive = false;     
     } // デフォルトコンストラクタ
     Bullet(float charX, float charY, float radi, CharType chartype);
     void Update(Map &map);      // マイループ呼び出す処理
     int Hit(Map &map);            // あたり判定
     void Move(Map &map);
     bool Kill(Map &map);        // 弾を消去するかどうかの判定
     bool isAlive();     // aliveがtrueかfalseか返す
     void setAlive();     // aliveをtrueにする       // なんかスマートじゃないかも
     void Draw(Camera &camera);
     void DebugDraw();
};
