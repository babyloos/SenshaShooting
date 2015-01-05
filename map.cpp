// map.cpp
// マップのロード, 表示等を行う。 

#pragma once

#ifndef __INCLUDE_MAP
#define __INCLUDE_MAP
#include "map.h"
#endif

#ifndef __INCLUDE_INITDEFINE
#define __INCLUDE_INITDEFINE
#include "initDefine.h"
#endif

#ifndef __INCLUDE_DXLIB
#define __INCLUDE_DXLIB
#include "DxLib.h"
#endif

#ifndef __INCLUDE_MYLIB
#define __INCLUDE_MYLIB
#include "mylib.h"
#endif


Map::Map() {
        // マップチップ画像のロード
        LoadDivGraph("mapchip\\sabaku.PNG", 140, 15, 8, 32, 32, hMapChip);  
       
        // マップデータをファイルからロード
        mylib::MapLoad("mapfile.dat", mapdate);
}
void Map::DebugInfo() {
       /*
       for(int i=0; i<MAP_SIZE_Y; i++) {
           for(int j=0; j<MAP_SIZE_X; j++) {
               DrawFormatString(j*10 + 10, i*20 + 10, GetColor(255, 0, 0), "%c", mapdate[i][j]);
           }
       }
       */
      
       
}

//　マップチップと自キャラの当たり判定
//  当たってたら１当たってなかったら０が帰る

int Map::HitMapObj(int objx, int objy, int objSize) {
        for(int i=0; i<MAP_SIZE_Y; i++) {
                for(int j=0; j<MAP_SIZE_X; j++) {
                       if((mylib::HitObj(objx, objy, objSize, j*32, i*32, 32) == 1)&(mapdate[i][j] == '1')) {
                               return 1;
                       } 
                }




        }
        return 0;
}


// マップの描画
int Map::Draw(Camera &camera) {


        for(int i=0; i<MAP_SIZE_Y; i++) {
                for(int j=0; j<MAP_SIZE_X; j++) {
                       if(mapdate[i][j] == '0') {
                               DrawGraph(j*32 - camera.showCameraX(), i*32 - camera.showCameraY(), hMapChip[0], FALSE);
                       }else if(mapdate[i][j] == '1') {
                               DrawGraph(j*32 - camera.showCameraX(), i*32 - camera.showCameraY(), hMapChip[1], FALSE);
                       }
                }
        }


        return 0;
}

