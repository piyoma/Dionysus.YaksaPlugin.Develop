/**
 * 
__     __   _                _____  _             _       
\ \   / /  | |              |  __ \| |           (_)      
 \ \_/ /_ _| | _____  __ _  | |__) | |_   _  __ _ _ _ __   @brief Yaksa Plugin
  \   / _` | |/ / __|/ _` | |  ___/| | | | |/ _` | | '_ \  @version 1.0.2
   | | (_| |   <\__ \ (_| | | |    | | |_| | (_| | | | | | Licensed under the MIT License 
   |_|\__,_|_|\_\___/\__,_| |_|    |_|\__,_|\__, |_|_| |_| @link <http://opensource.org/licenses/MIT>.
                                             __/ |        
                                            |___/         

 *  Copyright 1996-2023 @author piyoma. All rights reserved.
 *  Communicate, can be reached at @github:https://github.com/piyoma
 */

#ifndef __PLUGIN_EXPORT_H__
#define __PLUGIN_EXPORT_H__

#include "Plugin.Client.h"

namespace Yaksa{

    /**
     * @brief load a group of plugins form Json format configuration file.
     * @param json_path the path of plugins configuration file on localdisk.
     * @return if load plugins success returns true, false otherwise.
    */
    extern "C" bool loadYaksaPlugins(const char* json_path);
    
    /**
     * @brief Create a plugin object, this function used by plugin client
     * @param client the pointer of Yaksa::PluginClient.
    */
    extern "C" void createYaksaPlugin(void* client);
    
}

#endif //__PLUGIN_EXPORT_H__