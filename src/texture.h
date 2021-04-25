#ifndef TEXTURE___H
#define TEXTURE___H

#include "core.h"

typedef std::map<std::string, SDL_Texture*> texMap;
//texture manager
class textureM{
    private:
        texMap _textures;//texture container
    public:
        void reg(std::string id, SDL_Texture* texture);//register created texture
        void create(SDL_Renderer* renderer, std::string id, std::string path);//create new texture in the container
        
        texMap& getAll();//get all texture from container
        SDL_Texture* get(std::string id);//get specific texture
        
        void del(std::string);//delete texture
        void clear();//clear texture in the container
};

#endif