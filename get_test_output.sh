#!/bin/sh

mkdir _zaz_output 2> /dev/null

fct() {
	`./ressources/corewar -d $2 ./_cor/$1 > ./_zaz_output/$1`
}

source ./core_test.sh
