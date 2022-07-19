#include "pacman.h"
#include <iostream>
Pacman::Pacman() {
    _old_x = INIT_POS_X;
    _old_y = INIT_POS_Y;
    _x = INIT_POS_X;
    _y = INIT_POS_Y;
    speed = PAC_SPEED;
}

bool Pacman::verify_super(int time) {
    if((time - time_power)/1000 >= SUPER_DURATION){
        power=false;
    }
    return power;
}   

int Pacman::damage(int time,int fps) {
    if(time - last_time_damaged>3*fps) {
        life-=1;
        _x = INIT_POS_X;
        _y = INIT_POS_Y;
        set_old_pos();
        last_time_damaged = time;
    }
    return life;
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