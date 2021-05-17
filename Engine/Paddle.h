#pragma once
#include "Vec2.h"
#include "Colors.h"
#include "RectF.h"
#include "Graphics.h"
#include "Keyboard.h"
#include "Ball.h"

class Paddle {
private:
	Vec2 pos;

	Vec2 vel;
	static constexpr float width = 100.0f;
	static constexpr float height = 15.0f;
	static constexpr float speed = 15.0f;
public:
	Paddle() = default;
	Paddle(const Vec2& in_pos);
	void BoundInsideWindow();
	RectF GetRect()const;
	bool IsCollidingBall(Ball& ball)const;
	Vec2 GetCenter()const;
	void Update(const Keyboard& kbd, float dt, bool ballIsAttached, Ball& ball);
	void UpdateBall(Ball& ball)const;
	void StopAll();
	void DrawCollisionMask(Graphics& gfx)const;
	void Draw(Graphics& gfx)const;
	Vec2 GetVelocity()const;
	void Reset(Ball& ball);
	

};