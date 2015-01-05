// map.h
#pragma once
#ifndef __INCLUDE_INITDEFINE
#define __INCLUDE_INITDEFINE
#include "initDefine.h"
#endif

#ifndef __INCLUDE_CAMERA
#define __INCLUDE_CAMERA
#include "Camera.h"
#endif


class Map  {
        int mapx,mapy;          // �O���[�o���ȃ}�b�v���W   
        int hMapChip[140];      // �}�b�v�`�b�v�n���h��
        char mapdate[MAP_SIZE_X][MAP_SIZE_Y];
public:
        Map();
        int Draw(Camera &camera);
        int HitMapObj(int objx, int objy, int objSize);
        void virtual DebugInfo();

};
