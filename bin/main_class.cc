#include "main_class.h"

__BEGIN_API

Thread *Main::ghost_threads[4];
Thread *Main::pacman_thread;
Thread *Main::window_thread;
Thread *Main::input_thread;
Semaphore *Main::sem;

sf::RenderWindow* Main::window;
Pacman *Main::pacman;
Window *Main::window_logic;
Ghost  *Main::ghost_array[4];
__END_API
