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

#include "I2C.h"

#include "Dallas.h"
#include "ds89c450.h"



// *************************************************************************************************
//  FONCTIONS LOCALES
// *************************************************************************************************

void vI2CDelai (unsigned int iTemps);
void vI2CEcrire1Bit(bit bBit);
bit blI2CLire1Bit();

//************************************************************************
//  Fonctions
//************************************************************************

void vI2CDelai(unsigned char ucTemps) {
  while (ucTemps > 0) {
    i--;
  }
}


// *************************************************************************************************
//  Auteur: St�phane Desch�nes, bas� sur des fonctions faites par Alain Champagne le 30 mai 2007
//  Date de cr�ation :  28 mai 2021
//
//  Description: provoque un "start-condition" I2C sur les lignes SDA et SCL
//  Param�tres d'entr�es : Aucun
//  Param�tres de sortie : Aucun
//  Notes     		 	 : Aucune
//
void vI2CStartBit(void) {
  SDA = 1;
  vI2CDelai(5);
  SCL = 1;
  vI2CDelai(5);
  SDA = 0;
  vI2CDelai(5);
  SDA = 0;
}

// *************************************************************************************************
//  Auteur: St�phane Desch�nes, bas� sur des fonctions faites par Alain Champagne le 30 mai 2007
//  Date de cr�ation :  28 mai 2021
//
//  Description: provoque un "stop-condition" I2C sur les lignes SDA et SCL
//  Param�tres d'entr�es : Aucun
//  Param�tres de sortie : Aucun
//  Notes     		 : Aucune
//
void vI2CStopBit(void) {
  SDA = 0;
  vI2CDelai(5);
  SCL = 0;
  vI2CDelai(5);
  SDA = 1;
  vI2CDelai(5);
  SDA = 1;
}

void vI2CEcrire1Bit(bit bBit)
//
//  Auteur: Charles-Olivier 
//  Date de création :  06 septembre 2023
//  Version 1.0
//
//  Description: Envoie un bit de data 1 ou 0 sur les lignes i2c
//  Paramètres d'entrées : Aucun
//  Paramètres de sortie : Paramètre de Sortie
//  Notes     		       : 	Passage de 0 à 1 sur la ligne SDA durant un niveau haut de SCL
// *************************************************************************************************

{
  SCL = 0;
  vI2CDelai(5);
  SDA = bBit;
  vI2CDelai(5);
  SCL = 1;
  vI2CDelai(5);
  SCL = 0;
  vI2CDelai(5);
  SDA = 0;
}

bit bI2CLire1Bit() {
  bit bRXLineRead;
  SDA = 1;
  vI2CDelai(5);
  SCL = 0;
  vI2CDelai(5);
  SCL = 1;
  vI2CDelai(5);
  bRXLineRead = SDA;
  vI2CDelai(5);
  SCL = 0;
  return bRXLineRead;
}

void vI2CEcrire8Bits(char cTXData) {

  unsigned char i;
  for (i = 0; i < 8; i++) {
    vI2CWriteBit(cTXData & 0x80);
    cTXData << 1;
  }
  bI2CReadBit();
}



char ucI2CLire8Bits(bit bAck) {
  unsigned char ucRXFetch = 0;
  unsigned char i;

  for (i = 0; i < 8; i++) {
    ucRXFetch = ucRXFetch + bI2CReadBit();
    ucRXFetch << 1;
  }
  return ucRXFetch;
}
