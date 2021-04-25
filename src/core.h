#ifndef CORE___H
#define CORE___H

#include <iostream>
#include <vector>
#include <map>
#include <string>

#include <SDL.h>
#include <SDL_image.h>

//to warn (reason is where the warning come from, warn is the warning message)
void warning(std::string reason, std::string warn);
//to error (reason is where the error come from, err is the error message)
void error(std::string reason, std::string err);

//2d point
struct vect2d
{
    int x,y;
};

//timer
class timer{
    private:
        uint timeElp;//elapsed time from init
        uint frmTm;//frame limit time
        uint litTm;//literal time limit
        uint getDelta(uint& base);//get time elapsed from reset
        void reset(uint& base);//reset specific timer variable
    public:
        void init();//init timer
        void restart();//restart all of timer variable
        bool frmLim(uint fps);//limit frame
        bool timLim(uint tm);//limit time
        uint getTimeElp();//get elapsed time
};

#endif
