/****************************************************************************************
   Nom du fichier : I2C.h
   Auteur : Alain Champagne                  
      Date de création : 19-03-2006 
        Fichier de déclaration et de définition pour les fonctions de traitement du 
        I2C.
  
****************************************************************************************/

#ifndef MEMI2C_H
  #define MEMI2C_H


// *************************************************************************************************
//  CONSTANTES
// *************************************************************************************************

// *************************************************************************************************
//  LES PROTOTYPES DES FONCTIONS
// *************************************************************************************************


// *************************************************************************************************
// Auteur : Alain Champagne		     Date de création : 30-05-2007				      
// Modification : Pierre Chouinard   21/08/2009
//              : François Cardinal  29/08/2018
// Description  : Fonction de réception d'un octet de donnée provenant de la
//                mémoire I2C. Si le circuit ne répond pas, on l'indique
//                à l'écran.  
// Paramètres d'entrée :  iAdr (adresse où l'on veut lire)		
// Paramètres de sortie : ucData (Valeur lue)		
// 					
//
unsigned char ucLireMemI2C(unsigned int uiAdr);
// *************************************************************************************************



// *************************************************************************************************
// Auteur : Alain Champagne		           Date de création : 30-05-2007				      
// Modification : Pierre Chouinard 21/08/2009
// Description :  Fonction de transmission d'un octet de donnée 
//                provenant de la mémoire I2C.
//							
		
// Paramètres d'entrée :  ucData - Octet à écrire
//												iAdresse - Addresse où l'on veut écrire dans la mémoire.		
// Paramètres de sortie : Aucun		
// 						
void vEcrireMemI2C(unsigned char ucData, unsigned int uiAdr);
// *************************************************************************************************

#endif 

















