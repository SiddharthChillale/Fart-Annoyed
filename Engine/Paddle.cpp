#include "Paddle.h"


Paddle::Paddle(const Vec2& in_pos, const RectF& wall)
	:
	pos(in_pos),
	wall(wall)
{
	vel = Vec2(0.0f, 0.0f);
}


void Paddle::Draw(Graphics& gfx) const
{
	RectF rect_paddle = GetRect();
	gfx.DrawRect( rect_paddle , Colors::Red);
}

Vec2 Paddle::GetVelocity() const
{
	return vel;
}

void Paddle::Reset(Ball& ball)
{
	pos = Vec2(wall.GetCenter().x - (width/2), 500.0f);
	ball.ResetPosition(GetCenter());
}

void Paddle::Update(const Keyboard& kbd, float dt, bool ballIsAttached, Ball& ball)
{
	if (ballIsAttached) {
		UpdateBall(ball);
	}

	if (kbd.KeyIsPressed(VK_RIGHT)) {
		vel.x = speed;
		pos += vel;
	}
	if (kbd.KeyIsPressed(VK_LEFT)) {
		vel.x = -speed;
		pos += vel;
	}
	
	BoundInsideWindow();
}

void Paddle::UpdateBall(Ball& ball) const
{
	ball.ResetPosition(GetCenter());
}

void Paddle::StopAll()
{
	vel = Vec2(0.0f,0.0f);
}

void Paddle::DrawCollisionMask(Graphics& gfx) const
{
	RectF collision_mask = GetRect();
	gfx.DrawRect(collision_mask, Colors::LightGray);
}

void Paddle::BoundInsideWindow()
{
	if (pos.x < wall.left + 10) {
		pos.x = wall.left + 10 ;
		vel.x = -vel.x;
	}
	if (pos.x + width > wall.right - 10) {
		pos.x = (wall.right - 10 - width ) - 1;
		vel.x = -vel.x;
	}

}

RectF Paddle::GetRect() const
{
	return RectF(pos, Vec2(pos.x + width, pos.y + height));
}

bool Paddle::IsCollidingBall(Ball& ball) const
{
	
	if (GetRect().isCollidingWith(ball.GetRect())) {
		if (ball.GetCenter().y < pos.y) {
			ball.ReboundY();
		}
		else if (ball.GetCenter().y > pos.y) {
			ball.ReboundX();
		}
		if (ball.GetVelocity().x * vel.x < 0.0f) {
			ball.ReboundX();
		}
		return true;
	}
	return false;
}

Vec2 Paddle::GetCenter() const
{
	return Vec2(pos.x + (width / 2), pos.y + (height / 2));
}
