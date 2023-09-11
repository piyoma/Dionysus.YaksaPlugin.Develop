#include <stdio.h>
#include <iostream>

#include "agent/agent.h"

/**
 * 
                                    _     _    _                 _                 
   ____       /\                   | |   | |  | |               (_)                 @brief Agent Horaisan
  / __ \     /  \   __ _  ___ _ __ | |_  | |__| | ___  _ __ __ _ _ ___  __ _ _ __   @version 1.0.2
 / / _` |   / /\ \ / _` |/ _ \ '_ \| __| |  __  |/ _ \| '__/ _` | / __|/ _` | '_ \  Licensed under the MIT License
| | (_| |  / ____ \ (_| |  __/ | | | |_  | |  | | (_) | | | (_| | \__ \ (_| | | | | <http://opensource.org/licenses/MIT>.
 \ \__,_| /_/    \_\__, |\___|_| |_|\__| |_|  |_|\___/|_|  \__,_|_|___/\__,_|_| |_| @category [AGENT]
  \____/            __/ |                                                          
                   |___/                                                           

 *  @copyright 2023 @author piyoma. All rights reserved.
 *  Communicate, can be reached at @github:https://github.com/piyoma
*/

int main(int argc, char* argv[]) {
    Agent agent("configuration/plugins.json");
    agent.Run();
    return 0;
}