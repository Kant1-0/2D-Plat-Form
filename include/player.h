/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 11:22:30 by qfremeau          #+#    #+#             */
/*   Updated: 2016/04/21 11:23:36 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PLAYER_H
#define _PLAYER_H

/* Player wrapper class: heritage from Entity */

class LPlayer : public LEntity
{
    public:
        //Set clipping based on current key state
        //void checkScancode();
        //Plays the sound effects
        //void playSoundEffect();


        //Set direction to entity
        //void setDirection();


    private:
        //Animation setting
        int         mLastID;
        int         mStateID;
        int         mDirection;
        bool        mBusy;


        //Enumeration to handle the various states
        enum        eDirection
        {
            Left, Right
        };
        enum        eStateID
        {
            WalkRight,
            WalkLeft,
            AttackRight,
            AttackLeft,
            WaitingRight,
            WaitingLeft
        };
};

#endif // _PLAYER_H
