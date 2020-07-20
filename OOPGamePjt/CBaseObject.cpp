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


// ������Ʈ �±׸� return�ϴ� �Լ��Դϴ�.
ObjTagList CBaseObject::getObjTag() {

	return this->ObjectTag;
}