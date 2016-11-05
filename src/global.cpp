/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/10 17:26:04 by qfremeau          #+#    #+#             */
/*   Updated: 2016/04/11 14:12:00 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

//The dimensions of the level
const int       LEVEL_WIDTH     = 1280;
const int       LEVEL_HEIGHT    =  960;

//Screen dimension constants
const int       SCREEN_WIDTH    =  640;
const int       SCREEN_HEIGHT   =  480;

//The window renderer
SDL_Window*     gWindow     = nullptr;
SDL_Renderer*   gRenderer   = nullptr;

//Current displayed texture via LTexture
LTexture        gBackgroundTexture;
LTexture        gBackgroundParallaxTexture;

//Texture option
SDL_Color       gColorKey   = { COLOR_KEY_R, COLOR_KEY_G, COLOR_KEY_B,
                                COLOR_KEY_A };
const SDL_Color COLOR_NONE  =  { 0, 0, 0, 0 };

//Globally used font
TTF_Font*       gFont   = nullptr;
LTexture        gTextTexture;

//Entities
LPlayer         gBowserEntity;
LCamera         gCamera;

//The music that will be played
Mix_Music*      gMusicGrassWorld    = nullptr;

//Sound effect in game
Mix_Chunk*      gSoundBowserAttack1     = nullptr;
Mix_Chunk*      gSoundBowserAttack2     = nullptr;
Mix_Chunk*      gSoundBowserAttack3     = nullptr;
Mix_Chunk*      gSoundBowserWaiting5    = nullptr;
Mix_Chunk*      gSoundFootstepGrass1    = nullptr;
Mix_Chunk*      gSoundFootstepGrass2    = nullptr;
