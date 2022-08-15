/**
 * @Author: rahaingomanana_perriere <lrahaing_pperierr>
 * @Date:   2019-04-24T11:32:11+02:00
 * @Email:  laurent.rahaingomanana@estaca.eu_paul.perriere@estaca.eu
 * @Project: pentago
 * @Filename: check_win.h
 * @Last modified by:   lrahaing_pperierr
 * @Last modified time: 2019-04-28T15:54:48+02:00
 */



#ifndef CHECK_WIN_H
#define CHECK_WIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

//DEFINITION D'UN TYPE BOOLEEN (0:FALSE et 1:TRUE)
typedef enum
{FALSE, TRUE}       boolean_;

boolean_            check_for_line(char **array, int cond,char c); //RENVOIE TRUE SI LE TABLEAU DONNE EN PARAMETRE CONTIENT UN NOMBRE
//(EGAL À cond) D'ELEMENTS (EGAL À c) ALIGNES SUR UNE LIGNE
boolean_            check_for_column(char **array, int cond, char c); //RENVOIE TRUE SI LE TABLEAU DONNE EN PARAMETRE CONTIENT UN NOMBRE
//(EGAL À cond) D'ELEMENTS (EGAL À c) ALIGNES SUR UNE COLONNE
boolean_            check_for_diago(char **array, int cond, char c); //RENVOIE TRUE SI LE TABLEAU DONNE EN PARAMETRE CONTIENT UN NOMBRE
//(EGAL À cond) D'ELEMENTS (EGAL À c) ALIGNES SUR UNE DIAGONALE
void                check_for_win(boolean_ *game, char **array, int cond, int nb_player); //UTILISE LES FONCTIONS PRECEDENTES POUR AFFICHER
//SI UN DES JOUEURS (LE JEU CONTIENT nb_player JOUEURS) A GAGNE. SI UN JOUEUR GAGNE LE NOM DE CE JOUEUR EST AFFICHE ET LE JEU S'ARRETTE (*GAME = 0)
int                 min(int a, int b); //RENVOIE LE MINIMUM DES DEUX NOMBRES PASSES EN PARAMETRE
int                 max(int a, int b); //RENVOIE LE MAXIMUM DES DEUX NOMBRES PASSES EN PARAMETRE

#endif
