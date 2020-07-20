#include "stdafx.h"

#include "CBaseObject.h"
#include "CBulletObject.h"
#include "CEnemyObject.h"
#include "CPlayerObject.h"
#include "CObjectManager.h"

#include "CSceneBase.h"
#include "CSceneTitle.h"
#include "CSceneLoading.h"
#include "CSceneGame.h"
#include "CSceneOver.h"
#include "CSceneManager.h"



CScreenBuffer& CScreenBuffer::getInstance() {

	static CScreenBuffer scBuffer;

	return scBuffer;
}


CScreenBuffer::CScreenBuffer() {
	CScreenBuffer::cs_Initial();
}

CScreenBuffer::~CScreenBuffer() {

}


void CScreenBuffer::cs_Initial(void) {
	CONSOLE_CURSOR_INFO stConsoleCursor; // 커서 구조체

	stConsoleCursor.bVisible = FALSE; // 커서 안보이게
	stConsoleCursor.dwSize = 1; // 커서의 최소 크기

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorInfo(hConsole, &stConsoleCursor);
}

void CScreenBuffer::cs_MoveCursor(int iPosX, int iPosY) {
	COORD stCoord;
	stCoord.X = iPosX;
	stCoord.Y = iPosY;

	SetConsoleCursorPosition(hConsole, stCoord);
}

void CScreenBuffer::cs_ClearScreen(void) { // 버퍼 밀기
	unsigned long dw;
	FillConsoleOutputCharacter(GetStdHandle(STD_OUTPUT_HANDLE), ' ', 100 * 100, { 0,0 }, &dw);
}


//--------------------------------------------------------------------
// 버퍼의 내용을 화면으로 찍어주는 함수.
//
// 적군,아군,총알 등을 szScreenBuffer 에 넣어주고,
// 1 프레임이 끝나는 마지막에 본 함수를 호출하여 버퍼 -> 화면 으로 그린다.
//--------------------------------------------------------------------
void CScreenBuffer::Buffer_Flip(void)
{	
	cs_MoveCursor(0, 0);
	printf_s("체력 : %d ",CPlayerObject::getPlayerHp());

	for (int iCnt = 0; iCnt < SCREEN_HEIGHT; iCnt++)
	{
		cs_MoveCursor(0, iCnt+1);
		printf(ScreenBuffer[iCnt]);
	}
}


//--------------------------------------------------------------------
// 화면 버퍼를 지워주는 함수
//
// 매 프레임 그림을 그리기 직전에 버퍼를 지워 준다.
// 안그러면 이전 프레임의 잔상이 남으니까
//--------------------------------------------------------------------
void CScreenBuffer::Buffer_Clear(void)
{

	memset(this->ScreenBuffer, ' ', SCREEN_WIDTH * SCREEN_HEIGHT);

	for (int iCnt = 0; iCnt < SCREEN_HEIGHT; iCnt++)
	{
		this->ScreenBuffer[iCnt][SCREEN_WIDTH - 1] = '\0'; // 맨 마지막에만 null을 삽입합니다. 
	}
}

//--------------------------------------------------------------------
// 버퍼의 특정 위치에 원하는 문자를 출력.
//
// 입력 받은 X,Y 좌표에 아스키코드 하나를 출력한다. (버퍼에 그림)
//--------------------------------------------------------------------
bool CScreenBuffer::Sprite_Draw(int iY, int iX, char chSprite)
{
	if (iX < 0 || iY < 0 || iX >= SCREEN_WIDTH - 1 || iY >= SCREEN_HEIGHT)
		return false;

	ScreenBuffer[iY][iX] = chSprite;

	return true;
}


bool CScreenBuffer::Sprite_Draw_text(int iY, char* chSprite) {

	if (strlen(chSprite)+1 < 0 || iY < 0 || strlen(chSprite)+1 >= SCREEN_WIDTH - 1 || iY >= SCREEN_HEIGHT)
		return false;

	strcpy_s(ScreenBuffer[iY], strlen(chSprite)+1, chSprite);


	return true;
}


// 특정 Y축에서 로딩 텍스트를 랜더링하는 함수입니다.
bool CScreenBuffer::Sprite_Draw_Loading(int stage, int percent) {

	
	sprintf_s(ScreenBuffer[10], "                            stage %d  Loading... %d %s    ", stage, percent, "%%");

	return true;
}