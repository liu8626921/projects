#pragma once
#ifndef _POINT_H__
#define _POINT_H__

class Point {
public:
	Point(int x = 0, int y = 0) :m_x(x), m_y(y) {};
	~Point() {};

	Point& operator = (const Point &p) {
		m_x = p.m_x;
		m_y = p.m_y;
		return *this;
	}
	void Set(int x, int y);
	void SetX(int x);
	void SetY(int y);
	int GetX();
	int GetY();
private:
	int m_x;
	int m_y;

};
#endif // ! _POINT_H__
#pragma once
