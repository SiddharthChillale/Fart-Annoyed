#include "Ball.h"
#include "SpriteCodex.h"


Ball::Ball(Vec2& in_pos, Vec2& in_vel)
	:
	pos(in_pos),
	vel(in_vel)
{
}

void Ball::Draw(Graphics& gfx) const
{
	Vec2 center = GetCenter();
	SpriteCodex::DrawBall( center ,gfx);
}

void Ball::BoundInsideWindow()
{
	if (pos.x < 0) {
		pos.x = 0.0f;
		ReboundX();
	}
	if (pos.x +width > Graphics::ScreenWidth) {
		pos.x = (Graphics::ScreenWidth-1) - width;
		ReboundX();
	}
	if (pos.y < 0) {
		pos.y = 0.0f;
		ReboundY();
	}
	if (pos.y + height > Graphics::ScreenHeight) {
		pos.y = (Graphics::ScreenHeight-1) - height;
		ReboundY();
	}
}


void Ball::ReboundX()
{
	vel.x = -vel.x;
}

void Ball::ReboundY()
{
	vel.y = -vel.y;
}

void Ball::Update(float dt)
{
	pos += vel * dt * 60;
	BoundInsideWindow();

}

void Ball::DrawCollisionMask(Graphics& gfx) const
{
	RectF collision_mask = GetRect();
	gfx.DrawRect(collision_mask, Colors::LightGray);
}

Vec2 Ball::GetCenter() const
{
	return Vec2(pos.x + (width/2), pos.y + (height/2));
}

RectF Ball::GetRect() const
{
	return RectF(pos, Vec2(pos.x + width, pos.y + height));
}

Vec2 Ball::GetVelocity()const
{
	return vel;
}
