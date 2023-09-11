#ifndef __RPC_EXPORT_H__
#define __RPC_EXPORT_H__

    extern "C" int exec(void* obj, void* cmd, void* arg, int len,
		void* callback, void* obj_invoke, int msgid);

#endif