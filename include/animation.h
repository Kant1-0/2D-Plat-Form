/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 23:46:10 by qfremeau          #+#    #+#             */
/*   Updated: 2016/04/14 23:47:59 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ANIMATION_H
#define _ANIMATION_H

/* Animation wrapper class to render frame by frame the entity */

class   LAnimation
{
    public:
        //Initializes variables
        LAnimation();
        //Deallocate
        ~LAnimation();


        //Reset animation attributes
        void reset();
        //Animate clipping texture -> give the current frame
        void onAnimate();


        //Set animation state ID to be used later
        void setAnimStateID( Uint8 stateID );
        //Set oscillation
        void setOscillation( bool oscillate );
        //Set max frame rate to stop animation
        void setMaxFrames( int maxFrame );
        //Set frame rate for the animation
        void setFrameRate( int frameRate );
        //Set frame incrementation
        void setFrameInc( int frameInc );
        //Set current frame to display into the class
        void setCurrentFrame( int currentFrame );
        //Set a rectangle clip for the texture
        void setRectClip( int clipWidth, int clipHeight = (int)NULL );


        //Return the current frame to be displayed
        int getCurrentFrame() const;
        //Return the rectangle clip to display the texture
        SDL_Rect getRectClip() const;
        int getClipWidth() const;
        int getClipHeight() const;
        //Return the current animation state ID
        int getStateID() const;


    protected:
        //Rectangle for clip texture
        SDL_Rect    mRectangleClip;
        //State ID of animation
        Uint8       mStateID;
        //Determine if framed animation should mOscillate or not
        bool        mOscillate;


        //Set the maximum frame to show on animation
        int         mMaxFrames;
        //Current frame to display
        int         mCurrentFrame;
        //The number of frame to be increased
        int         mFrameInc;


        //Frame rate in milliseconds
        int         mFrameRate;
        //Time saved to check if time passed
        long        mOldTime;
};

#endif // _ANIMATION_H
