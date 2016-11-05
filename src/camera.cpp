/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 14:59:39 by qfremeau          #+#    #+#             */
/*   Updated: 2016/04/23 14:59:47 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

/* Initializes variables */

LCamera::LCamera()
{
    fprintf( stderr, "LCamera class is being created\n" );

    gCamera    = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
}


/* Deallocate memory */

LCamera::~LCamera()
{
    fprintf( stderr, "LCamera class is being deleted\n" );
}


/* Set camera effects */

void    LCamera::setCamera( int posX, int posY, int width, int height )
{
    gCamera.x = posX;
    gCamera.y = posY;
    gCamera.w = width;
    gCamera.h = height;
}

void    LCamera::setCamera( SDL_Rect camera )
{
    gCamera = camera;
}


/* Center camera over the player */

void    LCamera::onMotion( LMotion* motion, LAnimation* anim )
{
    gCamera.x = ( motion->getPosX() + anim->getClipWidth() / 2 )
                  - SCREEN_WIDTH / 2;
    gCamera.y = ( motion->getPosY() + anim->getClipHeight() / 2 )
                  - SCREEN_HEIGHT / 2;

    printf( "Test onMotion: PosX = %4d Width = %4d PosY = %4d Height = %4d\r",
            motion->getPosX(), anim->getClipWidth(), motion->getPosY(),
            anim->getClipHeight() );

    //Keep the camera in bounds
    if( gCamera.x < 0 )
    {
        gCamera.x = 0;
    }
    if( gCamera.y < 0 )
    {
        gCamera.y = 0;
    }
    if( gCamera.x > LEVEL_WIDTH - gCamera.w )
    {
        gCamera.x = LEVEL_WIDTH - gCamera.w;
    }
    if( gCamera.y > LEVEL_HEIGHT - gCamera.h )
    {
        gCamera.y = LEVEL_HEIGHT - gCamera.h;
    }
}


/* Get camera setting */

SDL_Rect LCamera::getCamera() const
{
    return gCamera;
}

SDL_Rect* LCamera::getCameraView()
{
    return &gCamera;
}
