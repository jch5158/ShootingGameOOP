#pragma once
class CPlayerObject : public CBaseObject
{
public:
	CPlayerObject(ObjTagList ObjectTag,int iY,int iX,int pBulletSpeed);

	virtual ~CPlayerObject();

	virtual bool Update();
	
	virtual void Render();

	virtual bool Colision(ObjTagList objTag);


	// �÷��̾� ü���� return�ϴ� static �Լ��Դϴ�.
	static int getPlayerHp();


private:

	// �÷��̾� �Ѿ��� �ӵ��Դϴ�.
	int pBulletSpeed;

	// �÷��̾� ü�°� static�Լ��Դϴ�.
	static int playerHp;

};
