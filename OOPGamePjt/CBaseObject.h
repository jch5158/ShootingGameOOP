#pragma once

class CObjectManager;

class CBaseObject
{
	
public:
	CBaseObject(ObjTagList ObjectTag,int iY, int iX);

	// 소멸자 가상함수
	virtual ~CBaseObject();

	// Update 순수 가상함수입니다.
	virtual bool Update() = 0;

	// 랜더 로직 순수 가상함수입니다.
	virtual void Render() = 0;

	// 충돌처리 로직 순수 가상함수 입니다.
	virtual bool Colision(ObjTagList objTag) = 0;

	// 나의 오브젝트 태그를 return 하는 함수입니다.
	virtual ObjTagList getObjTag();
	

	// X좌표와 Y좌표를 얻기위한 friend
	friend class CObjectManager;

	
protected:

	// 객체의 삭제여부를 체크하는 함수입니다.
	bool deleteCheck;

	// X좌표
	int iX;
	
	// Y좌표
	int iY;

	// 오브젝트의 객체 타입입니다.
	ObjTagList ObjectTag;

};


