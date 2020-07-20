#pragma once
class CSceneManager
{
public:
	static CSceneManager& getInstance();

	void Update();

	void Render();

	// 다음씬으로 넘어가달라는 요청을 하는 함수입니다. 
	// sceneCheck를 true로 하여 다음신을 변경합니다.
	void LoadScene(SceneList sceneCheck);

private:

	// scene 동적할당하는 변수입니다.
	CSceneBase* pScene;

	// LoadScene() 함수로 인해서 해당 값이 바뀌면 scene이 전환된다.
	SceneList nowScene;
	
	// true일 경우 nowScene의 값을 확인 후 새로 동적할당을 한다.
	bool sceneCheck;

	CSceneManager();

	CSceneManager(const CSceneManager& rhs) {};

	CSceneManager& operator=(const CSceneManager& rhs) {};

};


