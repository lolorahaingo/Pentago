/**
 * @Author: rahaingomanana_perriere <lrahaing_pperierr>
 * @Date:   2019-04-25T20:20:15+02:00
 * @Email:  laurent.rahaingomanana@estaca.eu_paul.perriere@estaca.eu
 * @Project: pentago
 * @Filename: turn_quarter.c
 * @Last modified by:   lrahaing_pperierr
 * @Last modified time: 2019-04-28T15:54:41+02:00
 */



#include "arrays_basics.h"
#include "check_win.h"
#include "game_output.h"
#include "get_user.h"
#include "turn_quarter.h"

char                **extracted_quarter(s_dim *pos, s_dim *size, char **array) // EXTRAIT LE QUARTER A PARTIR DU GRAND TABLEAU, DE SA TAILLE ET DE SA POSITION
// DANS LE GRAND TABLEAU (DEFINIES PAR L'UTILISATEUR). STRUCTURE SIMILAIRE AU SOUS PROGRAMME **init_tab
{
    char            **quarter;

    quarter = (char **)malloc(sizeof(char *) * (size->line+1));
    for(int i = 0; i < size->line; i++)
    {
        quarter[i]= (char *)malloc(sizeof(char) * (size->column+1));
        for(int j = 0; j < size->column; j++) quarter[i][j] = array[pos->line+i][pos->column+j]; // ATTRIBUTION DES ELEMENTS DU QUARTER A PARTIR DE CEUX DU ARRAY
        quarter[i][size->column] = '\0';
    }
    quarter[size->line] = (char *)malloc(sizeof(char) * 1);
    quarter[size->line][0] = '\0';
    return(quarter);
}

void                transpose_quarter(char **quarter) // EFFECTUE LA TRANSPOSEE DU QUARTER (OPERATION MATRICIELLE)
{
  int               i;
  int               j;
  char              **cpd_quarter;

  cpd_quarter = cpy_array(quarter);        // ON UTILISE LA FONCTION cpy_array AFIN DE CONSERVER UNE VERSION INTACTE DU QUARTER POUR REALISER LES OPERATIONS
  i = 0;
  j = 0;
  while(cpd_quarter[i][0] != '\0')
  {
    while(cpd_quarter[i][j] != '\0')
    {
        quarter[i][j] = cpd_quarter[j][i]; // CHAQUE LIGNE DEVIENT UNE COLONNE (OU INVERSEMENT)
        j++;
    }
    j = 0;
    i++;
  }
  free_dbl_array(cpd_quarter);
}

void                reverse_colonne_quarter(char **quarter) // INVERSE LES COLONNES DU QUARTER
{
    int             nb_c;
    int             nb_l;
    char            tmp;                                    // VARIABLE TAMPON

    nb_c = nb_col(quarter);
    nb_l = nb_li(quarter);
    for (int i = 0; i < nb_l; i++)
        for (int j = 0; j < (nb_c/2); j++)
        {
            tmp = quarter[i][j];
            quarter[i][j] = quarter[i][(nb_c-1)-j];
            quarter[i][(nb_c-1)-j] = tmp;
        }
}

void                turn_quarter(char **quarter, char rot) // UTILISE LES 2 FONCTIONS PRECEDENTES POUR EFFECTUER LA ROTATION DU QUARTER VERS LA GAUCHE OU LA DROITE
{
    transpose_quarter(quarter);
    reverse_colonne_quarter(quarter);
    if(rot == 'G')
        for(int i = 0; i < 2; i++)
        {
            transpose_quarter(quarter);
            reverse_colonne_quarter(quarter);
        }
}

void                put_quarter_in_array(char **quarter, char **array, s_dim *pos) // REINJECTE LE NOUVEAU QUARTER (APRES ROTATION) DANS LE GRAND TABLEAU
{
    int             i;
    int             j;
    s_dim           size_quarter;

    i = 0;
    j = 0;
    size_quarter.column = nb_col(quarter);
    size_quarter.line = nb_li(quarter);
    while(i < size_quarter.line)
    {
        while(j < size_quarter.column)
        {
            array[pos->line+i][pos->column+j] = quarter[i][j]; // ATTRIBUTION DES NOUVEAUX ELEMENTS DU ARRAY A PARTIR DE CEUX DU QUARTER MODIFIE
            j++;
        }
        j = 0;
        i++;
    }
}
