#pragma once
#define QUEUE_MAX 100

class CKeyboard
{

public:

    static CKeyboard& getInstance();

    // �÷��̾� ����Ű�� ���� �Լ��Դϴ�.
    void PlayController();

    bool IsFull();

    bool IsEmpty();

    bool EnQueue(KeyList message);

    bool DeQueue(KeyList* message);

    // Ÿ��Ʋ���� ���͸� üũ�ϴ� �Լ��Դϴ�.
    bool EnterCheck();

private:
	int front;
	int rear;

    KeyList messageQueue[QUEUE_MAX];

    CKeyboard():front(0),rear(0){};

    CKeyboard(const CKeyboard& rhs):front(0), rear(0) {};

    CKeyboard& operator=(CKeyboard& rhs) {};

};

