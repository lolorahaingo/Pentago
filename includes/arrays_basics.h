/**
 * @Author: rahaingomanana_perriere <lrahaing_pperierr>
 * @Date:   2019-04-24T11:28:38+02:00
 * @Email:  laurent.rahaingomanana@estaca.eu_paul.perriere@estaca.eu
 * @Project: pentago
 * @Filename: arrays_basics.h
 * @Last modified by:   lrahaing_pperierr
 * @Last modified time: 2019-04-28T15:54:45+02:00
 */



#ifndef ARRAYS_BASICS_H
#define ARRAYS_BASICS_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

//STRUCTURE POUR DES DIMENSIONS
typedef struct s_dim
{
    int column;
    int line;
}                   s_dim;

char                **init_tab(s_dim *size_array); //INITIALISE UN TABLEAU (DE TAILLE DONNEE EN PARAMETRE) ET LE RENVOIE
char                **cpy_array(char **array); //COPIE UN TABLEAU (DONNE EN PARAMETRE) ET RENVOIE SA COPIE
void                free_dbl_array(char **array); //LIBERE L'ESPACE MEMOIRE DU TABLEAU DONNE EN PARAMETRE
int                 nb_li(char **array); //RENVOIE LE NOMBRE DE LIGNES DU TABLEAU DONNE EN PARAMETRE
int                 nb_col(char **array); //RENVOIE LE NOMBRE DE COLONNES DU TABLEAU DONNE EN PARAMETRE

#endif
