#pragma once
#include"CDrawInfo.h"

// ��ο� �Ŵ���
// ��ġ������ �׸� ������ ��� �־�� �Ѵ�
// ��ġ������ RECT
// �׸������� char*�� ����ִ´�

/*
class CDrawManager {
	std::list<CDrawInfo*>* m_pObject;				// �� ���� ����ִ� ����Ʈ�� �޴� ������
public:
	void GetObjectInfo(std::list<CDrawInfo*>* pList)
	{
		m_pObject = pList;
	}


	void DrawObject(HDC hdc)
	{
		//m_pObject->sort()   // ���̺��� ������ ��
		for (auto& iter = m_pObject->cbegin();iter != m_pObject->cend();++iter) {
			CImage tmpImg;							// �ӽ� �̹��� ����

			tmpImg.Load((*iter)->m_pAddress);		// �ּҷκ��� �̹��� �ҷ�����
			RECT tmpPos = (*iter)->m_rcPosition;	// 

			StretchBlt(hdc,)
			(*iter)->
		}
	}

private:
	//bool SortObject()
};*/