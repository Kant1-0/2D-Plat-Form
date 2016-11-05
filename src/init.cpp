/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 21:12:52 by qfremeau          #+#    #+#             */
/*   Updated: 2016/04/11 14:12:01 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

/* Starts up SDL and creates window */

bool    init()
{
    fprintf( stdout, "Entering init()\n" );

    //Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO ) < 0 )
	{
		fprintf( stderr, "SDL could not initialize! SDL_Error: %s\n",
                 SDL_GetError() );
		return false;
	}
	else
	{
	    //Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			fprintf( stderr, "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		gWindow = SDL_CreateWindow( "SDL Tutorial",
                            SDL_WINDOWPOS_UNDEFINED,
                            SDL_WINDOWPOS_UNDEFINED,
                            SCREEN_WIDTH,
                            SCREEN_HEIGHT,
                            SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			fprintf( stderr, "Window could not be created! SDL_Error: %s\n",
                     SDL_GetError() );
			return false;
		}
		else
		{
		    //Create renderer for window
		    gRenderer = SDL_CreateRenderer( gWindow, -1,
                                            SDL_RENDERER_ACCELERATED |
                                            SDL_RENDERER_PRESENTVSYNC );
            if( gRenderer == NULL )
            {
                fprintf( stderr, "Renderer could not be created! "
                         "SDL Error: %s\n", SDL_GetError() );
                return false;
            }
            else
            {
                //Initialize renderer color
                SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

                //Initialize PNG loading
                int imgFlags = IMG_INIT_PNG;
                if( !( IMG_Init( imgFlags ) & imgFlags ) )
                {
                    fprintf( stderr, "SDL_image could not initialize! "
                             "SDL_image Error: %s\n", IMG_GetError() );
                    return false;
                }

                //Initialize SDL_ttf
                if( TTF_Init() == -1 )
                {
                    fprintf( stderr, "SDL_ttf could not initialize! "
                             "SDL_ttf Error: %s\n", TTF_GetError() );
                    return false;
                }

                //Initialize SDL_mixer
                if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 1024 ) < 0 )
                {
                    fprintf( stderr, "SDL_mixer could not initialize! "
                            "SDL_mixer Error: %s\n", Mix_GetError() );
                    return false;
                }
            }
		}
	}
	fprintf( stdout, "__Succeeded init()\n" );
	return true;
}


/* Frees media and shuts down SDL */

void    close()
{
    fprintf( stdout, "Entering close()\n" );

    //Free loaded images
    gBackgroundTexture.free();
    gBackgroundParallaxTexture.free();

    //Free global font
    gTextTexture.free();
    TTF_CloseFont( gFont );
    gFont = NULL;

    //Free the music
    Mix_FreeMusic( gMusicGrassWorld );
    gMusicGrassWorld = NULL;

    //Free sound effects
    Mix_FreeChunk( gSoundBowserAttack1 );
    gSoundBowserAttack1 = NULL;
    Mix_FreeChunk( gSoundBowserAttack2 );
    gSoundBowserAttack2 = NULL;
    Mix_FreeChunk( gSoundBowserAttack3 );
    gSoundBowserAttack3 = NULL;
    Mix_FreeChunk( gSoundBowserWaiting5 );
    gSoundBowserWaiting5 = NULL;
    Mix_FreeChunk( gSoundFootstepGrass1 );
    gSoundFootstepGrass1 = NULL;
    Mix_FreeChunk( gSoundFootstepGrass2 );
    gSoundFootstepGrass2 = NULL;

    //Destroy window
    SDL_DestroyRenderer( gRenderer );
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;
    gRenderer = NULL;

    //Quit SDL subsystems
    Mix_Quit();
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();

    fprintf( stdout, "__Succeeded close()\n" );
}
