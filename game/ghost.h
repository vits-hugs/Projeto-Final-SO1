#ifndef GHOST_H
#define GHOST_H
#include "agent.h"
class Ghost:public Agent{

public:
    Ghost(int id);
    static void send_pac_cord(int x,int y);
    void run();
    const short int id() {return _id;}
    void center_me(int x,int y);

    const int get_direction(){return direct;}
    void set_direction(direction dir){direct = dir;}

    bool possibles[4];
private:
    static int pac_x;
    static int pac_y;
    void seePossibles();
    void  Ghost_think();
    short int _id;
    direction direct;


     




};





#endif