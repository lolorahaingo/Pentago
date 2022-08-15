/**
 * @Author: rahaingomanana_perriere <lrahaing_pperierr>
 * @Date:   2019-04-26T22:55:16+02:00
 * @Email:  laurent.rahaingomanana@estaca.eu_paul.perriere@estaca.eu
 * @Project: pentago
 * @Filename: game_output.c
 * @Last modified by:   lrahaing_pperierr
 * @Last modified time: 2019-04-28T15:54:30+02:00
 */



#include "arrays_basics.h"
#include "check_win.h"
#include "game_output.h"
#include "get_user.h"
#include "turn_quarter.h"

void                play_game(char **array, char player, s_dim *dim_array, s_dim *dim_quarter) //JOUE UN TOUR DU JOUEUR player DONC
//MODIFIE LE TABLEAU EN FONCTION DE SES CHOIX
{
    s_dim           pos_p;
    s_dim           pos_t;
    char            **quarter;
    char            rot;

    pos_p = *get_pos('p', dim_quarter, dim_array);
    while(array[pos_p.line][pos_p.column] != '.') //VERIFIE QUE LA CASE NE SOIT PAS OCCUPEE
    {
        printf("\nCase déjà occupée\n\n");
        pos_p = *get_pos('p', dim_quarter, dim_array);
    }
    array[pos_p.line][pos_p.column] = player;
    printf("\n");
    disp_char_array(array, dim_quarter); //AFFICHE LE TABLEAU AVEC LE PION PLACE
    printf("\n\n\n");

    pos_t = *get_pos('t', dim_quarter, dim_array);
    quarter = extracted_quarter(&pos_t, dim_quarter, array);
    rot = get_rot();
    turn_quarter(quarter, rot);
    put_quarter_in_array(quarter, array, &pos_t);
}


#ifndef __WIN32__

void                style(stl action, ...) //GESTION DES COULEURS ET DE LA POLICE D'ECRITURE SUR UNIX
{
    va_list         pt;
    stl             c;

    va_start(pt, action);
    c = action;
    printf("\e[%im", c);
    while(c != END)
    {
        c = va_arg(pt, stl);
        printf("\e[%im", c);
    }
    va_end(pt);
}

void                disp_player(char *player, int nb_player) //AFFICHE LE JOUEUR QUI DOIT JOUEUR ET PASSE AU JOUEUR SUIVANT (EN
//MODIFIANT *player)
{
    (*player)++;
    if(*player == 'A'+nb_player) *player = 'A';
    style(BOLD, UNDERLINE, BLUE_F, END);
    printf("\n\n\nTour du joueur %c\n", *player);
    style(RESET, END);
}

void                disp_char_array(char **array, s_dim *dim_quarter) //AFFICHE UNE TABLEAU DE QUARTER DE DIMENSIONS dim_quarter ET DE
//TYPE CHAR (LE TABLEAU CONTIENDRA DES \0 À LA FIN DE CHAQUE LIGNE ET À LA FIN DU TABLEAU)
{

    int             i;
    int             j;
    int             num;

    i = 0;
    j = 0;
    style(YELLOW_F, END);
    for(num = 1; num <= nb_col(array); num++) printf("%-2d ",num);
    style(RESET, END);
    printf("\n\n");
    num = 1;
    while(array[i][0] != '\0')
    {
        while(array[i][j] != '\0')
        {
            print_char_format(array, i, j, dim_quarter);
            j++;
        }
        style(YELLOW_F, END);
        printf("     %d",num++);
        style(RESET, END);
        j = 0;
        i++;
        if (array[i][0] != '\0') printf("\n");
    }
}

