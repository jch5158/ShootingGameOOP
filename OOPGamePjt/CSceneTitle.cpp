#include "stdafx.h"
#include "CSceneBase.h"
#include "CSceneTitle.h"
#include "CSceneLoading.h"
#include "CSceneGame.h"
#include "CSceneOver.h"
#include "CSceneManager.h"


void CSceneTitle::Update() {


	// 엔터 키 입력 시 로딩 씬으로 갑니다.
	CKeyboard::getInstance().EnterCheck();

}


void CSceneTitle::Render() {
	
	// 타이틀 텍스트를 랜더링하는 함수입니다.
	CScreenBuffer::getInstance().Sprite_Draw_text(10, titleText);

}
