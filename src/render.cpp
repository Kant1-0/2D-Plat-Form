/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 03:53:22 by qfremeau          #+#    #+#             */
/*   Updated: 2016/04/13 03:56:14 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

void    render()
{
    //Move player with gravity and speed according to camera
    gBowserEntity.moveEntity();
    gCamera.onMotion( gBowserEntity.mMotion, gBowserEntity.mAnim );

    //Render background texture
    gBackgroundParallaxTexture.render( 0, 0, gCamera.getCameraView() );
    gBackgroundTexture.render( 0, 0, gCamera.getCameraView() );

    //Bowser setting
    /*checkBowserScancode();*/

    //Render animated bowser
    gBowserEntity.render( BOWSER_SIZE, gCamera.getCamera() );

    //Play sound effects
    /*playBowserSoundEffect();*/

    //Render text
    gTextTexture.render( ( SCREEN_WIDTH - gTextTexture.getWidth() ) / 2,
                         ( SCREEN_HEIGHT - gTextTexture.getHeight() ) / 12 );
}
