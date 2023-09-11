#ifndef __PRINT_LOGO_H__
#define __PRINT_LOGO_H__

#include <stdio.h>
#include <iostream>

#define COLOR_GREEN "\033[32m"
#define COLOR_RED "\033[31m"
#define COLOR_YELLOW "\033[33m"
#define COLOR_BLUE "\033[34m"
#define COLOR_PURPLE "\033[35m"
#define COLOR_CYAN "\033[36m"
#define COLOR_LGRAY "\033[37m"
#define COLOR_NORMAL "\033[m"

namespace agent_print{

static const char* c_banner = "                                    _     _    _                 _                 \n\
   ____       /\\                   | |   | |  | |               (_)                 \n\
  / __ \\     /  \\   __ _  ___ _ __ | |_  | |__| | ___  _ __ __ _ _ ___  __ _ _ __   @version 1.0.2\n\
 / / _` |   / /\\ \\ / _` |/ _ \\ '_ \\| __| |  __  |/ _ \\| '__/ _` | / __|/ _` | '_ \\  Licensed under the MIT License\n\
| | (_| |  / ____ \\ (_| |  __/ | | | |_  | |  | | (_) | | | (_| | \\__ \\ (_| | | | | @link <http://opensource.org/licenses/MIT>.\n\
 \\ \\__,_| /_/    \\_\\__, |\\___|_| |_|\\__| |_|  |_|\\___/|_|  \\__,_|_|___/\\__,_|_| |_| @category [AGENT]Holocene 2023\n\
  \\____/            __/ | \n\
                   |___/\n";
                   
    static void banner(void){
        std::cout << COLOR_YELLOW << "@Group Younger Dryas";
        std::cout << COLOR_LGRAY << " @Project: ";
        std::cout << COLOR_BLUE << "Holocene[July 2023]:" << 
        std::endl << COLOR_BLUE << std::endl << COLOR_NORMAL;
        std::cout << COLOR_PURPLE << c_banner << COLOR_PURPLE << std::endl << COLOR_NORMAL;
    };

};
#endif //__PRINT_LOGO_H__