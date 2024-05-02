#!/bin/bash

# /etc/fstab

if [ -d /root/Desktop/filename.c ]
then 
	cp /root/Desktop/filename.c ./
	echo "Done"
else
	echo "Error. file not found"
	exit
fi	




