/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 11:11:19 by qfremeau          #+#    #+#             */
/*   Updated: 2016/04/08 11:28:30 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _DEFS_H
#define _DEFS_H

//Using standard libraries
#include <stdio.h>
#include <time.h>
#include <string>
#include <cmath>
#include <vector>

//SDL2 libraries
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

//Transparency color = Magenta
#define COLOR_KEY_R                     255
#define COLOR_KEY_G                       0
#define COLOR_KEY_B                     255
#define COLOR_KEY_A                     255

//Default setting for template class
#define DEFAULT_SIZE                     64
#define DEFAULT_WIDTH                    64
#define DEFAULT_HEIGHT                   64
#define DEFAULT_FRAMERATE               100
#define DEFAULT_SPEED                    3
#define DEFAULT_GRAVITY                  4

//Animation clipping aka state ID
#define IDLE                              1
#define BUSY                              0

#define DIR_RIGHT                         1
#define DIR_LEFT                          2

#define BOWSER_SPEED                      2

#define BOWSER_SIZE                      76

#define BOWSER_ANIMATION_FRAMES         102
#define BOWSER_ANIMATION_TILES_X         17
#define BOWSER_ANIMATION_TILES_Y          6

#define BOWSER_ID_RIGHT_WALK              0
#define BOWSER_MAXFRAME_RIGHT_WALK       16

#define BOWSER_ID_LEFT_WALK               1
#define BOWSER_MAXFRAME_LEFT_WALK        16

#define BOWSER_ID_RIGHT_ATTACK            2
#define BOWSER_MAXFRAME_RIGHT_ATTACK     17
#define BOWSER_ENDPUNCH_RIGHT_ATTACK     14

#define BOWSER_ID_LEFT_ATTACK             3
#define BOWSER_MAXFRAME_LEFT_ATTACK      17
#define BOWSER_ENDPUNCH_LEFT_ATTACK      14

#define BOWSER_ID_RIGHT_WAITING           4
#define BOWSER_MAXFRAME_RIGHT_WAITING     7

#define BOWSER_ID_LEFT_WAITING            5
#define BOWSER_MAXFRAME_LEFT_WAITING      7

#endif // _DEFS_H
