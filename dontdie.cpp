// Programming 2D Games
// Copyright (c) 2011 by: 
// Charles Kelly
// Chapter 8 threeCsDX.cpp v1.0

#include "dontdie.h"

//=============================================================================
// Constructor
//=============================================================================
dontdie::dontdie()
{
}

//=============================================================================
// Destructor
//=============================================================================
dontdie::~dontdie()
{
    releaseAll();               // call deviceLost() for every graphics item
}

//=============================================================================
// initializes the game
// Throws GameError on error
//=============================================================================
void dontdie::initialize(HWND hwnd)
{
    Game::initialize(hwnd);
    graphics->setBackColor(graphicsNS::WHITE);

    // initialize DirectX fonts
    // 15 pixel high Arial
	// boss form 1 texture
	// if hp >66%
	if (!bossTexture.initialize(graphics, BOSS_IMAGE1))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Boss form 1 texture"));
	//// if hp >33% <66%
	//if (!bossTexture.initialize(graphics, BOSS_IMAGE2))
	//	throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Boss form 2 texture"));
	//// if hp <33%
	//if (!bossTexture.initialize(graphics, BOSS_IMAGE3))
	//	throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Boss form 3 texture"));
	// boss form 1 image
	if (!boss.initialize(this, boss::WIDTH, boss::HEIGHT, boss::TEXTURE_COLS, &bossTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing your boss"));
    
	boss.setFrames(boss::BOSS_START_FRAME, boss::BOSS_END_FRAME);
	boss.setCurrentFrame(boss::BOSS_START_FRAME);
	boss.setX(GAME_WIDTH / 4);
	boss.setY(GAME_HEIGHT / 4);

    reset();            // reset all game variables
    fpsOn = true;       // display frames per second
    return;
}


//=============================================================================
// Reset the game to begin play and after a score
//=============================================================================
void dontdie::reset()
{
    return;
}

//=============================================================================
// move all game items
// frameTime is used to regulate the speed of movement
//=============================================================================
void dontdie::update()
{
	boss.update(frameTime);

}

//=============================================================================
// render game items
//=============================================================================
void dontdie::render()
{
	const int BUF_SIZE = 20;
    static char buffer[BUF_SIZE];

    graphics->spriteBegin();
	boss.draw();
 
    if(fpsOn)           // if fps display requested
    {
            // convert fps to Cstring
            _snprintf_s(buffer, BUF_SIZE, "fps %d ", (int)fps);
            dxFont.print(buffer,GAME_WIDTH-200,GAME_HEIGHT-50);
     }
	 
    graphics->spriteEnd();


}

//=============================================================================
// The graphics device was lost.
// Release all reserved video memory so graphics device may be reset.
//=============================================================================
void dontdie::releaseAll()
{
    Game::releaseAll();
    return;
}

//=============================================================================
// The grahics device has been reset.
// Recreate all surfaces and reset all entities.
//=============================================================================
void dontdie::resetAll()
{
    Game::resetAll();
    return;
}
