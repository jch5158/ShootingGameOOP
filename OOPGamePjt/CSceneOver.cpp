#include "stdafx.h"

#include "CSceneBase.h"
#include "CSceneTitle.h"
#include "CSceneLoading.h"
#include "CSceneGame.h"
#include "CSceneOver.h"
#include "CSceneManager.h"


CSceneOver::CSceneOver() {
	
}

CSceneOver::~CSceneOver() {

}

void CSceneOver::Update() {

}

void CSceneOver::Render() {

	// 게임오버 텍스트를 랜더링하는 함수입니다.
	CScreenBuffer::getInstance().Sprite_Draw_text(10, overText);


}

