#include "Ball.h"
#include "SpriteCodex.h"


Ball::Ball(Vec2& in_pos, Vec2& in_vel, const RectF& in_wall)
	:
	pos(in_pos),
	vel(in_vel),
	wall(in_wall)
{
}

void Ball::Draw(Graphics& gfx) const
{
	Vec2 center = GetCenter();
	SpriteCodex::DrawBall( center ,gfx);
}

void Ball::StopAll()
{
	vel = Vec2(0.0f, 0.0f);
}
bool Ball::BoundInsideWindow()
{
	if (pos.x < wall.left) {
		pos.x = wall.left;
		ReboundX();
	}
	if (pos.x +width > wall.right) {
		pos.x = (wall.right - 1) - width;
		ReboundX();
	}
	if (pos.y < wall.top) {
		pos.y = wall.top;
		ReboundY();
		
	}
	if (pos.y + height > wall.bottom) {
		pos.y = (wall.bottom-1) - height;
		return true;
	}
	return false;
}


void Ball::ReboundX()
{
	vel.x = -vel.x;
}

void Ball::ReboundY()
{
	vel.y = -vel.y;
}

bool Ball::Update(float dt)
{
	pos += vel * dt * 60;
	return BoundInsideWindow();
	
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


void Ball::Start()
{
	vel = Vec2( 7.0f ,-7.0f);
}


void Ball::ResetPosition(const Vec2& paddle_center_pos)
{
	pos.x = paddle_center_pos.x - width / 2;
	pos.y = paddle_center_pos.y - 2* height;
}
