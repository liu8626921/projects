#pragma once
#ifndef _SETTING_H__
#define _SETTING_H__

#include<list>
using namespace std;
class Setting {
public:
	static void NewGameLevel();
	static void TankDamaged();
	static int GetLife() {
		return m_nLife;
	}
	static int GetGameLevel() {
		return m_nGameLevel;
	}
	static int GetTankLevel() {
		return m_nTankLevel;
	}
	static int GetTankNum() {
		return m_nTankNum;
	}
	static int GetSumScore() {
		return m_nSumScore;
	}
	static int GetTankScore() {
		return m_nTankScore;
	}
	static int GetTankSum() {
		return m_nTankSum;
	}
	static bool m_bNewLevel;
	static void Die();
private:
	static int m_nLife;

	static int m_nGameLevel;
	static int m_nTankLevel;

	static int m_nTankNum;
	static int m_nSumScore;
	static int m_nTankScore;
	static int m_nTankSum;
};

#endif // !_SETTING_H__
