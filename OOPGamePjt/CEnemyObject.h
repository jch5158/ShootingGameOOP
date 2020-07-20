#pragma once
class CEnemyObject:public CBaseObject
{

public:

	CEnemyObject(ObjTagList ObjectTag,int iY,int iX, int eSpeed,int eBulletSpeed);

	virtual ~CEnemyObject();

	virtual bool Update();

	virtual void Render();

	//�浹ó�� �����Դϴ�.
	virtual bool Colision(ObjTagList objTag);

	// ���� ��ü �� 0�̸� ���� ���� ȣ���ϴ� �Լ��� �����մϴ�. �ε������� ������ �����մϴ�.
	static int numberOfEnemy;

private:

	// ���� ������ �����Լ��Դϴ�.
	bool EnemyMove();

	// ������ ���� ��� �����Դϴ�.
	bool EnemyAttack();


	// true ������ false ����
	bool eDirection;

	// ���� �Ѿ� �ӵ�
	int eBulletSpeed;

	// ���� �ӵ�
	int eSpeed;

	// ���� �̵��ݰ��� üũ�ϴ� �����Դϴ�.
	int distance = 0;

	clock_t eSpeedCheck;

};

