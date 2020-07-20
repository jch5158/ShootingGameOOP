#include "stdafx.h"

#include "CSceneBase.h"
#include "CSceneTitle.h"
#include "CSceneLoading.h"
#include "CSceneGame.h"
#include "CSceneOver.h"
#include "CSceneManager.h"



int main()
{
	timeBeginPeriod(1);

	srand((unsigned int)time(NULL));

	while (1) {

		CSceneManager::getInstance().Update();

		CScreenBuffer::getInstance().Buffer_Clear();

		CSceneManager::getInstance().Render();

		CScreenBuffer::getInstance().Buffer_Flip();

		Sleep(16);
	}

	

	timeEndPeriod(1);
}
