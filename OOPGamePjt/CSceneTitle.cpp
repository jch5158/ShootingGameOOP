#include "stdafx.h"
#include "CSceneBase.h"
#include "CSceneTitle.h"
#include "CSceneLoading.h"
#include "CSceneGame.h"
#include "CSceneOver.h"
#include "CSceneManager.h"


void CSceneTitle::Update() {


	// ���� Ű �Է� �� �ε� ������ ���ϴ�.
	CKeyboard::getInstance().EnterCheck();

}


void CSceneTitle::Render() {
	
	// Ÿ��Ʋ �ؽ�Ʈ�� �������ϴ� �Լ��Դϴ�.
	CScreenBuffer::getInstance().Sprite_Draw_text(10, titleText);

}
