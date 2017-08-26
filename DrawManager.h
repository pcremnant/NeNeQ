#pragma once
#include"CDrawInfo.h"

// 드로우 매니저
// 위치정보와 그림 정보를 들고 있어야 한다
// 위치정보는 RECT
// 그림정보는 char*로 들고있는다

/*
class CDrawManager {
	std::list<CDrawInfo*>* m_pObject;				// 각 씬이 들고있는 리스트를 받는 포인터
public:
	void GetObjectInfo(std::list<CDrawInfo*>* pList)
	{
		m_pObject = pList;
	}


	void DrawObject(HDC hdc)
	{
		//m_pObject->sort()   // 깊이별로 정렬할 것
		for (auto& iter = m_pObject->cbegin();iter != m_pObject->cend();++iter) {
			CImage tmpImg;							// 임시 이미지 파일

			tmpImg.Load((*iter)->m_pAddress);		// 주소로부터 이미지 불러오기
			RECT tmpPos = (*iter)->m_rcPosition;	// 

			StretchBlt(hdc,)
			(*iter)->
		}
	}

private:
	//bool SortObject()
};*/