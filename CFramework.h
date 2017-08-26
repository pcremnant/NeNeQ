#pragma once
#include"define.h"
#include"CScene.h"
#include"MainMenuScene.h"

#define NUMBER_SCENE 1			// �� ���� ����

#define SCENE_MAIN 0			// �� �ѹ�

class CFramework {
private:
	CScene* m_pCurrentScene;
	CScene* m_Scene[NUMBER_SCENE];
public:
	CFramework() 
	{
		m_Scene[SCENE_MAIN] = new MainMenuScene;

		m_pCurrentScene = m_Scene[SCENE_MAIN];
	}
	~CFramework() {}

	// Ű���� �޼����� �޴� �Լ�
	void GetKey(const WPARAM& wParam)
	{
		m_pCurrentScene->GetKey(wParam);
	}

	// ���콺 ��Ŭ�� �ż����� �޴� �Լ�
	void LButtonDown(const LPARAM& lParam)
	{
		m_pCurrentScene->LButtonDowm(lParam);
	}

	// ���콺 �����̴� �޼����� �޴� �Լ�
	void MouseMove(const LPARAM& lParam)
	{
		m_pCurrentScene->MouseMove(lParam);
	}

	// ��ο� �Լ�
	void Draw(HDC hdc)
	{
		m_pCurrentScene->Draw(hdc);
	}

	// ������Ʈ �Լ�
	void Update(time_t t)
	{
		m_pCurrentScene->Update(t);
	}
};