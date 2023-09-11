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

#ifndef __PLUGIN_NETWORD_H__
#define __PLUGIN_NETWORD_H__

namespace Yaksa{

    /**
     *  @brief
     *  The Following Codes defines the interface and demonstrate Usage 
     *  that the basic ways of Yaksa plugin Component(Your Code) how to
     *  Communicate with agent(RPC-Module).
     * 
     *  ## Getting started
     */
    class PluginNet{

    public:
    
        /**
         * @brief Always be called when the net command received completion by Java server.
         * @param msg The message received form agent(RPC-Module).
        */
        virtual void onAsyncNetRecv(const char* msg){};

        /**
         * @brief Only the network plugin module need implement this method.
         * @param msg The message data that needs to send to Java server.
        */
        virtual const char* netRunWidthReturnMsg(const char* msg) {return nullptr;};

    };

    class PluginMod{

    public:
        /**
         * @brief Invoke plugin method internal.
         * @param pkg The message data that needs to send to Java server.
        */
        virtual void SubscribeEvent(void* pkg, void* mod_name, 
            void* event, void* callback) {};

    };
} 

#endif //__PLUGIN_NETWORD_H__ 