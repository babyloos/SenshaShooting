// Enemy.h
// “GƒLƒƒƒ‰ƒNƒ‰ƒX
/*
#ifndef __INCLUDE_MAP
#define __INCLUDE_MAP
#include "map.h"
#endif
*/
#pragma once

#ifndef __INCLUDE_PLAYER
#define __INCLUDE_PLAYER
#include "Player.h"
#endif

class Enemy : public Player{
    int hPlayer;
    int hHoutou;
    int vx,vy;
    int MoveRand;
    

public:
    Enemy();
    void Move(Map &map, int Direction);
    void MoveAi(Player &player, Map &map);
    void Draw(Camera &camera);
};
