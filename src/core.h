#ifndef CORE___H
#define CORE___H

#include <iostream>
#include <vector>
#include <map>
#include <string>

#include <SDL.h>
#include <SDL_image.h>

void warning(std::string reason, std::string warn);
void error(std::string reason, std::string err);

struct vect2d
{
    int x,y;
};

class timer{
    private:
        static uint timeElp;
        uint frmTm;
        uint litTm;
        uint getDelta(uint& base);
        void reset(uint& base);
    public:
        void init();
        void restart();
        bool frmLim(uint fps);
        bool timLim(uint tm);
        uint getTimeElp();
};

#endif