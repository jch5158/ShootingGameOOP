#pragma once
class CSceneOver:public CSceneBase
{

public:
	virtual void Update();

	virtual void Render();

	CSceneOver();

	~CSceneOver();


private:
	char overText[50] = "                                  Game Over...";


};

