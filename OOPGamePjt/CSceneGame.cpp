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



CSceneGame::CSceneGame() {
	
	
}

CSceneGame::~CSceneGame() {


	CObjectManager::getInstance().DestroyObjectAll();

	CScreenBuffer::getInstance().cs_ClearScreen();
}

void CSceneGame::Update() {
	
	CObjectManager::getInstance().Update();

}


void CSceneGame::Render() {

	CObjectManager::getInstance().Render();

}