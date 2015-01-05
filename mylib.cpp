// �ėp�I�Ȋ֐��Ƃ�
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


// �����`���m�̓����蔻��
// �������Ă���P��Ԃ��A�������ĂȂ�������O��Ԃ��B
int mylib::HitObj(int ax, int ay, int asize, int bx, int by, int bsize){
    int ax2 = ax + asize, ay2 = ay + asize;
    int bx2 = bx + bsize, by2 = by + bsize;
    if(!(ax2<bx || ax>bx2 || ay>by2 || ay2<by)) {
            return 1;
    }else {
            return 0;
    }
}


//  �}�b�v�t�@�C���̃��[�h
//  �}�b�v�T�C�Y���T�O���T�O�̃}�W�b�N�i���o�[�ɂȂ��Ă邩�炱���͏C�����Ȃ���
int mylib::MapLoad(char* MapFileName, char map[MAP_SIZE_X][MAP_SIZE_Y]) {
    FILE* pMapFile;

    if((pMapFile = fopen(MapFileName,"r")) == NULL) {
       printf("�t�@�C���I�[�v���G���[\n");
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

// �L�[�̓��͏�Ԃ��X�V����
/*
int mylib::gpUpdateKey(){
        char tmpKey[256]; // ���݂̃L�[�̓��͏�Ԃ��i�[����
        GetHitKeyStateAll( tmpKey ); // �S�ẴL�[�̓��͏�Ԃ𓾂�
        for( int i=0; i<256; i++ ){ 
                if( tmpKey[i] != 0 ){ // i�Ԃ̃L�[�R�[�h�ɑΉ�����L�[��������Ă�����
                    mylib::Key[i]++;     // ���Z
                } else {              // ������Ă��Ȃ����
                    mylib::Key[i] = 0;   // 0�ɂ���
                }
        }
        return 0;
}
*/
