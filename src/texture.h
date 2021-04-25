#ifndef TEXTURE___H
#define TEXTURE___H

#include "core.h"

typedef std::map<std::string, SDL_Texture*> texMap;
class textureM{
    private:
        texMap _textures;
    public:
        void reg(std::string id, SDL_Texture* texture);
        void create(SDL_Renderer* renderer, std::string id, std::string path);
        
        texMap& getAll();
        SDL_Texture* get(std::string id);
        
        void del(std::string);
        void clear();
};

#endif