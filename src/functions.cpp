/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 21:46:52 by qfremeau          #+#    #+#             */
/*   Updated: 2016/04/11 14:11:58 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

SDL_Surface*    loadSurface( std::string path )
{
    //The final optimized image
    SDL_Surface* optimizedSurface = NULL;

    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if( loadedSurface == NULL )
    {
        fprintf( stderr, "Unable to load image %s! SDL Error: %s\n",
                 path.c_str(), IMG_GetError() );
    }
    else
    {
        //Convert surface to screen format
        optimizedSurface = SDL_ConvertSurface( loadedSurface,
                                               gScreenSurface->format,
                                              (Uint32)NULL );
        if( optimizedSurface == NULL )
        {
            fprintf( stderr, "Unable to optimize image %s! SDL Error: %s\n",
                	 path.c_str(), SDL_GetError() );
        }

        //Get rid of old loaded surface
        SDL_FreeSurface( optimizedSurface );
    }

    return loadedSurface;
}
