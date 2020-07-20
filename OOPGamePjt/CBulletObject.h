#pragma once

class CBulletObject:public CBaseObject
{

public:
	CBulletObject(ObjTagList ObjectTag,int iY,int iX,int bulletSpeed);

	virtual ~CBulletObject();

	virtual bool Update();

	virtual void Render();

	// 충돌로직 함수입니다. 매개변수는 오브젝트 태그입니다.
	virtual bool Colision(ObjTagList objTag);


private:

	// 총알 움직임 로직 함수입니다.
	bool BulletMove();

	// 불렛의 스피드 멤버함수입니다.
	int bulletSpeed;

	// PLAYERBULLET == 플레이어 총알, ENEMYBULLET == 적군 총알
	BulletTypeList bulletType;

	// 불렛 스피드체크를 위한 변수입니다.
	clock_t bulletSpeedCheck;
};


