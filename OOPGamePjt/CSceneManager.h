#pragma once
class CSceneManager
{
public:
	static CSceneManager& getInstance();

	void Update();

	void Render();

	// ���������� �Ѿ�޶�� ��û�� �ϴ� �Լ��Դϴ�. 
	// sceneCheck�� true�� �Ͽ� �������� �����մϴ�.
	void LoadScene(SceneList sceneCheck);

private:

	// scene �����Ҵ��ϴ� �����Դϴ�.
	CSceneBase* pScene;

	// LoadScene() �Լ��� ���ؼ� �ش� ���� �ٲ�� scene�� ��ȯ�ȴ�.
	SceneList nowScene;
	
	// true�� ��� nowScene�� ���� Ȯ�� �� ���� �����Ҵ��� �Ѵ�.
	bool sceneCheck;

	CSceneManager();

	CSceneManager(const CSceneManager& rhs) {};

	CSceneManager& operator=(const CSceneManager& rhs) {};

};


