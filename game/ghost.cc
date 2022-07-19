#define GHOST_START_X 220
#define GHOST_START_Y 250

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
}

void Ghost::center_me(int x,int y) {
    //_x = (x*16) - 1;
    //_y = y*16 + 8;

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
    
    if(possibles[0]){
        set_direction(LEFT);
        std::cout << "VOU PRA DIREITA";
    }
    if(possibles[1]){
        set_direction(UP);
    }
    if(possibles[2]){
        set_direction(RIGHT);
    }
    if(possibles[3]) {
        set_direction(DOWN);
    }
    
    if (id()==0) {
    std::cout << "possibles: ";
    for (bool x:possibles) {
        
        std::cout << x << " ,";
    }
    std::cout << std::endl;
    }
}