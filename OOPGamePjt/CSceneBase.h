#pragma once

class CSceneBase
{

public:
	virtual void Update() = 0;

	virtual void Render() = 0;


	virtual ~CSceneBase() {};

};