void                print_char_format(char **array, int i, int j, s_dim *dim_quarter) //AFFICHE UNE CASE (DE POSITION [i, j]) DU
//TABLEAU (**array), DE QUARTERS DE DIMENSIONS dim_quarter, AU BON FORMAT C.A.D. AVEC SA COULEUR DE POLICE ET D'ARRIERE PLAN CORRESPONDANTE
{
    char            c;
    stl             bg_color;
    stl             ft_color;
    int             nb_quarter_line;
    int             nb_quarter_column;

    c = array[i][j];
    nb_quarter_line = i/dim_quarter->line;
    nb_quarter_column = j/dim_quarter->column;
    if(nb_quarter_line%2 == 0)
    {
        if(nb_quarter_column%2 == 0) bg_color = BRIGHT_BLACK_B;
        else bg_color = BLACK_B;
    }
    else
    {
        if(nb_quarter_column%2 != 0) bg_color = BRIGHT_BLACK_B;
        else bg_color = BLACK_B;
    }
    switch(c) //COULEUR DES BILLES DE CHAQUE JOUEUR
    {
        case 'A':
            ft_color = RED_F;
            c = 'O';
            break;
        case 'B':
            ft_color = BLUE_F;
            c = '0';
            break;
        case 'C':
            ft_color = YELLOW_F;
            c = '#';
            break;
        case 'D':
            ft_color = GREEN_F;
            c = '@';
            break;
        case 'E':
            ft_color = MAGENTA_F;
            c = '&';
            break;
        case 'F':
            ft_color = CYAN_F;
            c = '%';
            break;
        default:
        if (bg_color == BRIGHT_BLACK_B) ft_color = BLACK_F;
        else ft_color = WHITE_F;
    }
    style(bg_color, ft_color, END);
    if(j != 0) printf(" ");
    printf("%c", c);
    if(j+1 != nb_col(array)) printf(" ");
    style(RESET, END);
}

void                disp_menu(s_var_game *settings) // AFFICHE LE MENU DU JEU EN PROPOSANT AU JOUEUR DE JOUEUR OU D'ACCEDER AUX REGLAGES

{
    int             choix;
    char            exit;
    char             **tmp_array;
    s_dim           tmp_dim;

    settings->dim_a = 6;
    settings->dim_q = 3;
    settings->serie_p = 5;
    settings->nb_p = 2;
    do
    {
        style(BOLD, UNDERLINE, CYAN_F, YELLOW_B, END);
        printf("-- -- -- -- -- -- -- -- -- --/* PENTAGO *\\-- -- -- -- -- -- -- -- -- --");
        style(RESET, END);
        printf("\n\n\n\n");
        tmp_dim.column = settings->dim_a;
        tmp_dim.line = settings->dim_a;
        tmp_array = init_tab(&tmp_dim);
        tmp_dim.column = settings->dim_q;
        tmp_dim.line = settings->dim_q;
        disp_char_array(tmp_array, &tmp_dim);
        free_dbl_array(tmp_array);
        printf("\n\n\n\n\n\n");
        style(BOLD, UNDERLINE, RED_F, CYAN_B, END);
        printf("MENU");
        style(RESET, END);
        printf("\n\n\n");
        printf(". Tapez 1 pour jouer au Pentago\n\n");
        printf(". Tapez 2 pour accéder aux règles du jeu\n\n");
        printf(". Tapez 3 pour accéder aux paramètres du jeu\n\n");
        while(!scanf("%d", &choix) || !(choix <= 3 && choix >= 1)) rewind(stdin);

        if(choix == 1) {printf("\n.\n.\n.\n.\n.\n.\n\n.\n.\n.\n.\n.\n.\n\n.\n.\n.\n.\n.\n.\n\n");system(CLEAR);return;}
        else if(choix == 2)
        {
            do
            {
                system(CLEAR);
                printf("Le Pentago est un jeu joué sur un grand plateau 6x6, divisé en quatre petits plateaux de 3x3.\n");
                printf("À chaque tour, un joueur place une bille de sa couleur sur une case_ du grand plateau, puis tourne un des\n");
                printf("petits plateaux (appelés quarter) de 90 degrés dans le sens horaire ou dans le sens contraire.\n");
                printf("Un joueur gagne en obtenant cinq billes alignées sur une rangée verticale, horizontale ou diagonale\n\n");
                rewind(stdin);
            } while(!(scanf("%c", &exit)));
            system(CLEAR);
        }
        else if(choix == 3)
        {
            while (choix != 5)
            {
                system(CLEAR);
                printf("Tapez 1 pour changer la dimension du grand plateau\n");
                printf("Tapez 2 pour changer la dimension des quarters\n");
                printf("Tapez 3 pour changer le nombre de pions à aligner pour gagner\n");
                printf("Tapez 4 pour changer le nombre de joueurs\n");
                printf("Tapez 5 pour quitter\n");
                while(!scanf("%d", &choix) || !(choix <= 5 && choix >= 1)) rewind(stdin);
                system(CLEAR);
                rewind(stdin);
                switch(choix)
                {
                    case 1:
                        printf("Entrer la nouvelle dimension du grand plateau\n");
                        while(!scanf("%d", &(settings->dim_a))) rewind(stdin);
                        break;
                    case 2:
                        printf("Entrer la nouvelle dimension des quarters\n");
                        while(!scanf("%d", &(settings->dim_q))) rewind(stdin);
                        break;
                    case 3:
                        printf("Entrer le nombre de pions à aligner pour gagner");
                        while(!scanf("%d", &(settings->serie_p))) rewind(stdin);
                        break;
                    case 4:
                        printf("Entrer le nombre de joueurs (max 6)");
                        while(!scanf("%d", &(settings->nb_p)) || !(settings->nb_p <= 6 && choix >= 2)) rewind(stdin);
                        break;
                }
            }
        }
    } while(1);
}

