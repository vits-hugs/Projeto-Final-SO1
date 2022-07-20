#ifndef pacman_h
#define pacman_h

#include "agent.h"

#define INIT_POS_X 220
#define INIT_POS_Y 220
#define PAC_SPEED 5
#define SUPER_DURATION 5
class Pacman : public Agent
{
public:
    Pacman();
    
    const int get_direction(){return direct;}
    void set_direction(direction dir){direct = dir;}
    bool verify_super(int time);
    bool is_super(){return power;}
    void go_power(int time_init){time_power=time_init;power=true;}
    int damage(int time,int fps);
    void run();
    
private:
    int life{3};
    bool colide;
    bool power{false};
    int time_power;
    int last_time_damaged;
    direction direct{LEFT};
};





#endif