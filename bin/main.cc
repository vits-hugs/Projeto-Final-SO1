#include "window.h"
#include "../game/pacman.h"
#include "thread.h"
#include "system.h"
#include "main_class.h"

#include <iostream>

__USING_API 
int main(void)
{
    Window window;
    window.run();
    /*for (size_t i = 0; i < 31; i++)
    {
        for (size_t j = 0; j < 28; j++)
        {
            std::cout << Window::maze[j][i] << " ";
            
        } 
        std::cout << std::endl;
    }*/
    
    
    System::init(&Main::run);
    return 0;
}
