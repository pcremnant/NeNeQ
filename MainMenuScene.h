#pragma once
#include"CScene.h"

class MainMenuScene : public CScene {

public:
	void GetKey(const WPARAM& wParam) override
	{

	}

	void MouseMove(const LPARAM& lParam) override
	{

	}

	void LButtonDowm(const LPARAM& lParam) override
	{

	}

	void Draw(HDC hdc) override
	{
		RECT tmp = { 200, 50, 250, 100 };
		DrawText(hdc, TEXT("¶ÑµÐ!"), -1, &tmp, DT_CENTER | DT_VCENTER);
	}

	void Update(time_t t) override
	{

	}
};