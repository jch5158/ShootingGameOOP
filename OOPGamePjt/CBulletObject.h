#pragma once

class CBulletObject:public CBaseObject
{

public:
	CBulletObject(ObjTagList ObjectTag,int iY,int iX,int bulletSpeed);

	virtual ~CBulletObject();

	virtual bool Update();

	virtual void Render();

	// �浹���� �Լ��Դϴ�. �Ű������� ������Ʈ �±��Դϴ�.
	virtual bool Colision(ObjTagList objTag);


private:

	// �Ѿ� ������ ���� �Լ��Դϴ�.
	bool BulletMove();

	// �ҷ��� ���ǵ� ����Լ��Դϴ�.
	int bulletSpeed;

	// PLAYERBULLET == �÷��̾� �Ѿ�, ENEMYBULLET == ���� �Ѿ�
	BulletTypeList bulletType;

	// �ҷ� ���ǵ�üũ�� ���� �����Դϴ�.
	clock_t bulletSpeedCheck;
};


