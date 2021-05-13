#pragma once
#include "Vec2.h"
#include "Colors.h"
#include "RectF.h"
#include "Graphics.h"
#include "Keyboard.h"

class Paddle {
private:
	Vec2 pos;

	Vec2 vel;
	float width;
	float height;
	
public:
	Paddle() = default;
	Paddle(const Vec2& in_pos);
	void BoundInsideWindow();
	RectF& GetRect()const;

	Vec2& GetCenter()const;
	void Update(const Keyboard& kbd, float dt);
	void Draw(Graphics& gfx)const;
	
	

};