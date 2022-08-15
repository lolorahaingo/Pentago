/**
 * @Author: rahaingomanana_perriere <lrahaing_pperierr>
 * @Date:   2019-04-26T22:35:46+02:00
 * @Email:  laurent.rahaingomanana@estaca.eu_paul.perriere@estaca.eu
 * @Project: pentago
 * @Filename: get_user.c
 * @Last modified by:   lrahaing_pperierr
 * @Last modified time: 2019-04-28T15:54:33+02:00
 */



#include "arrays_basics.h"
#include "check_win.h"
#include "game_output.h"
#include "get_user.h"
#include "turn_quarter.h"

s_dim               *get_pos(char c, s_dim *dim_quarter, s_dim *dim_array) //DEMANDE À L'UTILISATEUR SON CHOIX DE LIGNE/COLONNE DANS LES
//TABLEAUX DE DIMENSIONS dim_array ET dim_quarter PUIS RENVOIE SON CHOIX À TRAVERS UN POINTEUR SUR TYPE STRUCTURE s_dim

//POUR c == 'p' ou c == 'P' LE SOUS PROGRAMME DEMANDE ET RENVOIE LE PLACEMENT DE LA BOULE DU JOUEUR
//POUR c == 't' ou c == 'T' LE SOUS PROGRAMME DEMANDE UNE CASE APPARTENANT AU QUARTER À TOURNER
//PUIS RENVOIE LA POSITION EN HAUT À GAUCHE DU QUARTER À TOURNER
//SINON LE SOUS PROGRAMME RENVOIE LA POSITION DE LA CASE DU COIN SUPERIEUR GAUCHE DU GRAND PLATEAU
{
    s_dim           *pos;

    pos = malloc(sizeof(s_dim));
    pos->line = 0;
    pos->column = 0;
    if(c == 'P' || c == 'p')  // P pour place
    {
        printf ("\nDans quelle colonne(1,2,...) placer la boule ? ");
        while(!scanf("%d", &pos->column) || !(pos->column >= 1 && pos->column <= dim_array->column)) //REDEMANDE À L'UTILISATEUR UN NOMBRE TANT QU'IL N'EN RENTRE PAS UN VALIDE
        {
            printf("Entree non valide\n");
            rewind(stdin); //POUR NE PAS "PERTURBER" LE FONCTIONNEMENT DE scanf()
        }
        pos->column--; // CONVERTIT EN UN FORMAT COMPREHENSIBLE PAR LE PROGRAMME (PREMIER ELEMENT = 0 != 1)

        printf ("\nDans quelle ligne(1,2,...) placer la boule ? ");
        while(!scanf("%d", &pos->line) || !(pos->line >= 1 && pos->line <= dim_array->line))
        {
            printf("Entree non valide\n");
            rewind(stdin);
        }
        pos->line--;
    }
    else if(c == 'T' || c == 't')  // T pour turn
    {
        printf("\nEntrer une colonne qui fait partie du quarter à tourner : ");
        while(!scanf("%d", &pos->column) || !(pos->column >= 1 && pos->column <= dim_array->column))
        {
            printf("Entree non valide\n");
            rewind(stdin);
        }
        pos->column--;

        printf("\nEntrer une ligne qui fait partie du quarter à tourner : ");
        while(!scanf("%d", &pos->line) || !(pos->line >= 1 && pos->line <= dim_array->line))
        {
            printf("Entree non valide\n");
            rewind(stdin);
        }
        pos->line--;

        pos->line -= pos->line%dim_quarter->line;
        pos->column -= pos->column%dim_quarter->column;                    // RENVOIE LA POSITION EN HAUT À GAUCHE DU QUARTER À TOURNER
    }
    return(pos);
}

char                get_rot(void) //DEMANDE À L'UTILISATEUR LE SENS DANS LEQUEL IL SOUHAITE EFFECTUER LA ROTATION D'UN QUARTER PUIS
//RENVOIE LA LETTRE CORRESPONDANTE EN ASCII ('D' ou 'd' POUR LE SENS HORAIRE|| 'G' ou 'g' POUR LE SENS ANTI-HORAIRE)
{
    char            rot;

    do {
        printf("\n'D': tourner dans le sens horaire / 'G': tourner dans le sens anti-horaire : ");
        rewind(stdin);
        scanf("%c", &rot);
    } while(!(rot == 'D' || rot == 'G' || rot == 'd' || rot == 'g'));      // SECURISATION DE LA SAISIE DE MANIERE A CE QUE LE PROGRAMME REDEMANDE LA ROTATION
    return(rot);                                                           // TANT QUE CETTE DERNIERE N'EST PAS COHERENTE
}
