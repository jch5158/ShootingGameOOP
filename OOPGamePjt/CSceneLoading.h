#pragma once
class CSceneLoading : public CSceneBase
{
public:

	CSceneLoading();

	~CSceneLoading();

	virtual void Update();

	virtual void Render();

	// 스테이지를 알려주는 함수입니다.
	static int getStage();

private:

	// 스테이지 체크하는 static 변수입니다.
	static int stage;

	//100%시 게임 시작
	int percent = 0;
};

