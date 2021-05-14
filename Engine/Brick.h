#pragma once
#include "RectF.h"	
#include "Colors.h"
#include "Graphics.h"
#include "Ball.h"

class Brick {
private:
	Vec2 pos;
	float width;
	float height;
	Color c;
	bool destroyed = false;
public:
	Brick(const Vec2& pos, Color c);
	void Draw(Graphics& gfx)const;
	void DoCollisionWithBall(Ball& ball);
	RectF GetRect()const;

};