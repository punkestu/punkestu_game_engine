#ifndef SPRITE___H
#define SPRITE___H

#include "texture.h"

namespace sprEnt{
    struct renTex{//texture for rendering
        std::string texture;
        SDL_Rect source;
    };

    struct sprite{
        renTex texture;
        vect2d position;
        vect2d scale;
        timer _timer;
        SDL_Color color;
    };

    struct anim{
        uint fps; uint nframe;
        uint frame;
        SDL_Rect start;
    };

    void animate(bool frmLim, renTex& object, anim& animProp);
};

typedef std::map<std::string, sprEnt::sprite> sprMap;
class spriteM{
    private:
        sprEnt::sprite NULLSPR;
        sprMap _sprites;
    public:
        void reg(std::string id, sprEnt::sprite& spr);
        void create(std::string id);

        sprEnt::sprite& get(std::string id);
        sprMap& getAll();

        void del(std::string id);
        void clear();
};

#endif