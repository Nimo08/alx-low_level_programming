#!/bin/bash
gcc -shared -fPIC -o libmake_me_win.so 101-rand.c
export LD_PRELOAD=$PWD/libmake_me_win.so
