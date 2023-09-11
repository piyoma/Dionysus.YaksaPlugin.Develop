#include "agent.h"
#include "waitable_event.h"
#include "YaksaPlugin/Pulgin.Export.h"
#include <json/json.h>
#include <iostream>
#include <fstream>

#include <stdio.h>  
#include <stdlib.h>   
#include <dlfcn.h>
#include <unistd.h>
#include <string.h>
#include <linux/limits.h> 
#include "agent.print.h"

 Agent::Agent(std::string configuration)
    :configuration_(configuration)
 {

 }
 Agent::~Agent()
 {

 }
 int Agent::Run()
 {  
    Yaksa::WaitableEvent exit_evnet{};

    agent_print::banner();

    if(Yaksa::loadYaksaPlugins(configuration_.c_str())){

        std::cout << std::endl 
        << COLOR_NORMAL << "[Agent]" 
        << COLOR_GREEN << ":Start up service with configuration Json file [" 
        << COLOR_BLUE << "./" << configuration_ 
        << COLOR_GREEN << "] successfully." 
        << COLOR_NORMAL << std::endl << std::endl;

    }else{

        std::cout 
        << "[Agent]:Error occured while loading packages. Exit Instance now."
        << std::endl;
        exit_evnet.Signal();
        return 0;
    }
        
    exit_evnet.Wait();
    return 1;
 }