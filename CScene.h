#pragma once
#include"define.h"

class CScene {

public:
	virtual void GetKey(const WPARAM& wParam) = 0;
	virtual void MouseMove(const LPARAM& lParam) = 0;
	virtual void LButtonDowm(const LPARAM& lParam) = 0;
	virtual void Draw(HDC hdc) = 0;
	virtual void Update(float t) = 0;
};