#else

#include <windows.h>

void                style(stl font_color, stl bgnd_color) //GESTION DES COULEURS SUR WINDOWS
{
    HANDLE          H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,bgnd_color*16+font_color);
}

void                disp_player(char *player, int nb_player)
{
    (*player)++;
    if(*player == 'A'+nb_player) *player = 'A';
    style(BLUE_F, BLACK_B);
    printf("\n\n\nTour du joueur %c\n", *player);
    style(WHITE_F, BLACK_B);
}

void                disp_char_array(char **array, s_dim *dim_quarter)
{

    int             i;
    int             j;
    int             num;

    i = 0;
    j = 0;
    style(YELLOW_F, BLACK_B);
    for(num = 1; num <= nb_col(array); num++) printf("%-2d ",num);
    style(WHITE_F, BLACK_B);
    printf("\n\n");
    num = 1;
    while(array[i][0] != '\0')
    {
        while(array[i][j] != '\0')
        {
            print_char_format(array, i, j, dim_quarter);
            j++;
        }
        style(YELLOW_F, BLACK_B);
        printf("     %d",num++);
        style(WHITE_F, BLACK_B);
        j = 0;
        i++;
        if (array[i][0] != '\0') printf("\n");
    }
}

void                print_char_format(char **array, int i, int j, s_dim *dim_quarter)
{
    char            c;
    stl             bg_color;
    stl             ft_color;
    int             nb_quarter_line;
    int             nb_quarter_column;

    c = array[i][j];
    nb_quarter_line = i/dim_quarter->line;
    nb_quarter_column = j/dim_quarter->column;
    if(nb_quarter_line%2 == 0)
    {
        if(nb_quarter_column%2 == 0) bg_color = BRIGHT_BLACK_B;
        else bg_color = BLACK_B;
    }
    else
    {
        if(nb_quarter_column%2 != 0) bg_color = BRIGHT_BLACK_B;
        else bg_color = BLACK_B;
    }
    switch(c) //COULEUR DES BILLES DE CHAQUE JOUEUR
    {
        case 'A':
            ft_color = RED_F;
            c = 'O';
            break;
        case 'B':
            ft_color = BLUE_F;
            c = '0';
            break;
        case 'C':
            ft_color = YELLOW_F;
            c = '#';
            break;
        case 'D':
            ft_color = GREEN_F;
            c = '@';
            break;
        case 'E':
            ft_color = MAGENTA_F;
            c = '&';
            break;
        case 'F':
            ft_color = CYAN_F;
            c = '%';
            break;
        default:
        if (bg_color == BRIGHT_BLACK_B) ft_color = BLACK_F;
        else ft_color = WHITE_F;
    }
    style(ft_color, bg_color);
    if(j != 0) printf(" ");
    printf("%c", c);
    if(j+1 != nb_col(array)) printf(" ");
    style(WHITE_F, BLACK_B);
}

