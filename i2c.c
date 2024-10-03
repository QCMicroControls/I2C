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

void vI2CDelai(unsigned char ucTemps) {
  while (ucTemps > 0) {
    i--;
  }
}

void vI2CStartBit(void) {
  SDA = 1;
  vI2CDelai(5);
  SCL = 1;
  vI2CDelai(5);
  SDA = 0;
  vI2CDelai(5);
  SDA = 0;
}

void vI2CStopBit(void) {
  SDA = 0;
  vI2CDelai(5);
  SCL = 0;
  vI2CDelai(5);
  SDA = 1;
  vI2CDelai(5);
  SDA = 1;
}

void vI2CWriteBit(bit bBit) {
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

bit bI2CReadBit() {
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

void vI2CWriteOct(char cTXData) {

  unsigned char i;
  for (i = 0; i < 8; i++) {
    vI2CWriteBit(cTXData & 0x80);
    cTXData << 1;
  }
  bI2CReadBit();
}

char cI2CReadOct(int bAck) {
  unsigned char ucRXFetch = 0;
  unsigned char i;

  for (i = 0; i < 8; i++) {
    ucRXFetch = ucRXFetch + bI2CReadBit();
    ucRXFetch << 1;
  }
  return ucRXFetch;
}
