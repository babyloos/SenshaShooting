// Player.h
// �v���C���[�N���X
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
        CharType chartype;  // �L�����N�^�̃^�C�v   
        float x, y;   // ���W
        int HitPoint; // �ϋv��
        int DrawX, DrawY; // ���ۂɕ`�悷����W
        float vx, vy; // �ړ����x
        float acceleration; // �����x
        float friction;     // �����x 
        int hPlayer, hHoutou;
        float HoutouKakudo; // �C���̊p�x
        int Speed;          // �ړ����x


        // �e�ۊ֘A
        Bullet bullet[100];     // �e�ۗp�̔z����P�O�O����Ƃ�

public:
        Player();
        virtual void Shoot();       // �e�۔��ˏ���
        virtual void BulletUpdate(Map &map);    // �e�ۏ���
        float GetX();               // X���W��Ԃ�
        float GetY();               // Y���W��Ԃ�
        void Update(Map &map);      // Player�̖��t���[���̏���
        void Move(Map &map);        // �ړ�����
        virtual void Hit();         // ��e�����Ƃ��̏���
        void Draw(Camera &camera);  // �`�揈��
        virtual void BulletDraw(Camera &camera); // �e�ە`�揈��
        void DebugInfo();           // �f�o�b�O�p�̏�����ʂɕ\��
};
