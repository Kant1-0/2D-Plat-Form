/* Set clipping based on current key state */

//void    LPlayer::checkScancode()
//{
    /*//Check keyboard state
    const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );

    //Players goes right
    if( currentKeyStates[ SDL_SCANCODE_RIGHT ] ||
        currentKeyStates[ SDL_SCANCODE_D ] )
    {
        gDirection = DIR_RIGHT;
        gBowserTexture.moveX( BOWSER_SPEED );

        if( gLastID != BOWSER_ID_RIGHT_WALK &&
            gLastID != BOWSER_ID_RIGHT_ATTACK &&
            gLastID != BOWSER_ID_LEFT_ATTACK )
        {
            gLastID = BOWSER_ID_RIGHT_WALK;
            gBowserAnim.reset();
            gBowserAnim.setMaxFrames( BOWSER_MAXFRAME_RIGHT_WALK );
            gBowserAnim.setAnimStateID( BOWSER_ID_RIGHT_WALK );
        }
    }
    //Players goes left
    else if( currentKeyStates[ SDL_SCANCODE_LEFT ] ||
             currentKeyStates[ SDL_SCANCODE_A ] )
    {
        gDirection = DIR_LEFT;
        gBowserTexture.moveX( BOWSER_SPEED );

        if( gLastID != BOWSER_ID_LEFT_WALK &&
            gLastID != BOWSER_ID_RIGHT_ATTACK &&
            gLastID != BOWSER_ID_LEFT_ATTACK )
        {
            gLastID = BOWSER_ID_LEFT_WALK;
            gBowserAnim.reset();
            gBowserAnim.setMaxFrames( BOWSER_MAXFRAME_LEFT_WALK );
            gBowserAnim.setAnimStateID( BOWSER_ID_LEFT_WALK );
        }
    }
    //Player attacks
    else if( currentKeyStates[ SDL_SCANCODE_G ]||
             currentKeyStates[ SDL_SCANCODE_KP_0 ] )
    {
        //On right
        if( gDirection == DIR_RIGHT )
        {
            if( gLastID != BOWSER_ID_RIGHT_ATTACK )
            {
                gBusy = BUSY;
                gLastID = BOWSER_ID_RIGHT_ATTACK;
                gBowserAnim.reset();
                gBowserAnim.setMaxFrames( BOWSER_MAXFRAME_RIGHT_ATTACK );
                gBowserAnim.setAnimStateID( BOWSER_ID_RIGHT_ATTACK );
            }
        }
        //On left
        else if( gDirection == DIR_LEFT )
        {
            if( gLastID != BOWSER_ID_LEFT_ATTACK )
            {
                gBusy = BUSY;
                gLastID = BOWSER_ID_LEFT_ATTACK;
                gBowserAnim.reset();
                gBowserAnim.setMaxFrames( BOWSER_MAXFRAME_LEFT_ATTACK );
                gBowserAnim.setAnimStateID( BOWSER_ID_LEFT_ATTACK );
            }
        }
    }
    //Player is idle : no keyboard input
    else
    {
        //Player is waiting on right
        if( gDirection == DIR_RIGHT && gBusy == IDLE )
        {
            if( gLastID != BOWSER_ID_RIGHT_WAITING )
            {
                gLastID = BOWSER_ID_RIGHT_WAITING;
                gBowserAnim.reset();
                gBowserAnim.setMaxFrames( BOWSER_MAXFRAME_RIGHT_WAITING );
                gBowserAnim.setAnimStateID( BOWSER_ID_RIGHT_WAITING );
            }
        }
        //Player is waiting on left
        else if( gDirection == DIR_LEFT && gBusy == IDLE )
        {
            if( gLastID != BOWSER_ID_LEFT_WAITING )
            {
                gLastID = BOWSER_ID_LEFT_WAITING;
                gBowserAnim.reset();
                gBowserAnim.setMaxFrames( BOWSER_MAXFRAME_LEFT_WAITING );
                gBowserAnim.setAnimStateID( BOWSER_ID_LEFT_WAITING );
            }
        }
        //Player is still attacking
        else if( ( gLastID == BOWSER_ID_RIGHT_ATTACK ||
                 gLastID == BOWSER_ID_LEFT_ATTACK ) && gBowserAnim.
                 getCurrentFrame() == BOWSER_MAXFRAME_RIGHT_ATTACK - 1 )
        {
            gBusy = IDLE;
        }
    }*/
//}


/* Plays the sound effects */

//void    LPlayer::playSoundEffect()
//{
    /*//Initialize random class
    LRandom     mRandom;

    switch( gLastID )
    {
        //When Bowser attack
        case BOWSER_ID_LEFT_ATTACK:
        case BOWSER_ID_RIGHT_ATTACK:
            if( gBowserAnim.getCurrentFrame() == 1 )
            {
                mRandom.rand_a_b( 1, 3 );
                if( mRandom.getRandomInt() == 1 )
                {
                    Mix_PlayChannel( -1, gSoundBowserAttack1, 0 );
                }
                else if( mRandom.getRandomInt() == 2 )
                {
                    Mix_PlayChannel( -1, gSoundBowserAttack2, 0 );
                }
                else if( mRandom.getRandomInt() == 3 )
                {
                    Mix_PlayChannel( -1, gSoundBowserAttack3, 0 );
                }
            }
            break;
        //When Bowser walk
        case BOWSER_ID_RIGHT_WALK:
        case BOWSER_ID_LEFT_WALK:
            if( gBowserAnim.getCurrentFrame() == 4 )
            {
                Mix_PlayChannel( -1, gSoundFootstepGrass1, 0 );
            }
            else if(gBowserAnim.getCurrentFrame() == 11 )
            {
                Mix_PlayChannel( -1, gSoundFootstepGrass2, 0 );
            }
            break;
        //When Bowser is waiting
        case BOWSER_ID_RIGHT_WAITING:
        case BOWSER_ID_LEFT_WAITING:
            mRandom.rand_a_b( 1, 20 );
            if( mRandom.getRandomInt() == 1 )
            {
                Mix_PlayChannel( -1, gSoundBowserWaiting5, 0 );
            }
    }*/
//}

