#pragma once
#include"define.h"
#include"NeneStatus.h"

#define STATUS_MAX 100

// TODO:

// [스탯관리]
// 포인트 가지고 스탯 올리기
// 우미코(아오바)가 왔을 때 보너스 스탯

// [네네퀘스트]
// 스탯을 넘겨주기
// 진척도에 따라 스탯포인트 환산

// [퀘스트]
// 퀘스트를 통해 각종 포인트를 번다
//  - 스탯포인트, 우미코(아오바) 포인트

// 가지고 있어야 할 변수
// 스탯포인트, 스테이터스, 우미코(아오바) 포인트

class NeneStatusManager {
	NeneStatus* m_Status;					// 현재 스테이터스
	NeneStatus m_BonusStatus;				// 우미코(아오바)를 통한 보너스 스테이터스
	int m_nStatusPoint;						// 스테이터스 포인트

	int m_nUmikoPoint;						// 우미코 포인트
	bool m_bUmikoHelp;						// 우미코가 현재 도움을 주고 있는가

public:
	// 생성자 - 변수들 초기화
	NeneStatusManager()
	{
		m_nStatusPoint = 0;
		m_Status = new NeneStatus();
		m_Status->Init();
		m_BonusStatus.Init(true);

		m_nUmikoPoint = 0;
		m_bUmikoHelp = false;
	}

	// 네네 퀘스트를 만들 때 스탯을 넘겨줌
	NeneStatus GetStatus() const
	{
		if (m_bUmikoHelp) {
			return (*m_Status) + m_BonusStatus;
		}
		else {
			return (*m_Status);
		}
	}

	// 스탯 레벨업
	// 넘겨주는 인자는 씬에서 마우스 위치로 어느 스탯인지 구별한 후 넘겨줌
	// 타입값은 디파인으로 정해져있다
	bool StatusUp(const int& nType)
	{
		if (m_nStatusPoint < 1)						// 스탯 포인트가 없을 경우
			return false;


		if (m_Status->CheckMaxStatus(nType)) {		// 스탯이 이미 100일 경우
			return false;
		}
		else {
			m_nStatusPoint--;
			m_Status->StatusUp(nType);
		}
	}
};
