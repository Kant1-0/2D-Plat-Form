/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 11:40:21 by qfremeau          #+#    #+#             */
/*   Updated: 2016/04/08 11:40:44 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PROTOTYPES_H
#define _PROTOTYPES_H

/* Includes project linker */

#include "defs.h"
#include "random.h"
#include "texture.h"
#include "animation.h"
#include "motion.h"
#include "camera.h"
#include "entity.h"
#include "player.h"


/* Global variables */

//The dimensions of the level
extern const int        LEVEL_WIDTH;
extern const int        LEVEL_HEIGHT;
//Screen dimension constants
extern const int        SCREEN_WIDTH;
extern const int        SCREEN_HEIGHT;
//The window we'll be rendering to
extern SDL_Window*      gWindow;
extern SDL_Renderer*    gRenderer;
//Current displayed texture via LTexture
extern LTexture         gBackgroundTexture;
extern LTexture         gBackgroundParallaxTexture;
//Texture option
extern SDL_Color        gColorKey; //Never define gColorKey with 0 alpha value
extern const SDL_Color  COLOR_NONE; //Or it may be considered as COLOR_NONE
//Globally used font
extern TTF_Font*        gFont;
extern LTexture         gTextTexture;
//Entities
extern LPlayer          gBowserEntity;
extern LCamera          gCamera;
//The music that will be played
extern Mix_Music*       gMusicGrassWorld;
//Sound effect in game
extern Mix_Chunk*       gSoundBowserAttack1;
extern Mix_Chunk*       gSoundBowserAttack2;
extern Mix_Chunk*       gSoundBowserAttack3;
extern Mix_Chunk*       gSoundBowserWaiting5;
extern Mix_Chunk*       gSoundFootstepGrass1;
extern Mix_Chunk*       gSoundFootstepGrass2;
//Random options
extern int              gRandomInt;
extern double           gRandomDouble;


/* List of main function prototypes */

//Starts up SDL and creates window
extern bool             init();
//Loads media
extern bool             loadMedia();
//Render on screen
extern void             render();
//Frees media and shuts down SDL
extern void             close();

#endif // _PROTOTYPES_H
