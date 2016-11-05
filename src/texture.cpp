/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/10 13:17:18 by qfremeau          #+#    #+#             */
/*   Updated: 2016/04/11 14:12:06 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

/* Initializes variables */

LTexture::LTexture()
{
    fprintf( stderr, "LTexture class is being created\n" );

    //Initialize
    mTexture    = nullptr;
    mWidth      = 0;
    mHeight     = 0;
}


/* Deallocate memory */

LTexture::~LTexture()
{
    fprintf( stderr, "LTexture class is being deleted\n" );

    //Deallocate
    free();
}


/* Deallocate texture */

void    LTexture::free()
{
    if( mTexture != nullptr )
    {
        SDL_DestroyTexture( mTexture );
        mTexture = nullptr;
        mWidth = 0;
        mHeight = 0;
    }
}


/* Load image at specified path with transparency set */

bool    LTexture::loadFromFile( std::string path, SDL_Color colorKey )
{
    //Get rid of preexisting texture
    free();

    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    if( loadedSurface == nullptr )
    {
        fprintf( stderr, "Unable to load image %s! SDL_image Error: %s\n",
                 path.c_str(), IMG_GetError() );
        return false;
    }
    else
    {
        if( !( colorKey.a == COLOR_NONE.a && colorKey.r == COLOR_NONE.r &&
               colorKey.g == COLOR_NONE.g && colorKey.b == COLOR_NONE.b ) )
        {
            //Transparency color key
            SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB
                             ( loadedSurface->format, colorKey.r, colorKey.g,
                             colorKey.b ) );
        }

        //Create texture from surface pixels
        mTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
        if( mTexture == nullptr )
        {
            fprintf( stderr, "Unable to create texture from %s! "
                     "SDL Error: %s\n", path.c_str(), SDL_GetError() );
            return false;
        }
        else
        {
            //Get image dimensions
            mWidth = loadedSurface->w;
            mHeight = loadedSurface->h;
        }

        //Get rid of old loaded surface
        SDL_FreeSurface( loadedSurface );
    }

    //Return success
    return true;
}


/* Create image from font string */
bool    LTexture::loadFromRenderedText( std::string textureText,
                                        SDL_Color textColor )
{
    //Get rid of preexisting texture
    free();

    //Render text surface
    SDL_Surface* textSurface = TTF_RenderText_Solid( gFont, textureText.c_str(),
                                                     textColor );
    if( textSurface == nullptr )
    {
        fprintf( stderr, "Unable to render text surface! SDL_ttf Error: %s\n",
                 TTF_GetError() );
        return false;
    }
    else
    {
        //Create texture from surface pixels
        mTexture = SDL_CreateTextureFromSurface( gRenderer, textSurface );
        if ( mTexture == nullptr )
        {
            fprintf( stderr, "Unable to create texture from rendered text! "
                     "SDL Error: %s\n", SDL_GetError() );
            return false;
        }
        else
        {
            //Get image dimensions
            mWidth = textSurface->w;
            mHeight = textSurface->h;
        }

        //Get rid of old surface
        SDL_FreeSurface( textSurface );
    }

    //Return success
    return true;
}


/* Set color modulation */

void    LTexture::setColorMod( Uint8 red, Uint8 green, Uint8 blue )
{
    //Modulate texture
    SDL_SetTextureColorMod( mTexture, red, green, blue );
}


/* Set blending */

void    LTexture::setBlendMode( SDL_BlendMode blending )
{
    //Set blending function
    SDL_SetTextureBlendMode( mTexture, blending );
}


/* Set alpha modulation */

void    LTexture::setAlphaMod( Uint8 alpha )
{
    //Modulate texture alpha
    SDL_SetTextureAlphaMod( mTexture, alpha );
}


/* Set new image dimensions */

void    LTexture::setImageSize( int width, int height )
{
    if( width != (int)NULL )
    {
        mWidth = width;
    }

    if( height != (int)NULL )
    {
        mHeight = height;
    }
}


/* Renders texture at given point */

void    LTexture::render( int x, int y, SDL_Rect* clip, double angle,
                          SDL_Point* center, SDL_RendererFlip flip )
{
    //Set rendering space and render to screen
    SDL_Rect renderQuad = { x , y, mWidth, mHeight };

    //Set clip rendering dimensions
    if( clip != nullptr )
    {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }

    //Render to screen
    SDL_RenderCopyEx( gRenderer, mTexture, clip, &renderQuad, angle,
                      center, flip );
}


/* Gets image dimensions */

int     LTexture::getWidth() const
{
    return mWidth;
}

int     LTexture::getHeight() const
{
    return mHeight;
}


/* Is texture still nullptr */

bool    LTexture::isTexture() const
{
    if( mTexture == nullptr )
    {
        return false;
    }

    return true;
}
