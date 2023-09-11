#include <stdio.h>

#include "export.h"
#include "Example.Plugin.Client.h"

int exec(void* obj, void* cmd, void* arg, int len,
		void* callback, void* obj_invoke, int msgid){

   Plugin::ExamplePluginClient::Get()->
   ForwardToPluginContainer(
   obj, cmd, arg, len, 
	callback, obj_invoke, msgid);
   return 1;
}