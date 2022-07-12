#include "main_class.h"

__BEGIN_API

Thread *Main::ghost_threads[4];
//Thread *pacman_thread;
Thread *Main::window_thread;
//Thread *input_thread;
Semaphore *Main::sem;

__END_API
