#!/bin/sh

i="0"
mkdir $1 2> /dev/null
while [ $i -lt 15000 ]
do
	`./ressources/corewar -d $i ./_cor/$1 > _ins_zaz`
	`./corewar -d $i ./_cor/$1 > _ins_vm`
	DIFF=`diff _ins_vm _ins_zaz`
	if [ "$DIFF" = "" ]
	then
		echo $i
	else
		exit
	fi
	i=$[$i+1]
done
echo "$i"
