/*Copyright (C) 2011 FrostTree Games
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is furnished to do
 * so, subject to the following conditions:
 * 
 *  The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */

#include "SDL/SDL.h"

Uint8* keystates;
SDL_Event ev;

Uint32 pLastTime;

// player "physics" information
int px;
int py;
float runSpeed;
int pDirection; //flag: 0 -> left, 1 -> right

//organ projectile "physics" information
int organX;
int organY;
float organXSpeed;
float organYSpeed;
int organOnScreen; //flag: 0 -> false, 1 -> true
Uint32 organLastTime; //last time organ was updated (logic)
Uint32 organBirthTime; //time when organ was initalized
SDL_Surface* organCurrentSheet;
int organFrame;
Uint32 organLastUpdate; // last frame jump

// block structure magic
struct block
{
	int x;
	int y;
};
struct block* blockList;
int blockCount;

// frame animation data
int pFrame;
Uint32 pLastUpdate; // last frame jump

// key bools for proper animation
int lDown;
int rDown;
int uDown;
int dDown;

//screen buffer
SDL_Surface* buffer;

//notable methods
int doLevel(SDL_Surface* screen, int levelWidth, int levelHeight);
void locating_start_end( int grid[][75] );


