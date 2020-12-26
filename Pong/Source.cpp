#include <iostream>
#include "Game.h"
#include "graphics.h"
#include "Config.h"

using namespace std;

int height = 800;
int width = 1200;
int playerOneScore = 0;
int playerTwoScore = 0;






void drawGame()
{

    graphics::Brush br;

    br.outline_opacity = 1.0f;

    graphics::drawLine(0, 0, width, 0, br);
    graphics::drawLine(0, height, width, height, br);


}







void update(float ms)
{  

    Game* pong = reinterpret_cast<Game*> (graphics::getUserData());
    pong->update();


    if (graphics::getKeyState(graphics::SCANCODE_SPACE)) {
        cout << "Space Pressed";
        graphics::setDrawFunction(drawGame);
        drawGame();
    }

}


void draw()
{

    Game* pong = reinterpret_cast<Game*> (graphics::getUserData());
    pong->draw();
    


}





int main()
{
    Game pong;
    graphics::createWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Pong");

    graphics::setUserData(&pong);

    graphics::setDrawFunction(draw);
    graphics::setUpdateFunction(update);


    graphics::setCanvasSize(CANVAS_WIDTH, CANVAS_HEIGHT);
    graphics::setCanvasScaleMode(graphics::CANVAS_SCALE_FIT);


    graphics::setFont((string)ASSET_PATH+"\\orange juice 2.0.ttf");

    graphics::startMessageLoop();
    graphics::destroyWindow();

   

    return 0;
}

