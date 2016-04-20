#!/bin/sh


# build the bomb
gcc -O1 -o bomb_prep bomb_prep.c phases.c
# do not include the debug symbol

# rename the executable somewhere so that gdb won't find the source files
# mv some_bomb bomb_prep

# begin debug
# gdb bomb_prep
