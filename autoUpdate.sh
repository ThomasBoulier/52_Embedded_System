#!/bin/sh

if [ -d /be/ ]
		then
			echo "folder /be/ already created "
		else
			mkdir /be/

fi

if [ -f /media/external/autoUpdate/mountKey.sh ]
		then
			cp /media/external/autoUpdate/mountKey.sh /be/
			chmod 777 /be/mountKey.sh
			echo "mountKey updated"
		else
			echo "moutKey.sh doesn't exist"

fi

if [ -f /media/external/autoUpdate/encrypt ]
		then
			cp /media/external/autoUpdate/encrypt /be/
			chmod 777 /be/encrypt
			echo "encrypt updated"
		else
			echo "encrypt doesn't exist"

fi
if [ -f /media/external/autoUpdate/decrypt ]
		then
			cp /media/external/autoUpdate/decrypt /be/
			chmod 777 /be/decrypt
			echo "decrypt updated"
		else
			echo "decrypt doesn't exist"

fi
if [ -f /media/external/autoUpdate/S99mount ]
		then
			cp /media/external/autoUpdate/S99mount /etc/init.d/S99mount
			chmod 777 /etc/init.d/S99mount
			echo "S99mount updated"
		else
			echo "S99mount doesn't exist"

fi


sync

echo "update done"
rm /media/external/autoUpdate/autoUpdate.sh
echo "rebooting..."
sleep 2
reboot 

