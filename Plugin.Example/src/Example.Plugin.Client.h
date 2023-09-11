#ifndef __EXAMPLE_PLUGIN_CLIENT_H__
#define __EXAMPLE_PLUGIN_CLIENT_H__

#include "YaksaPlugin/Pulgin.Export.h"

namespace Plugin
{
    class ExamplePluginClient:
          public Yaksa::PluginClient{
    public:

        static ExamplePluginClient* Get(){
            static ExamplePluginClient client;
            return &client;
        };

        ExamplePluginClient();
        ~ExamplePluginClient();

        virtual void onPluginCreated(Yaksa::OnePlugin* plugin) override;
        virtual void onPluginEvent(const char* cmd, const char* msg) override;
        virtual void onThreadSafeInitialize() override;
        virtual void onRunDelayTask(const char* args) override;
        virtual void onAsyncNetRecv(const char* msg) override;

        void ForwardToPluginContainer(void* obj, void* cmd, void* arg, int len,
		        void* callback, void* obj_invoke, int msgid);

    private:
        Yaksa::OnePlugin* getPlugin();
        Yaksa::OnePlugin* plugin_ = nullptr;
    };
}

#endif //__EXAMPLE_PLUGIN_CLIENT_H__