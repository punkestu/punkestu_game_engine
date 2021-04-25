#include "src/sprite.h"

int main(int argc, char* argv[]){
    
    //init
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG);
    //end of init

    //test code
    SDL_Window* window = SDL_CreateWindow("tester", 100,100,400,400,false);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

    SDL_Event e;
    textureM manager;
    spriteM sMan;
    sMan.create("test");
    sMan.get("test").texture = {"test",{0,0,128/8,32}};
    sMan.get("test").position = {100,100};
    sMan.get("test").scale = {2,2};
    sprEnt::anim anim1;
    anim1.fps = 1;
    anim1.nframe = 8;
    anim1.start = {0,0,128/8,32};
    anim1.frame = 0;
    manager.create(renderer, "test", "./src/test.png");
    SDL_Rect dst;
    dst = {sMan.get("test").position.x,sMan.get("test").position.y,
        sMan.get("test").texture.source.w*sMan.get("test").scale.x,
        sMan.get("test").texture.source.h*sMan.get("test").scale.y};
    while(true){
        SDL_PollEvent(&e);
        if(e.type == SDL_QUIT){
            break;
        }
        sprEnt::animate(sMan.get("test")._timer.frmLim(anim1.fps),sMan.get("test").texture,anim1);
        SDL_SetRenderDrawColor(renderer, 0,0,0,255);
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, manager.get("test"), &sMan.get("test").texture.source, &dst);
        SDL_RenderPresent(renderer);
    }
    //end of test code

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
    
    return 0;
}