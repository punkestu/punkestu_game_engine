#ifndef TEXTURE___H
#define TEXTURE___H

#include "core.h"

class textureM{
    private:

    public:
        void reg(std::string id, SDL_Texture* texture);
        void create(std::string id, std::string path);
        SDL_Texture* get(std::string id);
        void del(std::string);
        void clear();
};

#endif