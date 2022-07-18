#ifndef pacman_h
#define pacman_h
#define INIT_POS_X 220
#define INIT_POS_Y 220
class Pacman
{
public:
    typedef enum {LEFT,UP,RIGHT,DOWN} direction;
    Pacman();

    int damage();

    void move();
    void set_direction(direction dir){direct = dir;}
    int get_direction(){return direct;}
    float x() {return _x;}
    float y() {return _y;}

    void return_old_pos(){_x = _old_x; _y = _old_y;}
private:
    int life{3};
    float _x{INIT_POS_X};
    float _y{INIT_POS_Y};
    float _old_x{INIT_POS_X};
    float _old_y{INIT_POS_Y};
    float speed{2};
    bool colide;
    direction direct{LEFT};
};





#endif