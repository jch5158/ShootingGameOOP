#pragma once
class CObjectManager
{
public:
	// 싱글톤
	static CObjectManager& getInstance();


	// 오브젝트를 생성하는 로직입니다.
	bool CreateObject(ObjTagList objectTag,int iY,int iX, int objSpeed,int objBulletSpeed);


	// deleteObject가 트루일 경우 오브젝트를 지우는 로직입니다.
	bool DestroyObject();


	// 다음 스테이지를 위해 모든 객체를 정리한다.
	bool DestroyObjectAll();


	// 키보드 입력 및 로직을 처리하는 함수입니다.
	bool Update();

	// 리스트의 랜더 처리를 하는 함수입니다.
	bool Render();

	// 객체들 충돌 확인을 하는 함수입니다.
	bool Collision();
	
	CList<CBaseObject*> objList;

private:
	
	// 생성자
	CObjectManager() {};

	// 복사생성자
	CObjectManager(const CObjectManager& rhs) {}

	//  Iterator를 이용하여  오브젝트의 Update를 랩핑한 함수입니다.
	bool ObjUpdate();

	// Iterator를 이용하여 오브젝트의 Render를 랩핑한 함수입니다.
	bool ObjRender();

	// 대입 
	CObjectManager& operator=(const CObjectManager& rhs) {}
};

