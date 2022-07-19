#ifndef GHOST_H
#define GHOST_H
#include "agent.h"
#define GHOST_START_X 220
#define GHOST_START_Y 250
#define GHOST_SPEED 3;
class Ghost:public Agent{

public:
    Ghost(int id);
    static void send_pac_cord(int x,int y);
    void run();
    const short int id() {return _id;}
    void center_me(int x,int y);

    void kill(int time_of_death,int time_to_ressurect){
                        this->time_of_death = time_of_death;
                        this->time_to_ressurect = time_to_ressurect;
                        is_dead=true;
                        _x=GHOST_START_X;
                        _y=GHOST_START_Y;}

    void try_ressurection(int time_elapsed);
    const int get_direction(){return direct;}
    void set_direction(direction dir){direct = dir;}
    const int tile_old_x(){return _tile_old_x;}
    const int tile_old_y(){return _tile_old_y;}
    void set_tile_old(int x,int y) {_tile_old_x = x;_tile_old_y = y;}
    bool possibles[4];
private:
    static int pac_x;
    static int pac_y;
    void seePossibles();
    void  Ghost_think();
    short int _id;
    int _tile_old_x{-1};
    int _tile_old_y{-1};
    bool is_dead{false};
    int time_of_death;
    int time_to_ressurect;

    direction direct;

};





#endif