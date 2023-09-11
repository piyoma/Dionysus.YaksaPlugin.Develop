#include "RPC.Plugin.Client.h"

#include <iostream>
#include <sstream>
#include <thread>

namespace Plugin{
    
    RpcPluginClient::RpcPluginClient()
    {
        Yaksa::createYaksaPlugin(this);
    }
    RpcPluginClient::~RpcPluginClient()
    {

    }
    void RpcPluginClient::onPluginCreated(Yaksa::OnePlugin* plugin)
    {
        /**
         * @brief Demonstrate Codes.
         * The only action of this method is strore plugin pointer.
         * Should not do any other things.
        */
        plugin_ = plugin;
    }
    void RpcPluginClient::onPluginEvent(const char* cmd, const char* msg)
    {

    }
    void RpcPluginClient::onThreadSafeInitialize()
    {
        /**
         * Nothing to do with this method.
        */
     
    }
    void RpcPluginClient::onRunDelayTask(const char* args)
    {
        /**
         * Nothing to do with this method.
        */
    }
    const char* RpcPluginClient::netRunWidthReturnMsg(const char* args)
    {
        static std::string ret_msg;
        ret_msg = sendToServer(args);
        
        getPlugin()->ExecuteAsync(0, "Plugin.Example", "CommandFromRPC", "Sending Data", 0, 0);

        return ret_msg.c_str();
    }
    void RpcPluginClient::ForwardToPluginContainer(void* obj, void* cmd, void* arg, int len,
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
    std::string RpcPluginClient::sendToServer(const char* args)
    {
        if(!rpc_client_.get()){
            std::string target = "localhost:50051";
            rpc_client_ = std::make_shared<Rpc::Client>(grpc::CreateChannel(target, grpc::InsecureChannelCredentials()));      
        }
        std::string message(args);
        std::string reply = rpc_client_->send(message);   
        return reply;
    }
    Yaksa::OnePlugin* RpcPluginClient::getPlugin()
    {
        /**
         * @brief Demonstrate Codes.
         * it's not necessary to check if this pointer is nullptr.
        */
        return plugin_;
    }
}