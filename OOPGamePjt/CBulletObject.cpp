#include "stdafx.h"
#include "CBaseObject.h"
#include "CBulletObject.h"
#include "CEnemyObject.h"
#include "CPlayerObject.h"
#include "CObjectManager.h"


CBulletObject::CBulletObject(ObjTagList ObjectTag,int iY,int iX,int bulletSpeed): CBaseObject(ObjectTag,iY,iX) {

	if (this->ObjectTag == ObjTagList::PLAYERBULLETTAG) {
		this->deleteCheck = false;
		this->bulletType = BulletTypeList::PLAYERBULLET;
		this->bulletSpeed = bulletSpeed;
		this->bulletSpeedCheck = clock();
		this->deleteCheck = false;
	}
	else{
		this->deleteCheck = false;
		this->bulletType = BulletTypeList::ENEMYBULLET;
		this->bulletSpeed = bulletSpeed;
		this->bulletSpeedCheck = clock();
		
	}

}

CBulletObject::~CBulletObject() {

}


bool CBulletObject::Update() {

	// �Ѿ��� �����̴� �Լ��Դϴ�.
	BulletMove();
	
	return true;
}




bool CBulletObject::BulletMove() {

	if (clock() - this->bulletSpeedCheck >= this->bulletSpeed) {
		
		if (this->iY == 0 || this->iY == SCREEN_HEIGHT) {
			this->bulletSpeedCheck = clock();

			this->deleteCheck = true;
			return true;
		}


		//�Ʊ� �Ѿ����� ���� �Ѿ����� üũ
		if (this->bulletType == BulletTypeList::PLAYERBULLET)
			this->iY -= 1;
		else
			this->iY += 1;

		bulletSpeedCheck = clock();
		return true;
	}

	return false;
}


void CBulletObject::Render() {

	// �÷��̾� �Ǵ� ������ �� �Ѿ˿� ���� �Ѿ� ����� �ٸ��ϴ�.
	if (this->bulletType == BulletTypeList::PLAYERBULLET) {
		CScreenBuffer::getInstance().Sprite_Draw(this->iY, this->iX, '^');

	}
	else {
		CScreenBuffer::getInstance().Sprite_Draw(this->iY, this->iX, 'v');
	}


}


bool CBulletObject::Colision(ObjTagList objTag) {
	
	// �����̶� ������ �� �Ѿ��� �ε����� �� �ƹ��� ������ �߻����� �ʽ��ϴ�.
	if (objTag == ObjTagList::ENEMYTAG && this->ObjectTag == ObjTagList::ENEMYBULLETTAG) {
		return false;
	}

	// �÷��̾�� �÷��̾ �� �Ѿ��� �ε����� �� �ƹ��� ������ �߻����� �ʽ��ϴ�.
	else if (objTag == ObjTagList::PLAYERTAG && this->ObjectTag == ObjTagList::PLAYERBULLETTAG) {
		return false;
	}

	// �Ѿ��� �����ش޶�� ObjectManager���� ��û�մϴ�.
	//CObjectManager::getInstance().DestroyObject(this);


	this->deleteCheck = true;

	return true;
}

