/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 15:21:56 by qfremeau          #+#    #+#             */
/*   Updated: 2016/04/21 15:22:38 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

/* Initializes variables */

LMotion::LMotion()
{
    fprintf( stderr, "LMotion class is being created\n" );

    //Initialize the offsets
    mPosX = 0;
    mPosY = 0;

    //Initialize the velocity
    mVelX = 0;
    mVelY = 0;

    //Maximum axis velocity
    gSpeed      = DEFAULT_SPEED;
    gGravity    = DEFAULT_GRAVITY;

    //Set collision box dimension
    mCollider.w = DEFAULT_WIDTH;
    mCollider.h = DEFAULT_HEIGHT;
}


/* Deallocate memory */

LMotion::~LMotion()
{
    fprintf( stderr, "LMotion class is being deleted\n" );
}


/* Set position of movable */

void    LMotion::setPosition( int posX, int posY )
{
    mPosX = posX;
    mPosY = posY;
}



/* Set velocity's entity */

void    LMotion::setSpeed( int velX )
{
    mVelX = velX;
}

void    LMotion::setGravity( int velY )
{
    mVelY = velY;
}


/* Adjusts the velocity considering speed and gravity events */

void    LMotion::handleEvent( SDL_Event& e )
{
    //If a key was pressed
    if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_UP:
                mVelY -= gGravity;
                break;
            case SDLK_DOWN:
                mVelY += gGravity;
                break;
            case SDLK_LEFT:
                mVelX -= gSpeed;
                break;
            case SDLK_RIGHT:
                mVelX += gSpeed;
                break;
        }
    }

    //If a key was released
    else if( e.type == SDL_KEYUP && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_UP:
                mVelY += gGravity;
                break;
            case SDLK_DOWN:
                mVelY -= gGravity;
                break;
            case SDLK_LEFT:
                mVelX += gSpeed;
                break;
            case SDLK_RIGHT:
                mVelX -= gSpeed;
                break;
        }
    }
}


/* Set collision box */

void    LMotion::setCollisionBox( int width, int height )
{
    mCollider.w = width;
    if( height == (int)NULL )
    {
        mCollider.h = width;
    }
    else
    {
        mCollider.h = height;
    }
}


/* Move the entity */

void    LMotion::move()// SDL_Rect entity )
{
    //Move to left or right
    mPosX += mVelX;
    mCollider.x = mPosX;

    //If it went too far to the left or right
    if( ( mPosX < 0 ) ||
        ( mPosX + mCollider.w > LEVEL_WIDTH ) )// ||
        //checkCollision( mCollider, entity ) )
    {
        //Move back
        mPosX -= mVelX;
    }

    //Move up or down
    mPosY += mVelY;
    mCollider.y = mPosY;

    //If it went too far up or down
    if( ( mPosY < 0 ) ||
        ( mPosY + mCollider.h > LEVEL_HEIGHT ) )// ||
        //checkCollision( mCollider, entity ) )
    {
        //Move back
        mPosY -= mVelY;
    }
}



/* Calculate top/bottom and left/right of collision boxes */

bool LMotion::checkCollision( SDL_Rect a, SDL_Rect b )
{
    //The sides of the rectangles
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    //Calculate the sides of rectangle A
    leftA = a.x;
    rightA = a.x + a.w;
    topA = a.y;
    bottomA = a.y + a.h;

    //Calculate the sides of rectangle B
    leftB = b.x;
    rightB = b.x + b.w;
    topB = b.y;
    bottomB = b.y + b.h;

    //If any of the sides from A are outside of B = no collision
    if( bottomA <= topB )
    {
        return false;
    }

    if( topA >= bottomB )
    {
        return false;
    }

    if( rightA <= leftB )
    {
        return false;
    }

    if( leftA >= rightB )
    {
        return false;
    }

    //If none of the sides from A are outside B = collision
    return true;
}


/* Get position offsets */

int     LMotion::getPosX() const
{
    return mPosX;
}

int     LMotion::getPosY() const
{
    return mPosY;
}


/* Get collider rectangle */

SDL_Rect LMotion::getCollider() const
{
    return mCollider;
}
