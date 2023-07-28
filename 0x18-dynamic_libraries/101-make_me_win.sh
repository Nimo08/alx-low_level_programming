#!/bin/bash
wget -P .. https://github.com/Nimo08/alx-low_level_programming/raw/master/0x18-dynamic_libraries/libprint.so
export LD_PRELOAD="$PWD/../libprint.so"
