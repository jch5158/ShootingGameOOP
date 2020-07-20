#pragma once

#define SCREEN_WIDTH 81
#define SCREEN_HEIGHT 24

class CScreenBuffer
{
public:

	static CScreenBuffer& getInstance();


	~CScreenBuffer();

	void cs_Initial(void);

	void cs_MoveCursor(int iPosX, int iPosY);

	//�ܼ� �б�
	void cs_ClearScreen(void);


	//--------------------------------------------------------------------
	// ������ ������ ȭ������ ����ִ� �Լ�.
	//
	// ����,�Ʊ�,�Ѿ� ���� szScreenBuffer �� �־��ְ�,
	// 1 �������� ������ �������� �� �Լ��� ȣ���Ͽ� ���� -> ȭ�� ���� �׸���.
	//--------------------------------------------------------------------
	void Buffer_Flip(void);


	//--------------------------------------------------------------------
	// ȭ�� ���۸� �����ִ� �Լ�
	//
	// �� ������ �׸��� �׸��� ������ ���۸� ���� �ش�.
	// �ȱ׷��� ���� �������� �ܻ��� �����ϱ�
	//--------------------------------------------------------------------
	void Buffer_Clear(void);


	//--------------------------------------------------------------------
	// ������ Ư�� ��ġ�� ���ϴ� ���ڸ� ���.
	//
	// �Է� ���� X,Y ��ǥ�� �ƽ�Ű�ڵ� �ϳ��� ����Ѵ�. (���ۿ� �׸�)
	//--------------------------------------------------------------------
	bool Sprite_Draw(int iY, int iX, char chSprite);



	// Ư�� Y�࿡ ���ڿ��� �������ϴ� �Լ��Դϴ�. 
	bool Sprite_Draw_text(int iY, char* chSprite);


	// Ư�� Y�࿡�� �ε� �ؽ�Ʈ�� �������ϴ� �Լ��Դϴ�.
	bool Sprite_Draw_Loading(int stage, int percent);


private:
	char ScreenBuffer[SCREEN_HEIGHT][SCREEN_WIDTH];

	HANDLE hConsole;

	CScreenBuffer();

	CScreenBuffer(const CScreenBuffer& rhs);

	CScreenBuffer& operator=(const CScreenBuffer& rhs) {}

};

