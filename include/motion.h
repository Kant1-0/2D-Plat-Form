/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 14:42:21 by qfremeau          #+#    #+#             */
/*   Updated: 2016/04/21 14:44:35 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MOTION_H
#define _MOTION_H

/* Motion wrapper class to move entity and test collide */

class LMotion
{
    public:
        //Initializes variables
        LMotion();
        //Deallocate memory
        ~LMotion();


        //Maximum axis velocity
        int gSpeed;
        int gGravity;


        //Set position of movable
        void setPosition( int posX, int posY );
        //Set velocity's entity
        void setSpeed( int velX );
        void setGravity( int velY );
        //Set collision box
        void setCollisionBox( int width, int height = (int)NULL );


        //Adjusts the velocity considering speed and gravity events
        void handleEvent( SDL_Event& e );
        //Calculate top/bottom and left/right of collision boxes
        bool checkCollision( SDL_Rect a, SDL_Rect b );
        //Move the entity
        void move();// SDL_Rect entity );


        int getVelocity() const;
        //Get position offsets
        int getPosX() const;
        int getPosY() const;
        //Get collider rectangle
        SDL_Rect getCollider() const;


    protected:
        //The X and Y offsets
        int         mPosX;
        int         mPosY;
        //The velocity
        int         mVelX;
        int         mVelY;
        //Collision box
        SDL_Rect    mCollider;
};

#endif // _MOTION_H
