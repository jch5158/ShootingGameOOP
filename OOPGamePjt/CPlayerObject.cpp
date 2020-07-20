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
  
    // ����Ʈ üũ
    this->deleteCheck = false;

    this->pBulletSpeed = pBulletSpeed;
}

CPlayerObject::~CPlayerObject() {

}


// �÷��̾� Ű�Է°� Update �Լ��Դϴ�.
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



// �÷��̾ ���� �Ǵ� ������ �� �Ѿ��̶� �ε����� �� �浹������ ����Ǹ�,
// �÷��̾� ü���� 0�� ��� ������Ʈ �Ŵ������� �÷��̾� ��ü ������û�� �մϴ�.
bool CPlayerObject::Colision(ObjTagList objTag) {

    static clock_t hitCheck;

    if (objTag == ObjTagList::ENEMYBULLETTAG || objTag == ObjTagList::ENEMYTAG) {

        //  hit �� �÷��̾�� 0.5�� ������ �����Դϴ�.
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