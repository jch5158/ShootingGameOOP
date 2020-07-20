#include "stdafx.h"

#include "CSceneBase.h"
#include "CSceneTitle.h"
#include "CSceneLoading.h"
#include "CSceneGame.h"
#include "CSceneOver.h"
#include "CSceneManager.h"



// CSceneManager 생성자 첫 호출 시 title Scene를 동적할당 받습니다.
CSceneManager::CSceneManager() {

	this->nowScene = SceneList::SCENETITLE;

	this->sceneCheck = false;

	this->pScene = new CSceneTitle;
}

CSceneManager& CSceneManager::getInstance() {

	static CSceneManager scManager;

	return scManager;
}

void CSceneManager::Update() {

	//sceneCheck 가 true 이면 신을 바꾼다.
	if (this->sceneCheck) {
		

		// 현재 Scene를 delete합니다.
		delete pScene;

		// 현재 신을 확인하여 신을 전환한다.
		switch (this->nowScene) {
		
		case SceneList::SCENETITLE:

			this->sceneCheck = false;

			this->pScene = new CSceneTitle;

			break;

		case SceneList::SCENELOADING:
			
			this->sceneCheck = false;

			this->pScene = new CSceneLoading;
			
			break;

		case SceneList::SCENEGAME:

			this->sceneCheck = false;

			this->pScene = new CSceneGame;

			break;

		case SceneList::SCENEOVER:

			this->sceneCheck = false;

			this->pScene = new CSceneOver;

			break;
		}
	}


	// 해당 Scene의 Updata() 함수를 실행합니다.
	this->pScene->Update();
}


void CSceneManager::Render() {

	// 해당 Scene의 Render() 함수를 실행합니다.
	this->pScene->Render();
}



void CSceneManager::LoadScene(SceneList nowScene){

	// 매개변수로 전달받은 Scene값을 멤버변수에 저장한다.
	this->nowScene = nowScene;

	// 다음 Scene Update시 Scene 전환을 위한 bool 값입니다.
	this->sceneCheck = true;
}