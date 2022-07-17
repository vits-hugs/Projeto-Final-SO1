#ifndef pacman_h
#define pacman_h
#define INIT_POS_X 220
#define INIT_POS_Y 365
class Pacman
{
public:
    typedef enum {RIGHT,LEFT,UP,DOWN} direction;
    Pacman();

    int damage();

    void move();
    void setDirection(direction dir){direct = dir;}

    float x() {return _x;}
    float y() {return _y;}

private:
    int life{3};
    float _x{INIT_POS_X};
    float _y{INIT_POS_Y};
    float speed{10};
    direction direct{LEFT};
};





#endif