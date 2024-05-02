#!/bin/bash

	echo -n "Enter a number 1 < x < 10: "
	read num
	if [ "$num" -lt 10 && "$num" -gt 1 ] 
		then
			echo $num*$num=$(($num*$num))
		else
			echo "Wrong input!"
	fi
