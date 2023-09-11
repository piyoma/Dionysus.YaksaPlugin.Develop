#include "Example.Plugin.Client.h"

#include <iostream>
#include <sstream>
#include <thread>

namespace Plugin{
    
    ExamplePluginClient::ExamplePluginClient()
    {
        Yaksa::createYaksaPlugin(this);
    }
    ExamplePluginClient::~ExamplePluginClient()
    {
    }
    void ExamplePluginClient::onPluginCreated(Yaksa::OnePlugin* plugin)
    {
        /**
         * @brief Demonstrate Codes.
         * The only action of this method is strore plugin pointer.
         * Should not do any other things.
        */
        plugin_ = plugin;
    }
    void ExamplePluginClient::onPluginEvent(const char* cmd, const char* msg)
    {
        if(getPlugin()->IsRunInPluginThread()){
            printf("[ Async Called Example Client ] Example. CMD: %s, MSG: %s\n", cmd, msg);
        }else{
            printf("[ Sync Called Example Client ] Example. CMD: %s, MSG: %s\n", cmd, msg);    
        }
    }
    void ExamplePluginClient::onThreadSafeInitialize()
    {
        printf("Usage Example Prompt [1] : Plugin initialize code should be writen in here\n");
        getPlugin()->PostDelayTask(0, 100);
    }
    void ExamplePluginClient::onRunDelayTask(const char* args)
    { 
        /**
         * Send my data in RPC plugin.
        */
        getPlugin()->NetSend("Example Plugin Send RPC");
        /**
         * Will back to here 2 seconds later.
        */
        getPlugin()->PostDelayTask(0, 2000);
        
    }
    void ExamplePluginClient::onAsyncNetRecv(const char* msg)
    {
        printf("Asynchronously Read reply Message Back from RPC:%s\n", msg);
    }
    void ExamplePluginClient::ForwardToPluginContainer(void* obj, void* cmd, void* arg, int len,
		        void* callback, void* obj_invoke, int msgid)
    {
        /**
         * @brief Demonstrate Codes.
         * Ignore this method, PluginClient shouldn't call this funtion.
         * Do not call this method in plugin module.
        */
        getPlugin()->ForwardToPluginContainer(obj, cmd, arg, len, 
		    callback, obj_invoke, msgid);
        
    }
    Yaksa::OnePlugin* ExamplePluginClient::getPlugin()
    {
        /**
         * @brief Demonstrate Codes.
         * it's not necessary to check if this pointer is nullptr.
        */
        return plugin_;
    }
}