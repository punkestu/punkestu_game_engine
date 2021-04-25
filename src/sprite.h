#ifndef SPRITE___H
#define SPRITE___H

#include "texture.h"

struct sprite{
    std::string texture;
    vect2d position;
    vect2d scale;
    SDL_Color color;
};

#endif