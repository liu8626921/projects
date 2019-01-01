#pragma once
#ifndef _MAIN_TANK__
#define _MAIN_TANK__

#include"Tank.h"
#include"Bullet.h"
class MainTank :public Tank {
public:
	MainTank():Tank() {
		m_pos.Set(300, 300);
		this->CalculateSphere();
		m_color = YELLOW;
		m_dir = Dir::UP;
		m_step = 4;
	}
	~MainTank() {};

	void SetDir(Dir dir);

	void Display();
	void Move();
	void Shoot(list<Object*>& lstBullets);
	void Boom(list<Object*>& lstBombs);
	Rect GetSphere();
	void SetDisappear();
	bool NeedShoot();
	Dir Getdir();
protected:
	void CalculateSphere();
	void DrawTankBody();
};
#endif // !_MAIN_TANK__
