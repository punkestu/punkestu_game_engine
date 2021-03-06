#include "texture.h"

void textureM::reg(std::string id, SDL_Texture* texture){
    if(texture != NULL){
        if(_textures.find(id) == _textures.end()){//check is the id is available
            _textures[id] = texture;
        }else{
            warning("texture", "id has been used");
        }
    }else{
        warning("texture", "texture not valid");
    }
}

void textureM::create(SDL_Renderer* renderer, std::string id, std::string path){
    if(_textures.find(id) == _textures.end()){//check is the id is available
        SDL_Surface* surf = IMG_Load(path.c_str());
        if(surf != NULL){
            SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, surf);
            SDL_FreeSurface(surf);
            if(tex != NULL){
                _textures[id] = tex;
            }else{
                warning("texture", "texture not valid");
            }
        }else{
            warning("texture", "path not valid");
        }
    }else{
        warning("texture", "id has been used");
    }
}

texMap& textureM::getAll(){
    return _textures;
}

SDL_Texture* textureM::get(std::string id){
    if(_textures.find(id) != _textures.end()){//check is the texture is there
        return _textures[id];
    }else{
        warning("texture", "texture not found");
        return NULL;
    }
}

void textureM::del(std::string id){
    if(_textures.find(id) != _textures.end()){//check is the texture is there
        SDL_DestroyTexture(_textures[id]);
        _textures.erase(id);
    }else{
        warning("texture", "texture not found");
    }
}

void textureM::clear(){
    for(texMap::iterator it = _textures.begin(); it != _textures.end(); it++){//delete all texture before clear the container
        SDL_DestroyTexture(it->second);
    }
    _textures.clear();
}