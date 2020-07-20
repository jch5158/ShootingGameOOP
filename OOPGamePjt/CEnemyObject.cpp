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


int CEnemyObject::numberOfEnemy;

CEnemyObject::CEnemyObject(ObjTagList ObjectTag,int iY,int iX,int eSpeed,int eBulletSpeed):CBaseObject(ObjectTag,iY,iX) {

	// true일 경우 딜리트
	this->deleteCheck = false;

	// 움직이는 속도입니다.
	this->eSpeed = eSpeed;

	// 적군 총알의 속도입니다.
	this->eBulletSpeed = eBulletSpeed;

	// ture는 오른쪽 false는 왼쪽입니다.
	this->eDirection = true;

	this->eSpeedCheck = clock();
}

CEnemyObject::~CEnemyObject() {

}


bool CEnemyObject::Update() {


	// 적군이 움직이는 함수입니다.
	EnemyMove();
	
	// 적군이 랜덤 확률로 총을 쏘는 로직입니다.
	EnemyAttack();

	return false;
}


bool CEnemyObject::EnemyMove() {

	if (clock() - this->eSpeedCheck >= this->eSpeed) {
		if (this->eDirection == true) 
		{
			this->iX++;

			this->distance += 1;

			// 오른쪽으로 20만큼 움직이면 방향을 전환합니다.
			if (this->distance == 20) {
				this->eDirection = false;
			}

			this->eSpeedCheck = clock();
			return true;
		}
		else 
		{
			this->iX--;

			this->distance -= 1;

			// 왼쪽으로 18만큼 움직이면 방향을 전환합니다.
			if (this->distance == -18) {

				this->eDirection = true;
			}

			this->eSpeedCheck = clock();
			return true;
		}
	}

	return false;
}

bool CEnemyObject::EnemyAttack() 
{
	// 1% 확률로 오브젝트 매니저에게 총알 생성 요청을 합니다.
	if (rand() % 100 == 0) 
	{
		CObjectManager::getInstance().CreateObject(ObjTagList::ENEMYBULLETTAG, this->iY, this->iX, 0,this->eBulletSpeed);

		return true;
	}
}



void CEnemyObject::Render() 
{
	// 적군 랜더링
	CScreenBuffer::getInstance().Sprite_Draw(this->iY, this->iX, '#');
}

bool CEnemyObject::Colision(ObjTagList objTag) 
{

	if (objTag == ObjTagList::PLAYERBULLETTAG) 
	{

		if (this->deleteCheck == true)
			return false;


		this->deleteCheck = true;
		// numberOfEnemy가 0이 되면 다음 씬으로 넘어갑니다.
		numberOfEnemy -= 1;


		// getStage()는 static으로 구현되어있으며 return 값이 3이면 SCENEOVER가 된다.
		if (numberOfEnemy == 0 && CSceneLoading::getStage() != 3) 
		{
			CSceneManager::getInstance().LoadScene(SceneList::SCENELOADING);
		}
		else if(numberOfEnemy == 0) 
		{
			CSceneManager::getInstance().LoadScene(SceneList::SCENEOVER);
		}

		// 플레이어의 총알이랑 부딪혔을 경우 오브젝트 매니저에게 삭제요청을 한다.
		//CObjectManager::getInstance().DestroyObject(this);


		return true;
	}

	return false;
}