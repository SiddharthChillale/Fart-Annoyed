#include "Paddle.h"


Paddle::Paddle(const Vec2& in_pos)
	:
	pos(in_pos)
{
	
	
	vel = Vec2(0.0f, 0.0f);
}


void Paddle::Draw(Graphics& gfx) const
{
	RectF rect_paddle = GetRect();
	gfx.DrawRect( rect_paddle , Colors::Red);
}

void Paddle::Update(const Keyboard& kbd, float dt)
{
	
	if (kbd.KeyIsPressed(VK_RIGHT)) {
		vel.x = 10.0f;
		pos += vel;
	}
	if (kbd.KeyIsPressed(VK_LEFT)) {
		vel.x = -10.0f;
		pos += vel;
	}
	
	BoundInsideWindow();
}

void Paddle::DrawCollisionMask(Graphics& gfx) const
{
	RectF collision_mask = GetRect();
	gfx.DrawRect(collision_mask, Colors::LightGray);
}

void Paddle::BoundInsideWindow()
{
	if (pos.x < 0) {
		pos.x = 0.0f;
		vel.x = -vel.x;
	}
	if (pos.x + width > Graphics::ScreenWidth) {
		pos.x = (Graphics::ScreenWidth - width ) - 1;
		vel.x = -vel.x;
	}

}

RectF Paddle::GetRect() const
{
	return RectF(pos, Vec2(pos.x + width, pos.y + height));
}

void Paddle::IsCollidingBall(Ball& ball) const
{
	
	if (GetRect().isCollidingWith(ball.GetRect())) {
		if (ball.GetCenter().y < pos.y) {
			ball.ReboundY();
		}
		else if (ball.GetCenter().y > pos.y) {
			ball.ReboundX();
		}
	}
	
}

Vec2 Paddle::GetCenter() const
{
	return Vec2(pos.x + (width / 2), pos.y + (height / 2));
}
