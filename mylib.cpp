// 汎用的な関数とか
#ifndef __INCLUDE_MYLIB
#define __INCLUDE_MYLIB
#include"mylib.h"
#endif

#ifndef __INCLUDE_STDLIB
#define __INCLUDE_STDLIB
#include<stdlib.h>
#endif

#ifndef __INCLUDE_STDIO
#define __INCLUDE_STDIO
#include<stdio.h>
#endif

#ifndef __INCLUDE_DXLIB
#define __INCLUDE_DXLIB
#include "DxLib.h"
#endif

#ifndef __INCLUDE_INITDEFINE
#define __INCLUDE_INITDEFINE
#include "InitDefine.h"
#endif


// 正方形同士の当たり判定
// 当たってたら１を返す、当たってなかったら０を返す。
int mylib::HitObj(int ax, int ay, int asize, int bx, int by, int bsize){
    int ax2 = ax + asize, ay2 = ay + asize;
    int bx2 = bx + bsize, by2 = by + bsize;
    if(!(ax2<bx || ax>bx2 || ay>by2 || ay2<by)) {
            return 1;
    }else {
            return 0;
    }
}


//  マップファイルのロード
//  マップサイズが５０＊５０のマジックナンバーになってるからここは修正しないと
int mylib::MapLoad(char* MapFileName, char map[MAP_SIZE_X][MAP_SIZE_Y]) {
    FILE* pMapFile;

    if((pMapFile = fopen(MapFileName,"r")) == NULL) {
       printf("ファイルオープンエラー\n");
       exit(EXIT_FAILURE);
    }

   
    for(int i=0; i<50; i++) {
        for(int j=0; j<50; j++) {
            fscanf(pMapFile, "%c", &map[i][j]);
        }
    }
    

    fclose(pMapFile);

    return 0;

 
}

// キーの入力状態を更新する
/*
int mylib::gpUpdateKey(){
        char tmpKey[256]; // 現在のキーの入力状態を格納する
        GetHitKeyStateAll( tmpKey ); // 全てのキーの入力状態を得る
        for( int i=0; i<256; i++ ){ 
                if( tmpKey[i] != 0 ){ // i番のキーコードに対応するキーが押されていたら
                    mylib::Key[i]++;     // 加算
                } else {              // 押されていなければ
                    mylib::Key[i] = 0;   // 0にする
                }
        }
        return 0;
}
*/
