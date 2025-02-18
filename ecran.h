/* 
 * File:   ecran.h
 * Author: e2242786
 *
 * Created on 9 octobre 2024, 15:31
 */

#ifndef ECRAN_H
#define	ECRAN_H

#ifdef	__cplusplus
extern "C" {
#endif

/*
* Fonction : ecranAllume
* Description : Envoie la commande pour allumer l'ecran
*
* Params : Aucun
* 
* Retour : Aucun
*/
void ecranAllume(void);

/*
* Fonction : ecranEteint
* Description : Envoie la commande pour eteindre l'ecran
*
* Params : Aucun
* 
* Retour : Aucun
*/
void ecranEteint(void);

/*
* Fonction : curseurPosition
* Description : Envoie la commande pour bouger la position du curseur
*
* Params : int position
* 
* Retour : Aucun
*/
void curseurPosition(int position);

/*
* Fonction : videEcran
* Description : Envoie la commande pour vider l'écran
*
* Params : Aucun
* 
* Retour : Aucun
*/
void videEcran(void);

/*
* Fonction : ecrireCaractere
* Description : Envoie la commande pour écrire un caractère
*
* Params : char caractere
* 
* Retour : Aucun
*/
void ecrireCaractere(char caractere);

/*
* Fonction : curseurClignoteON
* Description : Envoie la commande pour faire clignoter le curseur
*
* Params : Aucun
* 
* Retour : Aucun
*/
void curseurClignoteON(void);

/*
* Fonction : curseurClignoteOFF
* Description : Envoie la commande pour ne pas faire clignoter le curseur
*
* Params : Aucun
* 
* Retour : Aucun
*/
void curseurClignoteOFF(void);

#ifdef	__cplusplus
}
#endif

#endif	/* ECRAN_H */

