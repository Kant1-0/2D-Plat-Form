/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 06:53:34 by qfremeau          #+#    #+#             */
/*   Updated: 2016/04/13 07:30:16 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

/* Dynamic array to hold entities - static to avoid circular dependencies */

std::vector<LEntity*> LEntity::entityList;


/* Initializes variables */

LEntity::LEntity()
{
    fprintf( stderr, "LEntity class is being created\n" );

    mTexture = new LTexture();
    mAnim    = new LAnimation();
    mMotion  = new LMotion();

    LEntity::entityList.push_back( this );
}


/* Deallocate memory */

LEntity::~LEntity()
{
    fprintf( stderr, "LEntity class is being deleted\n" );

    mTexture->free();
    delete mTexture;
    delete mAnim;
    delete mMotion;
}


/* Load texture at specified path with size and transparency */

bool    LEntity::loadFromFile( std::string path, SDL_Color colorKey, int width,
                               int height )
{
    //Load texture from LTexture class
    mTexture->loadFromFile( path.c_str(), colorKey );
    if ( !mTexture->isTexture() )
    {
        return false;
    }

    //Set new width and height if it was specified
    if( width != (int)NULL && height != (int)NULL )
    {
        mTexture->setImageSize( width, height );
    }

    return true;
}


/* Set the initial position, gravity, speed, state ID and various options */

void    LEntity::init()// int posX, int posY, int gravity, int speed, int animID,
//                       int maxFrame )
{

}


/* Renders animated entity at given point */

void    LEntity::render( int entitySize, SDL_Rect camera, int height,
                         double angle, SDL_Point* center,
                         SDL_RendererFlip flip )
{
    //Launch animation frame to get the current frame
    mAnim->onAnimate();

    //Create a rectangle frame
    mAnim->setRectClip( entitySize, height );
    SDL_Rect currentRect = mAnim->getRectClip();

    //Render the texture
    mTexture->render( mMotion->getPosX() - camera.x,
                      mMotion->getPosY() - camera.y,
                      &currentRect, angle, center, flip );
}


/* Animate entity sprite -> give the current frame */

void    LEntity::onAnimate( int maxFrame, int animID, bool oscillate,
                            int frameRate, int frameInc )
{
    //Reset all value to default
    mAnim->reset();

    //Then change some values if necessary
    if( oscillate )
    {
        mAnim->setOscillation( true );
    }

    if( frameRate )
    {
        mAnim->setFrameRate( frameRate );
    }

    if( frameInc )
    {
        mAnim->setFrameInc( frameInc );
    }

    mAnim->setMaxFrames( maxFrame );
    mAnim->setAnimStateID( animID );
}


/* Adjusts the velocity considering speed and gravity events */

void    LEntity::handleEvent( SDL_Event& e )
{
    mMotion->handleEvent( e );

    if( mOldStateID != mAnim->getStateID() )
    {
        mOldStateID = mAnim->getStateID();
        mMotion->setCollisionBox( mAnim->getClipHeight(),
                                  mAnim->getClipWidth() );
    }

}


/* Move and set speed + gravity */

void    LEntity::moveEntity()
{
    mMotion->move();
}
