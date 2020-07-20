#pragma once

class CObjectManager;

class CBaseObject
{
	
public:
	CBaseObject(ObjTagList ObjectTag,int iY, int iX);

	// �Ҹ��� �����Լ�
	virtual ~CBaseObject();

	// Update ���� �����Լ��Դϴ�.
	virtual bool Update() = 0;

	// ���� ���� ���� �����Լ��Դϴ�.
	virtual void Render() = 0;

	// �浹ó�� ���� ���� �����Լ� �Դϴ�.
	virtual bool Colision(ObjTagList objTag) = 0;

	// ���� ������Ʈ �±׸� return �ϴ� �Լ��Դϴ�.
	virtual ObjTagList getObjTag();
	

	// X��ǥ�� Y��ǥ�� ������� friend
	friend class CObjectManager;

	
protected:

	// ��ü�� �������θ� üũ�ϴ� �Լ��Դϴ�.
	bool deleteCheck;

	// X��ǥ
	int iX;
	
	// Y��ǥ
	int iY;

	// ������Ʈ�� ��ü Ÿ���Դϴ�.
	ObjTagList ObjectTag;

};


