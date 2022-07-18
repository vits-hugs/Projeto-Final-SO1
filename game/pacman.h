#ifndef pacman_h
#define pacman_h
#include "agent.h"
#define INIT_POS_X 220
#define INIT_POS_Y 220
#define PAC_SPEED 5
class Pacman : public Agent
{
public:
    typedef enum {LEFT,UP,RIGHT,DOWN} direction;
    Pacman();

    int damage();
    void run();
    void set_direction(direction dir){direct = dir;}
    const int get_direction(){return direct;}

    void return_old_pos(){_x = _old_x; _y = _old_y;}
private:
    int life{3};
    float _old_x{INIT_POS_X};
    float _old_y{INIT_POS_Y};
    bool colide;
    direction direct{LEFT};
};





#endif