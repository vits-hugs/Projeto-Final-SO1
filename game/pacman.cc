#include "pacman.h"
#include <iostream>
Pacman::Pacman() {
    _old_x = INIT_POS_X;
    _old_y = INIT_POS_Y;
    _x = INIT_POS_X;
    _y = INIT_POS_Y;
    speed = PAC_SPEED;
}

void Pacman::run() {
    set_old_pos();
    

    switch (direct)
    {
    case RIGHT:
        /* code */
        _x += speed;
        break;
    case LEFT:
        _x -= speed;
        break;
    case UP:
        _y -= speed;
        break;
    
    case DOWN:
        _y += speed;
        break;
    default:
        std::cout << "UEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE\n";

        break;
    }
}