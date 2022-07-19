#ifndef pacman_h
#define pacman_h

#include "agent.h"

#define INIT_POS_X 220
#define INIT_POS_Y 220
#define PAC_SPEED 5
class Pacman : public Agent
{
public:
    Pacman();
    
    const int get_direction(){return direct;}
    void set_direction(direction dir){direct = dir;}

    int damage();
    void run();
    
private:
    int life{3};
    bool colide;
    direction direct{LEFT};
};





#endif