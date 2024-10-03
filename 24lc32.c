//************************************************************************
//  Fichier:
//  Auteur: Charles-Olivier Lemelin
//  Date de creation
//  Version 2.x
//************************************************************************

//************************************************************************
//  Includes
//************************************************************************

#include <stdio.h>

#include "I2C_DS89C450.h"

#include "Dallas.h"
#include "ds89c450.h"

//************************************************************************
//  Fonctions
//************************************************************************
void v24lc32Delai(unsigned char cMilisecond) {
  int i;
  for (i = 0; i < (cMilisecond * 1000); i++)
    ;
}

void v24lc32Write(unsigned char ucData, unsigned int uiAdr) {

  // conversion d'adresse
  unsigned char ucAdrLSB;
  unsigned char ucAdrMSB;
  ucAdrLSB = uiAdr;
  uiAdr = uiAdr >> 8;
  ucAdrMSB = uiAdr;
  ucAdrMSB = ucAdrMSB & 0x0f;

  // écriture au microcontrolleur
  vI2CStartBit();
  vI2CWriteOct(0b10100000);
  v24lc32Delai(5);
  vI2CWriteOct(ucAdrMSB);
  v24lc32Delai(5);
  vI2CWriteOct(ucAdrLSB);
  v24lc32Delai(5);
  vI2CWriteOct(ucData);
  vI2CStopBit();
}

char v24lc32Read(unsigned int uiAdr) {
  unsigned char ucOutputChar;
  // conversion d'adresse
  unsigned char ucAdrLSB;
  unsigned char ucAdrMSB;
  ucAdrLSB = uiAdr;
  uiAdr = uiAdr >> 8;
  ucAdrMSB = uiAdr;
  ucAdrMSB = ucAdrMSB & 0x0f;

  // écriture de l'addresse
  vI2CStartBit();
  vI2CWriteOct(0b10100000);
  v24lc32Delai(5);
  vI2CWriteOct(ucAdrMSB);
  v24lc32Delai(5);
  vI2CWriteOct(ucAdrLSB);
  v24lc32Delai(5);
  vI2CStopBit();

  // lecture de l'adresse
  vI2CStartBit();
  vI2CWriteOct(0b10100001);
  v24lc32Delai(5);
  cI2CReadOct(0);
  v24lc32Delai(5);
  vI2CStopBit();
}
