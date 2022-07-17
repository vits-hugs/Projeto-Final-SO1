#ifndef inputReader_h
#define inputReader_h

#include "pacman.h"

class InputReader
{
public:
    InputReader();

    short int get_inputs();

private:
    Pacman* pacman;

};






#endif