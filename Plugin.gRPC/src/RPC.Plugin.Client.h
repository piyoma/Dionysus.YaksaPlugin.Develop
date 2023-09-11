#ifndef __RPC_PLUGIN_CLIENT_H__
#define __RPC_PLUGIN_CLIENT_H__

#include "YaksaPlugin/Pulgin.Export.h"
#include "gRPC.Message.Client.h"

namespace Plugin
{
   
    class RpcPluginClient:
          public Yaksa::PluginClient{
    public:

        static RpcPluginClient* Get(){
            static RpcPluginClient client;
            return &client;
        };

        RpcPluginClient();
        ~RpcPluginClient();

        virtual void onPluginCreated(Yaksa::OnePlugin* plugin) override;
        virtual void onPluginEvent(const char* cmd, const char* msg) override;
        virtual void onThreadSafeInitialize() override;
        virtual void onRunDelayTask(const char* args) override;
        virtual const char* netRunWidthReturnMsg(const char* args) override;
        void ForwardToPluginContainer(void* obj, void* cmd, void* arg, int len,
		        void* callback, void* obj_invoke, int msgid);

    private:

        std::string sendToServer(const char* args);
        
        int callback_id = 0;
        Yaksa::OnePlugin* getPlugin();
        Yaksa::OnePlugin* plugin_ = nullptr;
        std::shared_ptr<Rpc::Client> rpc_client_;
    };
}

#endif //__RPC_PLUGIN_CLIENT_H__