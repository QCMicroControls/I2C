/****************************************************************************************
   Nom du fichier : I2C.h
   Auteur : Alain Champagne                  
      Date de cr�ation : 19-03-2006 
        Fichier de d�claration et de d�finition pour les fonctions de traitement du 
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
// Auteur : Alain Champagne		     Date de cr�ation : 30-05-2007				      
// Modification : Pierre Chouinard   21/08/2009
//              : Fran�ois Cardinal  29/08/2018
// Description  : Fonction de r�ception d'un octet de donn�e provenant de la
//                m�moire I2C. Si le circuit ne r�pond pas, on l'indique
//                � l'�cran.  
// Param�tres d'entr�e :  iAdr (adresse o� l'on veut lire)		
// Param�tres de sortie : ucData (Valeur lue)		
// 					
//
unsigned char ucLireMemI2C(unsigned int uiAdr);
// *************************************************************************************************



// *************************************************************************************************
// Auteur : Alain Champagne		           Date de cr�ation : 30-05-2007				      
// Modification : Pierre Chouinard 21/08/2009
// Description :  Fonction de transmission d'un octet de donn�e 
//                provenant de la m�moire I2C.
//							
		
// Param�tres d'entr�e :  ucData - Octet � �crire
//												iAdresse - Addresse o� l'on veut �crire dans la m�moire.		
// Param�tres de sortie : Aucun		
// 						
void vEcrireMemI2C(unsigned char ucData, unsigned int uiAdr);
// *************************************************************************************************

#endif 

















