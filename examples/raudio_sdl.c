/*******************************************************************************************
*
*   raudio_sdl example - Using raudio with a custom SDL backend
*
*   NOTE: This is a fork of the raudio library (https://github.com/raysan5/raudio) by raysan5.
*
*   DEPENDENCIES:
*       miniaudio.h  	- Audio device management lib (https://github.com/dr-soft/miniaudio)
*	backend_sdl.h	- SDL backend based on miniaudio (https://github.com/mackron/miniaudio)
*       stb_vorbis.h 	- Ogg audio files loading (http://www.nothings.org/stb_vorbis/)
*       dr_wav.h     	- WAV audio file loading (https://github.com/mackron/dr_libs)
*       dr_mp3.h     	- MP3 audio file loading (https://github.com/mackron/dr_libs)
*       dr_flac.h    	- FLAC audio file loading (https://github.com/mackron/dr_libs)
*       jar_xm.h     	- XM module file loading
*       jar_mod.h    	- MOD audio file loading
*
*   COMPILATION:
*	Option 1:
*	Use the provided makefile. Make sure you have <SDL2/SDL.h> and the needed SDL2-libraries
*	setup correctly on your system.
*
*	Option 2:
*       gcc -o raudio_sdl.exe raudio_sdl.c ..\src\raudio.c -I..\src -I..\src\external -L. /
*           -lsdl2 -lsetupapi -lole32 -lgdi32 -limm32 -lversion -loleaut32 -lwinmm -Wall -std=c99 /
*			-DRAUDIO_STANDALONE -DSUPPORT_MODULE_RAUDIO -DSUPPORT_FILEFORMAT_WAV -DSUPPORT_FILEFORMAT_XM
*
*	The original raudio library is using the following license:
*
*   LICENSE: zlib/libpng
*
*   This example is licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software:
*
*   Copyright (c) 2014-2020 Ramon Santamaria (@raysan5)
*
*   This software is provided "as-is", without any express or implied warranty. In no event
*   will the authors be held liable for any damages arising from the use of this software.
*
*   Permission is granted to anyone to use this software for any purpose, including commercial
*   applications, and to alter it and redistribute it freely, subject to the following restrictions:
*
*     1. The origin of this software must not be misrepresented; you must not claim that you
*     wrote the original software. If you use this software in a product, an acknowledgment
*     in the product documentation would be appreciated but is not required.
*
*     2. Altered source versions must be plainly marked as such, and must not be misrepresented
*     as being the original software.
*
*     3. This notice may not be removed or altered from any source distribution.
*
********************************************************************************************/

// Define SDL_MAIN_HANDLED to handle main function on our own
#define SDL_MAIN_HANDLED

// Include SDL2 and raudio headers
#include <SDL2/SDL.h>
#include "raudio.h"

int main(void)
{
	// Initialize the audio device for music and sound playback
	InitAudioDevice();

	Music music = LoadMusicStream("resources/mini1111.xm");
	Sound sound = LoadSound("resources/weird.wav");

	// Play the loaded sound and music
	PlaySound(sound);
	PlayMusicStream(music);

	SDL_Event event;
	bool running = true;

	while (running)
	{	
		while (SDL_PollEvent(&event))
		{
	        	if (event.type == SDL_QUIT)
			{
	                	running = 0;
	        	} 
		}

		// Update the music stream in each iteration
		UpdateMusicStream(music);
		SDL_Delay(16);
	}
	
	// Free sound & music
	UnloadSound(sound);
	UnloadMusicStream(music);

	// Close the audio device
	CloseAudioDevice();
	return 0;
}
