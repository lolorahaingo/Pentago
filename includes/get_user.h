/**
 * @Author: rahaingomanana_perriere <lrahaing_pperierr>
 * @Date:   2019-04-24T11:47:21+02:00
 * @Email:  laurent.rahaingomanana@estaca.eu_paul.perriere@estaca.eu
 * @Project: pentago
 * @Filename: get_user.h
 * @Last modified by:   lrahaing_pperierr
 * @Last modified time: 2019-04-28T15:54:52+02:00
 */



#ifndef GET_USER_H
#define GET_USER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

s_dim               *get_pos(char c, s_dim *dim_quarter, s_dim *dim_array); //DEMANDE À L'UTILISATEUR SON CHOIX DE LIGNE/COLONNE DANS LES
//TABLEAUX DE DIMENSIONS dim_array ET dim_quarter PUIS RENVOIE SON CHOIX À TRAVERS UN POINTEUR SUR TYPE STRUCTURE s_dim

//POUR c == 'p' ou c == 'P' LE SOUS PROGRAMME DEMANDE ET RENVOIE LE PLACEMENT DE LA BOULE DU JOUEUR
//POUR c == 't' ou c == 'T' LE SOUS PROGRAMME DEMANDE UNE CASE APPARTENANT AU QUARTER À TOURNER
//PUIS RENVOIE LA POSITION EN HAUT À GAUCHE DU QUARTER À TOURNER
//SINON LE SOUS PROGRAMME RENVOIE LA POSITION DE LA CASE DU COIN SUPERIEUR GAUCHE DU GRAND PLATEAU

char                get_rot(void); //DEMANDE À L'UTILISATEUR LE SENS DANS LEQUEL IL SOUHAITE EFFECTUER LA ROTATION D'UN QUARTER PUIS
//RENVOIE LA LETTRE CORRESPONDANTE EN ASCII ('D' ou 'd' POUR LE SENS HORAIRE|| 'G' ou 'g' POUR LE SENS ANTI-HORAIRE)

#endif
