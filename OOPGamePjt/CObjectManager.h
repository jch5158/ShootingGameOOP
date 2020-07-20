#pragma once
class CObjectManager
{
public:
	// �̱���
	static CObjectManager& getInstance();


	// ������Ʈ�� �����ϴ� �����Դϴ�.
	bool CreateObject(ObjTagList objectTag,int iY,int iX, int objSpeed,int objBulletSpeed);


	// deleteObject�� Ʈ���� ��� ������Ʈ�� ����� �����Դϴ�.
	bool DestroyObject();


	// ���� ���������� ���� ��� ��ü�� �����Ѵ�.
	bool DestroyObjectAll();


	// Ű���� �Է� �� ������ ó���ϴ� �Լ��Դϴ�.
	bool Update();

	// ����Ʈ�� ���� ó���� �ϴ� �Լ��Դϴ�.
	bool Render();

	// ��ü�� �浹 Ȯ���� �ϴ� �Լ��Դϴ�.
	bool Collision();
	
	CList<CBaseObject*> objList;

private:
	
	// ������
	CObjectManager() {};

	// ���������
	CObjectManager(const CObjectManager& rhs) {}

	//  Iterator�� �̿��Ͽ�  ������Ʈ�� Update�� ������ �Լ��Դϴ�.
	bool ObjUpdate();

	// Iterator�� �̿��Ͽ� ������Ʈ�� Render�� ������ �Լ��Դϴ�.
	bool ObjRender();

	// ���� 
	CObjectManager& operator=(const CObjectManager& rhs) {}
};

