/**
 * @Author: rahaingomanana_perriere <lrahaing_pperierr>
 * @Date:   2019-04-27T21:28:05+02:00
 * @Email:  laurent.rahaingomanana@estaca.eu_paul.perriere@estaca.eu
 * @Project: pentago
 * @Filename: check_win.c
 * @Last modified by:   lrahaing_pperierr
 * @Last modified time: 2019-04-28T15:54:27+02:00
 */



#include "arrays_basics.h"
#include "check_win.h"
#include "game_output.h"
#include "get_user.h"
#include "turn_quarter.h"

void                check_for_win(boolean_ *game, char **array, int cond, int nb_player) //UTILISE LES FONCTIONS SUIVANTES POUR AFFICHER
//SI UN DES JOUEURS (LE JEU CONTIENT nb_player JOUEURS) A GAGNE. SI UN JOUEUR GAGNE LE NOM DE CE JOUEUR EST AFFICHE ET LE JEU S'ARRETTE (*GAME = 0)
{
    for(int i=0; i<nb_player; i++)
    {
        if(check_for_line(array, cond, 'A'+i) == TRUE || check_for_column(array, cond, 'A'+i) == TRUE ||
        check_for_diago(array, cond, 'A'+i) == TRUE)
        {
            printf("\n\nLe joueur %c a gagné\n", 'A'+i);
            *game = 0;
        }
    }
}

boolean_             check_for_line(char **array, int cond, char c) //RENVOIE TRUE SI LE TABLEAU DONNE EN PARAMETRE CONTIENT UN NOMBRE
//(EGAL À cond) D'ELEMENTS (EGAL À c) ALIGNES SUR UNE LIGNE
{
    int             k;
    int             nb_l;
    int             nb_c;
    int             i;
    int             j;

    nb_l = nb_li(array);
    nb_c = nb_col(array);
    k = 1;
    for(i=0; i < nb_l; i++)
    {
        for(j=0; j < nb_c; j++)
        {
            if(k == cond) return(TRUE); //SI LE COMPTEUR CORRESPOND À cond ALORS LES BILLES SONT ALIGNEES ET UN JOEUR A GAGNE
            if(array[i][j] == array[i][j+1] && array[i][j] == c)
                k++;
            else
                k=1;
        }
        k=1;
    }
    return(FALSE);
}

boolean_             check_for_column(char **array, int cond, char c) //RENVOIE TRUE SI LE TABLEAU DONNE EN PARAMETRE CONTIENT UN NOMBRE
//(EGAL À cond) D'ELEMENTS (EGAL À c) ALIGNES SUR UNE COLONNE
{
    int             k;
    int             nb_l;
    int             nb_c;
    int             i;
    int             j;

    nb_l = nb_li(array);
    nb_c = nb_col(array);
    k = 1;
    for(j=0; j < nb_c; j++)
    {
        for(i=0; i < nb_l; i++)
        {
            if(k == cond) return(TRUE); //SI LE COMPTEUR CORRESPOND À cond ALORS LES BILLES SONT ALIGNEES ET UN JOEUR A GAGNE
            if(array[i][j] == array[i+1][j] && array[i][j] == c)
                k++;
            else
                k=1;
        }
        k=1;
    }
    return(FALSE);
}

boolean_             check_for_diago(char **array, int cond, char c) //RENVOIE TRUE SI LE TABLEAU DONNE EN PARAMETRE CONTIENT UN NOMBRE
//(EGAL À cond) D'ELEMENTS (EGAL À c) ALIGNES SUR UNE DIAGONALE
{
    int             k;
    int             nb_l;
    int             nb_c;
    int             i;
    int             j;
    int             cursor_diag;
    int             hypo;

    nb_l = nb_li(array);
    nb_c = nb_col(array);
    k = 1;
    for(i=0; i < nb_l; i++)
    {
        for(j=0; j < nb_c; j++)
        {
            hypo = nb_c-j; //EST EGAL AU NOMBRE D'ELEMENTS À VERIFIER SUR LA DIAGONALE DE DROITE
            if(hypo > min(nb_l, nb_c)-i) hypo = min(nb_c-j, nb_l-i); //PLUS ON AVANCE DANS LE TABLEAU PLUS LE NOMBRE D'ELEMENT À VERIFIER DIMINUE
            for(cursor_diag = 0; cursor_diag<hypo; cursor_diag++) //AVANCE SUR LA DIAGONALE
            {
                if(k == cond) {return(TRUE);} //SI LE COMPTEUR CORRESPOND À cond ALORS LES BILLES SONT ALIGNEES ET UN JOEUR A GAGNE
                if(array[i+cursor_diag][j+cursor_diag] == array[i+cursor_diag+1][j+cursor_diag+1]
                && array[i+cursor_diag][j+cursor_diag] == c)
                    k++;
                else
                    k=1;
            }
            k=1;
            hypo = min(nb_c, nb_l)-hypo+1-i; //EST EGAL AU NOMBRE D'ELEMENTS À VERIFIER SUR LA DIAGONALE DE GAUCHE
            for(cursor_diag = 0; cursor_diag<hypo; cursor_diag++)
            {
                if(k == cond) return(TRUE); //SI LE COMPTEUR CORRESPOND À cond ALORS LES BILLES SONT ALIGNEES ET UN JOEUR A GAGNE
                if(array[i+cursor_diag][j-cursor_diag] == array[i+cursor_diag+1][j-cursor_diag-1]
                && array[i+cursor_diag][j-cursor_diag] == c)
                    k++;
                else
                    k=1;
            }
            k=1;
        }
    }
    return(FALSE);
}

int                 min(int a, int b) //RENVOIE LE MINIMUM DES DEUX NOMBRES PASSES EN PARAMETRE
{
    if(a<b) return(a);
    else return(b);
}

int                 max(int a, int b) //RENVOIE LE MAXIMUM DES DEUX NOMBRES PASSES EN PARAMETRE
{
    if(a>b) return(a);
    else return(b);
}
