#include "RectF.h"
#include <cmath>

RectF::RectF(float left, float right, float top, float bottom)
    :
    left(left),
    right(right),
    top(top),
    bottom(bottom)
{

}

RectF::RectF(const Vec2& topleft, const Vec2& bottomright)
    :
    RectF(topleft.x, bottomright.x, topleft.y, bottomright.y)
{

}

RectF::RectF(const Vec2& topleft, float width, float height)
    :
    RectF(topleft.x, topleft.x + width, topleft.y, topleft.y + height)
{

}

Vec2& RectF::GetCenter() const
{
    return Vec2(((left + right) / 2.0f), ((top + bottom) / 2.0f));
}

float RectF::GetWidth()const
{
    return abs(left - right);
}

float RectF::GetHeight() const
{
    return abs(top - bottom);
}

bool RectF::isCollidingWith(const RectF& rect)const
{
    
    return (rect.GetCenter().x - GetCenter().x < rect.GetWidth() || rect.GetCenter().y - GetCenter().y < rect.GetHeight());
}
