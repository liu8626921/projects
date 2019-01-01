#pragma once
#ifndef _OBJECT_H__
#define _OBJECT_H__
#include "Graphic.h"
#include<list>
using namespace std;
enum Dir { UP, DOWN, LEFT, RIGHT };
class Object {
public:
	virtual void Display() = 0;
	virtual void Move() = 0;
	virtual bool IsDisappear()=0;

	virtual void Boom(list<Object*>& lstBoombs) = 0;
	virtual Rect GetSphere() = 0;
	virtual void SetDisappear()=0;

	
protected:

	virtual void CalculateSphere() = 0;
	Point m_pos;
	Rect m_rectSphere;
	COLORREF m_color;
	Dir m_dir;
	bool m_bDisappear;
	int m_step;
};
#endif // !_OBJECT_H__
