/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 23:47:36 by qfremeau          #+#    #+#             */
/*   Updated: 2016/04/14 23:47:56 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

/* Initializes variables */

LAnimation::LAnimation()
{
    fprintf( stderr, "LAnimation class is being created\n" );

    //Initialize
    mCurrentFrame    = 0;
    mMaxFrames       = 1;
    mFrameInc        = 1;
    mFrameRate       = DEFAULT_FRAMERATE;
    mOldTime         = 0;
    mOscillate       = false;
    mRectangleClip   = { DEFAULT_SIZE,
                         DEFAULT_SIZE,
                         SCREEN_WIDTH,
                         SCREEN_HEIGHT / 2 - DEFAULT_SIZE };
    mStateID         = 0;
}


/* Deallocate */

LAnimation::~LAnimation()
{
    fprintf( stderr, "LAnimation class is being deleted\n" );
}


/* Reset animation attributes */

void    LAnimation::reset()
{
    mCurrentFrame    = 0;
    mFrameInc        = 1;
    mFrameRate       = DEFAULT_FRAMERATE;
    mOscillate       = false;
}


/* Animate clipping texture -> give the current frame */

void    LAnimation::onAnimate()
{
    if( mFrameInc != 0 )
    {
        // Give the frame rate; check if 1 second has passed
        if( (unsigned)mOldTime + (unsigned)mFrameRate > SDL_GetTicks() )
        {
            return;
        }
        //Old time is reset to current time
        mOldTime = SDL_GetTicks();

        //Increases current frame by mFrameInc (1)
        mCurrentFrame += mFrameInc;

        //If mOscillate is true, frames increase then decrease: 0 1 2 3 2 1 0
        if( mOscillate )
        {
            if( mFrameInc > 0)
            {
                if( mCurrentFrame >= mMaxFrames )
                {
                    mFrameInc = -mFrameInc;
                }
            }
            else
            {
                if( mCurrentFrame <= 0 )
                {
                    mFrameInc = -mFrameInc;
                }
            }
        }
        else //Frames only increase: 0 1 2 3 0 1 2 3
        {
            if( mCurrentFrame >= mMaxFrames )
            {
                mCurrentFrame = 0;
            }
        }
    }
}


/* Set animation state ID */

void    LAnimation::setAnimStateID( Uint8 stateID )
{
    mStateID = stateID;
}


/* Set oscillation */

void    LAnimation::setOscillation( bool oscillate )
{
    mOscillate = oscillate;
}


/* Set max frame rate to stop animation */

void    LAnimation::setMaxFrames( int maxFrames )
{
    mMaxFrames = maxFrames;
}


/* Set frame rate for the animation */

void    LAnimation::setFrameRate( int frameRate )
{
    mFrameRate = frameRate;
}


/* Set current frame to display into the class */

void    LAnimation::setCurrentFrame( int currentFrame )
{
    //Check if frame is not out of the texture
    if( currentFrame < 0 || currentFrame >= mMaxFrames )
    {
        return;
    }

    mCurrentFrame = currentFrame;
}


/* Set frame incrementation */

void    LAnimation::setFrameInc( int frameInc )
{
    mFrameInc = frameInc;
}


/* Set a rectangle clip for the texture to be displayed */

void    LAnimation::setRectClip( int clipWidth, int clipHeight )
{
    //Duplicate clipWidth to clipHeight if previous is NULL
    if( !clipHeight )
    {
        clipHeight = clipWidth;
    }

    //Get the current frame and set it as a rectangle
    mRectangleClip.x = getCurrentFrame() * clipWidth;
    mRectangleClip.y = mStateID * clipHeight;
    mRectangleClip.w = clipWidth;
    mRectangleClip.h = clipHeight;
}


/* Return the current frame to be displayed */

int     LAnimation::getCurrentFrame() const
{
    return mCurrentFrame;
}


/* Return the rectangle clip for the texture to be displayed */

SDL_Rect LAnimation::getRectClip() const
{
    return mRectangleClip;
}

int     LAnimation::getClipWidth() const
{
    return mRectangleClip.w;
}

int     LAnimation::getClipHeight() const
{
    return mRectangleClip.h;
}


/* Return the current animation state ID */

int     LAnimation::getStateID() const
{
    return mStateID;
}
