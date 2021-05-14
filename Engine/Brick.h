#pragma once
#include "RectF.h"	
#include "Colors.h"
#include "Graphics.h"
#include "Ball.h"

class Brick {
private:
	Vec2 pos;
	static constexpr float width = 80.0f;
	static constexpr float height = 30.0f;
	Color c;
	bool destroyed = false;
public:
	static constexpr float WIDTH = 80.0f;
	static constexpr float HEIGHT = 30.0f;
	Brick() = default;
	Brick(const Vec2& pos, Color c);
	void Draw(Graphics& gfx)const;
	bool DoCollisionWithBall(Ball& ball);
	RectF GetRect()const;
	bool GetDestroyedStatus()const;
	Vec2 GetCenter()const;
};