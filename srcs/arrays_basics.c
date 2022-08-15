/**
 * @Author: rahaingomanana_perriere <lrahaing_pperierr>
 * @Date:   2019-04-25T19:44:12+02:00
 * @Email:  laurent.rahaingomanana@estaca.eu_paul.perriere@estaca.eu
 * @Project: pentago
 * @Filename: arrays_basics.c
 * @Last modified by:   lrahaing_pperierr
 * @Last modified time: 2019-04-28T15:54:23+02:00
 */



#include "arrays_basics.h"
#include "check_win.h"
#include "game_output.h"
#include "get_user.h"
#include "turn_quarter.h"

char                **init_tab(s_dim *size_array) //INITIALISE UN TABLEAU (DE TAILLE DONNEE EN PARAMETRE) ET LE RENVOIE
{
    char        **array;

    array = (char **)malloc(sizeof(char *) * (size_array->line+1));         // ALLOCATION MEMOIRE
    for(int i = 0; i < size_array->line; i++)                               // PARCOURT LA PREMIERE COLONNE DU TABLEAU
    {
        array[i] = (char *)malloc(sizeof(char) * (size_array->column+1));   // ALLOCATION MEMOIRE
        for(int j = 0; j < size_array->column; j++) array[i][j] = '.';      // PARCOURT UNE LIGNE DU TABLEAU ET PLACE LES '.'
        array[i][size_array->column] = '\0';                                // PLACEMENT DU SYMBOLE DE FIN DE CHAINE (à la fin de chaque ligne)
    }
    array[size_array->line] = (char *)malloc(sizeof(char) * 1);             // ALLOCATION D'UNE CASE MEMOIRE
    array[size_array->line][0] = '\0';                                      // PLACEMENT DU SYMBOLE DE FIN DE CHAINE DANS CETTE DERNIERE (première colonne uniquement)

    return(array);
}

int                 nb_li(char **array) //RENVOIE LE NOMBRE DE LIGNES DU TABLEAU DONNE EN PARAMETRE
{
    int             i;

    i = 0;
    while (array[i++][0] != '\0');
    return(i-1);
}

int                 nb_col(char **array) //RENVOIE LE NOMBRE DE COLONNES DU TABLEAU DONNE EN PARAMETRE
{
    int             j;

    j = 0;
    while(array[0][j++] != '\0');
    return(j-1);
}

char                **cpy_array(char **array) //COPIE UN TABLEAU (DONNE EN PARAMETRE) ET RENVOIE SA COPIE
{
    int             i;
    int             j;
    char            **cpd_array;

    cpd_array = (char **)malloc(sizeof(char *) * (nb_li(array)+1));
    i = 0;
    j = 0;
    while(array[i][0] != '\0')    // UTILISATION DES SYMBOLES DE FIN DE CHAINE POUR COPIER TOUS LES ELEMENTS DE ARRAY
    {
        cpd_array[i] = (char *)malloc(sizeof(char) * (nb_col(array)+1));
        while(array[i][j] != '\0')
        {
            cpd_array[i][j] = array[i][j];
            j++;
        }
        cpd_array[i][j] = '\0';
        j = 0;
        i++;
    }
    cpd_array[i] = (char *)malloc(sizeof(char) * 1);
    cpd_array[i][0] = '\0';

    return(cpd_array);
}


void                free_dbl_array(char **array) //LIBERE L'ESPACE MEMOIRE DU TABLEAU DONNE EN PARAMETRE
{
    int             nb_l;

    nb_l = nb_li(array);
    for(int i=0; i<nb_l; i++) free(array[i]);
    free(array);
}
