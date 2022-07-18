#include"ghost.h"

Ghost::Ghost(int id) {
    _x = 220;
    _y = 240;
    _id = id;
}

void Ghost::run() {

    _x+=1;

}