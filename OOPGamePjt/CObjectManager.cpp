#include "stdafx.h"
#include "CBaseObject.h"
#include "CBulletObject.h"
#include "CEnemyObject.h"
#include "CPlayerObject.h"
#include "CObjectManager.h"



CObjectManager& CObjectManager::getInstance() {
	static CObjectManager objManager;

	return objManager;
}


// �Ű����� => ������Ʈ �±�, Y��ǥ, X��ǥ, �̵��ӵ�, ��ü�� �� �Ѿ��� �ӵ�
bool CObjectManager::CreateObject(ObjTagList objectTag,int iY, int iX,int objSpeed,int objBulletSpeed) {

	
	switch (objectTag) {

	case ObjTagList::PLAYERTAG:

		// �Ű����� => ������Ʈ ��ũ, Y��ǥ, X��ǥ, �÷��̾��� �Ѿ� �ӵ��Դϴ�.
		objList.PushBack(new CPlayerObject(ObjTagList::PLAYERTAG,iY,iX,30));
		return true;
		
	case ObjTagList::ENEMYTAG:

		// �Ű����� => ������Ʈ ��ũ, Y��ǥ, X��ǥ, ���� �̵��ӵ�, ���� �Ѿ��� �ӵ��Դϴ�.
		objList.PushBack(new CEnemyObject(ObjTagList::ENEMYTAG, iY, iX,objSpeed, objBulletSpeed));
		return true;
		
	case ObjTagList::PLAYERBULLETTAG:
		
		// �Ű����� => ������Ʈ ��ũ, Y��ǥ, X��ǥ, �Ѿ��� �ӵ��Դϴ�.
		objList.PushBack(new CBulletObject(ObjTagList::PLAYERBULLETTAG, iY - 1, iX, objBulletSpeed));
		return true;	

	case ObjTagList::ENEMYBULLETTAG:

		// �Ű����� => ������Ʈ ��ũ, Y��ǥ, X��ǥ, �Ѿ��� �ӵ��Դϴ�.
		objList.PushBack(new CBulletObject(ObjTagList::ENEMYBULLETTAG, iY + 1, iX, objBulletSpeed));
		return true;
	
	}	
}

// ������Ʈ ��ü�� ������ �� ����ϴ� �Լ��Դϴ�.
bool CObjectManager::DestroyObject() {
	
	CList<CBaseObject*>::Iterator iterE = objList.end();

	for (CList<CBaseObject*>::Iterator iter = objList.begin(); iter != iterE;)
	{

		if (iter->deleteCheck == true) 
		{
			delete* iter;

			iter = objList.erase(iter);
		}
		else 
		{
			++iter;
		}
	}

	return true;
}

// ��� ��ü�� �����ϴ� �Լ��Դϴ�.
bool CObjectManager::DestroyObjectAll() {

	CList<CBaseObject*>::Iterator iterE = objList.end();

	for (CList<CBaseObject*>::Iterator iter = objList.begin(); iter != iterE;)
	{
		
		delete* iter;

		iter = objList.erase(iter);
	}

	return true;
}


// Iterator�� �̿��Ͽ� ������Ʈ�� Update�� ������ �Լ��Դϴ�.
bool CObjectManager::ObjUpdate() {

	CList<CBaseObject*>::Iterator iterE = objList.end();

	for (CList<CBaseObject*>::Iterator iter = objList.begin(); iter != iterE; ++iter)
	{
		iter->Update();
	}

	return true;
}

// Iterator�� �̿��Ͽ� ������Ʈ�� Render�� ������ �Լ��Դϴ�.
bool CObjectManager::ObjRender() {

	CList<CBaseObject*>::Iterator iterE = objList.end();

	for (CList<CBaseObject*>::Iterator iter = objList.begin(); iter != iterE; ++iter) {

		iter->Render();

	}

	return true;
}

bool CObjectManager::Update() {

	// ����� Ű���� �Է��Լ��Դϴ�.
	CKeyboard::getInstance().PlayController();

	// Iterator�� �̿��Ͽ� ������Ʈ�� Update�� ������ �Լ��Դϴ�.
	ObjUpdate();

	// ������Ʈ �浹 üũ�� �ϴ� �Լ��Դϴ�. 
	Collision();


	// deleteCheck���� true���� ��� �ش� ������Ʈ�� �����մϴ�.
	DestroyObject();


	return true;
}


bool CObjectManager::Render() {
	// Iterator�� �̿��Ͽ� ������Ʈ�� Render�� ������ �Լ��Դϴ�.
	ObjRender();

	return true;
}



// ��ü�� �浹�� üũ�Ͽ� ������Ʈ���� �˷��ִ� �Լ��Դϴ�.
bool CObjectManager::Collision() {

	CList<CBaseObject*>::Iterator iterE = objList.end();

	for (CList<CBaseObject*>::Iterator iter = objList.begin(); iter != iterE;)
	{
		for (CList<CBaseObject*>::Iterator iterCheck = objList.begin(); iterCheck != iterE;) 
		{

			// ������ �������� ��� iterCheck�� ���� iterCheck�� ���Ѵ�.
			if (iter == iterCheck) 
			{
				++iterCheck;
				
				// iterCheck�� == iterE�� ������ ��� ++iter �� �ݺ����� �������´�.
				if (iterCheck == iterE)
				{
					++iter;
					break;
				}
			}


			// iter�� iterCheck�� ��ǥ�� ������ ���� ������ �����Ѵ�.
			if (iter->iX == iterCheck->iX && iter->iY == iterCheck->iY)
			{
				// �� iterator�� ������Ʈ �±׸� �̸� ������ ��´�.
				ObjTagList iterObjTag = iter->ObjectTag;
				ObjTagList iterCheckObjTag = iterCheck->ObjectTag;

				// iterBuffer�� iter�� ���� iter�� ���� ��Ƶд�.
				CList<CBaseObject*>::Iterator iterBuffer = iter.NextIter();				

				// �ش� ������Ʈ���� ������Ʈ �±׸� �Ű������� �����Ѵ�.
				iter->Colision(iterCheckObjTag);

				// iterBuffer�� ��Ƶ� iterator���� iter�� ��Ƶд�.
				iter = iterBuffer;
				

				// iterBuffer�� iter�� ���� iter�� ���� ��Ƶд�.
				iterBuffer = iterCheck.NextIter();	

				// �ش� ������Ʈ���� ������Ʈ �±׸� �Ű������� �����Ѵ�.
				iterCheck->Colision(iterObjTag);

				// iterBuffer�� iter�� ���� iter�� ���� ��Ƶд�.
				iterCheck = iterBuffer;


				// �Ʒ� ������ ��� for���� �������´�.
				if (iter == iterE || iterCheck == iterE)
				break;

			}
			else 
			{
				++iterCheck;

				if (iterCheck == iterE) {
					++iter;
					break;
				}
			}
			
		}
	}

	return true;
}