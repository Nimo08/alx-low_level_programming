#!/bin/bash
wget -P .. https://github.com/Nimo08/alx-low_level_programming/blob/master/0x18-dynamic_libraries/libmake_me_win.so
export LD_PRELOAD="$PWD/../libmake_me_win.so"
