// �ŏ��ɒ�`����}�N����`

#define WINDOW_SIZE_X 1028
#define WINDOW_SIZE_Y 640

#define MAP_SIZE_X 50
#define MAP_SIZE_Y 50

#define MAP_CHIP_SIZE 32

#define PI 3.14

// enum���Ԃˁ[
// �ϐ����̋����ɋC��t���Ȃ����޸ނ�
// ���Fdefine�ƈꏏ��������

//�@�㉺���E
enum Direction {
   Up = 0,
   Right = 1,
   Down = 2,
   Left = 3,
};

// ���̓��[�h
enum InputMode {
    RTS = 0,
    Shooting  = 1,
};

// �L�����N�^�^�C�v

enum CharType {
    C_Player = 0,
    C_Enemy = 1,
};
