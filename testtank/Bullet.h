#pragma once
#ifndef  _BULLET_H__
#define  _BULLET_H__
#include <list>
#include "Object.h"

using namespace std;
class Bullet : public Object {
public:
	Bullet();
	Bullet(Point pos, Dir dir, COLORREF color);
	~Bullet();
	void Display();
	void Move();
	bool IsDisappear() {
		return m_bDisappear;
	}
	 void Boom(list<Object*>& lstBombs);
	 void SetDisappear();
	 Rect GetSphere();
protected:
	void CalculateSphere();


};
#endif // ! _BULLET_H__
