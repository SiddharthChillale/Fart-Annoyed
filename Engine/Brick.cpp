#include "Brick.h"

Brick::Brick(const RectF& in_rect, Color in_c)
	:
	rect(in_rect),
	c(in_c)
{

}

void Brick::Draw(Graphics& gfx) const
{
	gfx.DrawRect(rect, c);	
}
