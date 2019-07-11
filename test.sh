#!/bin/bash
GRAPHS_PATH=graphs
EXECUTABLE_PATH=cmake-build-debug

for file in $GRAPHS_PATH/*

do
	echo File ${file} results:
	./$EXECUTABLE_PATH/bridge < ${file}
done
