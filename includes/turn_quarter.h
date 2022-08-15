/**
 * @Author: rahaingomanana_perriere <lrahaing_pperierr>
 * @Date:   2019-04-24T11:48:54+02:00
 * @Email:  laurent.rahaingomanana@estaca.eu_paul.perriere@estaca.eu
 * @Project: pentago
 * @Filename: turn_quarter.h
 * @Last modified by:   lrahaing_pperierr
 * @Last modified time: 2019-04-28T15:55:28+02:00
 */



#ifndef TURN_QUARTER_H
#define TURN_QUARTER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

char                **extracted_quarter(s_dim *pos, s_dim *size, char **array); //EXTRAIT LE QUARTER A PARTIR DU GRAND TABLEAU, DE SA TAILLE ET DE SA POSITION
// DANS LE GRAND TABLEAU (DEFINIES PAR L'UTILISATEUR)
void                transpose_quarter(char **quarter); //EFFECTUE LA TRANSPOSEE DU QUARTER (OPERATION MATRICIELLE)
void                reverse_colonne_quarter(char **quarter); //INVERSE LES COLONNES DU QUARTER
void                turn_quarter(char **quarter, char rot); //UTILISE LES 2 FONCTIONS PRECEDENTES POUR EFFECTUER LA ROTATION DU QUARTER VERS LA GAUCHE OU LA DROITE
void                put_quarter_in_array(char **quarter, char **array, s_dim *pos); //REINJECTE LE NOUVEAU QUARTER (APRES ROTATION) DANS LE GRAND TABLEAU

#endif
