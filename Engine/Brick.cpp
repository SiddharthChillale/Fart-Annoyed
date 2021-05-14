#include "Brick.h"

Brick::Brick(const Vec2& in_pos, Color in_c)
	:
	pos(in_pos),
	c(in_c)
{
}

void Brick::Draw(Graphics& gfx) const
{
	if (!destroyed) {
		gfx.DrawRect(GetRect(), c);
	}
}

bool Brick::DoCollisionWithBall(Ball& ball)
{
	if (!destroyed && GetRect().isCollidingWith(ball.GetRect())) {
		
		if (GetCenter().y < ball.GetCenter().y) {
			ball.ReboundY();
		}
		else {
			ball.ReboundX();
		}
		destroyed = true;
		return true;
	}
	else {
		return false;
	}
}

RectF Brick::GetRect() const
{
	return RectF(pos, Vec2(pos.x+width, pos.y+height));
}

bool Brick::GetDestroyedStatus() const
{
	return destroyed;
}

Vec2 Brick::GetCenter() const
{
	return Vec2(pos.x + (width / 2), pos.y + (height / 2));
}
