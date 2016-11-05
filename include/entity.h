/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 06:37:53 by qfremeau          #+#    #+#             */
/*   Updated: 2016/04/13 06:38:06 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ENTITY_H
#define _ENTITY_H

extern const SDL_Color      COLOR_NONE;


/* Entity wrapper class: using LTexture, LMotion, LAnimation, LSounds objects */
/* Template class to render an entity and count them into dynamic array */

class LEntity
{
    public:
        //Dynamic array to hold entities - static to avoid circular dependencies
        static std::vector<LEntity*>    entityList;


        //Initializes variables
        LEntity();
        //Deallocate memory
        ~LEntity();


        //Deallocate entity texture
        /*void free();*/


        //Load texture at specified path with size and transparency
        bool loadFromFile( std::string path, SDL_Color colorKey = COLOR_NONE,
                           int width = (int)NULL, int height = (int)NULL );
        //Set the initial position, gravity, speed, state ID and various options
        void init();
        //Animate entity sprite -> give the current frame
        void onAnimate( int maxFrame, int animID, bool oscillate = false,
                        int frameRate = (int)NULL, int frameInc = (int)NULL );
        //Adjusts the velocity considering speed and gravity events
        void handleEvent( SDL_Event& e );
        //Move and set speed + gravity
        void moveEntity();
        //Plays SFX sounds
        /*void playSFX();*/
        //Renders animated entity at given point
        void render( int entitySize, SDL_Rect camera, int height = (int)NULL,
                     double angle = 0.0, SDL_Point* center = nullptr,
                     SDL_RendererFlip flip = SDL_FLIP_NONE );


    public:
        //Texture to be rendered
        LTexture*       mTexture;
        //Animation object to control frame rate
        LAnimation*     mAnim;
        //Moves entity
        LMotion*        mMotion;
        //Play sounds
        /*LSoundEffect* mSoundsSfx;*/


    protected:
        //State ID for animation
        int             mOldStateID;
};

#endif // _ENTITY_H
