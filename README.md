# AGENT JULY DEV [2023] - BOSSA NOVA JAZZ

This project created by piyoma Jul 26, 2023

# Getting started


- **关于YaksaPlugin插件系统** @author piyoma Sep 4 2023

- **说明**

  - 本插件系统支持多种C++网络库，作为一个插件模块使用，是其他模块与云中心交互通信的唯一网络接口。
    (例如grpc, libuv, libevent等，即插即用，随意切换使用)
  - 内存管理模块在设计原则上应当也是一个插件模块封装在插件系统中模块，但是个人感觉不必要，感觉使用api hook实现是较为简单的实现方式。
  - 其实插件系统是没有主模块的概念的，如果真的需要一个主模块，那它应该是也一个插件模块。不然是违反设计原则，代码也容易写乱。
  - [ build.debug.sh ]自动编译debug版本的全部工程

- **使用方法**
```
  Step1. 在主进程工程调用 Yaksa::loadYaksaPlugins("your_json_config_path.json");即可完成加载。
         示例Json在/Agent.Horaisan/configuration目录下。
  Step2. 在插件模块项目包含头文件 #include "YaksaPlugin/Pulgin.Export.h"，并在CMake文件加上依赖的lib。
  Step3. 自己实现一个类，继承自Yaksa::PluginClient，实现几个接口方法，并保存Yaksa::OnePlugin*对象指针用来与插件系统交互。

  只需要三步就可以使用目前的这套插件系统进行开发了，使用还是非常简单的，不需要学习与动脑，专心实现模块内功能。
```
- **接口使用说明**

  1. onThreadSafeInitialize是插件第一次被加载初始化的地方，线程安全，运行在本插件自己的线程。
  2. onPluginEvent是响应命令的接口，相当于onCommand。是响应其他模块调用ExecuteSync/ExecuteAsync的，一般不会被使用。
  3. PostDelayTask和PostTask调用后，会异步向本插件线程投递一个任务回调到onRunDelayTask, 可以当作线程安全的定时器使用。
  4. 调用NetSend会通过其网络模块发送数据，网络模块会自动将结果异步返回并调用onAsyncNetRecv。
  5. IsRunInPluginThread判断当前是否在本插件的线程，用于线程安全。

  [build.debug.sh]: http://127.0.0.1:9875/piyoma/security.dionysus/-/blob/main/build.debug.sh