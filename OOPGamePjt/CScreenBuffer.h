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

	//콘솔 밀기
	void cs_ClearScreen(void);


	//--------------------------------------------------------------------
	// 버퍼의 내용을 화면으로 찍어주는 함수.
	//
	// 적군,아군,총알 등을 szScreenBuffer 에 넣어주고,
	// 1 프레임이 끝나는 마지막에 본 함수를 호출하여 버퍼 -> 화면 으로 그린다.
	//--------------------------------------------------------------------
	void Buffer_Flip(void);


	//--------------------------------------------------------------------
	// 화면 버퍼를 지워주는 함수
	//
	// 매 프레임 그림을 그리기 직전에 버퍼를 지워 준다.
	// 안그러면 이전 프레임의 잔상이 남으니까
	//--------------------------------------------------------------------
	void Buffer_Clear(void);


	//--------------------------------------------------------------------
	// 버퍼의 특정 위치에 원하는 문자를 출력.
	//
	// 입력 받은 X,Y 좌표에 아스키코드 하나를 출력한다. (버퍼에 그림)
	//--------------------------------------------------------------------
	bool Sprite_Draw(int iY, int iX, char chSprite);



	// 특정 Y축에 문자열을 랜더링하는 함수입니다. 
	bool Sprite_Draw_text(int iY, char* chSprite);


	// 특정 Y축에서 로딩 텍스트를 랜더링하는 함수입니다.
	bool Sprite_Draw_Loading(int stage, int percent);


private:
	char ScreenBuffer[SCREEN_HEIGHT][SCREEN_WIDTH];

	HANDLE hConsole;

	CScreenBuffer();

	CScreenBuffer(const CScreenBuffer& rhs);

	CScreenBuffer& operator=(const CScreenBuffer& rhs) {}

};

