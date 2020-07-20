#include "stdafx.h"
#include "CBaseObject.h"
#include "CBulletObject.h"
#include "CEnemyObject.h"
#include "CPlayerObject.h"
#include "CObjectManager.h"

#include "CSceneBase.h"
#include "CSceneTitle.h"
#include "CSceneLoading.h"
#include "CSceneGame.h"
#include "CSceneOver.h"
#include "CSceneManager.h"


int CPlayerObject::playerHp = 5;


CPlayerObject::CPlayerObject(ObjTagList ObjectTag,int iY,int iX,int pBulletSpeed): CBaseObject(ObjectTag,iY,iX){
  
    // 딜리트 체크
    this->deleteCheck = false;

    this->pBulletSpeed = pBulletSpeed;
}

CPlayerObject::~CPlayerObject() {

}


// 플레이어 키입력값 Update 함수입니다.
bool CPlayerObject::Update() {

    
    KeyList kList;

    while (1) {

        if (CKeyboard::getInstance().IsEmpty())
            break;

        CKeyboard::getInstance().DeQueue(&kList);

        if (kList == KeyList::KEYUP && this->iY > 0) {
            this->iY--;
        }
        else if (kList == KeyList::KEYDOWN && this->iY < SCREEN_HEIGHT-1) {
            this->iY++;
        }
        else if (kList == KeyList::KEYRIGHT && this->iX < SCREEN_WIDTH-2) {
            this->iX++;
        }
        else if (kList == KeyList::KEYLEFT && this->iX >0) {
            this->iX--;
        }
        else if (kList == KeyList::KEYSHOTBULLET) {
            CObjectManager::getInstance().CreateObject(ObjTagList::PLAYERBULLETTAG,this->iY,this->iX,0,this->pBulletSpeed);
        }

    }

	return true;
}

int CPlayerObject::getPlayerHp() {

    return playerHp;
}



void CPlayerObject::Render() {
    
	CScreenBuffer::getInstance().Sprite_Draw(this->iY, this->iX, 'A');
}



// 플레이어가 적군 또는 적군이 쏜 총알이랑 부딪혔을 때 충돌로직이 실행되며,
// 플레이어 체력이 0일 경우 오브젝트 매니저에게 플레이어 객체 삭제요청을 합니다.
bool CPlayerObject::Colision(ObjTagList objTag) {

    static clock_t hitCheck;

    if (objTag == ObjTagList::ENEMYBULLETTAG || objTag == ObjTagList::ENEMYTAG) {

        //  hit 후 플레이어는 0.5초 동안은 무적입니다.
        if (clock() - hitCheck >= 500) {

            hitCheck = clock();
            if (playerHp > 1) {
                playerHp--;
                return false;
            }
            else {

                
                this->deleteCheck = true;

                playerHp--;

                //CObjectManager::getInstance().DestroyObject(this);

                CSceneManager::getInstance().LoadScene(SceneList::SCENEOVER);
                return true;
            }
        
        }
    }
    

    return false;

}