void                disp_menu(s_var_game *settings)
{
    int             choix;
    char            exit;
    char             **tmp_array;
    s_dim           tmp_dim;

    settings->dim_a = 6;
    settings->dim_q = 3;
    settings->serie_p = 5;
    settings->nb_p = 2;
    do
    {
        style(CYAN_F, YELLOW_B);
        printf("-- -- -- -- -- -- -- -- -- --/* PENTAGO *\\-- -- -- -- -- -- -- -- -- --");
        style(WHITE_F, BLACK_B);
        printf("\n\n\n\n");
        tmp_dim.column = settings->dim_a;
        tmp_dim.line = settings->dim_a;
        tmp_array = init_tab(&tmp_dim);
        tmp_dim.column = settings->dim_q;
        tmp_dim.line = settings->dim_q;
        disp_char_array(tmp_array, &tmp_dim);
        free_dbl_array(tmp_array);
        printf("\n\n\n\n\n\n");
        style(RED_F, CYAN_B);
        printf("MENU");
        style(WHITE_F, BLACK_B);
        printf("\n\n\n");
        printf(". Tapez 1 pour jouer au Pentago\n\n");
        printf(". Tapez 2 pour accéder aux règles du jeu\n\n");
        printf(". Tapez 3 pour accéder aux paramètres du jeu\n\n");
        while(!scanf("%d", &choix) || !(choix <= 3 && choix >= 1)) rewind(stdin);

        if(choix == 1) {printf("\n.\n.\n.\n.\n.\n.\n\n.\n.\n.\n.\n.\n.\n\n.\n.\n.\n.\n.\n.\n");system(CLEAR);return;}
        else if(choix == 2)
        {
            do
            {
                system(CLEAR);
                printf("Le Pentago est un jeu joué sur un grand plateau 6x6, divisé en quatre petits plateaux de 3x3.\n");
                printf("À chaque tour, un joueur place une bille de sa couleur sur une case_ du grand plateau, puis tourne un des\n");
                printf("petits plateaux (appelés quarter) de 90 degrés dans le sens horaire ou dans le sens contraire.\n");
                printf("Un joueur gagne en obtenant cinq billes alignées sur une rangée verticale, horizontale ou diagonale\n\n");
                rewind(stdin);
            } while(!(scanf("%c", &exit)));
            system(CLEAR);
        }
        else if(choix == 3)
        {
            while (choix != 5)
            {
                system(CLEAR);
                printf("Tapez 1 pour changer la dimension du grand plateau\n");
                printf("Tapez 2 pour changer la dimension des quarters\n");
                printf("Tapez 3 pour changer le nombre de pions à aligner pour gagner\n");
                printf("Tapez 4 pour changer le nombre de joueurs\n");
                printf("Tapez 5 pour quitter\n");
                while(!scanf("%d", &choix) || !(choix <= 5 && choix >= 1)) rewind(stdin);
                system(CLEAR);
                rewind(stdin);
                switch(choix)
                {
                    case 1:
                        printf("Entrer la nouvelle dimension du grand plateau\n");
                        while(!scanf("%d", &(settings->dim_a))) rewind(stdin);
                        break;
                    case 2:
                        printf("Entrer la nouvelle dimension des quarters\n");
                        while(!scanf("%d", &(settings->dim_q))) rewind(stdin);
                        break;
                    case 3:
                        printf("Entrer le nombre de pions à aligner pour gagner");
                        while(!scanf("%d", &(settings->serie_p))) rewind(stdin);
                        break;
                    case 4:
                        printf("Entrer le nombre de joueurs (max 6)");
                        while(!scanf("%d", &(settings->nb_p)) || !(settings->nb_p <= 6 && choix >= 2)) rewind(stdin);
                        break;
                }
            }
        }
    } while(1);
}

#endif
