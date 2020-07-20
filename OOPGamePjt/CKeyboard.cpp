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


// �÷��̾� ����Ű�� ���� �Լ��Դϴ�.
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


        // 0.05�� �ֱ�� �Ѿ� �߻簡 �����մϴ�.
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
    // dummy �� ��ġ�� ���� �� ���� ť�� Full �̴�
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

    // ť�� ��á���� isFull �Լ��� true�� return
    if (IsFull() == true) {
        return false;
    }
    else {
        // �ε����� ���̷� ������ �ִ� ���̸� ����� �ʴ´�.
        rear = ++rear % QUEUE_MAX;
        messageQueue[rear] = message;
        return true;
    }
}

bool CKeyboard::DeQueue(KeyList* message) {

    // ������ ������� true�� return
    if (IsEmpty() == true)
        return false;
    else {

        // �ε����� ���̷� ������ �ִ� ���̸� ����� �ʴ´�.d
        front = ++front % QUEUE_MAX;
        *message = messageQueue[front];
        return true;
    }
}