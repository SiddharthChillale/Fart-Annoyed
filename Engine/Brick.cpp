#include "Brick.h"

Brick::Brick(const Vec2& in_pos, Color in_c)
	:
	pos(in_pos),
	c(in_c)
{
	width = 50.0f;
	height = 20.0f;

}

void Brick::Draw(Graphics& gfx) const
{
	if (!destroyed) {
		gfx.DrawRect(GetRect(), c);
	}
}

void Brick::DoCollisionWithBall(Ball& ball)
{
	if (GetRect().isCollidingWith(ball.GetRect())) {
		destroyed = true;
	}
}

RectF Brick::GetRect() const
{
	return RectF(pos, Vec2(pos.x+width, pos.y+height));
}
