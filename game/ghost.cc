#include"ghost.h"
#define GHOST_START_X 220
#define GHOST_START_Y 245
Ghost::Ghost(int id) {
    _old_x = GHOST_START_X;
    _old_y = GHOST_START_Y;
    _x = GHOST_START_X;
    _y = GHOST_START_Y;
    _id = id;
}

void Ghost::run() {
    set_old_pos();
    _x+=1;

}