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



int CSceneLoading::stage=0;


CSceneLoading::CSceneLoading() {

	CObjectManager::getInstance().CreateObject(ObjTagList::PLAYERTAG, 15, 40, 0, 0);


	int _iX;
	int _iY;

	// �Ѿ��� �ӵ�
	int _eBulletSpeed;
	
	// ������ �̵��ӵ�
	int _eSpeed;

	FILE* fp = nullptr;

	//���������� �ش��ϴ� ���� ������ �ؽ�Ʈ ���Ͽ��� �����´�
	if (stage == 0) {
		if (fopen_s(&fp, "enemyList1.txt", "rt"))
			return;
		stage++;
	}
	else if (stage == 1) {
		if (fopen_s(&fp, "enemyList2.txt", "rt"))
			return;
		stage++;
	}
	else if (stage == 2) {
		if (fopen_s(&fp, "enemyList3.txt", "rt"))
			return;
		stage++;
	}

	for (int index = 0; index < 20; index++) {
		fscanf_s(fp, "X,Y : (%d,%d)\nebulletSpeed : %d\neSpeed : %d\n", &_iX, &_iY, &_eBulletSpeed, &_eSpeed);
	
		// �Ű����� => ������Ʈ ��ũ, Y��ǥ, X��ǥ, ������ ���ǵ�, ���Ͱ� �� �Ѿ��� ���ǵ�
		CObjectManager::getInstance().CreateObject(ObjTagList::ENEMYTAG, _iY, _iX,_eSpeed, _eBulletSpeed);
	}

	CEnemyObject::numberOfEnemy = 20;

	fclose(fp);
}


CSceneLoading::~CSceneLoading() {
	
	

}

void CSceneLoading::Update() {
    
    static clock_t loadingCheck = clock();

	
    // 0.02�ʸ��� üũ
    if (clock() - loadingCheck >= 20) {
        loadingCheck = clock();
        this->percent += 1;
    }


	//percent�� 100�� ��� Game������ CSceneManager���� ��ȯ ��û�� �Ѵ�.
    if (percent > 100) {

        CSceneManager::getInstance().LoadScene(SceneList::SCENEGAME);
        this->percent = 0;
    }
}


void CSceneLoading::Render() {
    
	CScreenBuffer::getInstance().Sprite_Draw_Loading(stage, this->percent);
    
}

int CSceneLoading::getStage() {

	return stage;
}
