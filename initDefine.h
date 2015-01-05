// 最初に定義するマクロ定義

#define WINDOW_SIZE_X 1028
#define WINDOW_SIZE_Y 640

#define MAP_SIZE_X 50
#define MAP_SIZE_Y 50

#define MAP_CHIP_SIZE 32

#define PI 3.14

// enumあぶねー
// 変数名の競合に気を付けないとﾊﾞｸﾞる
// 所詮defineと一緒だったわ

//　上下左右
enum Direction {
   Up = 0,
   Right = 1,
   Down = 2,
   Left = 3,
};

// 入力モード
enum InputMode {
    RTS = 0,
    Shooting  = 1,
};

// キャラクタタイプ

enum CharType {
    C_Player = 0,
    C_Enemy = 1,
};
