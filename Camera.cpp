// Camera.cpp
#ifndef __INCLUDE_CAMERA
#define __INCLUDE_CAMERA
#include "Camera.h"
#endif

#ifndef __INCLUDE_MYLIB
#define __INCLUDE_MYLIB
#include "mylib.h"
#endif

#ifndef __INCLUDE_DXLIB
#define __INCLUDE_DXLIB
#include "Dxlib.h"
#endif

#ifndef __INCLUDE_INITDEFINE
#define __INCLUDE_INITDEFINE
#include "initDefine.h"
#endif

Camera::Camera() {
    cameraX = 0;
    cameraY = 0;
    cameraSpeed = 10;
}

void Camera::MoveCamera() {
    
    GetMousePoint(&MouseX, &MouseY);


    if((CheckHitKey(KEY_INPUT_UP))||(MouseY < 20)) cameraY-=cameraSpeed;
    if((CheckHitKey(KEY_INPUT_DOWN))||(MouseY > WINDOW_SIZE_Y - 20)) cameraY+=cameraSpeed;
    if((CheckHitKey(KEY_INPUT_LEFT))||(MouseX < 20)) cameraX-=cameraSpeed;
    if((CheckHitKey(KEY_INPUT_RIGHT))||(MouseX > WINDOW_SIZE_X - 20)) cameraX+=cameraSpeed;
}

int Camera::showCameraX() {
    return cameraX;
}
int Camera::showCameraY() {
    return cameraY;
}

