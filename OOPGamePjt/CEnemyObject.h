#pragma once
class CEnemyObject:public CBaseObject
{

public:

	CEnemyObject(ObjTagList ObjectTag,int iY,int iX, int eSpeed,int eBulletSpeed);

	virtual ~CEnemyObject();

	virtual bool Update();

	virtual void Render();

	//충돌처리 로직입니다.
	virtual bool Colision(ObjTagList objTag);

	// 몬스터 개체 수 0이면 다음 씬을 호출하는 함수를 구현합니다. 로딩씬에서 변수를 셋팅합니다.
	static int numberOfEnemy;

private:

	// 적군 움직임 로직함수입니다.
	bool EnemyMove();

	// 적군이 총을 쏘는 로직입니다.
	bool EnemyAttack();


	// true 오른쪽 false 왼쪽
	bool eDirection;

	// 몬스터 총알 속도
	int eBulletSpeed;

	// 몬스터 속도
	int eSpeed;

	// 몬스터 이동반경을 체크하는 변수입니다.
	int distance = 0;

	clock_t eSpeedCheck;

};

