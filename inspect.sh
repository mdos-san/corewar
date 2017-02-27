#!/bin/sh

i=$3
while [ $i -lt 15000 ]
do
	`./ressources/corewar -d $i ./_cor/$1 > _ins_zaz`
	`./corewar -d $i ./_cor/$1 > _ins_vm`
	DIFF=`diff _ins_vm _ins_zaz`
	if [ "$DIFF" != "" ]
	then
		echo $i
		exit
	fi
	i=$[$i+$2]
done
echo "No error, GG :)!"
