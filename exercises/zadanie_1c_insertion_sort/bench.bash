#!/bin/bash
clear
NAME=ex1
echo " "
echo "-O1"
gcc ins.c -D A -D IL -O1 -o $NAME
time ./$NAME

echo " "
echo "-O2"
gcc ins.c -D A -D IL -O2 -o $NAME
time ./$NAME

echo " "
echo "-O3"
gcc ins.c -D A -D IL -O3 -o $NAME
time ./$NAME

echo " "
echo "-Ofast"
gcc ins.c -D A -D IL -Ofast -o $NAME
time ./$NAME

echo " "
echo "-Os"
gcc ins.c -D A -D IL -Os -o $NAME
time ./$NAME

echo " "
echo "-O0"
gcc ins.c -D A -D IL -O0 -o $NAME
time ./$NAME
