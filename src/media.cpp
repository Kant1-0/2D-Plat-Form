/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   media.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 21:12:50 by qfremeau          #+#    #+#             */
/*   Updated: 2016/04/11 14:12:04 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

/* Loads media */

bool            loadMedia()
{
    fprintf( stdout, "Entering loadMedia()\n" );

    //Open the font
    gFont = TTF_OpenFont( "resource/font/nsm-font-main.ttf", 42 );
    if( gFont == NULL )
    {
        fprintf( stderr, "Failed to load lazy font! SDL_ttf Error: %s\n",
                 TTF_GetError() );
        return false;
    }
    else
    {
        //Render text
        SDL_Color textColor = { 255, 255, 0 };
        if( !gTextTexture.loadFromRenderedText( "Super Bowser World",
                                                textColor ) )
        {
            fprintf( stderr, "Failed to render text texture!\n" );
            return false;
        }
    }

    //Load music
    gMusicGrassWorld = Mix_LoadMUS( "resource/audio/03-grass-world.ogg" );
    if ( gMusicGrassWorld == NULL )
    {
        fprintf( stderr, "Failed to load gMusicGrassWorld music! "
                 "SDL_mixer Error: %s\n", Mix_GetError() );
        return false;
    }

    //Load sound effects
    gSoundBowserAttack1 = Mix_LoadWAV( "resource/sfx/bowser-attack.wav" );
    if ( gSoundBowserAttack1 == NULL )
    {
        fprintf( stderr, "Failed to load gSoundBowserAttack1 sound! "
                 "SDL_mixer Error: %s\n", Mix_GetError() );
        return false;
    }

    gSoundBowserAttack2 = Mix_LoadWAV( "resource/sfx/bowser-attack2.wav" );
    if ( gSoundBowserAttack2 == NULL )
    {
        fprintf( stderr, "Failed to load gSoundBowserAttack2 sound! "
                 "SDL_mixer Error: %s\n", Mix_GetError() );
        return false;
    }

    gSoundBowserAttack3 = Mix_LoadWAV( "resource/sfx/bowser-attack3.wav" );
    if ( gSoundBowserAttack3 == NULL )
    {
        fprintf( stderr, "Failed to load gSoundBowserAttack3 sound! "
                 "SDL_mixer Error: %s\n", Mix_GetError() );
        return false;
    }

    gSoundFootstepGrass1 = Mix_LoadWAV( "resource/sfx/event-footstep-"
                                        "grass1.wav" );
    if ( gSoundFootstepGrass1 == NULL )
    {
        fprintf( stderr, "Failed to load gSoundFootstepGrass1 sound! "
                 "SDL_mixer Error: %s\n", Mix_GetError() );
        return false;
    }

    gSoundFootstepGrass2 = Mix_LoadWAV( "resource/sfx/event-footstep-"
                                        "grass2.wav" );
    if ( gSoundFootstepGrass2 == NULL )
    {
        fprintf( stderr, "Failed to load gSoundFootstepGrass2 sound! "
                 "SDL_mixer Error: %s\n", Mix_GetError() );
        return false;
    }

    gSoundBowserWaiting5 = Mix_LoadWAV( "resource/sfx/bowser-waiting5.wav" );
    if ( gSoundBowserWaiting5 == NULL )
    {
        fprintf( stderr, "Failed to load gSoundBowserWaiting5 sound! "
                 "SDL_mixer Error: %s\n", Mix_GetError() );
        return false;
    }

    //Load Player texture
    if( !gBowserEntity.loadFromFile( "resource/player/smw-xt-bowser01.png",
                                      gColorKey ) )
    {
        fprintf( stderr, "Failed to load gBowserTexture image!\n" );
        return false;
    }

    //Load background texture
    if( !gBackgroundTexture.loadFromFile ( "resource/background/"
                                         "smw-bg-grassland00.png", gColorKey ) )
    {
        fprintf( stderr, "Failed to load background texture image!\n" );
        return false;
    }

    //Load background texture
    if( !gBackgroundParallaxTexture.loadFromFile( "resource/background/"
                                                  "smw-bg2-grassland01.png" ) )
    {
        fprintf( stderr, "Failed to load background parallax"
                " texture image!\n" );
        return false;
    }

    fprintf( stdout, "__Succeeded loadMedia()\n" );
    return true;
}
