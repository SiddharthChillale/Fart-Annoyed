#pragma once
#include "Vec2.h"
#include "RectF.h"
#include "Graphics.h"


class Ball {
private:
	Vec2 pos;
	Vec2 vel;
	RectF wall;
	static constexpr float width = 14.0f;
	static constexpr float height = 14.0f;
	
public:
	Ball() = default;
	Ball(Vec2& in_pos, Vec2& in_vel, const RectF& wall);
	void StopAll();
	bool BoundInsideWindow();
	Vec2 GetCenter()const;
	RectF GetRect()const;
	Vec2 GetVelocity()const;
	
	void Start();
	void ResetPosition(const Vec2& paddle_center_pos);
	void ReboundX();
	void ReboundY();
	bool Update(float dt);
	void DrawCollisionMask(Graphics& gfx)const;
	void Draw(Graphics& gfx)const;


	

};