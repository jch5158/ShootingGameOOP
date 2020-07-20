#include "stdafx.h"

#include "CSceneBase.h"
#include "CSceneTitle.h"
#include "CSceneLoading.h"
#include "CSceneGame.h"
#include "CSceneOver.h"
#include "CSceneManager.h"



// CSceneManager ������ ù ȣ�� �� title Scene�� �����Ҵ� �޽��ϴ�.
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

	//sceneCheck �� true �̸� ���� �ٲ۴�.
	if (this->sceneCheck) {
		

		// ���� Scene�� delete�մϴ�.
		delete pScene;

		// ���� ���� Ȯ���Ͽ� ���� ��ȯ�Ѵ�.
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


	// �ش� Scene�� Updata() �Լ��� �����մϴ�.
	this->pScene->Update();
}


void CSceneManager::Render() {

	// �ش� Scene�� Render() �Լ��� �����մϴ�.
	this->pScene->Render();
}



void CSceneManager::LoadScene(SceneList nowScene){

	// �Ű������� ���޹��� Scene���� ��������� �����Ѵ�.
	this->nowScene = nowScene;

	// ���� Scene Update�� Scene ��ȯ�� ���� bool ���Դϴ�.
	this->sceneCheck = true;
}