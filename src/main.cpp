/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 14:08:28 by qfremeau          #+#    #+#             */
/*   Updated: 2016/04/11 14:12:02 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

int main( int argc, char* args[] )
{
    (void)argc;
    (void)args;

    fprintf( stdout, "Entering main()\n" );

    srand( time(NULL) );

	//Start up SDL and create window
	if( !init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		//Load media
		if( !loadMedia() )
		{
			fprintf( stderr, "Failed to load media!\n" );
		}
		else
		{
			//Main loop flag
			bool quit = false;
			//Event handler
			SDL_Event e;

            //Play the music
            Mix_PlayMusic( gMusicGrassWorld, -1 );

            //Animation setting
            /*gLastID = BOWSER_ID_RIGHT_WAITING;
            gBusy = IDLE;
            gDirection = DIR_RIGHT;*/

            gBowserEntity.onAnimate( BOWSER_MAXFRAME_RIGHT_WAITING,
                                      BOWSER_ID_RIGHT_WAITING );

			//While application is running
			while( !quit )
			{
				//Handle events on queue
				while( SDL_PollEvent( &e ) != 0 )
				{
					//User requests quit
					if( e.type == SDL_QUIT )
					{
						quit = true;
					}

					//Handle input for the dot
					gBowserEntity.handleEvent( e );
				}

                //Clear screen
                SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
                SDL_RenderClear( gRenderer );

				//Render the buffer
				render();

                //Update screen
				SDL_RenderPresent( gRenderer );
			}
		}
	}

	//Free resources and close SDL
	close();

	fprintf( stdout, "__Succeeded main()\n" );
	return EXIT_SUCCESS;
}
