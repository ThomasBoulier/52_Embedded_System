# 52_Embedded_System
##Embedded System : Autonomous encryption station

- Thomas Boulier
- Anthony Calpas
- Camille Finand
- Antoine Marck


###Fair practices :
Use of git, autotools, the present README.

## Setup :
- Cross-compil *encrypt.c* and *decrypt.c* for Armadeaus apf28.
- Have a device containing : *encrypt*, *decrypt*, *mountKey.sh*, possibly *autoupdate.sh*
- Have the daemon *S99mount* in /etc/init.d in the Armadeus.
- Boot the board.
- The LED should slowly blink : the board is in idle state.
- Plug the USB device.
- The daemon *S99mount* will launch *mountKey.sh*
- *mountKey.sh* will launch *autoUpdate.sh* and move *encrypt* & *decrypt* from the stick to the board.
- *mountKey.sh* will execute encrypt creating a file *encrypted.xor* from *test*
- *mountKey.sh* will execute decrypt creating a file *decryptedFile* from *encrypted.xor*
- The LED should quickly blink 3 times to indicate that the process achieved, then light off.
- You can unplug the stick.
- The board will then return in idle state, the LED should blink slowly again.




##Setup : (versions before 1.3)
- Create directory */be* if it does not exist.
- Put *mountKey.sh* in it.
- Put binaries *encrypt* and *decrypt* in it
- Put daemon *S99mount* in /etc/init.d
- syncronize the RAM.

##Use:
- Boot.
- [Log]
- The LED should slowly blink : the board is in idle state.
- Plug the USB stick.
- The board will enter in busy state : it will mount the stick, encrypt the file called "XXX", then unmount the stick.
- The LED should quickly blink 3 times to indicate that the process achieved, then light off.
- You can unplug the stick.
- The board will then return in idle state, the LED should blink slowly again.





##State of the several version :

###0.1 Version:
- Script run by init.d which detect a USB device connected on the card (check /dev/sda1 periodically)
- Mounting the device.
- Unmounting the device.
- The LED flashes 3 times.

###0.2 Version:
- Every n secondes,a long flash of the LED for each check.

###0.2.1 Version:
After the mounting-unmounting, the system return in the idle state.

###1.0 Version:
- Between mounting & unmounting, a encryption programm is called.
- The encryption is the XorEncryption (cf https://github.com/KyleBanks/XOREncryption/tree/master/C)

- The programm is a C programm, crosscompiled using https://github.com/pblottiere/armadeus, with *make am28_defconfig*

###1.1 Version:
- Decrypt the file "todecrypt.xor"

###1.2 Version:
- Encrypt the whole directory */be* (unimplemented)
 
###1.3 Version:
- A bash *autoupdate.sh* on the device do the Setup process described higher.

