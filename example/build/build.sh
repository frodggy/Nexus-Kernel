#!/bin/bash

#use the Makefile from examples
if [ $1 = "build" ]
then
    make clean
    make
fi

if [ $1 = "run" ]
then
    make run
fi
