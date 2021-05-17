/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Ball.h"
#include "Graphics.h"
#include "FrameTimer.h"
#include "Paddle.h"
#include "Brick.h"
#include "Sound.h"

class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
	/********************************/
	/*  User Functions              */
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */
	FrameTimer ft;
	
	static constexpr int nBricksAcross = 7;
	static constexpr int nBricksDown = 5;
	bool gameIsOver = false;
	bool touchedFloor = false;
	bool allBricksBroken = false;
	bool isStarted = false;
	int nDestroyedBricks = 0;
	static constexpr int nBricks = nBricksAcross*nBricksDown;
	int nLives = 3;
	
	Brick bricks[nBricksAcross][nBricksDown];
	Ball ball;
	Paddle paddle;
	Sound soundpad;
	Sound soundbrick;
	bool COLLISION_MASK_ENABLED = false;
	/********************************/
};