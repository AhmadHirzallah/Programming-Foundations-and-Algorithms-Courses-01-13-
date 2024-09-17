#include "game.h"

void	ft_set_s_game_starting_initial_values(t_s_game_results *p_s_game)
{
	p_s_game->player_winning_times = 0;
    p_s_game->computer_winning_times = 0;
    p_s_game->draw_times = 0;
    p_s_game->game_rounds_nbr = 0;
}

void	ft_start_game()
{
	char	want_to_play;
	t_s_game_results	*p_s_game;

	p_s_game = malloc(sizeof(t_s_game_results));
    if (p_s_game == NULL) 
	{
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
	want_to_play = 'Y';
	while (want_to_play == 'Y' || want_to_play == 'y')
	{
		ft_set_s_game_starting_initial_values(p_s_game);
		p_s_game->game_rounds_nbr = ft_i_read_ranged_nbr("Please enter how many rounds you want to play:\n", 1, 10);
		ft_play_game(p_s_game);
		ft_print_game_over_screen();
		ft_print_game_results(p_s_game);
		printf("Do you want to play again? (Y/N):\n");
		scanf(" %c", &want_to_play);
	}
	free (p_s_game);
}

void ft_print_game_over_screen() 
{
    printf("\033[2J\033[1;1H"); // Clear the screen and move cursor to top-left
    printf("\033[1;33m"); // Set text color to yellow
    printf("┌───────────────────────────────────────────────┐\n");
    printf("│                                               │\n");
    printf("│             ┌───────────────┐                 │\n");
    printf("│             │   +++  G A M E   O V E R  +++   │\n");
    printf("│             └───────────────┘                 │\n");
    printf("│                                               │\n");
    printf("└───────────────────────────────────────────────┘\n");
    printf("\033[0m"); // Reset text color to default
    printf("└──────────────────────────────────────────┘\n");
    printf("\t\t\t[Game Results]\n");
    printf("───────────────────────────────────────────────\n\n");
}

void	ft_play_game(t_s_game_results *p_s_game)
{
	t_s_round_results *p_s_round;

	p_s_round = malloc(sizeof(t_s_round_results));
	p_s_round->round_nbr = 0;
    printf("\033[2J\033[1;1H"); // Clear the screen and move cursor to top-left
	printf("%sS T O N E ** P A P E R ** S C I S S O R S\n", ft_put_tabs(3));
	while (p_s_round->round_nbr++ < p_s_game->game_rounds_nbr)
	{	
		ft_show_round_nbr_in_round_start(p_s_round->round_nbr);
		p_s_round->player_choice = ft_get_e_player_choice();
		p_s_round->computer_choice = ft_get_e_computer_random_choice();
		p_s_round->round_winner = ft_get_e_round_winner(p_s_round->player_choice, p_s_round->computer_choice);
		ft_show_round_nbr_in_round_result(p_s_round->round_nbr);
		ft_print_round_results(p_s_round);
		ft_update_game_results(p_s_game, p_s_round->round_winner);
	}
	p_s_game->e_game_winner = ft_get_e_final_game_winner(p_s_game);
	free(p_s_round);
}

t_e_winner	ft_get_e_final_game_winner(t_s_game_results *p_s_game)
{
	if (p_s_game->player_winning_times > p_s_game->computer_winning_times)
		return (player);
	else if (p_s_game->player_winning_times < p_s_game->computer_winning_times)
		return (computer);
	else 
		return (draw);
}

void	ft_print_game_results(t_s_game_results *p_s_game)
{
	printf("%s", ft_color_change_result(p_s_game->e_game_winner));
	printf("Game Rounds\t\t\t: %d\n", p_s_game->game_rounds_nbr);
	printf("Player Winning Times\t\t: %d\n", p_s_game->player_winning_times);
	printf("Computer Winning Times\t\t: %d\n", p_s_game->computer_winning_times);
	printf("Drawing Times\t\t\t: %d\n", p_s_game->draw_times);
	printf("Final Winner\t\t\t: %s\n", ft_get_str_winner(p_s_game->e_game_winner));
    printf("───────────────────────────────────────────────\n\n");
    printf("%s", RESET);
}
