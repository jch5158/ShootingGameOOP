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

	// 총알이 움직이는 함수입니다.
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


		//아군 총알인지 적군 총알인지 체크
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

	// 플레이어 또는 적군이 쏜 총알에 따라서 총알 모양이 다릅니다.
	if (this->bulletType == BulletTypeList::PLAYERBULLET) {
		CScreenBuffer::getInstance().Sprite_Draw(this->iY, this->iX, '^');

	}
	else {
		CScreenBuffer::getInstance().Sprite_Draw(this->iY, this->iX, 'v');
	}


}


bool CBulletObject::Colision(ObjTagList objTag) {
	
	// 적군이랑 적군이 쏜 총알이 부딪혔을 때 아무런 로직이 발생하지 않습니다.
	if (objTag == ObjTagList::ENEMYTAG && this->ObjectTag == ObjTagList::ENEMYBULLETTAG) {
		return false;
	}

	// 플레이어랑 플레이어가 쏜 총알이 부딪혔을 때 아무런 로직이 발생하지 않습니다.
	else if (objTag == ObjTagList::PLAYERTAG && this->ObjectTag == ObjTagList::PLAYERBULLETTAG) {
		return false;
	}

	// 총알을 삭제해달라고 ObjectManager한테 요청합니다.
	//CObjectManager::getInstance().DestroyObject(this);


	this->deleteCheck = true;

	return true;
}

