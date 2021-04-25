#ifndef SPRITE___H
#define SPRITE___H

#include "texture.h"

//sprite entities
namespace sprEnt{
    //property for rendering
    struct renTex{//texture for rendering
        std::string texture;
        SDL_Rect source;
    };

    //sprite main property
    struct sprite{
        renTex texture;
        vect2d position;
        vect2d scale;
        timer _timer;
        SDL_Color color;
    };

    //sprite animation property    
    struct anim{
        uint fps; int nframe;
        int frame;
        SDL_Rect start;
    };

    //animate the sprite using the renTex
    void animate(bool frmLim, renTex& object, anim& animProp);
};

typedef std::map<std::string, sprEnt::sprite> sprMap;

//sprite manager
class spriteM{
    private:
        sprEnt::sprite NULLSPR;//default value for sprite
        sprMap _sprites;//sprite container
    public:
        void reg(std::string id, sprEnt::sprite& spr);//register created sprite
        void create(std::string id);//create new sprite in the container

        sprEnt::sprite& get(std::string id);//get specific sprite
        sprMap& getAll();//get all sprite in container

        void del(std::string id);//delete specific sprite
        void clear();//clear sprite in the container
};

#endif