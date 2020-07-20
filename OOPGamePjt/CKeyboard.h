#pragma once
#define QUEUE_MAX 100

class CKeyboard
{

public:

    static CKeyboard& getInstance();

    // 플레이어 조작키를 위한 함수입니다.
    void PlayController();

    bool IsFull();

    bool IsEmpty();

    bool EnQueue(KeyList message);

    bool DeQueue(KeyList* message);

    // 타이틀에서 엔터를 체크하는 함수입니다.
    bool EnterCheck();

private:
	int front;
	int rear;

    KeyList messageQueue[QUEUE_MAX];

    CKeyboard():front(0),rear(0){};

    CKeyboard(const CKeyboard& rhs):front(0), rear(0) {};

    CKeyboard& operator=(CKeyboard& rhs) {};

};

