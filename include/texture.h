/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 17:06:31 by qfremeau          #+#    #+#             */
/*   Updated: 2016/04/11 17:07:17 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _TEXTURE_H
#define _TEXTURE_H

extern const SDL_Color      COLOR_NONE;


/* Texture wrapper class to load the texture files into game */

class   LTexture
{
    public:
        //Initializes variables
        LTexture();
        //Deallocate memory
        ~LTexture();
        //Deallocate texture
        void free();


        //Load image at specified path
        bool loadFromFile( std::string path, SDL_Color colorKey = COLOR_NONE );
        //Create image from font string
        bool loadFromRenderedText( std::string textureText,
                                   SDL_Color textColor );


        //Set color modulation
        void setColorMod( Uint8 red, Uint8 green, Uint8 blue );
        //Set blending
        void setBlendMode( SDL_BlendMode blending );
        //Set alpha modulation
        void setAlphaMod( Uint8 alpha );
        //Set new image dimensions
        void setImageSize( int width = (int)NULL, int height = (int)NULL );


        //Renders texture at given point
        void render( int x, int y, SDL_Rect* clip = nullptr,
                     double angle = 0.0, SDL_Point* center = nullptr,
                     SDL_RendererFlip flip = SDL_FLIP_NONE );


        //Gets image dimensions
        int getWidth() const;
        int getHeight() const;
        //Is texture still NULL
        bool isTexture() const;


    protected:
        //The actual hardware texture
        SDL_Texture*    mTexture;

        //Image dimensions
        int             mWidth;
        int             mHeight;
};

#endif // _TEXTURE_H
