#!/bin/sh

if [ -l /sys/class/gpio/gpio21]
	then
		echo "fichier gpio21 existe "
	else
		echo 21 > /sys/class/gpio/export

fi
echo out > /sys/class/gpio/gpio21/direction

i=0
while [ $i -le 1 ]
do
	echo 1 > /sys/class/gpio/gpio21/value
	sleep 1
	echo 0 > /sys/class/gpio/gpio21/value
	sleep 1



   if [ -b /dev/sda1 ]
	then 
	break
   		

fi
done 
if [ -d /media/external ]
	then
		echo "media/external existe"
	else
		mkdir /media/external/

fi

mount /dev/sda1 /media/external/


umount /media/external/

for j in 1 2 3 
do
	echo 1 > /sys/class/gpio/gpio21/value
	usleep 500000
	echo 0 > /sys/class/gpio/gpio21/value
	usleep 500000
done
