#include "core.h"

void warning(std::string reason, std::string warn){
    printf("warning[%s]: %s", reason.c_str(), warn.c_str());
}

void error(std::string reason, std::string err){
    printf("error[%s]: %s", reason.c_str(), err.c_str());
}

uint timer::getDelta(uint& base){
    return SDL_GetTicks()-base;
}

void timer::reset(uint& base){
    base = SDL_GetTicks();
}

void timer::init(){
    restart();
}

void timer::restart(){
    reset(timeElp);
    reset(frmTm);
    reset(litTm);
}

bool timer::frmLim(uint fps){
    if(getDelta(frmTm) > 1000/fps){
        reset(frmTm);
        return true;
    }else{
        return false;
    }
}

bool timer::timLim(uint tm){
    if(getDelta(litTm) > tm){
        reset(litTm);
        return true;
    }else{
        return false;
    }
}

uint timer::getTimeElp(){
    return getDelta(timeElp);
}