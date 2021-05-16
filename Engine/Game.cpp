/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
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
#include "MainWindow.h"
#include "Game.h"
#include "SpriteCodex.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	ball(Vec2(40.0f, 400.0f), Vec2(7.0f, 7.0f)),
	paddle( Vec2( 30.0f, 500.0f)),
	soundpad(L"Sounds\\arkpad.wav"),
	soundbrick(L"Sounds\\arkbrick.wav")
{
	const Color colors[7] = { Colors::Red, Colors::Green, Colors::Magenta, Colors::Cyan, Colors::Yellow, Colors::White, Colors::Blue };

	const Vec2 topleft = { 100.0f, 50.0f };
	const int padding = 3;
	for (int i = 0; i < nBricksAcross; i++) {
		Color brick_color = colors[i];
		for (int j = 0; j < nBricksDown; j++) {
			bricks[i][j] = Brick(topleft + Vec2(i*(Brick::WIDTH + padding), j*(Brick::HEIGHT + padding)), brick_color);
		}
	}
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	const float dt = ft.Mark();
		if (wnd.kbd.KeyIsPressed(VK_CONTROL)) {
			COLLISION_MASK_ENABLED = !COLLISION_MASK_ENABLED;
		}

		if (paddle.IsCollidingBall(ball)) {
			soundpad.Play();
		}
		for (int i = 0; i < nBricksAcross; i++) {
			for (int j = 0; j < nBricksDown; j++) {
				if (bricks[i][j].DoCollisionWithBall(ball)) {
					soundbrick.Play();
					nDestroyedBricks++;
					
				}
			}
		}

		
		if (nDestroyedBricks == nBricks) {
			allBricksBroken = true;
			paddle.StopAll();
			ball.StopAll();
		}
		else {
			paddle.Update(wnd.kbd, dt);
			ball.Update(dt);
		}
		}

void Game::ComposeFrame()
{
	if (!gameIsOver) {

		for (int i = 0; i < nBricksAcross; i++) {
			for (int j = 0; j < nBricksDown; j++) {
				if (!bricks[i][j].GetDestroyedStatus()) {
					bricks[i][j].Draw(gfx);
				}
				
			}
		}

		if (COLLISION_MASK_ENABLED) {
			ball.DrawCollisionMask(gfx);
		}

		ball.Draw(gfx);

		paddle.Draw(gfx);
		if (COLLISION_MASK_ENABLED) {
			paddle.DrawCollisionMask(gfx);

		}
	}
	else {
		
		SpriteCodex::DrawGameOver(Graphics::ScreenWidth / 2, Graphics::ScreenHeight / 2, gfx);
	}
	if (allBricksBroken) {
		// need to show a different screen when all bricks are broken
		SpriteCodex::DrawGameOver(Graphics::ScreenWidth / 2, Graphics::ScreenHeight / 2, gfx);

	}
}
