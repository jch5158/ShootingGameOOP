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
	CONSOLE_CURSOR_INFO stConsoleCursor; // Ŀ�� ����ü

	stConsoleCursor.bVisible = FALSE; // Ŀ�� �Ⱥ��̰�
	stConsoleCursor.dwSize = 1; // Ŀ���� �ּ� ũ��

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorInfo(hConsole, &stConsoleCursor);
}

void CScreenBuffer::cs_MoveCursor(int iPosX, int iPosY) {
	COORD stCoord;
	stCoord.X = iPosX;
	stCoord.Y = iPosY;

	SetConsoleCursorPosition(hConsole, stCoord);
}

void CScreenBuffer::cs_ClearScreen(void) { // ���� �б�
	unsigned long dw;
	FillConsoleOutputCharacter(GetStdHandle(STD_OUTPUT_HANDLE), ' ', 100 * 100, { 0,0 }, &dw);
}


//--------------------------------------------------------------------
// ������ ������ ȭ������ ����ִ� �Լ�.
//
// ����,�Ʊ�,�Ѿ� ���� szScreenBuffer �� �־��ְ�,
// 1 �������� ������ �������� �� �Լ��� ȣ���Ͽ� ���� -> ȭ�� ���� �׸���.
//--------------------------------------------------------------------
void CScreenBuffer::Buffer_Flip(void)
{	
	cs_MoveCursor(0, 0);
	printf_s("ü�� : %d ",CPlayerObject::getPlayerHp());

	for (int iCnt = 0; iCnt < SCREEN_HEIGHT; iCnt++)
	{
		cs_MoveCursor(0, iCnt+1);
		printf(ScreenBuffer[iCnt]);
	}
}


//--------------------------------------------------------------------
// ȭ�� ���۸� �����ִ� �Լ�
//
// �� ������ �׸��� �׸��� ������ ���۸� ���� �ش�.
// �ȱ׷��� ���� �������� �ܻ��� �����ϱ�
//--------------------------------------------------------------------
void CScreenBuffer::Buffer_Clear(void)
{

	memset(this->ScreenBuffer, ' ', SCREEN_WIDTH * SCREEN_HEIGHT);

	for (int iCnt = 0; iCnt < SCREEN_HEIGHT; iCnt++)
	{
		this->ScreenBuffer[iCnt][SCREEN_WIDTH - 1] = '\0'; // �� ���������� null�� �����մϴ�. 
	}
}

//--------------------------------------------------------------------
// ������ Ư�� ��ġ�� ���ϴ� ���ڸ� ���.
//
// �Է� ���� X,Y ��ǥ�� �ƽ�Ű�ڵ� �ϳ��� ����Ѵ�. (���ۿ� �׸�)
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


// Ư�� Y�࿡�� �ε� �ؽ�Ʈ�� �������ϴ� �Լ��Դϴ�.
bool CScreenBuffer::Sprite_Draw_Loading(int stage, int percent) {

	
	sprintf_s(ScreenBuffer[10], "                            stage %d  Loading... %d %s    ", stage, percent, "%%");

	return true;
}