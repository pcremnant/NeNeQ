#pragma once
#include"define.h"
#include"CScene.h"
#include"MainMenuScene.h"

#define NUMBER_SCENE 1			// 총 씬의 갯수

#define SCENE_MAIN 0			// 씬 넘버

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

	// 키보드 메세지를 받는 함수
	void GetKey(const WPARAM& wParam)
	{
		m_pCurrentScene->GetKey(wParam);
	}

	// 마우스 좌클릭 매세지를 받는 함수
	void LButtonDown(const LPARAM& lParam)
	{
		m_pCurrentScene->LButtonDowm(lParam);
	}

	// 마우스 움직이는 메세지를 받는 함수
	void MouseMove(const LPARAM& lParam)
	{
		m_pCurrentScene->MouseMove(lParam);
	}

	// 드로우 함수
	void Draw(HDC hdc)
	{
		m_pCurrentScene->Draw(hdc);
	}

	// 업데이트 함수
	void Update(time_t t)
	{
		m_pCurrentScene->Update(t);
	}
};