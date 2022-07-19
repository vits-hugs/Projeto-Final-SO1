#define GHOST_START_X 220
#define GHOST_START_Y 250
#define GHOST_SPEED 1;
#include"ghost.h"
#include<iostream>
int Ghost::pac_x=220;
int Ghost::pac_y=245;

void Ghost::send_pac_cord(int x,int y) 
{pac_x=x;pac_y=y;}


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
    int d;
    for (int i = 0; i < 4; i++)
    {
        if (possibles[i]) {
            d=i;
        }
    }
    int dist_x = pac_x - x();
    int dist_y = pac_y - y();
    if(possibles[0] && direct!=RIGHT){
        set_direction(LEFT);
    }
    if(possibles[1]&& direct!=DOWN){
        set_direction(UP);
    }
    if(possibles[2] && direct!=LEFT){
       /*if(possibles[0] && pac_x > 0)*/ set_direction(RIGHT);
    }
    if(possibles[3] && direct!=UP) {
       /* if(possibles[0] && pac_y > 0)*/ set_direction(DOWN);
    }
    
    if (id()==0) {
    std::cout << "possibles: ";
    for (bool x:possibles) {
        
        std::cout << x << " ,";
    }
    std::cout << std::endl;
    }
}