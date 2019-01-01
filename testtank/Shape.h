#pragma once
#ifndef _SHAPE_H__
#define _SHAPE_H__

#include "Rect.h"

class Shape {
public:
	static bool CheckPointInRect(Point & point, Rect& rect);
	static bool CheckIntersect(Rect& rectA, Rect& rectB);
};
#endif // !_SHAPE_H__
