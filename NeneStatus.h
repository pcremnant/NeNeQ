#pragma once


#define STATUS_LUCK 0
#define STATUS_INT 1
#define STATUS_SKILL 2

// 네네가 가지고 있는 능력치
class NeneStatus {
	int m_nLuck;						// 운
	int m_nInt;							// 지능
	int m_nSkill;						// 숙련도
public:
	// 처음 능력치 세팅
	// 후에 정한 능력치로 바꿔줄 것
	void Init(const bool& IsBonus = false) noexcept
	{
		m_nLuck = 0;
		m_nInt = 0;
		m_nSkill = 0;
	}

	void StatusUp(const int& StatusType)
	{
		switch (StatusType) {
		case STATUS_LUCK:
			m_nLuck++;
			break;
		case STATUS_INT:
			m_nInt++;
			break;
		case STATUS_SKILL:
			m_nSkill++;
			break;
		}
	}

	bool CheckMaxStatus(const int& StatusType)
	{
		switch (StatusType) {
		case STATUS_LUCK:
			if (m_nLuck >= 100)
				return false;
			else
				return true;
			break;
		case STATUS_INT:
			if (m_nInt >= 100)
				return false;
			else
				return true;
			break;
		case STATUS_SKILL:
			if (m_nSkill >= 100)
				return false;
			else
				return true;
			break;
		}
	}


	//////////////////////////////////////////////////////////////////////////////////
	// 오퍼레이터 

	NeneStatus operator+(const NeneStatus other)
	{
		NeneStatus tmp;
		tmp.m_nInt = this->m_nInt + other.m_nInt;
		tmp.m_nLuck = this->m_nLuck + other.m_nLuck;
		tmp.m_nSkill = this->m_nSkill + other.m_nSkill;
		return tmp;
	}

	NeneStatus operator=(const NeneStatus other)
	{
		NeneStatus tmp;
		tmp.m_nInt = other.m_nInt;
		tmp.m_nLuck = other.m_nLuck;
		tmp.m_nSkill = other.m_nSkill;
		return tmp;
	}
};