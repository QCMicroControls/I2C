/****************************************************************************************
   Nom du fichier : ClavierI2C.h
   Auteur : St�phane Desch�nes                  
   Date de cr�ation : 30 oct 2019 
        Fichier de d�claration et de d�finition pour les fonctions de traitement du 
        clavier I2C.
  
****************************************************************************************/

#ifndef CLAVIER_I2C_H
  #define CLAVIER_I2C_H





// *************************************************************************************************
//  Auteur: St�phane Desch�nes 	
//  Date de cr�ation :  11 novembre 2022
//  Version 1.0
//
//  Description					 : Lit les touches lues sur le clavier I2C
//  Param�tres d'entr�es : Aucune
//  Param�tres de sortie : La valeur de la touches appuy�e en ASCII.  Retourne ' ' si aucune touche est appuy�e.
//
//  Notes     		       : Cette fonction est faite pour lire le clavier sans utiliser les interruptions
//												 Pour ne pas manquer de touches appuy�es par l'utilisateur, il est recommand� 
//												 d'appeler cette fonction aux 10 ms.
// *************************************************************************************************
unsigned char ucReadKeyI2C(void);

#endif
