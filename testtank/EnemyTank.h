#pragma once
#ifndef __ENEMY_TANK__
#define __ENEMY_TANK__

#include "Tank.h"
#include "Bomb.h"
#include "Bullet.h"
#define MAX_STEP 10
#define MAX_STEP_SHOOT 20

class EnemyTank :public Tank {
public:
	EnemyTank() {
		RandomTank();
	}
	~EnemyTank(){}
	void Display();
	void Move();
	void Shoot(list<Object*>& lstBullet);
	void Boom(list<Object*>& lstBombs);
	Rect GetSphere();
	void SetDisappear();
	bool NeedShoot();
protected:
	void CalculateSphere();
	void RandomTank();
	bool m_bNeedShoot;
	void RandomDir(int type);
	int m_stepCnt;
};

#endif // !__ENEMY_TANK__
