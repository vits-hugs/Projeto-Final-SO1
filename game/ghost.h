#ifndef GHOST_H
#define GHOST_H
#include "agent.h"
class Ghost:public Agent{

public:
    Ghost(int id);
    void run();
    const short int id() {return _id;}

private:
    short int _id;



};





#endif