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
	void StopAll();
	bool BoundInsideWindow();
	Vec2 GetCenter()const;
	RectF GetRect()const;
	Vec2 GetVelocity()const;
	void SetVelocity(Vec2 in_vel);
	void SetPosX(float in_x);
	void ReboundX();
	void ReboundY();
	bool Update(float dt);
	void DrawCollisionMask(Graphics& gfx)const;
	void Draw(Graphics& gfx)const;


	

};