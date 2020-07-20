#pragma once
class CPlayerObject : public CBaseObject
{
public:
	CPlayerObject(ObjTagList ObjectTag,int iY,int iX,int pBulletSpeed);

	virtual ~CPlayerObject();

	virtual bool Update();
	
	virtual void Render();

	virtual bool Colision(ObjTagList objTag);


	// 플레이어 체력을 return하는 static 함수입니다.
	static int getPlayerHp();


private:

	// 플레이어 총알의 속도입니다.
	int pBulletSpeed;

	// 플레이어 체력값 static함수입니다.
	static int playerHp;

};
