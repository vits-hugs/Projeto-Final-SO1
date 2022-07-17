#include "pacman.h"
#include <iostream>
Pacman::Pacman() {

}

void Pacman::move() {

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