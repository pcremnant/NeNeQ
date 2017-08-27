#pragma once
#include"define.h"

#define NONE_ACTIVE 0


// 오브젝트가 가지고 있을 것

// [변수]
// 그림 파일 위치
// RECT (위치 및 크기 확인, 콜리전 박스)
// 오브젝트 타입 (마우스 클릭 시 어떤 작용을 하는지)
// 현재 생성되어있는지 확인

// [함수]
// 드로우 (드로우 매니저를 구현한다면 삭제)
// 마우스 무브 (마우스 커서를 올리면 효과주는 용도)
// 마우스 좌클릭 (클릭시 움직임)

// CObject가 아닌 메뉴바를 구현 중
// 후에 CObject를 상속하는 자녀 클래스로 옮겨 줄 것

class CObject {
	CImage m_img;						// 그림 정보 -> 후에 이미지 클래스로 바꿔줄 것

	RECT m_rcPosition;					// 화면상 위치
	int m_nObjType;						// 오브젝트 타입
public:



	// 후에 씬에서 불변수로 관리할 경우에는 매개변수를 bool 타입으로 수정할 것
	virtual void MouseMove(const LPARAM& lParam)	
	{
		POINT tmp = { LOWORD(lParam), HIWORD(lParam) };
		if (PtInRect(&m_rcPosition, tmp)) {
			// 커서가 올라왔다는 효과를 줄 것
		}
		else {
			;
		}
	}

	// 후에 씬에서 불변수로 관리할 경우에는 매개변수를 bool 타입으로 수정할 것
	virtual const int LButtonDown(const LPARAM& lParam)
	{
		POINT tmp = { LOWORD(lParam), HIWORD(lParam) };
		if (PtInRect(&m_rcPosition, tmp)) {
			return m_nObjType;				// 오브젝트 타입을 생성자에서 정해줄 것
		}
		else {
			return NONE_ACTIVE;					// 후에 아무것도 아닌 메세지를 처리하는 상수로 넘겨줄 것
		}
	}

	virtual void DrawObj(HDC hdc) const
	{
		Rectangle(hdc, m_rcPosition.left, m_rcPosition.top, m_rcPosition.right, m_rcPosition.bottom);
	}

};