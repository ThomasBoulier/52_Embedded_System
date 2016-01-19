# 52_Embedded_System
BE de Système embarqué : Mise en place d'un station de cryptage

Thomas Boulier
Anthony Calpas
Camille Finand
Antoine Marck

##Station de cryptage autonome :

##Bonnes pratiques :
Utilisation de git, des autotools, un README.


##Version 0.1:
-Script lancé par init.d qui detecte un clé USB connectée sur la carte (voir /dev/sda1, check périodique)
-On monte la clé.
-On la démonte.
-La LED clignote trois fois.

##Version 0.2:
-Toute les n secondes, un clignotement long de la LED.
