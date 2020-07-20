#include "stdafx.h"

#include "CSceneBase.h"
#include "CSceneTitle.h"
#include "CSceneLoading.h"
#include "CSceneGame.h"
#include "CSceneOver.h"
#include "CSceneManager.h"


CKeyboard& CKeyboard::getInstance() {

    static CKeyboard cirQueue;

    return cirQueue;
}


// 플레이어 조작키를 위한 함수입니다.
void CKeyboard::PlayController() {
  
    static clock_t shotSpeed;

    
    if (GetAsyncKeyState(VK_UP))
        EnQueue(KeyList::KEYUP);

    if (GetAsyncKeyState(VK_DOWN))
        EnQueue(KeyList::KEYDOWN);

    if (GetAsyncKeyState(VK_LEFT))
        EnQueue(KeyList::KEYLEFT);

    if (GetAsyncKeyState(VK_RIGHT))
        EnQueue(KeyList::KEYRIGHT);

    if (GetAsyncKeyState(VK_SPACE)) {
        if (shotSpeed == 0)
            shotSpeed = clock();


        // 0.05초 주기로 총알 발사가 가능합니다.
        if (clock() - shotSpeed >= 50) {
            EnQueue(KeyList::KEYSHOTBULLET);
            shotSpeed = 0;
        }
    }
}



bool CKeyboard::EnterCheck() {
    if (GetAsyncKeyState(VK_RETURN)) {
        CSceneManager::getInstance().LoadScene(SceneList::SCENELOADING);
        return true;
    }
    return false;
}



bool CKeyboard::IsFull() {
    // dummy 값 위치에 있을 때 원형 큐는 Full 이다
    if ((rear + 1) % QUEUE_MAX == front) {
        return true;
    }
    else {
        return false;
    }
}

bool CKeyboard::IsEmpty() {
    if (front == rear) {
        return true;
    }
    else
        return false;
}

bool CKeyboard::EnQueue(KeyList message) {

    // 큐가 꽉찼으면 isFull 함수는 true를 return
    if (IsFull() == true) {
        return false;
    }
    else {
        // 인덱스의 길이로 나누어 최대 길이를 벗어나지 않는다.
        rear = ++rear % QUEUE_MAX;
        messageQueue[rear] = message;
        return true;
    }
}

bool CKeyboard::DeQueue(KeyList* message) {

    // 스택이 비었으면 true를 return
    if (IsEmpty() == true)
        return false;
    else {

        // 인덱스의 길이로 나누어 최대 길이를 벗어나지 않는다.d
        front = ++front % QUEUE_MAX;
        *message = messageQueue[front];
        return true;
    }
}