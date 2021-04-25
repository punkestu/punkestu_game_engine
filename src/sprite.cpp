#include "sprite.h"

using namespace sprEnt;

void spriteM::reg(std::string id, sprite& spr){
    if(_sprites.find(id) == _sprites.end()){//check is the id available
        _sprites[id] = spr;
    }else{
        warning("sprite", "id has been used");
    }
}

void spriteM::create(std::string id){
    if(_sprites.find(id) == _sprites.end()){//check is the id available
        sprite temp;
        //set default value
        temp.texture.texture = "-";
        temp.texture.source = {0,0,0,0};
        temp.scale = {1,1};
        temp.position = {0,0};
        temp.color = {0,0,0,0};
        temp._timer.init();
        _sprites[id] = temp;
    }else{
        warning("sprite", "id has been used");
    }
}

sprite& spriteM::get(std::string id){
    if(_sprites.find(id) != _sprites.end()){//check is the sprite is there
        return _sprites[id];
    }else{
        warning("sprite", "sprite not found");
        NULLSPR.texture = {"-",{0,0,0,0}};
        NULLSPR.position = {0,0};
        NULLSPR.scale = {1,1};
        NULLSPR.color = {0,0,0,0};
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

void sprEnt::animate(bool frmLim, renTex& object, anim& animProp){
    object.source = {animProp.start.x+animProp.frame*animProp.start.w,
                    animProp.start.y,animProp.start.w,animProp.start.h};
    if(animProp.frame>=animProp.nframe){
        animProp.frame = 0;
    }else{
        if(frmLim){
            animProp.frame++;
        }
    }

}