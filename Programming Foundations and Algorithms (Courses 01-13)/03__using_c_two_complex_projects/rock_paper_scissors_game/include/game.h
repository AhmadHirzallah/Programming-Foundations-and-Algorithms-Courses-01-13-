#ifndef GAME_H
# define GAME_H

#include <stdio.h>
#include <stdlib.h>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

// Enum and struct declarations
typedef enum e_winner {
    player = 1,
    computer,
    draw
} t_e_winner;

typedef struct s_game_results {
    short player_winning_times;
    short computer_winning_times;
    short draw_times;
    short game_rounds_nbr;
    t_e_winner e_game_winner;
} t_s_game_results;

typedef enum e_choice {
    stone = 1,
    paper,
    scissor,
	invalid_choice
} t_e_choice;

typedef struct s_round_results {
    short round_nbr;
    t_e_choice player_choice;
    t_e_choice computer_choice;
    t_e_winner round_winner;
} t_s_round_results;


typedef enum e_datatypes
{
    int_type,
    float_type,
    double_type,
    char_type,
    short_type,
    long_type,
    long_long_type,
    unsigned_int_type,
    unsigned_short_type,
    unsigned_long_type,
    unsigned_long_long_type
}	t_e_datatypes;

// Function declarations
void ft_set_s_game_starting_initial_values(t_s_game_results *p_s_game);
char    *ft_color_change_result(t_e_winner winner);
void ft_start_game();
void ft_print_game_over_screen();
void ft_play_game(t_s_game_results *p_s_game);
t_e_winner ft_get_e_final_game_winner(t_s_game_results *p_s_game);
void ft_print_game_results(t_s_game_results *p_s_game);
void ft_show_round_nbr_in_round_start(short round_nbr);
void ft_show_round_nbr_in_round_result(short round_nbr);
t_e_choice ft_get_e_player_choice();
t_e_choice ft_get_e_computer_random_choice();
char* ft_get_str_choice(t_e_choice choice);
t_e_winner ft_get_e_round_winner(t_e_choice player_choice, t_e_choice computer_choice);
char* ft_get_str_winner(t_e_winner winner);
void ft_print_round_results(t_s_round_results *p_e_round);
void ft_update_game_results(t_s_game_results *p_s_game, t_e_winner round_winner);
int ft_i_read_nbr(char *speak);
char* ft_read_str();
double ft_d_read_nbr(char *speak);
void* ft_malloc(int i_number_of_elements, int i_element_size);
int ft_i_read_ranged_nbr(char *tell, int min, int max);
char* ft_put_tabs(short num);
int ft_p_generate_random_nbr_in_range(int from, int to);
#endif // GAME_H
