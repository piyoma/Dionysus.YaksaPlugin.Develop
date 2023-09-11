#!/bin/bash

#
#   @author 2023/07/17 piyoma
#

BUILD_DIR=./build

echo "----------------------------------------------------------------------"
echo -e "\e[1;34m   Building Project-Dionysus version:debug @author 2023/07/17 piyoma\e[0m"
echo "----------------------------------------------------------------------"

function build_debug(){

#
#   Check if the build directory exist
#

  if [ -d "$BUILD_DIR" ]; then

    cd build
    cmake .. -DCMAKE_BUILD_TYPE=Debug
    make clean
    make

  else

    mkdir build
    cd build
    cmake .. -DCMAKE_BUILD_TYPE=Debug
    make

  fi

}

function copy_agent(){

    mkdir debug
    cp ./Agent.Horaisan/Lakshmi ./debug/Agent.Horaisan

}

function copy_plugins(){
   
    cd debug
    mkdir -p plugins/Plugin.Example
    mkdir -p plugins/Plugin.Garuda
    mkdir -p plugins/Plugin.RPC
    mkdir -p plugins/Plugin.libuv
    mkdir -p Yaksa.Component

    cd ..
    cp ./Plugin.Example/libPlugin.Example.so ./debug/plugins/Plugin.Example/Plugin.Example.so
    cp ./Plugin.RPC/libPlugin.RPC.so ./debug/plugins/Plugin.RPC/Plugin.RPC.so

    cd ..
    cp ./Library.Component/libs/libLibrary.Yaksa.Plugin.so ./build/debug/Yaksa.Component/Yaksa.Module.Plugin.so
    cd build
}

function copy_configs(){
  
    cd debug
    mkdir -p configuration

    cd ..
    cp ../Agent.Horaisan/configuration/plugins.json ./debug/configuration/plugins.json
}
   
function copy_binary(){

  out=./debug

  if [ -d "$out" ]; then

    rm -rf ./debug

    copy_agent
    copy_plugins

  else

    copy_agent
    copy_plugins

  fi

}

build_debug
copy_binary
copy_configs

#
#   Copy plugins into working directory
#