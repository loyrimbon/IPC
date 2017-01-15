//
//  doxygen_comment.c
//  
//
//  Created by LOY RIMBON on 08/01/2017.
//
//

#include "doxygen_comment.h"
/*
*\file nom_fichier
*\brief courte description
*        meme sur plusieurs ligne
*
* \author{ Aurélie Bonnavent, Loy Rimbon}
* \version 0.1
* \date 08/01/2017
*
* Programme description du programme
*
*/
 typdedef struct{
    int i;/*!<attribut i de ma struc.*/
    char c;/*!<attribut c de ma struc.*/
 }ma_struc_t;
/** \fn int ma_fonction(int arg1, double arg2)
*    \param[in] arg1 mon premier argument
*    \param[in] arg2 mon deuxième argument
*    \param[out] paramètre retourner par la fonction
*    \return paramètre retourner par la fonction
*/
int ma_fonction(int arg1, double arg2)
{
    
    return 0;
}
/*
* \fn int main (void)
* \brief programme principal
*
* \return EXIT_SUCCESS - Arret du programme
*/
int main(void)
{
    return EXIT_SUCCESS;
}

/* doxygen_comment_c */
