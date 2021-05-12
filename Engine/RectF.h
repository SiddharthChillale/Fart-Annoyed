#pragma once
#include "Colors.h"
#include "Vec2.h"

class RectF {
public:
	float left;
	float right;
	float top;
	float bottom;
	
public:
	RectF() = default;
	RectF(float left, float right, float top, float bottom);
	RectF(const Vec2& topleft, const Vec2& bottomright);
	//RectF(const Vec2& center, float halfWidth, float halfHeight);
	RectF(const Vec2& topleft, float width, float height);

	Vec2& GetCenter()const;
	float GetWidth() const;
	float GetHeight() const;
	bool isCollidingWith(const RectF& rect)const;
};