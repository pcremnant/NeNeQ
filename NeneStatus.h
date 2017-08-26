#pragma once


#define STATUS_LUCK 0
#define STATUS_INT 1
#define STATUS_SKILL 2

// �׳װ� ������ �ִ� �ɷ�ġ
class NeneStatus {
	int m_nLuck;						// ��
	int m_nInt;							// ����
	int m_nSkill;						// ���õ�
public:
	// ó�� �ɷ�ġ ����
	// �Ŀ� ���� �ɷ�ġ�� �ٲ��� ��
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
	// ���۷����� 

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