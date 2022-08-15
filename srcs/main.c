/**
 * @Author: rahaingomanana_perriere <lrahaing_pperierr>
 * @Date:   2019-04-27T21:24:30+02:00
 * @Email:  laurent.rahaingomanana@estaca.eu_paul.perriere@estaca.eu
 * @Project: pentago
 * @Filename: main.c
 * @Last modified by:   lrahaing_pperierr
 * @Last modified time: 2019-04-28T15:54:36+02:00
 */



#include "arrays_basics.h"
#include "check_win.h"
#include "game_output.h"
#include "get_user.h"
#include "turn_quarter.h"

int                 main(void)
{
    char            **game_brd;
    s_dim           dim_game_brd;
    s_dim           dim_quarter;
    char            player;
    boolean_        game;
    s_var_game      param;

    disp_menu(&param);
    dim_game_brd.column = param.dim_a;
    dim_game_brd.line = param.dim_a;
    dim_quarter.line = param.dim_q;
    dim_quarter.column = param.dim_q;
    game_brd = init_tab(&dim_game_brd);
    disp_char_array(game_brd, &dim_quarter);
    printf("\n");
    game = TRUE;
    player = 'A'-1;
    while(game) //TANT QUE LE JEU CONTINUE
    {
        disp_player(&player, param.nb_p);
        play_game(game_brd, player, &dim_game_brd, &dim_quarter);
        printf("\n.\n.\n.\n.\n.\n.\n\n.\n.\n.\n.\n.\n.\n\n.\n.\n.\n.\n.\n.\n\n");
        system(CLEAR);
        disp_char_array(game_brd, &dim_quarter);
        check_for_win(&game, game_brd, param.serie_p, param.nb_p);
    }
    printf("\nMerci d'avoir joué !\n\n");
    return(0);
}
