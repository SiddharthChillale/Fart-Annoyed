#pragma once
#include "Vec2.h"
#include "RectF.h"
#include "Graphics.h"

class Ball {
private:
	Vec2 pos;
	Vec2 vel;
	float width = 14.0f;
	float height = 14.0f;
	
public:
	Ball() = default;
	Ball(Vec2& in_pos, Vec2& in_vel);
	void Draw(Graphics& gfx)const ;
	void BoundInsideWindow();
	void ReboundX();
	void ReboundY();
	void Update(float dt);
	
	Vec2& GetCenter()const;

};