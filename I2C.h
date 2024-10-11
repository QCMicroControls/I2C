/****************************************************************************************
   Nom du fichier : I2C.h
   Auteur : Charles-Olivier Lemelin                  
      Date de création : 06 septembre 2023
        Fichier de déclaration et de définition pour les fonctions de traitement du 
        I2C.
  
****************************************************************************************/

#ifndef I2C_H
  #define I2C_H


// *************************************************************************************************
//  CONSTANTES
// *************************************************************************************************
//Definitions de parametres. 
#define SDA P3_4
#define SCL P3_5
#define INT P3_2

#define I2C_DELAI 1
 
void vI2CStartBit(void);
void vI2CStopBit(void);
unsigned char ucI2CLire8Bits (bit bAckValue);
void vI2CEcrire8Bits(unsigned char ucTxData);


#endif 


