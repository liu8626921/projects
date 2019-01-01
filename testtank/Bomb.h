#pragma once
#ifndef _BOMB_H__
#define _BOMB_H__

#include "Object.h"
#include <list>
using namespace std;
enum  BombType
{
	LARGE, SMALL
};
class Bomb:public Object {
public:
	Bomb();
	Bomb(Point pos, BombType type);
	~Bomb() {}

	void Display();
	void Move();
	void Boom(list<Object*>& lstBombs);
	bool IsDisappear();
	Rect GetSphere();
	void SetDisappear();
protected:
	void CalculateSphere();
	BombType m_type;
	int m_timer;
	

};
#endif // !_BOMB_H__
