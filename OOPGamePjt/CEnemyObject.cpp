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

	// true�� ��� ����Ʈ
	this->deleteCheck = false;

	// �����̴� �ӵ��Դϴ�.
	this->eSpeed = eSpeed;

	// ���� �Ѿ��� �ӵ��Դϴ�.
	this->eBulletSpeed = eBulletSpeed;

	// ture�� ������ false�� �����Դϴ�.
	this->eDirection = true;

	this->eSpeedCheck = clock();
}

CEnemyObject::~CEnemyObject() {

}


bool CEnemyObject::Update() {


	// ������ �����̴� �Լ��Դϴ�.
	EnemyMove();
	
	// ������ ���� Ȯ���� ���� ��� �����Դϴ�.
	EnemyAttack();

	return false;
}


bool CEnemyObject::EnemyMove() {

	if (clock() - this->eSpeedCheck >= this->eSpeed) {
		if (this->eDirection == true) 
		{
			this->iX++;

			this->distance += 1;

			// ���������� 20��ŭ �����̸� ������ ��ȯ�մϴ�.
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

			// �������� 18��ŭ �����̸� ������ ��ȯ�մϴ�.
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
	// 1% Ȯ���� ������Ʈ �Ŵ������� �Ѿ� ���� ��û�� �մϴ�.
	if (rand() % 100 == 0) 
	{
		CObjectManager::getInstance().CreateObject(ObjTagList::ENEMYBULLETTAG, this->iY, this->iX, 0,this->eBulletSpeed);

		return true;
	}
}



void CEnemyObject::Render() 
{
	// ���� ������
	CScreenBuffer::getInstance().Sprite_Draw(this->iY, this->iX, '#');
}

bool CEnemyObject::Colision(ObjTagList objTag) 
{

	if (objTag == ObjTagList::PLAYERBULLETTAG) 
	{

		if (this->deleteCheck == true)
			return false;


		this->deleteCheck = true;
		// numberOfEnemy�� 0�� �Ǹ� ���� ������ �Ѿ�ϴ�.
		numberOfEnemy -= 1;


		// getStage()�� static���� �����Ǿ������� return ���� 3�̸� SCENEOVER�� �ȴ�.
		if (numberOfEnemy == 0 && CSceneLoading::getStage() != 3) 
		{
			CSceneManager::getInstance().LoadScene(SceneList::SCENELOADING);
		}
		else if(numberOfEnemy == 0) 
		{
			CSceneManager::getInstance().LoadScene(SceneList::SCENEOVER);
		}

		// �÷��̾��� �Ѿ��̶� �ε����� ��� ������Ʈ �Ŵ������� ������û�� �Ѵ�.
		//CObjectManager::getInstance().DestroyObject(this);


		return true;
	}

	return false;
}