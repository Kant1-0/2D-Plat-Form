/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 14:59:16 by qfremeau          #+#    #+#             */
/*   Updated: 2016/04/23 14:59:23 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CAMERA_H
#define _CAMERA_H

/* Camera wrapper class to create a scrolling camera */

class   LCamera
{
    public:
        //Initializes variables
        LCamera();
        //Deallocate memory
        ~LCamera();


        //Center camera over the player
        void onMotion( LMotion* motion, LAnimation* anim );


        //Set camera effects
        void setCamera( int posX, int posY, int width, int height );
        void setCamera( SDL_Rect camera );

        //Get camera setting
        SDL_Rect getCamera() const;
        SDL_Rect* getCameraView();


    protected:
        //The camera area
        SDL_Rect gCamera;
};

#endif // _CAMERA_H
