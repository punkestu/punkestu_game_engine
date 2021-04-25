#include "sprite.h"

void spriteM::reg(std::string id, sprite& spr){
    if(_sprites.find(id) == _sprites.end()){
        _sprites[id] = spr;
    }else{
        warning("sprite", "id has been used");
    }
}

void spriteM::create(std::string id){
    if(_sprites.find(id) == _sprites.end()){
        sprite temp;
        temp.texture.texture = "-";
        temp.texture.source = {0,0,0,0};
        temp.scale = {1,1};
        temp.position = {0,0};
        temp.color = {0,0,0,0};
        _sprites[id] = temp;
    }else{
        warning("sprite", "id has been used");
    }
}

sprite& spriteM::get(std::string id){
    if(_sprites.find(id) != _sprites.end()){
        return _sprites[id];
    }else{
        warning("sprite", "sprite not found");
        NULLSPR = {{"-",{0,0,0,0}},{0,0},{1,1},{0,0,0,0}};
        return NULLSPR;
    }
}

sprMap& spriteM::getAll(){
    return _sprites;
}

void spriteM::del(std::string id){
    if(_sprites.find(id) != _sprites.end()){
        _sprites.erase(id);
    }else{
        warning("sprite", "sprite not found");
    }
}

void spriteM::clear(){
    _sprites.clear();
}