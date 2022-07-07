#include "window.h"
#include "../game/pacman.h"
#include <iostream>
int main(void)
{
    Window window;
    window.run();
    for (size_t i = 0; i < 31; i++)
    {
        for (size_t j = 0; j < 28; j++)
        {
            std::cout << Window::maze[j][i] << " ";
            /* code */
        }
        /* code */
        std::cout << std::endl;
    }
    

    return 0;
}
