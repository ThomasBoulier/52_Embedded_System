# 52_Embedded_System
##Embedded System : Autonomous encryption station

- Thomas Boulier
- Anthony Calpas
- Camille Finand
- Antoine Marck


###Fair practices :
Use of git, autotools, the present README.

##Use:
- Boot.
- Log
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




