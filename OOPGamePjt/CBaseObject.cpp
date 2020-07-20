#include "stdafx.h"

#include "CBaseObject.h"
#include "CBulletObject.h"
#include "CEnemyObject.h"
#include "CPlayerObject.h"
#include "CObjectManager.h"


CBaseObject::CBaseObject(ObjTagList ObjectTag,int iY, int iX):ObjectTag(ObjectTag),iY(iY),iX(iX){

}


CBaseObject::~CBaseObject() {

}


// 오브젝트 태그를 return하는 함수입니다.
ObjTagList CBaseObject::getObjTag() {

	return this->ObjectTag;
}