#pragma once
#include"define.h"

#define NONE_ACTIVE 0


// ������Ʈ�� ������ ���� ��

// [����]
// �׸� ���� ��ġ
// RECT (��ġ �� ũ�� Ȯ��, �ݸ��� �ڽ�)
// ������Ʈ Ÿ�� (���콺 Ŭ�� �� � �ۿ��� �ϴ���)
// ���� �����Ǿ��ִ��� Ȯ��

// [�Լ�]
// ��ο� (��ο� �Ŵ����� �����Ѵٸ� ����)
// ���콺 ���� (���콺 Ŀ���� �ø��� ȿ���ִ� �뵵)
// ���콺 ��Ŭ�� (Ŭ���� ������)

// CObject�� �ƴ� �޴��ٸ� ���� ��
// �Ŀ� CObject�� ����ϴ� �ڳ� Ŭ������ �Ű� �� ��

class CObject {
	CImage m_img;						// �׸� ���� -> �Ŀ� �̹��� Ŭ������ �ٲ��� ��

	RECT m_rcPosition;					// ȭ��� ��ġ
	int m_nObjType;						// ������Ʈ Ÿ��
public:



	// �Ŀ� ������ �Һ����� ������ ��쿡�� �Ű������� bool Ÿ������ ������ ��
	virtual void MouseMove(const LPARAM& lParam)	
	{
		POINT tmp = { LOWORD(lParam), HIWORD(lParam) };
		if (PtInRect(&m_rcPosition, tmp)) {
			// Ŀ���� �ö�Դٴ� ȿ���� �� ��
		}
		else {
			;
		}
	}

	// �Ŀ� ������ �Һ����� ������ ��쿡�� �Ű������� bool Ÿ������ ������ ��
	virtual const int LButtonDown(const LPARAM& lParam)
	{
		POINT tmp = { LOWORD(lParam), HIWORD(lParam) };
		if (PtInRect(&m_rcPosition, tmp)) {
			return m_nObjType;				// ������Ʈ Ÿ���� �����ڿ��� ������ ��
		}
		else {
			return NONE_ACTIVE;					// �Ŀ� �ƹ��͵� �ƴ� �޼����� ó���ϴ� ����� �Ѱ��� ��
		}
	}

	virtual void DrawObj(HDC hdc) const
	{
		Rectangle(hdc, m_rcPosition.left, m_rcPosition.top, m_rcPosition.right, m_rcPosition.bottom);
	}

};