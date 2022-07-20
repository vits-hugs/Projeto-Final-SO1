#include"ghost.h"
#include<iostream>
int Ghost::pac_x=220;
int Ghost::pac_y=245;

void Ghost::send_pac_cord(int x,int y) 
{pac_x=x;pac_y=y;}

void Ghost::try_ressurection(int time_elapsed) {
    if ((time_elapsed - time_of_death)/1000 >= time_to_ressurect) {
        is_dead = false;
    }
}
Ghost::Ghost(int id) {
    _old_x = GHOST_START_X;
    _old_y = GHOST_START_Y;
    _x = GHOST_START_X;
    _y = GHOST_START_Y;
    _id = id;
    speed = GHOST_SPEED;
}

void Ghost::center_me(int x,int y) {
   
    if (direct%2) {
        _x = x*16;
    } else {
        _y = y*16;
    }
}



void Ghost::run() { 
    Ghost_think();
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
        std::cout << "fantasma ué\n";

        break;
    }

}



void Ghost::Ghost_think() {
    int direct_temp= get_direction();
    if (!is_dead) {
        int dist_x = pac_x - x();
        int dist_y = pac_y - y();
        if(possibles[0] && direct_temp!=RIGHT){
            set_direction(LEFT);
        }
        if(possibles[1]&& direct_temp!=DOWN){
            set_direction(UP);
        }
        if(possibles[2] && direct_temp!=LEFT){
        if(!possibles[0] || dist_x > 0) set_direction(RIGHT);
        }
        if(possibles[3] && direct_temp!=UP) {
        if(!possibles[1] || dist_y > 0) set_direction(DOWN);
        }
    } else {
        if (!possibles[2]) {
            set_direction(RIGHT);
        } else {
            set_direction(LEFT);
        }

    }
}