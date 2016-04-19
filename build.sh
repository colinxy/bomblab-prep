#!/bin/sh


# build the bomb
gcc -O1 -g -o some_bomb bomb_prep.c phases.c

# rename the executable somewhere so that gdb won't find the source files
mv some_bomb bomb_prep

# begin debug
# gdb bomb_prep
