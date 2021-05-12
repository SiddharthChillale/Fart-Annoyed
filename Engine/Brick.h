#pragma once
#include "RectF.h"	
#include "Colors.h"
#include "Graphics.h"

class Brick {
private:
	RectF rect;
	Color c;
	bool destroyed = false;
public:
	Brick(const RectF& rect, Color c);
	void Draw(Graphics& gfx)const;

};