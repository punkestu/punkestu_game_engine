#ifndef SPRITE___H
#define SPRITE___H

#include "texture.h"

struct renTex{//texture for rendering
    std::string texture;
    SDL_Rect source;
};

struct sprite{
    renTex texture;
    vect2d position;
    vect2d scale;
    SDL_Color color;
};

typedef std::map<std::string, sprite> sprMap;
class spriteM{
    private:
        sprMap _sprites;
    public:
        void reg(std::string id, sprite* spr);
        void create(std::string id);

        sprite get(std::string id);
        sprMap getAll();

        void del(std::string id);
        void clear();
};

#endif