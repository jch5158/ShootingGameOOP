#pragma once
class CSceneLoading : public CSceneBase
{
public:

	CSceneLoading();

	~CSceneLoading();

	virtual void Update();

	virtual void Render();

	// ���������� �˷��ִ� �Լ��Դϴ�.
	static int getStage();

private:

	// �������� üũ�ϴ� static �����Դϴ�.
	static int stage;

	//100%�� ���� ����
	int percent = 0;
};

