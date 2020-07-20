#pragma once
class CSceneTitle : public CSceneBase
{

public:

	virtual void Update();

	virtual void Render();

private:
	char titleText[50] = "                            Press enter key....";


};

