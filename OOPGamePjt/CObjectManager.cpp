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


// 매개변수 => 오브젝트 태그, Y좌표, X좌표, 이동속도, 객체가 쏜 총알의 속도
bool CObjectManager::CreateObject(ObjTagList objectTag,int iY, int iX,int objSpeed,int objBulletSpeed) {

	
	switch (objectTag) {

	case ObjTagList::PLAYERTAG:

		// 매개변수 => 오브젝트 태크, Y좌표, X좌표, 플레이어의 총알 속도입니다.
		objList.PushBack(new CPlayerObject(ObjTagList::PLAYERTAG,iY,iX,30));
		return true;
		
	case ObjTagList::ENEMYTAG:

		// 매개변수 => 오브젝트 태크, Y좌표, X좌표, 적군 이동속도, 적군 총알의 속도입니다.
		objList.PushBack(new CEnemyObject(ObjTagList::ENEMYTAG, iY, iX,objSpeed, objBulletSpeed));
		return true;
		
	case ObjTagList::PLAYERBULLETTAG:
		
		// 매개변수 => 오브젝트 태크, Y좌표, X좌표, 총알의 속도입니다.
		objList.PushBack(new CBulletObject(ObjTagList::PLAYERBULLETTAG, iY - 1, iX, objBulletSpeed));
		return true;	

	case ObjTagList::ENEMYBULLETTAG:

		// 매개변수 => 오브젝트 태크, Y좌표, X좌표, 총알의 속도입니다.
		objList.PushBack(new CBulletObject(ObjTagList::ENEMYBULLETTAG, iY + 1, iX, objBulletSpeed));
		return true;
	
	}	
}

// 오브젝트 객체를 삭제할 때 사용하는 함수입니다.
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

// 모든 객체를 삭제하는 함수입니다.
bool CObjectManager::DestroyObjectAll() {

	CList<CBaseObject*>::Iterator iterE = objList.end();

	for (CList<CBaseObject*>::Iterator iter = objList.begin(); iter != iterE;)
	{
		
		delete* iter;

		iter = objList.erase(iter);
	}

	return true;
}


// Iterator를 이용하여 오브젝트의 Update를 랩핑한 함수입니다.
bool CObjectManager::ObjUpdate() {

	CList<CBaseObject*>::Iterator iterE = objList.end();

	for (CList<CBaseObject*>::Iterator iter = objList.begin(); iter != iterE; ++iter)
	{
		iter->Update();
	}

	return true;
}

// Iterator를 이용하여 오브젝트의 Render를 랩핑한 함수입니다.
bool CObjectManager::ObjRender() {

	CList<CBaseObject*>::Iterator iterE = objList.end();

	for (CList<CBaseObject*>::Iterator iter = objList.begin(); iter != iterE; ++iter) {

		iter->Render();

	}

	return true;
}

bool CObjectManager::Update() {

	// 사용자 키보드 입력함수입니다.
	CKeyboard::getInstance().PlayController();

	// Iterator를 이용하여 오브젝트의 Update를 랩핑한 함수입니다.
	ObjUpdate();

	// 오브젝트 충돌 체크를 하는 함수입니다. 
	Collision();


	// deleteCheck에서 true값일 경우 해당 오브젝트를 삭제합니다.
	DestroyObject();


	return true;
}


bool CObjectManager::Render() {
	// Iterator를 이용하여 오브젝트의 Render를 랩핑한 함수입니다.
	ObjRender();

	return true;
}



// 객체의 충돌을 체크하여 오브젝트에게 알려주는 함수입니다.
bool CObjectManager::Collision() {

	CList<CBaseObject*>::Iterator iterE = objList.end();

	for (CList<CBaseObject*>::Iterator iter = objList.begin(); iter != iterE;)
	{
		for (CList<CBaseObject*>::Iterator iterCheck = objList.begin(); iterCheck != iterE;) 
		{

			// 동일한 데이터일 경우 iterCheck의 다음 iterCheck를 구한다.
			if (iter == iterCheck) 
			{
				++iterCheck;
				
				// iterCheck가 == iterE와 동일할 경우 ++iter 후 반복문을 빠져나온다.
				if (iterCheck == iterE)
				{
					++iter;
					break;
				}
			}


			// iter와 iterCheck의 좌표가 같으면 안의 로직을 실행한다.
			if (iter->iX == iterCheck->iX && iter->iY == iterCheck->iY)
			{
				// 각 iterator의 오브젝트 태그를 미리 변수에 담는다.
				ObjTagList iterObjTag = iter->ObjectTag;
				ObjTagList iterCheckObjTag = iterCheck->ObjectTag;

				// iterBuffer에 iter의 다음 iter의 값을 담아둔다.
				CList<CBaseObject*>::Iterator iterBuffer = iter.NextIter();				

				// 해당 오브젝트에게 오브젝트 태그를 매개변수로 전달한다.
				iter->Colision(iterCheckObjTag);

				// iterBuffer에 담아둔 iterator값을 iter에 담아둔다.
				iter = iterBuffer;
				

				// iterBuffer에 iter의 다음 iter의 값을 담아둔다.
				iterBuffer = iterCheck.NextIter();	

				// 해당 오브젝트에게 오브젝트 태그를 매개변수로 전달한다.
				iterCheck->Colision(iterObjTag);

				// iterBuffer에 iter의 다음 iter의 값을 담아둔다.
				iterCheck = iterBuffer;


				// 아래 조건일 경우 for문을 빠져나온다.
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