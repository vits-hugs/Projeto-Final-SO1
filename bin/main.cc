#include "thread.h"
#include "system.h"
#include "main_class.h"

#include <iostream>

__USING_API 
int main(void)
{    
    System::init(&Main::run);
    return 0;
}
