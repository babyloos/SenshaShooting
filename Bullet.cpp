// �e�N���X

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
    radian = radi + PI * 1.5;      // ���˕��������   �Ȃ����p�x�C�����Ȃ��Ɛ������������甭�˂��Ȃ�
    x = charX + 16;          // ���˃L�����N�^�̍��W�����
    y = charY + 16;
    shotChar = chartype;     // ���˂����L�����N�^�̃^�C�v �����蔻��̎��g���܂�
    speed = 15;             // �e�ۂ̑��x

    size = 24;          // �傫��(�����`)�����蔻��̎��Ɏg���܂�
    aliveTime = 300;      // �������Ԃ̐ݒ�(�t���[����)

    alive = false;       // �ŏ��͎���ł�

    hBullet = LoadGraph("bullet.bmp");  // �`��p�摜�f�[�^�A�e�ۂ𐶐�����x�Ƀ��[�h����͈̂Ⴄ�C�����܂�.



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
    // �����ɓ���������e������
    if(map.HitMapObj(x, y, size)) {    // Map�Ƃ̓����蔻��
        return 1;   // �����ɓ���������P��Ԃ�
    }
    /*
     * �v���C���[�Ƃ̓����蔻��
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

    aliveTime--;    // �������Ԃ����炷
    
}

bool Bullet::Kill(Map &map) {
    if((aliveTime < 0) || (x < 0) || (x > MAP_SIZE_X * MAP_CHIP_SIZE) || (y < 0) || (y > MAP_SIZE_Y * MAP_CHIP_SIZE)||(Hit(map)))  {
        alive = false;      // �e�̐������Ԃ��Ȃ��Ȃ�����A�}�b�v�O�ɏo���ꍇ
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
