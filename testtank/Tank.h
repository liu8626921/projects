#pragma once
#ifndef _TANK_H__
#define _TANK_H__
#include "Object.h"
#include <list>
using namespace std;

class Tank:public Object {
public:
	Tank() {
		m_pos.Set(300, 300);
		this->CalculateSphere();
		m_color = YELLOW;
		m_dir = Dir::UP;
		m_step = 4;
		
		m_bDisappear = false;
	}
	~Tank() {}
	virtual void Display() {

	}
	virtual void Move() {

	}

	void Shoot(list<Object*> & lstBullets) {

	}

	bool IsDisappear() {
		return m_bDisappear;
	}
	
	virtual void Boom(list<Object*>& lstBombs) {

	}
	virtual Rect GetSphere() = 0;
	virtual void SetDisappear()=0;
	virtual bool NeedShoot()=0;
protected:

	void CalculateSphere() {

	}

};
#endif // !_TANK_H__
