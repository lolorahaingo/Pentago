/**
 * @Author: rahaingomanana_perriere <lrahaing_pperierr>
 * @Date:   2019-04-26T21:43:31+02:00
 * @Email:  laurent.rahaingomanana@estaca.eu_paul.perriere@estaca.eu
 * @Project: pentago
 * @Filename: game_output.h
 * @Last modified by:   lrahaing_pperierr
 * @Last modified time: 2019-04-28T15:54:50+02:00
 */



#ifndef GAME_OUTPUT_H
#define GAME_OUTPUT_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

#ifdef __WIN32__
#define CLEAR "cls"
typedef enum //GESTION DES COULEURS DIFFERENTES SUR WINDOWS/UNIX
{
    END = -1, RESET = 15, BOLD=200, FAINT, ITALIC, UNDERLINE,
    REVERSE, BLACK_F = 0, RED_F = 4, GREEN_F = 2, YELLOW_F = 14,
    BLUE_F = 1, MAGENTA_F = 5,CYAN_F = 3, WHITE_F = 15, BLACK_B = 0,
    RED_B = 4, GREEN_B = 2, YELLOW_B = 14, BLUE_B = 1, MAGENTA_B = 5,
    CYAN_B = 3, WHITE_B = 15, BRIGHT_BLACK_B = 7
}                   stl;
void                style(stl font_color,stl bgnd_color);
#else
#define CLEAR "clear"
typedef enum
{
    END = -1, RESET = 0, BOLD, FAINT, ITALIC, UNDERLINE,
    REVERSE = 7, BLACK_F = 30, RED_F, GREEN_F, YELLOW_F,
    BLUE_F, MAGENTA_F,CYAN_F, WHITE_F, BLACK_B = 40,
    RED_B, GREEN_B, YELLOW_B, BLUE_B, MAGENTA_B,
    CYAN_B, WHITE_B, BRIGHT_BLACK_B = 100
}                   stl;
void                style(stl action, ...);
#endif

//STRUCTURE CONTENANT LES PARAMETRES DU JEU CHANGEABLES
typedef struct var_game
{
    int dim_a;
    int dim_q;
    int serie_p;
    int nb_p;
}                   s_var_game;

void                disp_char_array(char **array, s_dim *dim_quarter); //AFFICHE UNE TABLEAU DE QUARTER DE DIMENSIONS dim_quarter ET DE
//TYPE CHAR (LE TABLEAU CONTIENDRA DES \0 À LA FIN DE CHAQUE LIGNE ET À LA FIN DU TABLEAU)
void                print_char_format(char **array, int i, int j, s_dim *dim_quarter); //AFFICHE UNE CASE (DE POSITION [i, j]) DU
//TABLEAU (**array), DE QUARTERS DE DIMENSIONS dim_quarter, AU BON FORMAT C.A.D. AVEC SA COULEUR DE POLICE ET D'ARRIERE PLAN CORRESPONDANTE
void                play_game(char **array, char player, s_dim *dim_array, s_dim *dim_quarter);//JOUE UN TOUR DU JOUEUR player DONC
//MODIFIE LE TABLEAU EN FONCTION DE SES CHOIX
void                disp_player(char *player, int nb_player); //AFFICHE LE JOUEUR QUI DOIT JOUEUR ET PASSE AU JOUEUR SUIVANT (EN
//MODIFIANT *player)
void                disp_menu(s_var_game *settings); //AFFICHE LE MENU DU JEU EN PROPOSANT AU JOUEUR DE JOUEUR OU D'ACCEDER AUX REGLAGES

#endif
