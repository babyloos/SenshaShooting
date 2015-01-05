// �e�ۃN���X
//
// �ق�Ƃ̓I�u�W�F�N�g�w���ŁA�e�ۂ�Ǝ��̃I�u�W�F�N�g�Ƃ��Ĉ������񂾂��ǂ悭�킩��Ȃ�����A�v���C���[�̎��I�u�W�F�N�g�Ƃ��ăv���C���[���ŏ���������Ď����ŏ����ĈӖ��킩��Ȃ�

#ifndef __INCLUDE_MAP
#define __INCLUDE_MAP
#include "Map.h"
#endif

#ifndef __INCLUDE_CAMERA
#define __INCLUDE_CAMERA
#include "camera.h"
#endif


class Bullet {
     CharType shotChar; // �e�ۂ𔭎˂����L�����N�^�̃^�C�v
     bool alive;    // �e�ۂ������Ă��邩�ǂ���
     int size;     // �T�C�Y 
     int x, y;      // ���W
     float radian;  // ����
     int speed;     //  �ړ����x
     int aliveTime;     // �e�ۂ̐�������(�t���[����)
     int DrawX, DrawY;      // �`��p
     int hBullet;       // �e�ۉ摜�n���h��

public:
     Bullet(){
        alive = false;     
     } // �f�t�H���g�R���X�g���N�^
     Bullet(float charX, float charY, float radi, CharType chartype);
     void Update(Map &map);      // �}�C���[�v�Ăяo������
     int Hit(Map &map);            // �����蔻��
     void Move(Map &map);
     bool Kill(Map &map);        // �e���������邩�ǂ����̔���
     bool isAlive();     // alive��true��false���Ԃ�
     void setAlive();     // alive��true�ɂ���       // �Ȃ񂩃X�}�[�g����Ȃ�����
     void Draw(Camera &camera);
     void DebugDraw();
};
