# 52_Embedded_System
##Embedded System : Autonomous encryption station

Thomas Boulier, //
Anthony Calpas, //
Camille Finand, //
Antoine Marck


###Fair practices :
Use of git, autotools, the present README.


###0.1 Version:
- Script run by init.d which detect a USB device connected on the card (check /dev/sda1 periodically)
- Mounting the device.
- Unmounting the device.
- The LED flashes 3 times.

###0.2 Version:
- Every n secondes,a long flash of the LED for each check.
