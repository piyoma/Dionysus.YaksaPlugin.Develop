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

 *  @copyright 1996-2023 @author tonoshiki piyoma. All rights reserved.
 *  Communicate, can be reached at @github:https://github.com/piyoma
 */

#ifndef __PLUGIN_CLIENT_H__
#define __PLUGIN_CLIENT_H__

#include "Plugin.Unnecessary.h"

namespace Yaksa{

    /**
     *  @brief
     *  The Following Codes defines the interface and demonstrate Usage 
     *  that the basic ways of Yaksa plugin Component(Your Code) how to
     *  Communicate with agent(RPC-Module).
     * 
     *  ## Getting started
     *  @version 1.0.1 @date updated July/19/2023
     * 
     *  Examples Usage:
     *   
     *  @example (1) Send Your I/O data to Agent(RPC-Module).
     *  void OnYourIOComplete(const char* data){
     *      OnePlugin* plugin_ = GetYourPlugin();
     *      plugin_->NetSend(data);
     *      //Or you may encode your data to Json.
     *      Json json_ = ConstrutJsonData(data);
     *      plugin_->NetSend(json.raw_byte());
     *  }
     *  @example (2) Response to agent(RPC-Module) commands
     *  virtual void YourPluginClientClass::onPluginEvent(
     *  const char* cmd, const char* msg) override{
     *      if(strcmp(cmd, "suspend") == 0){
     *          //Run your suspend module method.
     *          doSuspend();
     *      }
     *  }
     */

    /**
     * @interface Control interface used by PluginClient instance.
     * For send message to agent(RPC-Module) or maintain Thread-Safe.
     * @version 1.0.3
     */
    class OnePlugin {

    public:

        /**
         * @brief Send Json or Binrary data message to agent(RPC-Module) Asynchronously,
         * should be called in the Plugin Client.
         * @param msg The message send to agent(RPC-Module).
        */
        virtual void NetSend(const char* msg) = 0;

        /**
         * @brief Post a Thread-Safe-Task run in Plugin Thread if you like.
        */
        virtual void PostTask(const char* data = nullptr) = 0;

        /**
         * @brief Post a delay Thread-Safe-Task run in Plugin Thread that 
         * created by agent(RPC-Module).
        */
        virtual void PostDelayTask(const char* data = nullptr, unsigned int inverval_ms = 0) = 0;

        /**
         * @brief Note this method is used for agent(RPC-Module) only, 
         * Do not invoke this methon in plugin module.
        */
        virtual void ForwardToPluginContainer(void* obj, void* cmd, void* arg, int len, 
                void* callback, void* obj_invoke, int msgid) = 0;
        
        /**
         * @brief call a module method synchronously.
        */
        virtual void ExecuteSync(const char* pkg, const char* mod_name, const char* cmd, const char* data, 
            void* callback, int msgid) = 0;

        /**
         * @brief call a module method asynchronously.
        */
        virtual void ExecuteAsync(const char* pkg, const char* mod_name, const char* cmd, const char* data,
            void* callback, int msgid) = 0;

        /**
         * @brief Private method used in Plugin System. 
        */
        virtual void ForwordAsyncCmd(const char* cmd, const char* msg) = 0;

        /**
         * @brief Retrive if current run in plugin thread. For thread safe. 
        */
        virtual bool IsRunInPluginThread() = 0;
    };

    /**
     * @interface Delegate interface to handle the events form server.
     *  be invoked by agent(RPC-Module) or other plugins.
     * @version 1.0.6
     * @brief Necessary PluginClient interface that every plugin should implement.
     */
    class PluginClient

    /**
     * @version 1.0.2
     *  Network interface that only network module should implement or want recv net message.
     */
    : public Yaksa::PluginNet {

    public:

        /**
         * @brief This method be called when OnePlugin be created.
         * It's method only used for store the control pointer of OnePlugin.
        */
        virtual void onPluginCreated(OnePlugin* plugin) = 0;

        /**
         * @brief Initialize PluginClient run in the Safe-Thread 
         * created by agent(RPC-Module). Write initialize codes here.
        */
        virtual void onThreadSafeInitialize() = 0;

        /**
         * @brief The PluginClient control interface. Invoked by agent(RPC-Module).
         * @param cmd The type of command. 
         * @param msg The message received form agent(RPC-Module).
        */
        virtual void onPluginEvent(const char* cmd, const char* msg) = 0;

         /**
         * @brief Called when run on named privare plugin thread task that invoked by yourself.
         * @param args The task params,typicaly json data or binary data.
        */
        virtual void onRunDelayTask(const char* args) = 0;

    };
}

#endif //__PLUGIN_CLIENT_H__