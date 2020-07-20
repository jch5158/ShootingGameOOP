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

	// 총알의 속도
	int _eBulletSpeed;
	
	// 적군의 이동속도
	int _eSpeed;

	FILE* fp = nullptr;

	//스테이지에 해당하는 몬스터 정보를 텍스트 파일에서 가져온다
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
	
		// 매개변수 => 오브젝트 태크, Y좌표, X좌표, 몬스터의 스피드, 몬스터가 쏜 총알의 스피드
		CObjectManager::getInstance().CreateObject(ObjTagList::ENEMYTAG, _iY, _iX,_eSpeed, _eBulletSpeed);
	}

	CEnemyObject::numberOfEnemy = 20;

	fclose(fp);
}


CSceneLoading::~CSceneLoading() {
	
	

}

void CSceneLoading::Update() {
    
    static clock_t loadingCheck = clock();

	
    // 0.02초마다 체크
    if (clock() - loadingCheck >= 20) {
        loadingCheck = clock();
        this->percent += 1;
    }


	//percent가 100일 경우 Game씬으로 CSceneManager에게 전환 요청을 한다.
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
