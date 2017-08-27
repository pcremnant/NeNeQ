#pragma once
#include"define.h"
#include"NeneStatus.h"

#define STATUS_MAX 100

// TODO:

// [���Ȱ���]
// ����Ʈ ������ ���� �ø���
// �����(�ƿ���)�� ���� �� ���ʽ� ����

// [�׳�����Ʈ]
// ������ �Ѱ��ֱ�
// ��ô���� ���� ��������Ʈ ȯ��

// [����Ʈ]
// ����Ʈ�� ���� ���� ����Ʈ�� ����
//  - ��������Ʈ, �����(�ƿ���) ����Ʈ

// ������ �־�� �� ����
// ��������Ʈ, �������ͽ�, �����(�ƿ���) ����Ʈ

class NeneStatusManager {
	NeneStatus* m_Status;					// ���� �������ͽ�
	NeneStatus m_BonusStatus;				// �����(�ƿ���)�� ���� ���ʽ� �������ͽ�
	int m_nStatusPoint;						// �������ͽ� ����Ʈ

	int m_nUmikoPoint;						// ����� ����Ʈ
	bool m_bUmikoHelp;						// ����ڰ� ���� ������ �ְ� �ִ°�

public:
	// ������ - ������ �ʱ�ȭ
	NeneStatusManager()
	{
		m_nStatusPoint = 0;
		m_Status = new NeneStatus();
		m_Status->Init();
		m_BonusStatus.Init(true);

		m_nUmikoPoint = 0;
		m_bUmikoHelp = false;
	}

	// �׳� ����Ʈ�� ���� �� ������ �Ѱ���
	NeneStatus GetStatus() const
	{
		if (m_bUmikoHelp) {
			return (*m_Status) + m_BonusStatus;
		}
		else {
			return (*m_Status);
		}
	}

	// ���� ������
	// �Ѱ��ִ� ���ڴ� ������ ���콺 ��ġ�� ��� �������� ������ �� �Ѱ���
	// Ÿ�԰��� ���������� �������ִ�
	bool StatusUp(const int& nType)
	{
		if (m_nStatusPoint < 1)						// ���� ����Ʈ�� ���� ���
			return false;


		if (m_Status->CheckMaxStatus(nType)) {		// ������ �̹� 100�� ���
			return false;
		}
		else {
			m_nStatusPoint--;
			m_Status->StatusUp(nType);
		}
	}
};
