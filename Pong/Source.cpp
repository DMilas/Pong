#include <iostream>
#include "Game.h"
#include "graphics.h"
#include "Config.h"

using namespace std;















void update(float ms)
{  

    Game* pong = reinterpret_cast<Game*> (graphics::getUserData());
    pong->update();


    

}


void draw()
{

    Game* pong = reinterpret_cast<Game*> (graphics::getUserData());
    pong->draw();
    


}





int main()
{
    Game pong;
    pong.init();
    graphics::createWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Pong");

    graphics::setUserData(&pong);

    graphics::setDrawFunction(draw);
    graphics::setUpdateFunction(update);


    graphics::setCanvasSize(CANVAS_WIDTH, WINDOW_HEIGHT);
    graphics::setCanvasScaleMode(graphics::CANVAS_SCALE_FIT);


    graphics::setFont((string)ASSET_PATH+"\\orange juice 2.0.ttf");

    graphics::startMessageLoop();
    graphics::destroyWindow();

   

    return 0;
}

