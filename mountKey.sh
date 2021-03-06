#!/bin/sh

x=0
y=0

if [ -l /sys/class/gpio/gpio21 ]
		then
			echo "fichier gpio21 existe "
		else
			echo 21 > /sys/class/gpio/export

fi
echo out > /sys/class/gpio/gpio21/direction

while [ $x -le 1 ]
	do
	i=0
	if [ $y -eq 0 ]
		then
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
			if [ -d /media/external/autoUpdate ]
				then
					if [ -f /media/external/autoUpdate/autoUpdate.sh ]
						then
							echo "updating"
							/media/external/autoUpdate/autoUpdate.sh
						else
							echo "autoUpdate.sh doesn't exist"
							echo " crypting..."
							/be/encrypt
							/be/decrypt
					fi
				else
					/be/encrypt
					/be/decrypt
			fi
			umount /media/external/

			for j in 1 2 3 
			do
				echo 1 > /sys/class/gpio/gpio21/value
				usleep 500000
				echo 0 > /sys/class/gpio/gpio21/value
				usleep 500000
			done
			y=1
		
			
	fi
	if [ -b /dev/sda1 ]
		then
			y=1	
		else
			y=0
	fi

done

