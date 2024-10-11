/*/////////////////////////////////////////////////////////////////////////////////////
   Nom du fichier : Dallas.c
   Auteur : Xavier Champoux, Harold Malbrouck, Charles-Olivier Lemelin

Version 1.0 25-06-06
Date de modification :  09-11-09


*****************************************************************************************/

//-------------- header files  -----------------
#include "ClavierI2C.h"
#include "Dallas.h"
#include "I2C.h"
#include "ds89c450.h" // Définition des bits et des registres du microcontrôleur

#define INT P3_2

// *************************************************************************************************
unsigned char ucReadKeyI2C(void)
//   Auteur :
//   Paramètres d'entrée : Aucun.
//   Paramètres de sortie : Output un charactère ASCII
//   Variables utilisées : Aucun.
//***************************************************************************************************
{
  const unsigned char ucTabKeymap[16] = {'1', '2', '3', 'A', '4', '5',
                                         '6', 'B', '7', '8', '9', 'C',
                                         '*', '0', '#', 'D'};

  unsigned char ucKeymapNew = ' ', ucKeymap = ' ';
  unsigned int uiAddresse = 0x29;

  if (!INT) {
    vI2CStartBit();
    vI2CEcrire8Bits(uiAddresse);
    ucKeymapNew = ucI2CLire8Bits(1);
    vI2CStopBit();

    ucKeymap = ucTabKeymap[ucKeymapNew];
  }
  return ucKeymap;
}
