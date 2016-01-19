#!/bin/sh

i=0
while [ $i -le 1 ]
do
   if [ -b /dev/sda1 ]
	then 
	break

fi
done 

mount /dev/sda1

if [ -l /sys/class/gpio/gpio21]
	then
		echo "fichier gpio21 existe "
	else
		echo 21 > /sys/class/gpio/export

fi


echo out > /sys/class/gpio/gpio21/direction

unmount /dev/sda1

for j in 1 2 3 
do
	echo 1 > /sys/class/gpio/gpio21/value
	sleep 1
	echo 0 > /sys/class/gpio/gpio21/value
	sleep 1
done
