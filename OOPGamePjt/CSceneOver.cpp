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

	// ���ӿ��� �ؽ�Ʈ�� �������ϴ� �Լ��Դϴ�.
	CScreenBuffer::getInstance().Sprite_Draw_text(10, overText);


}

