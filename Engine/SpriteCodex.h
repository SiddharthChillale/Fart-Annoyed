#pragma once

#include "Graphics.h"
#include "Vec2.h"
#include "RectF.h"

class SpriteCodex
{
public:
	// centered drawing of 14x14 sprite
	static void DrawBall( const Vec2& center,Graphics& gfx );
	static void DrawGameOver(int x, int y, Graphics& gfx);
	static void DrawBorder(const RectF& rect, float thickness, Graphics& gfx);

};