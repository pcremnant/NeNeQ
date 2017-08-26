#pragma once
#include"CScene.h"

class MainMenuScene : public CScene {
	float test_time;
	float test_m_x{0};
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

		CString strmoney;

		strmoney.Format(L"%d", int(1000*test_time));


		DrawText(hdc, strmoney, lstrlen(strmoney), &tmp, DT_TOP | DT_LEFT);

		Rectangle(hdc, test_m_x-1, 100, test_m_x + 5, 105);
	}

	void Update(float t) override
	{
		test_time = t;
		test_m_x += test_time;
	}
};