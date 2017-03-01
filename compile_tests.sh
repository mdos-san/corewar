#!/bin/sh

mkdir _cor 2> /dev/null

fct (){
	./ressources/asm "./tests/${1%.cor}.s"
	mv ./tests/$1 ./_cor/$1
}

source ./core_test.sh
